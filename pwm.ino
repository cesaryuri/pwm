#include <avr/io.h>
#include <avr/interrupt.h>
//#include <avr/delay.h>
#define F_CPU 16000000


int ms1 = 0;
int contime = 0;
int main(void){
	
	cli();
	DDRD =(1<<6) | (1<<5);
	
	TCCR0A=(1<<COM0A1) | (1<<COM0B1) | (1<<WGM01) | (1<<WGM00);
	TCCR0B=(1<<CS01) | (1<<CS00);

	TCCR2A = 0;
	TCCR2B = (1<<CS22); // pre
	TIMSK2= (1<<TOIE2); //hablita interrupção
	TCNT2 = 5;
	OCR0A = 0;//PIN 6
	OCR0B = 255; //PIN 5
	sei();
	

	while(1){
			
	}

}

ISR(TIMER2_OVF_vect){

	ms1++;
	TCNT2 = 5;
	
	if(ms1 == 10){
    contime++;
		
    if(contime > 255){
			OCR0A--;
			OCR0B++;
			if (contime == 510){contime = 0;}
		}else/*if(contime < 255)*/{
			OCR0A++;
			OCR0B--;
		}
		
		ms1 = 0;
	}

}