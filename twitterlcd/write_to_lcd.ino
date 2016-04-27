// This #include statement was automatically added by the Particle IDE.
#include "Serial_LCD_SparkFun/Serial_LCD_SparkFun.h"

// Initialize the LCD library
Serial_LCD_SparkFun lcd = Serial_LCD_SparkFun();

int writeRow1Handler(const char *event, const char *data){
    
    // Clear the display
    lcd.clear();
    int totalStrLen = strlen(data);
    if (totalStrLen > 32) {
        for (int i = 32; i <= totalStrLen; i++) {
            char firstLine[16];
            strncpy(firstLine, &data[i - 32], 16);
            Serial1.print(firstLine);
            char secondLine[16];
            strncpy(secondLine, &data[i - 16], sizeof(secondLine));
            secondLine[16] = '\0';
            lcd.selectLine(2);
            Serial1.print(secondLine);    
            delay(250);
            if (i < totalStrLen - 1) {
                lcd.clear();
            }
        }
    } else if (totalStrLen > 16 && totalStrLen <= 32) {
        char firstLine[16];
        strncpy(firstLine, data, sizeof(firstLine));
        Serial1.print(firstLine);
        char secondLine[16];
        strncpy(secondLine, &data[16], sizeof(secondLine));
        secondLine[16] = '\0';
        lcd.selectLine(2);
        Serial1.print(secondLine);
    } else {
        Serial1.print(data);
    }

    // Write whatever was send to the command

    // Return 1 for giggles
    return 1;
}

// Writing to row 2
int writeRow2Handler(const char *event, const char *data){
    //lcd.clear();

    // Ahhh, but this one is a little different!
    // Here we're moving the "cursor" to line 2
    lcd.selectLine(2);
    Serial1.print(data);
    return 1;
}

void setup() {
    Spark.subscribe("writeRow1", writeRow1Handler);
    lcd.clear();
}

void loop() {

}
