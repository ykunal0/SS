#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child exiting...\n");
        return 0;
    }
    else
    {
        printf("Parent sleeping...\n");
        sleep(30);
    }

    return 0;
}