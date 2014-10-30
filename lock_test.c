#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int fcntl(int fd, int cmd, ... /* arg */ );

int main() {
	int ret = 0;
	int fd = open("/tmp/lock_test", O_RDWR | O_CREAT, S_IRWXU | S_IRGRP);
	char buf[4096];
	assert(write(fd, buf, 4096) == 4096);
	assert(write(fd, buf, 4096) == 4096);

	struct flock lck = {
		.l_type = F_WRLCK,
		.l_whence = SEEK_SET,
		.l_start = 0,
		.l_len = 4096,
	};
	if ((ret = fcntl(fd, F_SETLKW, &lck)) != 0)
		error(1, errno, "cannot lock file in parent process");
	printf("parent locked the file\n");
	int pid = fork();
	if (pid > 0) {
		printf("parent sleep for 2 second\n");
		sleep(2);
		lck.l_type = F_UNLCK;
		assert(fcntl(fd, F_SETLKW, &lck) == 0);
		printf("parent released the lock\n");
		int status = 0;
		waitpid(pid, &status, 0);
	} else if (pid < 0) {
		error(1, errno, "cannot fork child process");
	} else {
		int lck_ret = fcntl(fd, F_SETLKW, &lck);
		if (lck_ret < 0) {
			printf("child cannot lock the file: %s\n", strerror(errno));
			return 2;
		} else if (lck_ret == 0) {
			printf("child waked up and locked the file\n");
			printf("child sleep 2 seconds\n");
			sleep(2);
		}
	}
	return 0;
}
