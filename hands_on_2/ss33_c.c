/*
===========================================================================================
Name : ss33_c.c
Author : Dhruva Sharma
Description : Write a program to communicate between two machines
Output:
[parallels@fedora-linux-38 handsOn2]$ ./client
server says: world

============================================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>

static void die(const char *msg){
	int err = errno;
	fprintf(stderr, "[%d] %s\n", err, msg);
	abort();
}

int main(){
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd<0){
		die("socket()");
	}
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = ntohs(1234);
	addr.sin_addr.s_addr = ntohl(INADDR_LOOPBACK); //Loopback address 127.0.0.1
	int rv = connect(fd, (const struct sockaddr *)&addr, sizeof(addr));
	if(rv){
		die("connect");
	}
	char msg[] = "hello";
	write(fd, msg, strlen(msg));
	char rbuffer[64] = {};
	ssize_t n = read(fd, rbuffer, sizeof(rbuffer)-1);
	if(n<0){
		die("read");
	}
	printf("server says: %s\n", rbuffer);
	close(fd);
	return 0;
}
