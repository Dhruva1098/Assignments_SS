/*
 ===========================================================================================
Name : ss4.c
Author : Dhruva Sharma
Description : Write a program to measure how much time is taken to execute 100 getppid() system
calls. use time stamp counter.
Output : CPU cycles elapsed: 57354
=============================================================================================
*/

#include <unistd.h>
#include <stdio.h>

unsigned long long rdtsc(void) {
	unsigned int a,b;
	__asm__ __volatile__ ("rdtsc":"=a" (a), "=d" (b));
	return ((unsigned long long)b << 32) | a;
}
int main(){
	unsigned long long start, end;
	start = rdtsc();
	volatile int a;
	for(int i = 0; i < 100; i++){
		a = getpid();
	}
	end = rdtsc();
	printf("CPU cycles elapsed: %llu\n", end - start);
}
