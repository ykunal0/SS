#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
        return 0;

    setsid();

    while (1)
    {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == 19 && t->tm_min == 15)
        {
            FILE *fp = fopen("daemon_output.txt", "w");

            if (fp != NULL)
            {
                fprintf(fp, "Task executed at 19:15\n");
                fclose(fp);
            }

            break;
        }

        sleep(30);
    }

    return 0;
}