/*
 ===========================================================================================
Name : ss10a.c
Author : Dhruva Sharma
Description : Write a seperate program using sigaction system call to catch the following signals
b. SIGINT

output:  parallels@fedora-linux-38 handsOn2]$ ./a.out
waiting for ctrl + c
^CSIGINT caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig(int sig, siginfo_t *info, void* args){
	if(sig == SIGINT){
		printf("SIGINT caught");
	}
}

int main(){
	struct sigaction s;
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = sig;
	sigaction(SIGINT, &s, NULL);

	printf("waiting for ctrl + c\n");
	sleep(10);
}
