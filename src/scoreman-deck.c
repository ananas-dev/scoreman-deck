/*
 * Name: scoreman.c
 * Author: Lucien Fiorini
 * Project: Scoreman Deck
 * Version: 0.5
 * Licence: MIT
 */

#include <stdio.h>
#include "../include/wiringPi.h"

/*
 +-----+-----+---------+------+---+---Pi 4B--+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   2 |   8 |   SDA.1 |   IN | 1 |  3 || 4  |   |      | 5v      |     |     |
 |   3 |   9 |   SCL.1 |   IN | 1 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | IN   | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | IN   | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | IN   | GPIO. 1 | 1   | 18  |
 |  27 |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 |   0 |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   5 |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | 12  |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | 16  |
 |  26 |  25 | GPIO.25 |   IN | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | 20  |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | 21  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 4B--+---+------+---------+-----+-----+
*/

/* Pins layout */
#define button1Pin 1 // BCM18
#define button2Pin 4 // BCM23
#define button3Pin 5 // BCM24
#define button4Pin 6 // BCM25

int main(void)
{
    /* Initialize variables */
    short int input = 0x0;

    printf(":: Starting...\n");

    /* Initialize wiringPi */
    printf(" (1/3) Initializing wiringPi\n");
    if(!wiringPiSetup()) {return 1;}

    /* Set the button to input */
    printf(" (2/3) Set the buttons to input\n");
    pinMode(button1Pin, INPUT);
    pinMode(button2Pin, INPUT);
    pinMode(button3Pin, INPUT);
    pinMode(button4Pin, INPUT);

    /* Set pull up to HIGH level */
    printf(" (3/3) Set pull up to HIGH level\n");
    pullUpDnControl(button1Pin, PUD_UP);
    pullUpDnControl(button2Pin, PUD_UP);
    pullUpDnControl(button3Pin, PUD_UP);
    pullUpDnControl(button4Pin, PUD_UP);

    /* Main loop */

    printf(":: Listening inputs\n");
    while(1)
    {
        /* Check if the buttons are pushed */
        if (digitalRead(button1Pin) == LOW)
        {
            input = 0x1;
            while(1)
            {
                if (digitalRead(button1Pin) == HIGH) { break; }
            }
        }
        if (digitalRead(button2Pin) == LOW)
        {
            input = 0x2;
            while(1)
            {
                if (digitalRead(button2Pin) == HIGH) { break; }
            }
        }
        if (digitalRead(button3Pin) == LOW)
        {
            input = 0x3;
            while(1)
            {
                if (digitalRead(button3Pin) == HIGH) { break; }
            }
        }
        if (digitalRead(button4Pin) == LOW)
        {
            input = 0x4;
            while(1)
            {
                if (digitalRead(button4Pin) == HIGH) { break; }
            }
        }
        /* Only output each inputs once */
        printf("%x\n", input);
    }
    return 0;
}