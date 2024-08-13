/*
 * 3. Write a program to create a file and print the file descriptor value. Use creat() system call.
 * */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd = creat("creat().txt", 0644);
	if (fd < 0){
		perror("creat");
	}
	printf("File descriptor value for creat().txt is :%d\n", fd);
	close(fd);
}
