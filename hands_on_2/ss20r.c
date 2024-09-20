/*
===========================================================================================
Name : ss20r.c
Author : Dhruva Sharma
Description : write two programs so that both can communicate by FIFO -Use one way
communication.
Output: 

============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	mkfifo("fifo", 0666);
	char buff[100];
	int fd = open("fifo", O_WRONLY);
	if(fd < 0) perror("open");

	read(fd, buff, sizeof(buff) - 1);
	buff[sizeof(buff) - 1] = '\0';
	printf("Reader recieved: %s\n", buff);
	close(fd);
}

