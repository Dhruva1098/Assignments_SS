/*
 ===========================================================================================
Name : ss7.c
Author : Dhruva Sharma
Description : Write a simple program to print the created thread ids.
output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
Thread -1161760352 is running 
Thread -1182731872 is running 
Thread -1172246112 is running 

=============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void fn_thread(void){
	int thread = pthread_self();
	printf("Thread %d is running \n", thread);
}

int main(){
	pthread_t th1, th2, th3;
	pthread_create(&th1, NULL, (void*)fn_thread, NULL);
	pthread_create(&th2, NULL, (void*)fn_thread, NULL);
	pthread_create(&th3, NULL, (void*)fn_thread, NULL);
}
