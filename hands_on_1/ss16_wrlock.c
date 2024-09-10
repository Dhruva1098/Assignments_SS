/*
============================================================================
Name : ss16_wrlock.c
Author : Dhruva Sharma
Descripton : Write a program to perform mandatory locking.
a. Implement write lock

============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
	int fd = open("example.txt", O_RDWR);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("entering cs \n");
	fcntl(fd,F_SETLKW, &lock);
	printf("inside the cs \nPress enter to exit cs \n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("exiting the cs\n");
	printf("out of cs");
}
