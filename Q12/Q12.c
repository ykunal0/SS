#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("q12.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        return 1;
    }

    int mode = flags & O_ACCMODE;

    if (mode == O_RDONLY)
        printf("Read only\n");
    else if (mode == O_WRONLY)
        printf("Write only\n");
    else if (mode == O_RDWR)
        printf("Read and write\n");

    close(fd);

    return 0;
}