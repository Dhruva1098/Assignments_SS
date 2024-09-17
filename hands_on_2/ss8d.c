/*
 ===========================================================================================
Name : ss8d.c
Author : Dhruva Sharma
Description : Write a program using signal system call to catch the following signals
d) SIGALRM

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGALRM caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler(int sig){
	if(sig == SIGALRM){
		printf("SIGALRM caught\n");
	}
	else
		printf("unknown signal\n");
}

int main(){
	signal(SIGALRM, sig_handler);
	alarm(2);
	pause();
}


