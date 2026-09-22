#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("PID: %d\n", getpid());
    printf("Initial nice value: %d\n", nice(0));

    nice(5);

    printf("New nice value: %d\n", nice(0));

    while (1)
    {
    }

    return 0;
}