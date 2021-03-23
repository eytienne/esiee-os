#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

pid_t pid = -1;

void handler(int sig) {
	kill(pid, SIGKILL);
	int loc;
	waitpid(pid, &loc, 0);
	if (loc == SIGKILL) {
		printf("Assassinat du fils\n");
	} else {
		printf("Mort naturelle du fils\n");
	}
	exit(EXIT_SUCCESS);
}

int main(int argc, const char *argv[]) {
	assert(argc == 3);
	pid = fork();
	if (pid == 0) {
		execl(argv[1], argv[1], argv[2], NULL);
	}
	signal(SIGALRM, handler);
	alarm(2);
	while (1)
		;
}