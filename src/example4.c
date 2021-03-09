#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
	int pid = fork();
	if (pid == 0) { // child
		int spid = fork();
		if (spid == 0) { // grandchild
			execl("/bin/ls", "ls", "-l", NULL);
		}
		wait(NULL);
		exit(18);
	}
	int status = 0;
	wait(&status);
	printf("status: %d\n", WEXITSTATUS(status));
	return 0;
}