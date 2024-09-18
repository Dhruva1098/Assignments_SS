/*
 ===========================================================================================
Name : ss10a.c
Author : Dhruva Sharma
Description : Write a seperate program using sigaction system call to catch the following signals
a. SIGSEGV

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGSEGV caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig(int sig, siginfo_t *info, void* args){
	if(sig == SIGSEGV){
		printf("SIGSEGV caught");
		exit(0);
	}
}

int main(){
	struct sigaction s;
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = sig;
	sig(SIGSEGV, &s, NULL);

	int * ptr = NULL;
	*ptr = 1;
}
