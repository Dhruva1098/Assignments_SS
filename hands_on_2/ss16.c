/*
 ===========================================================================================
Name : ss16.c
Author : Dhruva Sharma
Description : Write a simple program to send some data from parent to child vice versa. Use
two way communication.
Output:
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Child recieved: Message from Parent
Parent Recieved: Message from Child
=============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd_p[2];
	int fd_c[2];
	pid_t pid;
	char msg_p[] = "Message from Parent";
	char msg_c[] = "Message from Child";
	char buff[100];
	if(pipe(fd_p) < 0 || pipe(fd_c) < 0){
		perror("pipe");
		exit(0);
	}
	pid = fork();
	if(pid < 0){
		perror("fork");
	}
	if(pid == 0){
		close(fd_p[1]); //close write end of parent
		close(fd_c[0]); // cloase read end of child
		read(fd_p[0], buff, sizeof(buff));
		printf("Child recieved: %s\n", buff);
		write(fd_c[1], msg_c, strlen(msg_c) + 1);
		close(fd_p[0]);
		close(fd_c[1]);
	}
	else {
		close(fd_p[0]); //close write end of child
		close(fd_c[1]); // close read end of parent
		write(fd_p[1], msg_p, strlen(msg_p) + 1);
		read(fd_c[0], buff, sizeof(buff));
		printf("Parent Recieved: %s\n", buff);
		close(fd_p[1]);
		close(fd_c[0]);

		wait(NULL);
	}
}
