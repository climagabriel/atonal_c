#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>


unsigned short cksum(unsigned char* buf, int size) {

	unsigned int sum, i;

	for (i = 0; i < size -1; i++) {
		unsigned short word16 = *(unsigned short *) &buf[i];
		sum += word16;
	}

	if (size & 1) { //neckbeard oddity check
		unsigned short word16 = *(unsigned short *) &buf[i];
		sum += word16;
	}

	while (sum >> 16) { // if the 16 highest bits are not 0
		sum = (sum & 0xFFFF) + (sum >> 16); // lowest + highest
	}

	return ~sum; //implicit cast to unsigned short by return type
}

