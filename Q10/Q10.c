#include <stdio.h>
#include <fcntl.h>+-
#include <unistd.h>

int main()
{
    int fd = open("q10.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "ABCDEFGHIJ", 10);

    off_t pos = lseek(fd, 10, SEEK_CUR);

    if (pos == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("New file offset: %ld\n", pos);

    write(fd, "KLMNOPQRST", 10);

    close(fd);

    return 0;
}