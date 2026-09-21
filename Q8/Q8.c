#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("source.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[100];
    char line[100];
    int n, pos = 0;

    
  //  int wfd=open("dest.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    //n = read(fd, buffer, sizeof(buffer));
    //write(wfd, buffer, n);

    while ((n = read(fd, buffer, sizeof(buffer))) > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (buffer[i] == '\n')
            {
                line[pos] = '\0';
                printf("%s\n", line);
                pos = 0;
            }
            else
            {
                line[pos++] = buffer[i];
            }
        }
    }

    if (pos > 0)
    {
        line[pos] = '\0';
        printf("%s\n", line);
    }

    close(fd);

    return 0;
}