/*
 ===========================================================================================
Name : ss8b.c
Author : Dhruva Sharma
Description : Write a program using signal system call to catch the following signals
b) SIGINT

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGINT caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler(int sig){
	if(sig == SIGINT){
		printf("SIGSEGV caught\n");
	}
	else
		printf("unknown signal\n");
}

int main(){
	signal(SIGINT, sig_handler);
}


