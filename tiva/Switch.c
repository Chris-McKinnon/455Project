// Switch.c
// This software configures the on-board switches and LEDs.

// Port B bits 2-0 have the 3-bit DAC

// Port E is for switches PE0(SW1) and PE1 (SW2)
#define buttons (*((volatile unsigned long *)0x4002400c))

#include <stdint.h>
#include "tm4c123gh6pm.h"

void PortA_Init(void)
{
	volatile uint32_t delay;
	SYSCTL_RCGCGPIO_R |= 0x2;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTB_AMSEL_R &= ~0x1F;
	GPIO_PORTB_AFSEL_R &= ~0x1F;
	GPIO_PORTB_PCTL_R &= ~0x000FFFFF;
	GPIO_PORTB_DIR_R = 0x10;
	// GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTB_DEN_R |= 0x10;
}

void PortD_Init(void)
{
	volatile uint32_t delay;
	SYSCTL_RCGCGPIO_R |= 0x8;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R = 0x1;
	GPIO_PORTD_AMSEL_R &= ~0x1F;
	GPIO_PORTD_AFSEL_R &= ~0x1F;
	GPIO_PORTD_PCTL_R &= ~0x000FFFFF;
	GPIO_PORTD_DIR_R = 0x0;
	// GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTD_DEN_R |= 0x1;
}
