#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
 
#include "tcp_client.h"

int client_init_socket(void)
{
    int socket_fd;
    struct sockaddr_in server_address;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(SERVER_PORT);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

int client_receive_data(int socket_fd, char *message, ssize_t *size) 
{
    ssize_t bytes_received = recv(socket_fd, message, BUFFER_SIZE, 0);
    if (bytes_received == -1) 
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    *size = bytes_received;
    return 0;
}

void client_send_data(int socket_fd, const char *message, ssize_t size) 
{
    if (send(socket_fd, message, size, 0) < 0) 
    {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

int client_check_tcp_connection(int socket_fd) 
{
    int error = 0;
    socklen_t len = sizeof(error);
    if (getsockopt(socket_fd, SOL_SOCKET, SO_ERROR, &error, &len) == 0) 
    {
        if (error == 0) 
        {
            return 1;
        }
    }
    return 0;
}

int client_close_socket(int socket_fd)
{
    close(socket_fd);
    return 0;
}
