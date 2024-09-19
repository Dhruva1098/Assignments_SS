/*
 ===========================================================================================
Name : ss12.c
Author : Dhruva Sharma
Description : Write a program to create an orphan process. Use kill system call to send 
SIGKILL signal to the parent process from the child process.

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Parent process: 48059
fork: Success
Parent process: 48059
Child Process: 48060
SIGKILL to parent
Killed
[parallels@fedora-linux-38 handsOn2]$ Parent pid now:1963

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	pid_t pid = fork();
	if(pid < 1) perror("fork");
	if(pid == 0){
		printf("Parent process: %d\nChild Process: %d\n",getppid(), getpid());
		sleep(1);
		printf("SIGKILL to parent\n");
		kill(getppid(), SIGKILL);
		sleep(2);
		printf("Parent pid now:%d\n", getppid());
	} else {
		printf("Parent process: %d\n", getpid());
		sleep(5);
	}
}
