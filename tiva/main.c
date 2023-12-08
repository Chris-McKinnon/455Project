
#include "stdint.h"
#include "PLL.h"
#include "UART.h"
#include "Switch.h"
#include "tm4c123gh6pm.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

int main()
{

    unsigned long i;
    unsigned int input, mode;
    // Functions
    DisableInterrupts(); // The function to disarm the Interrupts - Disabling the interrupt before the PLL configuration
    PLL_Init(Bus80MHz);  // bus clock at 50 MHz
    PortA_Init();
    // change following module in UART.c to configure UART0 for 8-bit (no parity, One stop) and 9600 baud
    UART_Init(); // Initialize UART
    UART_printf("STart");
    while (1)
    {
        //GPIO_PORTB_DATA_R = 0x10; // Toggle blue
        input = UART_inUDec();
        // GPIO_PORTB_DATA_R =input<<4;
        switch (input)
        {
        case 0:
            
            GPIO_PORTB_DATA_R = 0x00; // Toggle blue

            break;
        case 1:
            GPIO_PORTB_DATA_R = 0x10; // Toggle blue

            break;

        default:
            break;
        }
    }
}
