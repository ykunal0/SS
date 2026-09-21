#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("q4.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    int fd= open("q4.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

   // write(fd,"hello using fd\n", 15);

   // close(fd);

    char buffer[100];

    int n = read(fd, buffer, 99);

    if (n == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(fd);

    return 0;
}