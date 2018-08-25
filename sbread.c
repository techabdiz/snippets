#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void executeLogic(){

    int fd = open("/dev/sdb", O_RDONLY); // Pass device file as argument, REQUIRES ROOT TO EXECUTE
    printf("seeked at: %d\n", lseek(fd, 1024, 0)); //seek to offset 1024 from start of device
    void *buffer = malloc(1024);
    printf("read %d byte(s) from buffer\n\n", read(fd, buffer, 1024));

    printf("inodes count: %d\n", *((int*)buffer+0));
    printf("block count: %d\n", *((int*)buffer+4));
    printf("super user reserved block count: %d\n", *((int*)buffer+8));
    printf("free block count: %d\n", *((int*)buffer+12));
    printf("free inode count: %d\n", *((int*)buffer+16));
    printf("Free block head: %d\n", *((int*)buffer+20));
    printf("Log back size: %d\n", *((int*)buffer+24));
    printf("Log frag size: %d\n", *((int*)buffer+28));
    printf("Blocks per group: %d\n", *((int*)buffer+32));
    printf("Frags per group: %d\n", *((int*)buffer+36));
    printf("Inodes per group: %d\n", *((int*)buffer+40));
    printf("Mount time: %d\n", *((int*)buffer+44));
    printf("Write time: %d\n\n", *((int*)buffer+48));



    printf("mount count: %d\n", *((short*)buffer+52));
    printf("Max mount count: %d\n", *((short*)buffer+54));
    printf("Magic number: %d\n", *((short*)buffer+56));
    printf("FS state: %d\n", *((short*)buffer+58));
    printf("Errors: %d\n", *((short*)buffer+60));
    printf("Minor revision level: %d\n\n", *((short*)buffer+62));

    printf("Last check: %d\n", *((int*)buffer+64));
    printf("Creator OS: %d\n", *((int*)buffer+72));
    printf("Revision level: %d\n", *((int*)buffer+76));

    free(buffer);
	close(fd);

	// perror("");
}

int main()
{
    executeLogic();
    return 0;
}


