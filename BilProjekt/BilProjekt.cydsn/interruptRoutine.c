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

#include "interruptRoutine.h"
#include <stdbool.h>
#include "DCControl.h"
#include "servoControl.h"

#define ISR_PIN 0x01

CY_ISR(GPIO_ISR)
{
	uint8 InterruptState = Pin_interrupt_ClearInterrupt();
	if(InterruptState == ISR_PIN)
	{
		extern bool driving;
        extern bool enoughSpace;
        driving = false;
        enoughSpace = false;
        stopDriving();
        middlePos();
        UART_1_PutString("System stopped by user!!!");
	}
}

/* [] END OF FILE */
