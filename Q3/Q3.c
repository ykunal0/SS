#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = creat("q3.txt", 0644);

    if (fd == -1)
    {
        perror("creat");
        return 1;
    }

    printf("File descriptor: %d\n", fd);
    write(fd, "Hello, World!\n", 14);
    close(fd);
    return 0;
}