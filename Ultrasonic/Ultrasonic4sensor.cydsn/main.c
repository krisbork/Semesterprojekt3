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


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    UART_1_PutString("Ultrasonic sensor\r\n");
    
    char buffer[255];
    uint16 counts1 = 0, counts2 = 0, counts3 = 0, counts4 = 0; 
    float cmForS1, cmForS2, cmForS3, cmForS4;

    
    for(;;)
    {
        /*----------------------------*/
        /***        Sensor 1        ***/
        
        Pin_S1_Trig_Write(0);
        CyDelayUs(2);
    
        Pin_S1_Trig_Write(1);
        CyDelayUs(10);
        Pin_S1_Trig_Write(0);

        while(Pin_S1_Echo_Read() != 1) //wait until return pulse starts 
        {}
        
        counts1 = 0;
        
        while(Pin_S1_Echo_Read() != 0) //wait unit return pulse stops  
        {
            counts1++;
            CyDelayUs(10);
        }

        cmForS1 = (counts1-2.8214)/4.6726;        
        
        snprintf(buffer,255, "The distance for sensor 1: %f cm \n\r", cmForS1);
        UART_1_PutString(buffer); 

        
        CyDelayUs(100);
        
        
        /*----------------------------*/
        /***        Sensor 2        ***/
        
        Pin_S2_Trig_Write(0);
        CyDelayUs(2);
    
        Pin_S2_Trig_Write(1);
        CyDelayUs(10);
        Pin_S2_Trig_Write(0);

        while(Pin_S2_Echo_Read() != 1) //wait until return pulse starts 
        {}
        
        counts2 = 0;
        
        while(Pin_S2_Echo_Read() != 0) //wait unit return pulse stops  
        {
            counts2++;
            CyDelayUs(10);
        }

        cmForS2 = (counts2-2.8214)/4.6726;        
        
        snprintf(buffer,255, "The distance for sensor 2: %f cm \n\r", cmForS2);
        UART_1_PutString(buffer); 

        
        CyDelayUs(100);
        
        
        /*----------------------------*/
        /***        Sensor 3        ***/
        
        Pin_S3_Trig_Write(0);
        CyDelayUs(2);
    
        Pin_S3_Trig_Write(1);
        CyDelayUs(10);
        Pin_S3_Trig_Write(0);

        while(Pin_S3_Echo_Read() != 1) //wait until return pulse starts 
        {}
        
        counts3 = 0;
        
        while(Pin_S3_Echo_Read() != 0) //wait unit return pulse stops  
        {
            counts1++;
            CyDelayUs(10);
        }

        cmForS3 = (counts3-2.8214)/4.6726;        
        
        snprintf(buffer,255, "The distance for sensor 3: %f cm \n\r", cmForS3);
        UART_1_PutString(buffer); 

        
        CyDelayUs(100);
        
        
        /*----------------------------*/
        /***        Sensor 4        ***/
        
        Pin_S4_Trig_Write(0);
        CyDelayUs(2);
    
        Pin_S4_Trig_Write(1);
        CyDelayUs(10);
        Pin_S4_Trig_Write(0);

        while(Pin_S4_Echo_Read() != 1) //wait until return pulse starts 
        {}
        
        counts4 = 0;
        
        while(Pin_S4_Echo_Read() != 0) //wait unit return pulse stops  
        {
            counts4++;
            CyDelayUs(10);
        }

        cmForS4 = (counts4-2.8214)/4.6726;        
        
        snprintf(buffer,255, "The distance for sensor 4: %f cm \n\r", cmForS4);
        UART_1_PutString(buffer); 

        
        CyDelayUs(100);
    }
}

/* [] END OF FILE */


