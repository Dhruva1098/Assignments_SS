/*
 ===========================================================================================
Name : ss2.c
Author : Dhruva Sharma
Description : Write a program to print the system resource limits. Use getrlimit system call
Output :
Limits for FD: soft limit = 1024 	hard limits = 524288
=============================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
int main(){
	struct rlimit lim;
	int t = getrlimit(RLIMIT_NOFILE, &lim);
	if (t == 0) {
		printf("Limits for FD: soft limit = %ld \thard limits = %ld\n", lim.rlim_cur, lim.rlim_max);
	}
	else{
		perror("getrlimit");
	}
}

		
