/*
 ===========================================================================================
Name : ss9.c
Author : Dhruva Sharma
Description : Write a program to ignore a SIGINT signal then reset the default action of
the SIGINT signal - use signal system call
output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGINT is being ignored
^CSIGINT caught but ignoring
SIGINT is on default behaviour again
^C

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int sig){
	if(sig == SIGINT){
		printf("SIGINT caught but ignoring\n");
	}
	else
		printf("unknown signal\n");
}

int main(){
	signal(SIGINT, sig_handler);
	printf("SIGINT is being ignored\n");
	sleep(5);
	signal(SIGINT, SIG_DFL);
	printf("SIGINT is on default behaviour again\n");
	sleep(5);
}
