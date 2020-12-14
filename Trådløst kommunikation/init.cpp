#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    fd = open("/sys/class/gpio/gpio19/direction", O_WRONLY);
    if (fd == -1)
    {
        close(fd);
        fd = open("/sys/class/gpio/export", O_WRONLY);
        write(fd, "19",3);
        close(fd);
    }
    
    fd = open("/sys/class/gpio/gpio19/direction", O_WRONLY);
    write(fd,"out",4);
    close(fd);
    
    return 0;
}
