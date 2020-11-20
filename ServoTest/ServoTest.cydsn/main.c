/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 * Kristian Gaardsted Bork
 *
 * ========================================
*/
#include "project.h"
#include <stdint.h>

CY_ISR_PROTO(ISR_UART_rx_handler);

void handleByteReceived(uint8_t byteReceived);

void turnRight();
void turnLeft();
void middlePos();

uint8_t compare = 20;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    PWM_1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    UART_1_PutString("DC-Motor-PWM application started\r\n");
    
    for(;;)
    {
//        PWM_1_WriteCompare(1000);
//        CyDelay(1000);
//        PWM_1_WriteCompare(2000);
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '1' :
        {
            turnRight();
            UART_1_PutString("Turn right\r\n");
        }
        break;
        case '2' :
        {
            turnLeft();
            UART_1_PutString("Turn left\r\n");
        }
        break;
        case '3' :
        {
            middlePos();
            UART_1_PutString("Middle position\r\n");
        }
        default :
        {
            // nothing
        }
        break;
    }
}

void turnRight()
{
    PWM_1_WriteCompare(1000);
}

void turnLeft()
{
    PWM_1_WriteCompare(2000);
}

void middlePos()
{
    PWM_1_WriteCompare(1500);
}


/* [] END OF FILE */
