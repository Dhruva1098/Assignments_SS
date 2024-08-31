/*
============================================================================
Name : ss16_rdlock.c
Author : Dhruva Sharma
Descripton :Write a program to perform mandatory locking.
b. Implement read lock
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
	int fd = open("example.txt", O_RDWR);
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("entering cs \n");
	fcntl(fd,F_SETLKW, &lock);
	printf("inside the cs \n Press enter to exit cs \n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("out of cs");
}
