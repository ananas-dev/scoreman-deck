#include "../include/wiringPi.h"
#include<stdio.h>

/* Pins layout */
#define BUTTON_1 1 // Pin 18
#define BUTTON_2 4 // Pin 23
#define BUTTON_3 5 // Pin 24
#define BUTTON_4 6 // Pin 25

int main(void)
{
    short input;
    short lastInput;

    printf(":: Starting...\n");

    /* Initialize wiringPi */
    printf(" (1/3) Initializing wiringPi\n");
    wiringPiSetup(); 

    /* Set the button to input */
    printf(" (2/3) Set the buttons to input\n");
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
    pinMode(BUTTON_3, INPUT);
    pinMode(BUTTON_4, INPUT);

    /* Set pull up to HIGH level */
    printf(" (3/3) Set pull up to HIGH level\n");
    pullUpDnControl(BUTTON_1, PUD_UP);
    pullUpDnControl(BUTTON_2, PUD_UP);
    pullUpDnControl(BUTTON_3, PUD_UP);
    pullUpDnControl(BUTTON_4, PUD_UP);

    /* Main loop */

    printf(":: Listenig inputs");
    while(1)
    {
        /* Check if the buttons are pushed */
        if (digitalRead(BUTTON_1) == LOW)
        {
            input = 0x1;
        }
        if (digitalRead(BUTTON_1) == LOW)
        {
            input = 0x2;
        }
        if (digitalRead(BUTTON_1) == LOW)
        {
            input = 0x3;
        }
        if (digitalRead(BUTTON_1) == LOW)
        {
            input = 0x4;
        }
        /* Only output each inputs once */
        if(input != lastInput)
        {
            printf("%x\n", input);
        }
        lastInput = input;
    }
    return 0;
}