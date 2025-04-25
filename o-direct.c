#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h> //BLKSSZGET

int main() {

    /* */
    struct statvfs buf;
    int x = statvfs(".", &buf);

    int blocksize;
    int fd = open("/dev/vda2", O_RDONLY);
    printf("%d\n", fd);
    ioctl(fd, BLKSSZGET, &blocksize);
    printf("%d\n", blocksize);

    if (x == -1) {
        return 1;
    }

    unsigned int filesystem_block_size = buf.f_bsize - 1;
    unsigned int mask = 1U << (sizeof(unsigned int) * 8 -1);
    unsigned int alignment_mask = filesystem_block_size;
    unsigned int inverse_alignment_mask = ~(filesystem_block_size);

    printf("filesystem block size: %lu\n", buf.f_bsize);
	for (int i = 0; i < sizeof(alignment_mask)*8; i++) {
		printf("%u", inverse_alignment_mask & mask ? 1 : 0);
		mask = mask >> 1;
	}
}
