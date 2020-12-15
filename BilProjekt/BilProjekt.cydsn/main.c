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
#include "distSensor.h"
#include "DCControl.h"
#include "servoControl.h"
#include "interruptRoutine.h"

bool driving = false;
bool enoughSpace = false;
int distance = 0;
int initialDist = 0;

CY_ISR_PROTO(GPIO_ISR);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    isr_RPi_StartEx(GPIO_ISR);
    CyGlobalIntEnable;
    UART_1_Start();
    PWM_DC_Start();
    PWM_Servo_Start();
    //Pin_RPi_Tester = Pin_RPi_Read();
    UART_1_PutString("Park-a-lot system started.\r\n");

    for(;;)
    {
        int Pin_RPi_Tester = Pin_RPi_Read();
        
        if(Pin_RPi_Tester != 0)
        {
            //Find p-plads
            distance = 0;
            initialDist = getDistance(1);
            middlePos();
            CyDelay(500);
            driveForwards();
            UART_1_PutString("Driving forwards. Looking for space\r\n");
            driving = true;
            
            
            while(driving == true)
            {
                
                
                if(getDistance(1) > (initialDist+4))
                {
                    distance++;
                    CyDelayUs(10);
                }
                else
                {
                    if(distance > 10)
                    {
                        driving = false;
                        stopDriving();
                        UART_1_PutString("Parking space found\r\n");
                        enoughSpace = true;
                        break;
                    }
                    else
                    {
                        distance = 0;
                        UART_1_PutString("Not enough space\r\n");
                    }
                }
//                if(getDistance(2) < 50)
//                {
//                    stopDriving();
//                    UART_1_PutString("Obstacle in front. Ejecting driver.\r\n");
//                    break;
//                }
//                
//                CyDelay(30);
                
            }
            
            while(enoughSpace == true)
            {
                CyDelay(1000);
                UART_1_PutString("Initiating parkingsequence\r\n");
                turnWheelsRight();
                UART_1_PutString("Turning wheels right\r\n");
                CyDelay(500);
                driveBackwards();
                UART_1_PutString("Driving backwards\r\n");
                CyDelay(1000);
                stopDriving();
                turnWheelsLeft();
                UART_1_PutString("Turning wheels left\r\n");
                CyDelay(500);
                driveBackwards();
                UART_1_PutString("Driving backwards again\r\n");
                CyDelay(1000);
                stopDriving(); //parking foretaget
                CyDelay(1000);
                middlePos();
                UART_1_PutString("Parking done\r\n");
                
                enoughSpace = false;
            }
        }
    }
}


/* [] END OF FILE */
