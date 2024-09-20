/*
===========================================================================================
Name : ss20w.c
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
	printf("Enter message:\n");
	fflush(stdout);
	int r = read(STDIN_FILENO, buff, sizeof(buff) - 1);
	if(r > 0){
		buff[r] = '\0';
	}
	write(fd,buff,r);
	close(fd);
}
