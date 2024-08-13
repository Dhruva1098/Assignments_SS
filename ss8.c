/*
 * 8. write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of flie is reached
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void){
	int fd = open("example.txt", O_RDONLY, 0644);
	if (fd < 0){
		perror("open");
	}
	char buf[100];
	ssize_t retval = read(fd, buf, sizeof(buf));
	int i = 0;
	for(i = 0; i <= retval ; i++){
		printf("%c", buf[i]);
	}
}
