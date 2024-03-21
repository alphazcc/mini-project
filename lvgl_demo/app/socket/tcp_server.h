#ifndef __TCP_SERVER__
#define __TCP_SERVER__

#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

extern char buffer[BUFFER_SIZE];

int server_init_socket(void);
int server_accept_client(int socket_fd);
int server_set_socket_timeout(int socket_fd, long milliseconds);
int server_receive_data(int socket_fd, char *message, ssize_t *size) ;
void server_send_data(int socket_fd, const char *message, ssize_t size);
int server_check_tcp_connection(int socket_fd);
int server_close_socket(int fd);

#endif
