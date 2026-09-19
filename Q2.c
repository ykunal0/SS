#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main()
{
    while (1)
    {
        printf("My PID: %d\n", getpid());

        DIR *dir = opendir("/proc");

        if (dir == NULL)
        {
            perror("opendir");
            return 1;
        }

        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL)
        {
            int is_pid = 1;

            for (int i = 0; entry->d_name[i] != '\0'; i++)
            {
                if (entry->d_name[i] < '0' || entry->d_name[i] > '9')
                {
                    is_pid = 0;
                    break;
                }
            }

            if (is_pid)
            {
                char path[256];

                snprintf(path, sizeof(path),
                         "/proc/%s/status", entry->d_name);

                FILE *file = fopen(path, "r");

                if (file == NULL)
                {
                    continue;
                }

                char line[256];

                printf("\nPID: %s\n", entry->d_name);

                while (fgets(line, sizeof(line), file) != NULL)
                {
                    if (strncmp(line, "Name:", 5) == 0 ||
                        strncmp(line, "State:", 6) == 0 ||
                        strncmp(line, "PPid:", 5) == 0)
                    {
                        printf("%s", line);
                    }
                }

                fclose(file);
            }
        }

        closedir(dir);

        printf("\n-------------------------\n");

        sleep(5);
    }

    return 0;
}