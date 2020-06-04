#!/usr/bin/env python

# File: prototype.py
# Author: Ananas

from gpiozero import *
from time import sleep

led = LED(7)

while True:
    led.on()
    print("on")
    sleep(1)
    led.off()
    print("off")
    sleep(1)
