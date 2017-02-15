#include <avr/io.h>

#define TIME1 960000

void show(uint8_t num){
	uint32_t i=TIME1;
	switch (num){

		case 1 :
		while(i>0){
			PORTB=1<<0;   //1
			i--;
		}
		PORTB=1<<3; //pullup on button
		break;
		case 2 :
		while(i>0){
			PORTB=1<<1|1<<2; //2
			i--;
		}
		PORTB=1<<3;
		break;
		case 3 :
		while(i>0){
			PORTB=1<<0;   //1
			PORTB=1<<1|1<<2; //2
			i--;
		}
		PORTB=1<<3;
		break;
		case 4 :
		while(i>0){
			PORTB=1<<1|1<<2; //2
			PORTB=1<<0|1<<1; //3
			i--;
		}
		PORTB=1<<3;
		break;
		case 5 :
		while(i>0){
			PORTB=1<<0;   //1
			PORTB=1<<1|1<<2; //2
			PORTB=1<<0|1<<1; //3
			i--;

		}
		PORTB=1<<3;
		break;
		case 6 :
		while(i>0){
			PORTB=1<<1|1<<2; //2
			PORTB=1<<0|1<<1; //3
			PORTB=1<<2;   //4
			i--;
		}
		PORTB=1<<3;
		break;
		default :
		while(i>0){
			PORTB=1<<3;
			i--;
		}
		break;
	}


}
static inline void initTimer1(void) {
	/* Normal mode (default), just counting */
	TCCR0B |= (1 << CS00);

}
int main(void)
{
	initTimer1();
	DDRB=1<<0|1<<1|1<<2;
	PORTB=1<<3;
	while (1)
	{
		loop_until_bit_is_clear(PINB,3);
		TCNT0 = 0;
		loop_until_bit_is_set(PINB,3);
		show(TCNT0%6+1);
	}
}

