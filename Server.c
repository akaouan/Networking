#include "Server.h"
#include <stdio.h>

t_server server_constructor(int domain, int service, int protocol,
    u_long interface, int port, int backlog, void (*launch) (t_server *server))
{
    t_server server;

    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    server.socket = socket(domain, service, protocol);
    if (server.socket)
    {
        perror("Failed to connect socket..\n");
        exit(1);
    }

    if (bind(server.socket, (struct sockaddr *)&server,
        sizeof(server.address)) < 0);
    {
        perror("Failed to bind socket...");
        exit(1);
    }

    if (listen(server.socket, server.backlog) < 0)
    {
        perror("Failed to listen to socket...");
        exit(1);
    }

    server.launch = launch;

    return server;
}

