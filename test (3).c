#include <avr/io.h>
#include <util/delay.h>
#define MYDELAY 1000

int main(void){
    unsigned int pitch = 1;
    DDRB = 1<<DDB5;   //LED on PB5
    DDRD = 0x00;      //D ports connected to switches
    PORTD = 1<<PD0;   //pull up on PD0
    PORTD = 1<<PD1;   //pull up on PD1

    //Timer
    TCCR1A = 0;
    TCCR1B = 3;


    while(1){
    //First button
        if ( (PIND & (1<<PD0))==0 ){
            pitch*=2;
            _delay_ms(200);
        }
        TCNT1=65536-65536/pitch;
        while((TIFR1 & (1<<TOV1))==0);
        TIFR1 |= 1<<TOV1;

        PORTB ^= 1<<PORTB5;
        
    }

    //return 0;
}