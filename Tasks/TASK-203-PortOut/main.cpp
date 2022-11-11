#include "mbed.h"

// Hardware Definitions 
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASK 0b0100000011001101
#define TRAF_GRN1_PIN PB_14
#define TRAF_YEL1_PIN PB_7
#define TRAF_RED1_PIN PB_0
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut ledsC(PortC, LEDMASK);
PortOut ledsB(Port B, LEDMASK);

int main()
{
    while (true) {
    //Binary 000 
        ledsC = 0;   
        ledsB = 0;
        wait_us(500000);
    //Binary 11111111
        leds = 0xFF;   
        leds = 0xFF;
        wait_us(500000);    
    }
}




