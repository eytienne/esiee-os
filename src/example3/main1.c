#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t forkId = fork();
	if (forkId == 0) {
		printf("(Caller) pid: %d ppid: %d\n", getpid(), getppid());
		execl("./exe2", "exe2", NULL);
	}
}