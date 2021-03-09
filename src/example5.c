#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
	int pid1 = fork();
	if (pid1 == 0) {
		while (1)
			;
	}
	sleep(1);
	int pid2 = fork();
	if (pid2 == 0) {
		execl("/bin/ps", "ps", "-o", "pid,tty,time,cmd,stat", NULL);
	}
	sleep(1);
	kill(pid1, SIGKILL);
	int pid3 = fork();
	if (pid3 == 0) {
		execl("/bin/ps", "ps", "-o", "pid,tty,time,cmd,stat", NULL);
	}
	sleep(2);
	return 0;
}