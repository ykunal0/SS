#include <stdio.h>
#include <unistd.h>

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
        sleep(5);
        printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent exiting. PID = %d\n", getpid());
    }

    return 0;
}