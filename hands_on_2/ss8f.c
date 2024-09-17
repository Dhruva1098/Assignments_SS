/*
 ===========================================================================================
Name : ss8f.c
Author : Dhruva Sharma
Description : Write a program using signal system call to catch the following signals
f) SIGVTALRM

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGVTALRM caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler(int sig){
	if(sig == SIGVTALRM){
		printf("SIGVTALRM caught\n");
	}
	else
		printf("unknown signal\n");
}

int main(){
	signal(SIGVTALRM, sig_handler);
	struct itimerval timer;
	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec  = 0;
	timer.it_interval.tv_usec = 0;
	setitimer(ITIMER_VIRTUAL, &timer, NULL);
	pause();
}


