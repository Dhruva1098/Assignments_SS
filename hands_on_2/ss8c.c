/*
 ===========================================================================================
Name : ss8c.c
Author : Dhruva Sharma
Description : Write a program using signal system call to catch the following signals
c) SIGFPE

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGFPE caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler(int sig){
	if(sig == SIGFPE){
		printf("SIGFPE caught\n");
	}
	else
		printf("unknown signal\n");
}

int main(){
	signal(SIGFPE, sig_handler);
	int a = 1 / 0;
}


