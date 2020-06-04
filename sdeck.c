#include <stdio.h>
#include <wiringPi.h>

// LED Pin
#define LED 17

int main(void)
{
    printf("Raspberry Pi StreamDeck");

    wiringPiSetupGpio();
    pinMode(LED, OUTPUT);

    int x;
    for (x=0; x<5; x++)
    {
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
    }
}
