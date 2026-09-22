#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <1-5>\n", argv[0]);
        return 1;
    }

    if (argv[1][0] == '1')
    {
        execl("/bin/ls", "ls", "-Rl", NULL);
    }
    else if (argv[1][0] == '2')
    {
        execlp("ls", "ls", "-Rl", NULL);
    }
    else if (argv[1][0] == '3')
    {
        execle("/bin/ls", "ls", "-Rl", NULL, environ);
    }
    else if (argv[1][0] == '4')
    {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
    }
    else if (argv[1][0] == '5')
    {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
    }
    else
    {
        printf("Invalid option\n");
    }

    perror("exec");
    return 1;
}