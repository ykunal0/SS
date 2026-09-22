#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p1, p2, p3;

    p1 = fork();

    if (p1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        return 0;
    }

    p2 = fork();

    if (p2 == 0)
    {
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);
        return 0;
    }

    p3 = fork();

    if (p3 == 0)
    {
        printf("Child 3: PID = %d\n", getpid());
        sleep(6);
        return 0;
    }

    printf("Parent waiting for Child 2: %d\n", p2);

    waitpid(p2, NULL, 0);

    printf("Child 2 finished. Parent exiting.\n");

    return 0;
}