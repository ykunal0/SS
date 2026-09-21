#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("records.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int records[3] = {100, 200, 300};

    write(fd, records, sizeof(records));

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

    lock.l_type = F_WRLCK;
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

    printf("Write lock acquired on record %d.\n", record);

    lseek(fd, (record - 1) * sizeof(int), SEEK_SET);

    int value;
    read(fd, &value, sizeof(value));

    printf("Current value: %d\n", value);

    value++;

    lseek(fd, (record - 1) * sizeof(int), SEEK_SET);
    write(fd, &value, sizeof(value));

    printf("New value: %d\n", value);

    printf("Holding lock for 20 seconds...\n");
    sleep(20);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);

    return 0;
}