/*
 ===========================================================================================
Name : ss14.c
Author : Dhruva Sharma
Description : Write a simple program to create a pipe, write to the pipe, read from pipe
and display on the monitor.
Output:
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Child got: hello this is a message

=============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	pid_t pid;
	char msg[] = "hello this is a message";
	char buff[100];

	if(pipe(fd) == -1) {
		perror("pipe");
		exit(0);
	}
	pid = fork();
	if(pid < 0){
		perror("fork");
		exit(0);
	}

	if(pid == 0) {
		close(fd[1]);
		read(fd[0], buff, sizeof(buff));
		printf(" Child got: %s\n", buff);
		close(fd[0]);
	}
	else {
		close(fd[0]);
		write(fd[1], msg, strlen(msg));
		close(fd[1]);
		wait(NULL);
	}
}

