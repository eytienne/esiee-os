#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		perror("Use with arguments: <shmid> <pid>\n");
		exit(EXIT_FAILURE);
	}
	int shmid = atoi(argv[1]);
	int pid = atoi(argv[2]);

	char *shm_seg = (char *)shmat(shmid, NULL, 0);
	if (shm_seg == NULL) {
		perror("Shared memory not found\n");
		exit(EXIT_FAILURE);
	}

	strcpy(shm_seg, "1 3 5");
	kill(pid, SIGUSR1);
}
