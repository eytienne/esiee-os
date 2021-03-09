#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int hours = 0;
int minutes = 0;
int seconds = 0;

void hours_handler(int signum) {
	hours++;
	if (hours == 24) {
		hours = 0;
	}
}

void minutes_handler(int signum) {
	minutes++;
	if (minutes == 60) {
		minutes = 0;
		raise(SIGUSR2);
	}
}

void seconds_handler(int signum) {
	seconds++;
	if (seconds == 60) {
		seconds = 0;
		raise(SIGUSR1);
	}
}

int main(int argc, const char *argv[]) {
	if (argc != 7) {
		perror("Shoudl give args as such: <hours> <minutes> <seconds> <chours> "
			   "<cminutes> <cseconds>");
		exit(EXIT_FAILURE);
	}
	hours = atoi(argv[1]);
	minutes = atoi(argv[2]);
	seconds = atoi(argv[3]);

	int chours = atoi(argv[4]);
	int cminutes = atoi(argv[5]);
	int cseconds = atoi(argv[6]);

	signal(SIGALRM, seconds_handler);
	signal(SIGUSR1, minutes_handler);
	signal(SIGUSR2, hours_handler);

	while (1) {
		raise(SIGALRM);
		printf("%02d:%02d:%02d", hours, minutes, seconds);
		if (hours == chours && minutes == cminutes && seconds == cseconds) {
			printf(" DRING DRING!");
		}
		printf("\r");
		fflush(stdout);
		sleep(1);
	}
	return 0;
}