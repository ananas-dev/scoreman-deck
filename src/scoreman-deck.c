/*
 * Name: scoreman.c
 * Author: Lucien Fiorini
 * Project: Scoreman Deck
 * Version: 0.5
 * Licence: MIT
 */

#include <stdio.h>
#include "../include/wiringPi.h"

/* wiringPi pins layout:
NAME:   BCM GPIO:   WIRINGPI PIN:
---------------------------------
SDA     2           8                
SCL     3           9
GPIO7   4           7
GPIO0   17          0
GPIO2   27          2
GPIO3   22          3
MOSI    10          13
MISO    9           12
SCLK    11          14
TxD     14          15
RxD     15          16
GPIO1   18          1
GPIO4   23          4
GPIO5   24          5
GPIO6   25          6
CEO     8           10
CE1     7           11
*/

/* Pins layout */
#define BUTTON_1 1 // BCM18
#define BUTTON_2 4 // BCM23
#define BUTTON_3 5 // BCM24
#define BUTTON_4 6 // BCM25

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

    printf(":: Listening inputs\n");
    while(1)
    {
        /* Check if the buttons are pushed */
        if (digitalRead(BUTTON_1) == LOW)
        {
            input = 0x1;
        }
        if (digitalRead(BUTTON_2) == LOW)
        {
            input = 0x2;
        }
        if (digitalRead(BUTTON_3) == LOW)
        {
            input = 0x3;
        }
        if (digitalRead(BUTTON_4) == LOW)
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