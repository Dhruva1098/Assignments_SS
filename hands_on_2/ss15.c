/*
 ===========================================================================================
Name : ss15.c
Author : Dhruva Sharma
Description : Write a simple program to send some data from parent to child process.
Output:
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Child recieved :  Message from parent 

=============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	pid_t pid;
	char msg[] = " Message from parent ";
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
		printf(" Child recieved : %s\n", buff);
		close(fd[0]);
	}
	else {
		close(fd[0]);
		write(fd[1], msg, strlen(msg));
		close(fd[1]);
		wait(NULL);
	}
}
