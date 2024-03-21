/**
 * Copyright (c) 2022-2023，HelloAlpha
 *
 * Change Logs:
 * Date           Author       Notes
 */
#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include <stdint.h>
// typedef signed char int8_t;
// typedef unsigned char uint8_t;
// typedef unsigned int uint16_t;

#ifndef NULL
#define NULL ((void *)0)
#endif

#define MSG_FRAME_HEAD0 0xED /* Frame header */
#define MSG_FRAME_HEAD1 0xB9 /* Frame header */
#define MSG_FRAME_HEAD2 0x55 /* Frame header */
#define MSG_FRAME_HEAD3 0xAA /* Frame header */
#define MSG_FRAME_TAil0 0x5A /* Frame end */
#define MSG_FRAME_TAil1 0xA5 /* Frame end */

#define MSG_FRAME_MAX_LEN 64
#define MSG_BUF_MAX_LEN 96

/* Error type Definition */
typedef enum
{
    MSG_OK = 0,               /* normal */
    MSG_FRAME_FORMAT_ERR = 1, /* Frame format error */
    MSG_FRAME_CHECK_ERR = 2,  /* The validation value is wrong */
    MSG_TIMEOUT = 3,          /* Communication timeout */
    MSG_PKG_NULL = 4,         /* Data packet empty */
} MSG_RESULT;

/* Frame format definition */
typedef struct msg_frame
{
    //  uint32_t head;                      /* Frame header */
    uint8_t type;                    /* Device  ID */
    uint8_t cmd;                     /* Order code */
    uint16_t code;                   /* Function code */
    uint16_t datalen;                /* Data length */
    uint8_t data[MSG_FRAME_MAX_LEN]; /* Data storage area */
    //  uint16_t chkval;                    /* Check value */
    //  uint16_t tail;                      /* Frame end */
} msg_frame_t;

typedef struct msg_pkg
{
    struct msg_frame frame;
    struct msg_frame *pkg;
    int8_t pkg_state;
} msg_pkg_t;

typedef struct msg_buf
{
    uint8_t buf[MSG_BUF_MAX_LEN];
    uint8_t *buf_ptr;
    uint16_t buf_size;
    int8_t buf_state;
} msg_buf_t;

/* Global variable definitions */
extern msg_pkg_t msg_pkg;
extern msg_buf_t msg_buf;

msg_pkg_t *unpkg_frame(const uint8_t *_msg_buf, const uint8_t size);
msg_buf_t *pkg_frame(const msg_frame_t *_msg_pkg);

#endif