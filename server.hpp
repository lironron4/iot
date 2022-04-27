#pragma once

#include <vector>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/types.h>  
#include <sys/socket.h>

namespace smarthome
{

class Server
{
public:

private:
    int m_socket;
    int m_port;
    struct sockaddr_in m_serverAddress;
    std::vector<struct sockaddr_in> m_clientAddresses;
    fd_set m_fds;
    size_t m_maxClients;
    size_t m_activity;
    std::vector<int> m_clients;
    void* m_buffer;
    Protocol m_protocol;
    mt::BlockingQueue<cdr::Cdr>& m_CdrQueue;
};

} //namespace smarthome
