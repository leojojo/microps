#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "socket.h"
#include "udp.h"
#include "tcp.h"

int
socket_create (int type) {
  return -1;
}

int
socket_close (int soc) {
  return -1;
}

int
socket_connect (int soc, ip_addr_t *addr, uint16_t port) {
  return -1;
}

int
socket_bind (int soc, ip_addr_t *addr, uint16_t port) {
  return -1;
}

int
socket_listen (int soc, int backlog) {
  return -1;
}

int
socket_accept (int soc) {
  return -1;
}

ssize_t
socket_recvfrom (int soc, uint8_t *buf, size_t size, ip_addr_t *peer, uint16_t *port, int timeout) {
  return -1;
}

ssize_t
socket_recv (int soc, uint8_t *buf, size_t size) {
  return -1;
}

ssize_t
socket_sendto (int soc, uint8_t *buf, size_t len, ip_addr_t *peer, uint16_t port) {
  return -1;
}

ssize_t
socket_send (int soc, uint8_t *buf, size_t size) {
  return -1;
}
