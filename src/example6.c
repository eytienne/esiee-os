#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
	int pid = fork();
	if (pid == 0) { // child
		while (1)
			;
	}
	kill(pid, SIGKILL);
	int status = 0;
	pid_t waited = wait(&status);
	printf("pid: %d, waited: %d, status: %x\n", pid, waited, status);
	return 0;
}