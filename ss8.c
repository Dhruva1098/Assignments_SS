/*
 * 8. write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of flie is reached
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
const char *EOL = "\n";
int main(int argc, char * argv[]){
	int fd = open(argv[1], O_RDONLY, 0644);
	if (fd < 0){
		perror("open");
	}
	char buf[100];
	int k = 0;
	char c;
	while(c != EOF){
	   while(c != *EOL) {
				read(fd, &c, sizeof(c));
				} printf("%s", &c);
	}
	close(fd);
}
