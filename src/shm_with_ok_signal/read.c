#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>

#define BUFFER_SIZE 100

static char *shm_seg;

void read_handler(int sig) {
	int a, b, c;
	sscanf(shm_seg, "%d %d %d", &a, &b, &c);
	printf("Retrieved: %d %d %d\n", a, b, c);
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		perror("Give shm id as argument\n");
		exit(EXIT_FAILURE);
	}
    int shmid = atoi(argv[1]);

	shm_seg = (char *)shmat(shmid, NULL, 0);
	if (shm_seg == NULL) {
		perror("Shared memory not found\n");
		exit(EXIT_FAILURE);
	}

	printf("Reader pid: %d\n", getpid());
	signal(SIGUSR1, read_handler);
	while (1)
		;
}