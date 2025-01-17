/*
 * PDU_timer.c
 *
 * Created: 5/15/2024 5:16:05 PM
 *  Author: Admin
 */ 
#include <avr/interrupt.h>
#include "PDU_timer.h"

void	PDU_timer_start_timer0(void)
{

	TCCR0 |= (1 << CS02);	//prescaler = 64
			  // enable compare interrupt
	TIMSK |= (1 << OCIE0);

			  // enable global interrupts
	sei();
}
void	PDU_timer_stop_timer0(void)
{
	TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));	
}
void PDU_timer_timer0_init(void)
{
	  // set up timer with prescaler = 64 and CTC mode
	  TCCR0 |= (1 << WGM01);

	  // initialize counter
	  TCNT0 = 0;

	  // initialize compare value (tick every 1ms)
	  OCR0 = 125 - 1;


}