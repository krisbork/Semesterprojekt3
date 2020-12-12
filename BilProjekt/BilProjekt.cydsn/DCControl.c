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
#include "DCControl.h"
#include <stdint.h>

uint8_t compare = 20;

void driveForwards()
{
    UART_1_PutString("Set direction: forwards\r\n");
    PWM_DC_WriteCompare(compare);
    Pin_1_7_Write(0);
    Pin_1_6_Write(1);
}

void driveBackwards()
{
    UART_1_PutString("Set direction: backwards\r\n");
    PWM_DC_WriteCompare(compare);
    Pin_1_7_Write(1);
    Pin_1_6_Write(0);
}

void stopDriving()
{
    UART_1_PutString("Stop\r\n");
    Pin_1_7_Write(0);
    Pin_1_6_Write(0);
}

void decreaseSpeed()
{
    UART_1_PutString("Decreasing speed\r\n");
    if(compare > 0) 
    {
        compare -= 2;
        PWM_DC_WriteCompare(compare);
    }
}

void increaseSpeed()
{
    UART_1_PutString("Increasing speed\r\n");
    if(compare < 100)
    {
        compare += 2;
        PWM_DC_WriteCompare(compare);
    }
}

/* [] END OF FILE */
