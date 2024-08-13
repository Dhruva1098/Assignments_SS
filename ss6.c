/*
 * 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
 * */
#include <unistd.h>
#include <stdio.h>

int main(void) {
	char buff[100];
	printf("Please provide input for STDIN:\n");
	int in = read(0, buff, sizeof(buff));
	printf("Output for STDOUT is:\n");
	write(1, buff, in);
}
