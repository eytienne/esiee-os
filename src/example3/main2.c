#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	printf("(Called) pid: %d ppid: %d\n", getpid(), getppid());
}
