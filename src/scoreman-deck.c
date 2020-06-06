#include <stdio.h>
#include <bcm2835.h>

/* Map pins */
#define LED 17

int main(void)
{
    printf("Raspberry Pi StreamDeck\n");

    /* Initialize bcm2835 */
    if (!bcm2835_init()) return 1;

    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
    unsigned int delay = 1000;

    int x;
    for (x=0; x<5; x++)
    {
        bcm2835_gpio_set(LED);
        bcm2835_delay(delay);
        bcm2835_gpio_clr(LED);
        bcm2835_delay(delay);
    }
    return 0;
}
