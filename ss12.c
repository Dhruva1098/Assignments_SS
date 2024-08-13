/*
 * 12 Write a program to find out the opening mode of a file. Use fcntl.
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	int fd = open("example.txt", O_RDONLY, 0644);
	if (fd < 0) perror("open");
	int opening_mode = fcntl(fd, F_GETFL);
	printf("The opening mode of file is:%d\n", opening_mode);
}
