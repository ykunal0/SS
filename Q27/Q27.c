#include <stdio.h>
#include <sched.h>

int main()
{
    printf("SCHED_FIFO min: %d\n",
           sched_get_priority_min(SCHED_FIFO));

    printf("SCHED_FIFO max: %d\n",
           sched_get_priority_max(SCHED_FIFO));

    printf("SCHED_RR min: %d\n",
           sched_get_priority_min(SCHED_RR));

    printf("SCHED_RR max: %d\n",
           sched_get_priority_max(SCHED_RR));

    return 0;
}