#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("q16.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        return 1;
    }

    printf("Write lock acquired.\n");

    write(fd, "Process has the write lock\n", 27);

    printf("Data written. Holding lock for 20 seconds...\n");
    sleep(20);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Write lock released.\n");

    close(fd);

    return 0;
}