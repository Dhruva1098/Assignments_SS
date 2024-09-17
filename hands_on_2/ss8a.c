/*
 ===========================================================================================
Name : ss8a.c
Author : Dhruva Sharma
Description : Write a program using signal system call to catch the following signals
a) SIGSEGV

output:  
[parallels@fedora-linux-38 handsOn2]$ ./a.out
SIGSEGV caught

=============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler(int sig){
	if(sig == SIGSEGV){
		printf("SIGSEGV caught\n");
		exit(0);
	}
	else
		printf("unknown signal\n");
}

int main(){
	signal(SIGSEGV, sig_handler);
	int *p = NULL;
	*p = 1; 
}








