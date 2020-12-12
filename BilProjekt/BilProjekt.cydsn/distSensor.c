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
#include "distSensor.h"

int getDistance(int id)
{
    switch(id)
    {
        case 1:
        {
            int counter = 0;
    
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
                    return (counter-2.8214)/4.6726;
                    break;
                }
            }
        }
        break;
        case 2:
        {
            int counter = 1;
    
            Pin_SensorFront_Trig_Write(0);
            CyDelayUs(2);
            Pin_SensorFront_Trig_Write(1);
            CyDelayUs(10);
            Pin_SensorFront_Trig_Write(0);
            
            while(Pin_SensorFront_Echo_Read() != 1) {}
            
            while(Pin_SensorFront_Echo_Read() != 0)
            {
                counter++;
                CyDelayUs(10);
                if(Pin_SensorFront_Echo_Read() == 0)
                {
                    return counter;
                    break;
                }
            }
        }
        break;
    }
    
    
    return 0;
}

/* [] END OF FILE */
