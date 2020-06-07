#include <wiringPi.h>
#include<stdio.h>

#define buttonPin 1

void main(void)
{
    short input;

    printf(":: Starting...\n")

    /* Initialize wiringPi */
    printf(" (1/3) Initializing wiringPi\n")
    wiringPiSetup(); 

    /* Set the button to input */
    printf(" (2/3) Set the button to input\n")
    pinMode(buttonPin, INPUT);

    /* Set pull up to HIGH level */
    printf(" (3/3) Set pull up to HIGH level\n")
    pullUpDnControl(buttonPin, PUD_UP);

    /* Main loop */
    while(1)
    {
        if (digitalRead(buttonPin) == LOW)
        {
            input = 0x1
        }
    }
    return 0;
}