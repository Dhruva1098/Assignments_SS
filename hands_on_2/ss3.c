/*
 ===========================================================================================
Name : ss3.c
Author : Dhruva Sharma
Description : Write a program to set the system resource limit. Use setrlimit system call
Output :
 Old limits for FD: soft limit = 1024 	hard limits = 524288
 New limits for FD: soft limit = 5 	hard limits = 1024
=============================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
int main(){
	struct rlimit lim, new_lim;
	int t = getrlimit(RLIMIT_NOFILE, &lim);
	if (t == 0) {
		printf(" Old limits for FD: soft limit = %ld \thard limits = %ld\n", lim.rlim_cur, lim.rlim_max);
	}
	else{
		perror("getrlimit");
	}
	lim.rlim_cur = 5;
	lim.rlim_max = 1024;
	int q = setrlimit(RLIMIT_NOFILE, &lim);
	if (q < 0) perror("setrlimit");
	if (getrlimit(RLIMIT_NOFILE, &new_lim) == 0) {
		printf(" New limits for FD: soft limit = %ld \thard limits = %ld\n", new_lim.rlim_cur, new_lim.rlim_max);
	} else {
		perror("getrlimit");
	}
}
