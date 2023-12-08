// Switch.h
// This software configures the on-board switches and LEDs.
//
// For use with the LM4F120 or TM4C123
// September 15, 2013
// Port B bits 2-0 have the 3-bit DAC
// Port F is onboard LaunchPad switches and LED
// Port F bit 4 is negative logic switch to play sound, SW1
// SysTick ISR: PF3 ISR heartbeat


void PortA_Init(void);
void PortD_Init(void);

