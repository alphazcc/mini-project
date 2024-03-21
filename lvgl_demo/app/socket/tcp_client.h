#ifndef __TCP_CLIENT_H__
#define __TCP_CLIENT_H__

#include <sys/socket.h>

#define SERVER_IP "116.62.81.138"   // 心知天气
#define SERVER_PORT 80              // 心知天气
#define BUFFER_SIZE 1024

int client_init_socket(void);
int client_receive_data(int socket_fd, char *message, ssize_t *size);
void client_send_data(int socket_fd, const char *message, ssize_t size);
int client_check_tcp_connection(int socket_fd);
int client_close_socket(int socket_fd);

#endif