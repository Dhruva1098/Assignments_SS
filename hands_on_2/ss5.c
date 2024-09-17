/*
 ===========================================================================================
Name : ss5.c
Author : Dhruva Sharma
Description : Write a program to print the system limitations of
a. maximum length of the arguments to the exec family of functions
b. maximum number of simultaneous process per user id;
c. numbers of clock ticks(jiffy) per second
d. maximum no. of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory
output:
[parallels@fedora-linux-38 handsOn2]$ ./a.out
maximum length of the arguments to the exec family of functions is: 2097152
maximum number of simultaneous processes per user id: 7362
number of clock ticks(jiffy) per second: 100
maximum number of open files: 1024
Size of a page is: 4096
Total number of pages in the physical memory is: 498589
number of currently available pages in the physical memory is: 14861
=============================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(){

	printf("maximum length of the arguments to the exec family of functions is: %lu\n", sysconf(_SC_ARG_MAX));
	printf("maximum number of simultaneous processes per user id: %lu\n", sysconf(_SC_CHILD_MAX));
	printf("number of clock ticks(jiffy) per second: %lu\n", sysconf(_SC_CLK_TCK));
	printf("maximum number of open files: %lu\n", sysconf(_SC_OPEN_MAX));
	printf("Size of a page is: %lu\n", sysconf(_SC_PAGE_SIZE));
	printf("Total number of pages in the physical memory is: %lu\n", sysconf(_SC_PHYS_PAGES));
	printf("number of currently available pages in the physical memory is: %lu\n", sysconf(_SC_AVPHYS_PAGES));
}
