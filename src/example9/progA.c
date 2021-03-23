#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
	assert(argc == 2);
	sleep(atoi(argv[1]));
}