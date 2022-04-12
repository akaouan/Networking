#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/socket.h>

typedef struct t_list{
    int                 domain;
    int                 protocol;
    int                 service;
    u_long              interface;
    int                 port;
    int                 backlog;
    
    int                 socket;

    struct sockaddr_in  address;
    void                *launch) (struct t_list *server);
} t_server;

t_server server_constructor(int domain, int service, int protocol,
    u_long interface, int port, int backlog, void (*launch) (t_server *server)));
#endif