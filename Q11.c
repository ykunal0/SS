#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1 = open("q11.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd1 == -1)
    {
        perror("open");
        return 1;
    }

    //int fd2 = dup(fd1);
    //int fd2 = dup2(fd1,10);
    int fd2 = fcntl(fd1, F_DUPFD, 10);

    if (fd2 == -1)
    {
        perror("dup2");
        return 1;
    }

    printf("fd1 = %d\n", fd1);
    printf("fd2 = %d\n", fd2);

    write(fd1, "Hello\n", 6);
    write(fd2, "World\n", 6);

    close(fd1);
    close(fd2);

    return 0;
}