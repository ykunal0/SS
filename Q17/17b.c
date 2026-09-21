#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("ticket.txt", O_RDWR);

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

    int ticket;

    read(fd, &ticket, sizeof(ticket));

    ticket++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));

    printf("Reserved ticket number: %d\n", ticket);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}