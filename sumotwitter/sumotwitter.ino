// SumoTwitter.ino
//void twitterEventHandler1(const char *event, const char *data);

Servo leftServo;
Servo rightServo;

void stop() {
    leftServo.write(90);
    rightServo.write(90);
}

void forward() {
    leftServo.write(180);
    rightServo.write(0);
    delay(2000);
    stop();
}

void backwards() {
    leftServo.write(0);
    rightServo.write(180);
    delay(2000);
    stop();
}

void left() {
    leftServo.write(0);
    rightServo.write(0);
    delay(750);
    stop();
}

void right() {
    leftServo.write(180);
    rightServo.write(180);
    delay(750);
    stop();
}

void twitterEventHandler(const char *event, const char *data) {
    if (strcmp(data,"f")==0) {
        forward();
    } else if (strcmp(data,"b")==0) {
        backwards();
    } else if (strcmp(data,"r")==0) {
        right();
    } else if (strcmp(data,"l")==0) {
        left();
    } else {
        stop();
    }
}

void setup() {
    Particle.subscribe("twitterEvent", twitterEventHandler);
    leftServo.attach(D0);
    rightServo.attach(D1);
}

void loop() {

}
