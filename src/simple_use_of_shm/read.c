#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		perror("Give shm id as argument\n");
		exit(EXIT_FAILURE);
	}

    char *shm_seg = (char *)shmat(atoi(argv[1]), NULL, 0);
	if (shm_seg == NULL) {
		perror("Shared memory not found\n");
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	strncpy(buffer, shm_seg, BUFFER_SIZE);
    printf("Read: '%s'\n", buffer);
}