/* 
 * 5. Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	const char *files[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
	for(int i=0;i<5;i++) {
		int fd = creat(files[i], 0744);
		if (fd < 0) {
			perror("creat");
		}
	}
	for(;;);
}
