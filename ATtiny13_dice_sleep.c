/*
* tiny13_1.c
*
* Created: 2017-02-06 23:07:14
* Author : PCV
*/

#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>


#define TIME1 1000

void show(uint8_t num){
	uint32_t i=TIME1;
	switch (num){
		
		case 1 :
		while(i>0){
			PORTB=1<<0|1<<1;	//1
			_delay_ms(2);
			i--;
		}
		PORTB=0;
		break;
		case 2 :
		while(i>0){
			PORTB=1<<0;			//2
			_delay_ms(2);
			i--;
		}
		PORTB=0;
		break;
		case 3 :
		while(i>0){
			PORTB=1<<1;			//1+3
			_delay_ms(2);
			i--;
		}
		PORTB=0;
		break;
		case 4 :
		while(i>0){
			PORTB=1<<0;			//2
			_delay_ms(1);
			PORTB=1<<1|1<<2;	//3
			_delay_ms(1);
			i--;
		}
		PORTB=0;
		break;
		case 5 :
		while(i>0){
			PORTB=1<<0;			//2
			_delay_ms(1);
			PORTB=1<<1;			//1+3
			_delay_ms(1);
			i--;
			
		}
		PORTB=0;
		break;
		case 6 :
		while(i>0){
			PORTB=1<<0|1<<2;	//4+2
			_delay_ms(1);
			PORTB=1<<1|1<<2;	//3
			_delay_ms(1);
			i--;
		}
		PORTB=0;
		break;
		default :
		while(i>0){
			PORTB=0;
			i--;
		}
		break;
	}
	
	
}

int main(void)
{
	ADMUX|=1<<MUX1;
	ADCSRA|=1<<ADEN|1<<ADPS2|1<<ADPS1;
	DDRB=1<<0|1<<1|1<<2;
	PORTB=1<<3;
	ADCSRA |= (1 << ADSC); /* start ADC conversion */
	loop_until_bit_is_clear(ADCSRA, ADSC); /* wait until done */
	show((ADCL)%6+1);
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();



}