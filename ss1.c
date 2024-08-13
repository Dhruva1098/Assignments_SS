/* 1. Create the following types of files using ii) System call
a) soft link
b) hard link
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(void) {
	int out = symlink("example.txt", "example_soft_link.txt");
	if (out < 0) {
		perror("symlink");
	}
	int out2 = link("example.txt", "example_hard_link.txt");
	if (out2 < 0) {
		perror("linkat");
	}
}
