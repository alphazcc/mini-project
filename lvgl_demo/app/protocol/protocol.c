/**
 * Copyright (c) 2022-2023，HelloAlpha
 *
 * Change Logs:
 * Date           Author       Notes
 */
#include "protocol.h"

msg_pkg_t msg_pkg;
msg_buf_t msg_buf;

/* CRC16 verification */
static uint16_t mc_check_crc16(const uint8_t *data, uint8_t len)
{
    uint16_t crc16 = 0xffff;
    uint8_t state, i, j;
    for (i = 0; i < len; i++)
    {
        crc16 ^= data[i];
        for (j = 0; j < 8; j++)
        {
            state = crc16 & 0x01;
            crc16 >>= 1;
            if (state)
            {
                crc16 ^= 0xa001;
            }
        }
    }
    return crc16;
}

/* Packet decoding */
msg_pkg_t *unpkg_frame(const uint8_t *_msg_buf, const uint8_t size)
{
    msg_pkg_t *_msg_pkg = &msg_pkg;
    uint8_t cnt = 0;
    uint16_t rxchkval = 0;  /* Received parity value */
    uint16_t calchkval = 0; /* Calculate the resulting parity value */

    if (NULL == _msg_buf)
    {
        _msg_pkg->pkg_state = MSG_PKG_NULL;
        goto msg_err;
    }

    if (_msg_buf[cnt++] != MSG_FRAME_HEAD0)
    {
        _msg_pkg->pkg_state = MSG_FRAME_FORMAT_ERR;
        goto msg_err;
    }
    if (_msg_buf[cnt++] != MSG_FRAME_HEAD1)
    {
        _msg_pkg->pkg_state = MSG_FRAME_FORMAT_ERR;
        goto msg_err;
    }
    if (_msg_buf[cnt++] != MSG_FRAME_HEAD2)
    {
        _msg_pkg->pkg_state = MSG_FRAME_FORMAT_ERR;
        goto msg_err;
    }
    if (_msg_buf[cnt++] != MSG_FRAME_HEAD3)
    {
        _msg_pkg->pkg_state = MSG_FRAME_FORMAT_ERR;
        goto msg_err;
    }

    /* CRC16 verification */
    calchkval = mc_check_crc16(_msg_buf, size - 4);

    /* Received parity value */
    rxchkval = ((uint16_t)_msg_buf[size - 3] << 8) + _msg_buf[size - 4];

    if (calchkval == rxchkval)
    {
        /* Parse data into structs */
        _msg_pkg->pkg = &_msg_pkg->frame;
        _msg_pkg->pkg->type = _msg_buf[cnt++];
        _msg_pkg->pkg->cmd = _msg_buf[cnt++];
        _msg_pkg->pkg->code = (uint16_t)_msg_buf[cnt++] << 8;
        _msg_pkg->pkg->code += (uint16_t)_msg_buf[cnt++];
        _msg_pkg->pkg->datalen = (uint16_t)_msg_buf[cnt++] << 8;
        _msg_pkg->pkg->datalen += (uint16_t)_msg_buf[cnt++];

        if (_msg_pkg->pkg->datalen)
        {
            for (uint8_t i = 0; i < _msg_pkg->pkg->datalen; i++)
            {
                _msg_pkg->pkg->data[i] = _msg_buf[cnt++];
            }
        }
        _msg_pkg->pkg_state = MSG_OK;
    }
    else
    {
        _msg_pkg->pkg_state = MSG_FRAME_CHECK_ERR;
        goto msg_err;
    }
    return _msg_pkg;

msg_err:
    return _msg_pkg;
}

/* Packet packaging */
msg_buf_t *pkg_frame(const msg_frame_t *_msg_pkg)
{
    msg_buf_t *_msg_buf = &msg_buf;
    uint8_t cnt = 0;

    if (NULL == _msg_pkg)
    {
        _msg_buf->buf_state = MSG_PKG_NULL;
        goto msg_err;
    }

    /* Add frame header */
    _msg_buf->buf[cnt++] = MSG_FRAME_HEAD0;
    _msg_buf->buf[cnt++] = MSG_FRAME_HEAD1;
    _msg_buf->buf[cnt++] = MSG_FRAME_HEAD2;
    _msg_buf->buf[cnt++] = MSG_FRAME_HEAD3;

    /* Writes instructions to the store */
    _msg_buf->buf[cnt++] = _msg_pkg->type;
    _msg_buf->buf[cnt++] = _msg_pkg->cmd;
    _msg_buf->buf[cnt++] = (_msg_pkg->code & 0xff00) >> 8;
    _msg_buf->buf[cnt++] = _msg_pkg->code & 0xff;

    /* Writes data to the store */
    _msg_buf->buf[cnt++] = (_msg_pkg->datalen & 0xff00) >> 8;
    _msg_buf->buf[cnt++] = _msg_pkg->datalen & 0xff;

    if (_msg_pkg->datalen)
    {
        for (uint8_t i = 0; i < _msg_pkg->datalen; i++)
        {
            _msg_buf->buf[cnt++] = _msg_pkg->data[i];
        }
    }

    /* Calculate the parity value */
    uint16_t calchkval = mc_check_crc16(_msg_buf->buf, cnt);

    /* Add the parity value */
    _msg_buf->buf[cnt++] = calchkval & 0xff;
    _msg_buf->buf[cnt++] = calchkval >> 8;

    /* Add frame end */
    _msg_buf->buf[cnt++] = MSG_FRAME_TAil0;
    _msg_buf->buf[cnt++] = MSG_FRAME_TAil1;

    _msg_buf->buf_ptr = _msg_buf->buf;
    _msg_buf->buf_size = cnt;
    _msg_buf->buf_state = MSG_OK;

    return _msg_buf;

msg_err:
    return _msg_buf;
}