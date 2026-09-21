#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat st;

    if (stat("source.txt", &st) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", st.st_ino);
    printf("Hard links: %ld\n", st.st_nlink);
    printf("UID: %d\n", st.st_uid);
    printf("GID: %d\n", st.st_gid);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Block size: %ld bytes\n", st.st_blksize);
    printf("Number of blocks: %ld\n", st.st_blocks);
    printf("Last access: %ld\n", st.st_atime);
    printf("Last modification: %ld\n", st.st_mtime);
    printf("Last change: %ld\n", st.st_ctime);

    return 0;
}