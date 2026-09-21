#include<unistd.h>
#include<stdio.h>

int main()
{
    char buffer[100];
    int n=read(0,buffer,sizeof(buffer));
    if(n==-1)
    {
        perror("read");
        return 1;
    }
    write(1,buffer,n);

  //  printf("\n\n%s\n",buffer);
    return 0;
}