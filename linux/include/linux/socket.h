#ifndef _LINUX_SOCKET_H
#define _LINUX_SOCKET_H

#include <lwk/socket.h>

/*
 * Desired design of maximum size and alignment (see RFC2553)
 */
#define _K_SS_MAXSIZE   128 /* Implementation specific max size */
#define _K_SS_ALIGNSIZE (__alignof__ (struct sockaddr *))
                /* Implementation specific desired alignment */

struct __kernel_sockaddr_storage {
	unsigned short  ss_family;      /* address family */
	/* Following field(s) are implementation specific */
	char        __data[_K_SS_MAXSIZE - sizeof(unsigned short)];
                /* space to achieve desired size, */
                /* _SS_MAXSIZE value minus size of ss_family */
} __attribute__ ((aligned(_K_SS_ALIGNSIZE)));   /* force desired alignment */

#define sockaddr_storage __kernel_sockaddr_storage

#define AF_INET     2   /* Internet IP Protocol     */
#define AF_INET6    10  /* IP version 6         */

#endif
