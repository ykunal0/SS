#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int count = 0;

    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            char name[30];

            sprintf(name, "file%d.txt", count++);

            int fd = creat(name, 0644);

            if (fd == -1)
            {
                perror("creat");
                return 1;
            }
        }

        sleep(2);
    }

    return 0;
}