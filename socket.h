#ifndef M_SOCKET_H
#define M_SOCKET_H

#include <stddef.h>
#include <stdint.h>
#include "ip.h"

#define SOCKET_TYPE_UDP 1
#define SOCKET_TYPE_TCP 2

extern int
socket_create (int type);
extern int
socket_close (int type);
extern int
socket_connect (int soc, ip_addr_t *addr, uint16_t port);
extern int
socket_bind (int soc, ip_addr_t *addr, uint16_t port);
extern int
socket_listen (int soc, int backlog);
extern int
socket_accept (int soc);
extern ssize_t
socket_recvfrom (int soc, uint8_t *buf, size_t size, ip_addr_t *peer, uint16_t *port, int timeout);
extern ssize_t
socket_recv (int soc, uint8_t *buf, size_t size);
extern ssize_t
socket_sendto (int soc, uint8_t *buf, size_t len, ip_addr_t *peer, uint16_t port);
extern ssize_t
socket_send (int soc, uint8_t *buf, size_t size);

#endif
