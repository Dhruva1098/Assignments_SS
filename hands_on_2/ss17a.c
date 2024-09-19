/*
 ===========================================================================================
Name : ss17a.c
Author : Dhruva Sharma
Description :  Write a program to execute ls -l | wc
============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int fd[2];
	pid_t pid;
	if(pipe(fd) < 0){
		perror("pipe");
		exit(0);
	}
	pid = fork();
	if(pid < 0){
		perror("fork");
	}

	if(pid == 0) {
		close(fd[0]);
		dup(fd[1]); //redirect stdout to pipes write end
		close(fd[1]);
		execlp("ls", "ls", "-l", (char*)NULL);
		perror("execlp");
	} else {
		close(fd[1]);
		dup(fd[0]); // redirect stdin to pipes read end
		close(fd[0]);
		execlp("wc", "wc", (char*)NULL);
		perror("execlp");
	
}


