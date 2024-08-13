/* 
 * 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(void) {
	int fd = open("example.txt", O_RDWR | O_EXCL, 0644);
	if (fd < 0) {
		perror("open");
	}
	close(fd);
}
