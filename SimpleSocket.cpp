#include "SimpleSocket.hpp"

// default constructor

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long iface)
{
  // define address structure
  address.sin_family = domain;
  address.sin_port = port;
  address.sin_addr.S_un.S_addr = htonl(iface);
  // establish socket
  sock = socket(domain, service, protocol);
  test_connection(sock);
  // establish connect
  connection = connect_to_network(sock, address);
  test_connection(connection);
}

// test connection virtual function

void HDE::SimpleSocket::test_connection(int item_to_test)
{
  // confirm that the socket or connection has been properly established
  if (item_to_test < 0)
  {
    perror("Failed to connect...");
    exit(EXIT_FAILURE);
  }
}

// getter functions

struct sockaddr_in HDE::SimpleSocket::get_address() { return address; };
int HDE::SimpleSocket::get_sock() { return sock; }
int HDE::SimpleSocket::get_connection() { return connection; }