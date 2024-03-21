#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/time.h>
#include <errno.h>
#include "tcp_server.h"

char buffer[BUFFER_SIZE] = {0};

int server_init_socket(void) 
{
    int socket_fd;
    struct sockaddr_in address;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 3) < 0) 
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

int server_set_socket_timeout(int socket_fd, long milliseconds)
{
    struct timeval tv;

    tv.tv_sec =  milliseconds / 1000; 
    tv.tv_usec = (milliseconds % 1000) * 1000;

    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0) 
    {
        perror("setsockopt SO_RCVTIMEO");
        exit(EXIT_FAILURE);
    }

    return 0;
}

int server_accept_client(int socket_fd) 
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int temp_fd = accept(socket_fd, (struct sockaddr *)&address, 
                                            (socklen_t*)&addrlen);
    if (temp_fd < 0) 
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Connection established with %s:%d\n", 
            inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    return temp_fd;
}

int server_receive_data(int socket_fd, char *message, ssize_t *size) 
{
    ssize_t bytes_received = recv(socket_fd, message, BUFFER_SIZE, 0);
    if (bytes_received == -1) 
    {
	    if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ETIMEDOUT)
        {
            printf("socket recv time out \r\n");
            return 1;
        } 
        else 
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    *size = bytes_received;
    return 0;
}

void server_send_data(int socket_fd, const char *message, ssize_t size) 
{
    if (send(socket_fd, message, size, 0) < 0) 
    {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

int server_check_tcp_connection(int socket_fd) 
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

int server_close_socket(int socket_fd) 
{
    close(socket_fd);
    return 0;
}
