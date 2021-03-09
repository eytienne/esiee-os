#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 2;

void fonc_display() {
	printf("pid: %d, ppid: %d, var: %d\n", getpid(), getppid(), var);
}

int main() {
	int pid = fork();
	fonc_display();
	if (pid == 0) { // child
		var--;
		fonc_display();
		exit(EXIT_FAILURE);
	} else { // parent
		var++;
		fonc_display();
		sleep(1);
		exit(EXIT_SUCCESS);
	}
	return 0;
}