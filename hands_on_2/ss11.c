/*
 ===========================================================================================
Name : ss11.c
Author : Dhruva Sharma
Description : Write a program to ignore a SIGINT signal then reset the default action of
the SIGINT signal using the sigaction system call

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
waiting for ctrl + c 
^CSIGINT ignored 
restored default action of SIGINT
^C

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig(int sig, siginfo_t *info, void* args){
	if(sig == SIGINT){
		printf("SIGINT ignored \n");
	}
}

int main(){
	struct sigaction s;
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = sig;
	sigaction(SIGINT, &s, NULL);
	printf("waiting for ctrl + c \n");
	pause();
	s.sa_sigaction = SIG_DFL;
	printf("restored default action of SIGINT\n");
	sigaction(SIGINT, &s, NULL);
	pause();
}
