#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("records.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int record;

    printf("Enter record number (1-3): ");
    scanf("%d", &record);

    if (record < 1 || record > 3)
    {
        printf("Invalid record number\n");
        close(fd);
        return 1;
    }

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record - 1) * sizeof(int);
    lock.l_len = sizeof(int);

    printf("Trying to lock record %d...\n", record);

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired on record %d.\n", record);

    lseek(fd, (record - 1) * sizeof(int), SEEK_SET);

    int value;
    read(fd, &value, sizeof(value));

    printf("Record value: %d\n", value);

    printf("Holding read lock for 5 seconds...\n");
    sleep(5);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Read lock released.\n");

    close(fd);

    return 0;
}