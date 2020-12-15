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
        
        fd = open("/sys/class/gpio/gpio13/direction", O_WRONLY);
        if (fd == -1)
        {
            close(fd);
            fd = open("/sys/class/gpio/export", O_WRONLY);
            cout << "Initializing GPIO port 13..." << endl;
            sleep(1);
            write(fd, "13",3);
            close(fd);
        }
    
        fd = open("/sys/class/gpio/gpio13/direction", O_WRONLY);
        cout << "Setting direction of GPIO port 13 to 'out'..." << endl;
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
                    cout << "Press '0' to cancel parking" << endl;
                    int fd;
                    fd = open("/sys/class/gpio/gpio19/value", O_WRONLY);
                    write(fd,"1",2);
                    sleep(1);
                    write(fd,"0",2);
                    close(fd);
                    sleep(1);
                    
                    fd = open("/sys/class/gpio/gpio13/value", O_RDONLY);
                }
                break;
                case 48:
                {
                    std::system("clear");
                    cout << "Parking cancelled!" << endl;
                    int fd;
                    fd = open("/sys/class/gpio/gpio13/value", O_WRONLY);
                    write(fd,"1",2);
                    sleep(1);
                    write(fd,"0",2);
                    close(fd);
                    for(int i = 5; i > 0; i--)
                    {
                        std::system("clear");
                        cout << "Returning to main screen in " << i << "..." << endl;
                        sleep(1);
                    }
                    std::system("clear");
                    cout << "Park-A-Lot system started" << endl;
                    cout << "Press '1' to start parking" << endl;
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
