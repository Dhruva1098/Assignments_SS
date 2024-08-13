/*
 * 10. Write a program to opem a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
 * a.) check the return value of lseek
 * b.) open the file with od and check the empty spaces in between the data.
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void) {
	int fd = open("example_lseek.txt", O_RDWR|O_CREAT, 0744);
	if (fd < 0) {
		perror("open");
	}
	char buff[50] = "my name is dhruva Sharma. I am a studen of IIITB";
	write(fd, buff, 10);
	off_t ls = lseek(fd, 10, SEEK_CUR);
	write(fd, buff, 10);
}
