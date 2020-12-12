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
#include "stdio.h"

CY_ISR_PROTO(ISR_UART_rx_handler);

int getDistance();


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    UART_1_PutString("Ultrasonic sensor\r\n");
    
    char buffer[255];
    float cm;

    
    for(;;)
    {
        cm = (getDistance()-2.8214)/4.6726;
        float count = getDistance();
        
        snprintf(buffer,255, "The distance for sensor: %.2f cm \n\r", count);
        UART_1_PutString(buffer); 
        
        CyDelay(1000);
    }
}

int getDistance()
{
    int counter = 0;
    
    Pin_S1_Trig_Write(0);
    CyDelayUs(2);

    Pin_S1_Trig_Write(1);
    CyDelayUs(10);
    Pin_S1_Trig_Write(0);

    while(Pin_S1_Echo_Read() != 1) //wait until return pulse starts 
    {}
    
    while(Pin_S1_Echo_Read() != 0) //wait unit return pulse stops  
    {
        counter++;
        CyDelayUs(10);
        if (Pin_S1_Echo_Read() == 0)
        {
            return counter;
            break;
        }
    }
    return 0;
}

/* [] END OF FILE */

