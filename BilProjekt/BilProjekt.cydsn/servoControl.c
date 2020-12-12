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
#include "servoControl.h"

void turnWheelsRight()
{
    PWM_Servo_WriteCompare(1000);
}

void turnWheelsLeft()
{
    PWM_Servo_WriteCompare(2000);
}

void middlePos()
{
    PWM_Servo_WriteCompare(1500);
}

/* [] END OF FILE */
