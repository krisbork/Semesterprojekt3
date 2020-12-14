#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    fd = open("/sys/class/gpio/gpio19/value", O_WRONLY);
    write(fd,"1",2);
    sleep(1);
    write(fd,"0",2);
    close(fd);
    sleep(1);
    
    return 0;
}
