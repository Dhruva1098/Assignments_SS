/*
 ===========================================================================================
Name : ss13a_wait.c
Author : Dhruva Sharma
Description : Write two programs: first program is waititng to catch SIGSTOP signal, the 
second program will send the signal (using kill system call). Find out whether the first program
is able to catch the signal or not.

output: for send:
[parallels@fedora-linux-38 handsOn2]$ ./wait
Process waiting for signals: 50013

[4]+  Stopped                 ./wait
[parallels@fedora-linux-38 handsOn2]$ Caught SIGCONT, continuing

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig(int sig){
	if(sig == SIGCONT){
		printf("Caught SIGCONT, continuing\n");
	} else if (sig == SIGINT) {
		printf("Caught SIGINT\n");
	}
}
int main(){
	signal(SIGINT, sig);
	signal(SIGCONT, sig);
	printf("Process waiting for signals: %d\n", getpid());
	while(1){sleep(1);}
}

