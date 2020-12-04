/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdbool.h>
bool driving = false;
int distance = 0;
int initialDist = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(RPi_PIN == 1)
        {
            //Find p-plads
            distance = 0;
            initialDist = getDistance(id);
            driveForwards(speed);
            driving = true;
            
            
            while(driving == true)
            {
                if(getDistance(id) > initialDist+4)
                {
                    distance++;
                    CyDelayUs(10);
                }
                else
                {
                    if(distance == enough???)
                    {
                        driving = false;
                        break;
                    }
                    else
                    {
                        distance = 0;
                    }
                }
            }
            
            turnWheelsRight();
            driveBackwards(speed);
            CyDelay(1000);
            turnWheelsLeft();
            CyDelay(1000);
            stopDriving(); //parking foretaget
            
        }
    }
}

int getDistance(id)
{
    int counter = 0;
    float cm;
    
    Pin_SensorRight_Trig_Write(0);
    CyDelayUs(2);
    
    Pin_SensorRight_Trig_Write(1);
    CyDelayUs(10);
    Pin_SensorRight_Trig_Write(0);
    
    while(Pin_SensorRight_Echo_Read() != 1) {}
    
    while(Pin_SensorRight_Echo_Read() != 0)
    {
        counter++;
        CyDelayUs(10);
        if(Pin_SensorRight_Echo_Read() == 0)
        {
            return counter;
            break;
        }
    }
}


/* [] END OF FILE */
