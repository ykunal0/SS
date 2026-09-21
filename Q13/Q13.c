#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set set;
    struct timeval timeout;

    FD_ZERO(&set);
    FD_SET(0, &set);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    int result = select(1, &set, NULL, NULL, &timeout);

    if (result == -1)
    {
        perror("select");
        return 1;
    }

    if (result == 0)
    {
        printf("No input available within 10 seconds.\n");
    }
    else if (FD_ISSET(0, &set))
    {
        printf("Input is available on STDIN.\n");
    }

    return 0;
}