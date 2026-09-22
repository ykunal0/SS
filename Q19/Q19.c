#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("PID: %d\n", getpid());

    if (argc != 2)
        return 1;

    if (argv[1][0] == 'r')
    {
        while (1);
    }
    else if (argv[1][0] == 's')
    {
        while (1)
            sleep(5);
    }

    return 0;
}