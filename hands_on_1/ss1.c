/*
============================================================================
Name : ss1.c
Author : Dhruva Sharma
Description : 1. Create the following types of files using ii) System call
a) soft link
b) hard link
c) fifo
============================================================================
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(void) {
	int out = symlink("example.txt", "example_soft_link.txt");
	if (out < 0) {
		perror("symlink");
	}
	int out2 = link("example.txt", "example_hard_link.txt");
	if (out2 < 0) {
		perror("linkat");
	}
  int out3 = mkfifo("fifo", 0666);
  if(out3 < 0) {
    perror("mkfifo");
  }
}
