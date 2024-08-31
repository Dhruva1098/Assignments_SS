/*
============================================================================
Name : ss7.c
Author : Dhruva Sharma
Description : Write a program to copy file1 into file2
============================================================================
*/
#include <fcntl.h>
#include <sys/fcntl.h>
#include <sys/syslimits.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0){
		perror("open");
	}
	int fd2 = open(argv [2],O_WRONLY | O_EXCL | O_CREAT, 0600);
	if (fd2 < 0){
		perror("creat");
	}
	char buf[100];
	size_t ret_size;
	while((ret_size = read(fd, buf, sizeof(buf))) > 0){
	write(fd2, buf, ret_size);}
	close(fd);
	close(fd2);
}
