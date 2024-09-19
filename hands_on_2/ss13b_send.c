/*
 ===========================================================================================
Name : ss13a_send.c
Author : Dhruva Sharma
Description : Write two programs: first program is waititng to catch SIGSTOP signal, the 
second program will send the signal (using killsystem call). Find out whether the first program
is able to catch the signal or not.

output: for send:
[parallels@fedora-linux-38 handsOn2]$ ./send
Enter pid of process to send signals to:50013

Sending SIGSTOP
Sending SIGCONT

=============================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	printf("Enter pid of process to send signals to:");
	scanf("%d", &pid);
	printf("\nSending SIGSTOP\n");
	kill(pid, SIGSTOP);
	sleep(3);
	printf("Sending SIGCONT\n");
	kill(pid, SIGCONT);
}

