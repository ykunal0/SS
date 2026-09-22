#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current policy: %d\n", policy);

    if (sched_setscheduler(0, SCHED_FIFO, &(struct sched_param){.sched_priority = 10}) == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Policy changed to SCHED_FIFO\n");

    return 0;
}