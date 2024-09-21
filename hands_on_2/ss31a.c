/*
===========================================================================================
Name : ss31.c
Author : Dhruva Sharma
Description : Write a program to create a semaphore and initialize a value to the semaphore
a. Create a binary semaphore
Output: 
[parallels@fedora-linux-38 handsOn2]$ ./a.out
waiting for semaphore
semaphore acquired
In critical section
waiting for semaphore

releasing semaphore
semaphore acquired
In critical section

releasing semaphore

============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t binary;
void* fn(){
	printf("waiting for semaphore\n");
	sem_wait(&binary);
	printf("semaphore acquired\nIn critical section\n");
	getchar();
	printf("releasing semaphore\n");
	sem_post(&binary);
}

int main(){
	sem_init(&binary, 0, 1);
	pthread_t t1,t2;
	pthread_create(&t1, NULL, fn, NULL);
	pthread_create(&t2, NULL, fn, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2, NULL);
	sem_destroy(&binary);
}




