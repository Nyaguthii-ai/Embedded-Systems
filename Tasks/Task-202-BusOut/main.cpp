#include "mbed.h"

// Hardware Definitions 
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define TRAF_GRN2_PIN PC_14
#define TRAF_YEL2_PIN PC_7
#define TRAF_RED2_PIN PC_0

// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
BusOut leds2(TRAF_RED2_PIN, TRAF_YEL2_PIN, TRAF_GRN2_PIN);

int main()
{
    while (true) {

    //flash leds2
        leds2 = 0; //set second set to zero 
        wait_us(500000);
        leds2 = 7; //set all to one 

     //this counts up the leds from zero to seven 
      for (n = 0; n <= 7; n++) {
        leds = n; 
        wait_us(500000);
      }    
    }
}


