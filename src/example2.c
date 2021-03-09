#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pid = fork();
	if (pid == 0) { // child
		execl("/bin/ps", "ps", "-l", NULL);
		printf("AH");
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	return 0;
}