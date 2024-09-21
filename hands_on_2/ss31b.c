/*
===========================================================================================
Name : ss31.c
Author : Dhruva Sharma
Description : Write a program to create a semaphore and initialize a value to the semaphore
b. create a counting semaphore
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
waiting for semaphore
semaphore acquired
In critical sectionwaiting for semaphore
semaphore acquired
In critical sectionwaiting for semaphore

releasing semaphore
semaphore acquired

In critical sectionreleasing semaphore

releasing semaphore

============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t counting;
void* fn(){
	printf("waiting for semaphore\n");
	sem_wait(&counting);
	printf("semaphore acquired\nIn critical section");
	getchar();
	printf("releasing semaphore\n");
	sem_post(&counting);
}

int main(){
	sem_init(&counting, 0, 2);
	pthread_t t1,t2,t3;
	pthread_create(&t1, NULL, fn, NULL);
	pthread_create(&t2, NULL, fn, NULL);
	pthread_create(&t3, NULL, fn, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3, NULL);
	sem_destroy(&counting);
}




