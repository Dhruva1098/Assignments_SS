/* 
* 11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated with proper descriptors or not
* a. Use dup
* b. Use dup2
* c. Use fcntl
* */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(void) {
	int fd = open("example.txt", O_RDWR, 0744);
	int fd2 = dup(fd);
	char buff[30] = "abcdefghijklmnopqrstuvwxyz  ";
	write(fd2, buff, sizeof(buff));
	int fd3 = dup2(fd2, 10);
	write(fd3, buff, sizeof(buff));
	int new_fd = fcntl(fd3, F_DUPFD, 0744);
	write(new_fd, buff, sizeof(buff));

}
