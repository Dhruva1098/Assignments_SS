/* 
 * write a program to print information about a given file
 */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
void print_time_info(const struct timespec *ts, const char* label) {
	char timebuf[100];
	struct tm *tm;
	tm = localtime(&ts->tv_sec);
	strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm);
	printf("%s: %s.%02ld\n", label, timebuf, ts->tv_nsec);
}

int main(void) {
	struct stat out;
	int fd = open("example.txt", O_RDWR, 0644);
	if (fd < 0){
		perror("open");
	}
	fstat(fd, &out);
	printf(" inode : %lu\n", out.st_ino);
	printf(" Number of hard links : %u\n", out.st_nlink);
	printf(" uid : %u\n", out.st_uid);
	printf(" gid : %u\n", out.st_gid);
	printf(" size : %lu\n", out.st_size);
	printf(" blocksize : %u\n", out.st_blksize);
	printf(" Number of blocks : %lu\n", out.st_blocks);
	print_time_info(&out.st_ctim, "Time of last status change:");
	print_time_info(&out.st_atim, "Time of last access:");
	print_time_info(&out.st_mtim, "time of last modufication:");
}
