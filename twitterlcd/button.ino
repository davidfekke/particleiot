#include "InternetButton/InternetButton.h"

// Create a Button named b. It will be your friend, and you two will spend lots of time together.
// You may be wondering about those two slashes and this gray text- they're called comments, and
// don't affect the code. Think of this as the voice of the narrator.
InternetButton b = InternetButton();

bool rainbow_mode = false;

void myHandler(const char *event, const char *data)
{  
  b.ledOn(9, 255, 0, 255); // Magenta
  delay(500);
  b.ledOn(12, 255, 0, 0); // Red
  delay(500);
  b.ledOn(3, 0, 255, 0); // Green
  delay(500);
  b.ledOn(6, 0, 0, 255); // Blue
  delay(500);
  b.rainbow(5);
  rainbow_mode = true;
}

void setup() {
    // Tell b to get everything ready to go
    // Use b.begin(1); if you have the original SparkButton, which does not have a buzzer or a plastic enclosure
    // to use, just add a '1' between the parentheses in the code below.
    b.begin();
    Particle.subscribe("rainbow", myHandler);
}

void loop(){

    // If this calls for a full spectrum situation, let's go rainbow!
    if(b.allButtonsOn()) {
        // Publish the event "allbuttons" for other services like IFTTT to use
        Particle.publish("allbuttons","All four in sync", 60, PRIVATE);
        b.rainbow(5);
        rainbow_mode = true;

        // If all buttons are on, don't try to process
        // the individual button responses below.  Just return.
        return;
    }

    // If we are not in rainbow mode anymore, turn the LEDs off
    if (rainbow_mode == true) {
        b.allLedsOff();
        rainbow_mode = false;
    }

    // Process individual buttons and LED response
    if (b.buttonOn(1)) {
        b.ledOn(12, 255, 0, 0); // Red
        // Publish the event "button1" for other services like IFTTT to use
        Particle.publish("button1","Bottom", 60, PRIVATE);
        delay(500);
    }
    else {
        b.ledOn(12, 0, 0, 0);
    }

    if (b.buttonOn(2)) {
        b.ledOn(3, 0, 255, 0); // Green
        // Publish the event "button2" for other services like IFTTT to use
        Particle.publish("button2","Left", 60, PRIVATE);
        delay(500);
    }
    else {
        b.ledOn(3, 0, 0, 0);
    }

    if (b.buttonOn(3)) {
        b.ledOn(6, 0, 0, 255); // Blue
        // Publish the event "button3" for other services like IFTTT to use
        Particle.publish("button3","Top", 60, PRIVATE);
        delay(500);
    }
    else {
        b.ledOn(6, 0, 0, 0);
    }

    if (b.buttonOn(4)) {
        b.ledOn(9, 255, 0, 255); // Magenta
        // Publish the event "button4" for other services like IFTTT to use
        Particle.publish("button4","Right", 60, PRIVATE);
        delay(500);
    }
    else {
        b.ledOn(9, 0, 0, 0);
    }

    if(b.allButtonsOff()) {
        // Do something here when all buttons are off
    }
}
