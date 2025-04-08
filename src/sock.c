/**
 * sock.c
 *
 * Copyright (C) 2017 Nickolas Burr <nickolasburr@gmail.com>
 */

#include "sock.h"

/**
 * Create TCP socket.
 */
int mksock(
	const char *url,
	BIO *bp
) {
	int buflen, lindex, sockfd;
	int port, status;
	char *buf = NULL;
	char hostname[256] = "";
	char port_num[6] = "443";
	char protocol[6] = "";
	char *tmp_ptr = NULL;
	struct hostent *host = NULL;
	struct sockaddr_in dest_addr;

	buflen = strlen(url);
	buf = ALLOC(
		sizeof(char) * (
			buflen + NUL_BYTE
		)
	);
	copy(buf, url);

	/**
	 * Remove trailing slash, if applicable.
	 */
	lindex = buflen - 1;

	if (buf[lindex] == '/') {
		buf[lindex] = '\0';
	}

	/**
	 * Protocol (e.g. https).
	 */
	strncpy(
		protocol,
		buf,
		(strchr(buf, ':') - buf)
	);

	/**
	 * Hostname (e.g. www.example.com)
	 */
	strncpy(
		hostname,
		strstr(buf, "://") + 3,
		sizeof(hostname)
	);

	/**
	 * Port (if applicable).
	 */
	tmp_ptr = strchr(hostname, ':');

	if (tmp_ptr != NULL) {
		strncpy(
			port_num,
			tmp_ptr + NUL_BYTE,
			sizeof(port_num)
		);
		*tmp_ptr = '\0';
	}

	host = gethostbyname(hostname);
	port = atoi(port_num);

	/**
	 * Verify hostname is resolvable.
	 */
	if (host == NULL) {
		return -1;
	}

	sockfd = socket(
		AF_INET,
		SOCK_STREAM,
		0
	);

	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(port);
	dest_addr.sin_addr.s_addr = *(long *)(host->h_addr);

	memset(
		&(dest_addr.sin_zero),
		'\0',
		8
	);
	tmp_ptr = inet_ntoa(dest_addr.sin_addr);

	status = connect(
		sockfd,
		(struct sockaddr *) &dest_addr,
		sizeof(struct sockaddr)
	);

	if (status == -1) {
		BIO_printf(
			bp,
			"Error: Cannot connect to host %s [%s] on port %d.\n",
			hostname,
			tmp_ptr,
			port
		);
		return -1;
	}

	return sockfd;
}
