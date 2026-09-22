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

    if (pid == 0)//return value of fork() is 0 for the child process
    {
        printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent: PID = %d, Child PID = %d\n", getpid(), pid);
        //if pid>0 then it is the parent process and the return value of fork() is the PID of the child process.
    }

    return 0;
}