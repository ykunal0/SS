#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int src = open("source.txt", O_RDONLY);
    int dest = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (src == -1 || dest == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[100];
    int n;

    while ((n = read(src, buffer, sizeof(buffer))) > 0)
    {
        write(dest, buffer, n);
    }

    close(src);
    close(dest);

    return 0;
}