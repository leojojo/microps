#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "socket.h"
#include "udp.h"
#include "tcp.h"

#define SOCKET_ENTRY_TABLE_SIZE 1024

struct socket_entry {
  int used;
  int type;
  int descriptor;
};

struct socket_entry socket_table[SOCKET_ENTRY_TABLE_SIZE];

int
socket_create (int type) {
  //printf(">>> socket_create <<<\n");

  for (int i = 0; i < SOCKET_ENTRY_TABLE_SIZE; i++) {
    if (socket_table[i].used)
      continue;

    socket_table[i].type = type;
    switch (type) {
      case SOCKET_TYPE_UDP:
        socket_table[i].descriptor = udp_api_open();
        if (socket_table[i].descriptor < 0)
          perror("udp_api_open() failed\n");
        break;
      case SOCKET_TYPE_TCP:
        socket_table[i].descriptor = tcp_api_open();
        if (socket_table[i].descriptor < 0)
          perror("tcp_api_open() failed\n");
        break;
      default:
        printf("failed to create socket: invalid socket type\n");
        return -1;
    }

    socket_table[i].used = 1;
    //printf(">>> socket_created! <<<\n%d\n", i);
    return i;
  }
}

int
socket_close (int soc) {
  //printf(">>> socket_close <<<\n%d\n", soc);
  if (soc > SOCKET_ENTRY_TABLE_SIZE)
    perror("out of socket_table\n");

  switch (socket_table[soc].type) {
    case SOCKET_TYPE_UDP:
      if (udp_api_close(socket_table[soc].descriptor) < 0)
        perror("udp_api_close() failed\n");
      break;
    case SOCKET_TYPE_TCP:
      if (tcp_api_close(socket_table[soc].descriptor) < 0)
        perror("tcp_api_close() failed\n");
      break;
    default:
      printf("failed to close socket: invalid socket type\n");
      return -1;
  }

  socket_table[soc].used = 0;
  memset(&socket_table[soc], 0, sizeof(struct socket_entry));      // delete from socket_table:w
  //printf(">>> socket_closed! <<<\n");
  return 0;
}

int
socket_connect (int soc, ip_addr_t *addr, uint16_t port) {
  return -1;
}

int
socket_bind (int soc, ip_addr_t *addr, uint16_t port) {
  //printf(">>> socket_bind <<<\n");
  if (soc > SOCKET_ENTRY_TABLE_SIZE)
    perror("out of socket_table\n");

  switch (socket_table[soc].type) {
    case SOCKET_TYPE_UDP:
      if (udp_api_bind(socket_table[soc].descriptor, addr, port) < 0)
        perror("udp_api_bind() failed\n");
      break;
    //case SOCKET_TYPE_TCP:
    //  if (tcp_api_bind(socket_table[soc].descriptor, addr, port) < 0)
    //    perror("tcp_api_bind() failed\n");
    //  break;
    default:
      printf("failed to bind socket: invalid socket type\n");
      return -1;
  }
  //printf(">>> socket_binded! <<<\n%d\n",soc);
  return 0;
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
  //printf(">>> socket_recvfrom <<<\n");
  if (soc > SOCKET_ENTRY_TABLE_SIZE)
    perror("out of socket_table\n");

  switch (socket_table[soc].type) {
    case SOCKET_TYPE_UDP:
      if ((size = udp_api_recvfrom(socket_table[soc].descriptor, buf, size, peer, port, timeout)) < 0)
        perror("udp_api_recvfrom() failed\n");
      break;
    default:
      printf("failed to recvfrom socket: invalid socket type\n");
      return -1;
  }
  //printf(">>> socket_recvfromed! <<<\n%d\n",size);
  return size;
}

ssize_t
socket_recv (int soc, uint8_t *buf, size_t size) {
  return -1;
}

ssize_t
socket_sendto (int soc, uint8_t *buf, size_t len, ip_addr_t *peer, uint16_t port) {
  //printf(">>> socket_sendto <<<\n");
  if (soc > SOCKET_ENTRY_TABLE_SIZE)
    perror("out of socket_table\n");

  switch (socket_table[soc].type) {
    case SOCKET_TYPE_UDP:
      if ((len = udp_api_sendto(socket_table[soc].descriptor, buf, len, peer, port)) < 0)
        perror("udp_api_sendto() failed\n");
      break;
    default:
      printf("failed to sendto socket: invalid socket type\n");
      return -1;
  }
  //printf(">>> socket_sendtoed! <<<\n%d\n",len);
  return len;
}

ssize_t
socket_send (int soc, uint8_t *buf, size_t size) {
  return -1;
}
