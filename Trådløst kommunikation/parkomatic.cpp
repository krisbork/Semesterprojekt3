#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <linux/gpio.h>
#include "conio.h"

using namespace std;

int main()
{
    char mode = 0;
    char val[2];

    while (1)
    {
        // Initialization
        std::system("clear");
        
        cout << "Starting Park-A-Lot system..." << endl;
        sleep(1);
        
        int fd;
        fd = open("/sys/class/gpio/gpio19/direction", O_WRONLY);
        if (fd == -1)
        {
            close(fd);
            fd = open("/sys/class/gpio/export", O_WRONLY);
            cout << "Initializing GPIO port 19..." << endl;
            sleep(1);
            write(fd, "19",3);
            close(fd);
        }
    
        fd = open("/sys/class/gpio/gpio19/direction", O_WRONLY);
        cout << "Setting direction of GPIO port 19 to 'out'..." << endl;
        sleep(1);
        write(fd,"out",4);
        close(fd);

        // Welcome message
        std::system("clear");
        cout << "Park-A-Lot system started" << endl;
        cout << "Press '1' to start parking" << endl;
   
        do
        {
            mode = getch();

            switch (mode)
            {
                case 49:  // Ascii value for 1
                {
                    std::system("clear");
                    cout << "Parking started..." << endl;
                    int fd;
                    fd = open("/sys/class/gpio/gpio19/value", O_WRONLY);
                    write(fd,"1",2);
                    sleep(1);
                    write(fd,"0",2);
                    close(fd);
                    sleep(1);
                    
                    fd = open("/sys/class/gpio/gpio13/value", O_RDONLY);
                    
                    while((getch() != 48) || (val[0] != 0))
                    {
                        std::system("clear");
                        cout << "Parking started..." << endl;
                        read(fd, val, 1);
                        sleep(1);
                    }
                    cout << "Parking finished!" << endl;
                }
                break;
                default:
                {
                    cout << endl << "Button not recognized. Try again." << endl;
                }
                break;
            }
        } while (1);
    }
}
