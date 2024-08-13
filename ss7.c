/* 
 * 7. Write a program to copy file1 into file2
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	int fd = open("example.txt", O_RDONLY);
	if (fd < 0){
		perror("open");
	}
	int fd2 = open("example_cpy.txt", O_RDWR | O_CREAT, 0744);
	if (fd2 < 0){
		perror("creat");
	}
	char buf[100];
	size_t ret_size = read(fd, buf, sizeof(buf));
	write(fd2, buf, ret_size);
}
