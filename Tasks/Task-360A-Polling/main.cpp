#include "mbed.h"
#include "SWPoll.hpp"

#define N 1000000
#define RELEASED 0
#define PRESSED  1

//Hardware objects
DigitalOut yellow_led(TRAF_YEL1_PIN);  //CountDown is in its critical section
SWPoll switch1(BTN1_PIN, TRAF_RED1_PIN);
SWPoll switch2(BTN2_PIN, TRAF_GRN1_PIN);

DigitalOut statusLED(LED1);

/*
class flash {
private:
    DigitalOut led;  //name handle for the leds
    Timer tmr;       //timer for each instance

public:
   //constructor that references the led
   flash(PinName gpioOutIn) : led(gpioOutIn){
       tmr.reset();
       led = !led;
   }

   //destructor to turn off led when out of scope
   ~flash() {
       //Shut down
        tmr.stop();
        tmr.reset();
        led = 0;  
   }
};

flash yellow_led(TRAF_YEL1_PIN);
*/

int main() {
    
    //Main uses a Timer
    yellow_led = 1;
    Timer tmr;
        
    //Now loop forever
    tmr.start();
    while(1) { 

        //Flash the yellow
        
        if (tmr.elapsed_time() >= 500ms) {
            yellow_led = !yellow_led;   
            tmr.reset();        
        }
        

        //Update state and outputs
        switch1.poll();
        switch2.poll();
        
        //Toggle the status LED to indicate polling loop speed
        statusLED = !statusLED;
        //wait_us(1); //Uncomment this if you want to see the LED!
    };
}


