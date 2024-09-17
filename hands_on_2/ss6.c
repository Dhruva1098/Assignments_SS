/*
 ===========================================================================================
Name : ss6.c
Author : Dhruva Sharma
Description : Write a simple program to create three threads.
output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
thread created
thread created
thread created
=============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void fn_thread(void){
	printf("thread created\n");
}

int main(){
	pthread_t th1, th2, th3;
	pthread_create(&th1, NULL, (void*)fn_thread, NULL);
	pthread_create(&th2, NULL, (void*)fn_thread, NULL);
	pthread_create(&th3, NULL, (void*)fn_thread, NULL);
}
