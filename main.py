#!/usr/bin/env python

import RPI.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BOARD)
GPIO.setup(7, GPIO.OUT)

for x in range(0, 3):
    GPIO.output(7, True)
    sleep(1)
    GPIO.output(7, False)
    sleep(1)

# Clean the GPIO
GPIO.cleanup()
