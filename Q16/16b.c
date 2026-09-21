#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("q16.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire read lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        return 1;
    }

    printf("Read lock acquired.\n");

    char buffer[100];
    int n = read(fd, buffer, sizeof(buffer) - 1);

    if (n > 0)
    {
        buffer[n] = '\0';
        printf("Data: %s", buffer);
    }

    printf("\nHolding read lock for 20 seconds...\n");
    sleep(20);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released.\n");

    close(fd);

    return 0;
}