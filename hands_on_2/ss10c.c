/*
 ===========================================================================================
Name : ss10c.c
Author : Dhruva Sharma
Description : Write a seperate program using sigaction system call to catch the following signals
c. SIGFPE

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGFPE caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig(int sig, siginfo_t *info, void* args){
	if(sig == SIGFPE){
		printf("SIGFPE caught");
		exit(0);
	}
}

int main(){
	struct sigaction s;
	s.sa_flags = SA_SIGINFO;
	
	int a = 5;
	int b = 0;s.sa_sigaction = sig;
	sigaction(SIGFPE, &s, NULL);

	int z = a/b;
	printf("%d", z);
}
