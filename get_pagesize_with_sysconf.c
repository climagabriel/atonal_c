#include <stdio.h>
#include <unistd.h>

int main() {
	long pagesize = sysconf(_SC_PAGESIZE);
 	printf("%lu\n", pagesize);
}

