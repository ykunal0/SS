#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("./25a", "25a", "Kunal", NULL);

    perror("execl");
    return 1;
}