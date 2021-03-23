#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define SHM_KEY ((key_t)1000)
#define SHM_SIZE 15

int main(int argc, char const *argv[]) {
	int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | SHM_R | SHM_W);
	if (shm_id == -1) {
		fprintf(stderr, "shmget error: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	printf("shm_id: %d\n", shm_id);
	return 0;
}
