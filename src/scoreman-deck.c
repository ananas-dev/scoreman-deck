#include <stdio.h>
#include "../include/bcm2835.h"

/* Map pins */
#define BUTTON1 18
#define BUTTON2 23
#define BUTTON3 24
#define BUTTON4 25

int main(void)
{
    printf("Raspberry Pi StreamDeck\n");

    /* Initialize bcm2835 */
    if (!bcm2835_init()) return 1;

    /* Set buttons to output mode */
    bcm2835_gpio_fsel(BUTTON1, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(BUTTON2, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(BUTTON3, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(BUTTON4, BCM2835_GPIO_FSEL_INPT);
    /* Set pud-up */
    bcm2835_gpio_set_pud(BUTTON1, BCM2835_GPIO_PUD_UP);
    bcm2835_gpio_set_pud(BUTTON2, BCM2835_GPIO_PUD_UP);
    bcm2835_gpio_set_pud(BUTTON3, BCM2835_GPIO_PUD_UP);
    bcm2835_gpio_set_pud(BUTTON4, BCM2835_GPIO_PUD_UP);
    
    unsigned int delay = 50;

/*
    while(1)
    {
        bcm2835_gpio_write(LED, LOW);
        bcm2835_delay(delay);
        bcm2835_gpio_write(LED, HIGH);
        bcm2835_delay(delay);
    }
    bcm2835_close();
    return 0;
}

*/