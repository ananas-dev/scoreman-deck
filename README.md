# Scoreman Stream Deck

A stream deck for scoreman using a raspberry pi a breadboard and some buttons.

# Important

! The project wont work in this stage !

# Using

To use the deck you need:

- 8 10k resistors
- 4 buttons
- 1 breadboard 

There is 2 options:

- 1 GPIO extension board
- 15 male male jumpers

or

- 6 female male jumpers
- 9 male male jumpers

# Building

I've tested the program on a Raspberry Pi 4B but it should work on anterior versions but you might have to change the pin mapping at the head of `src/scoreman-deck.c`

First, install Raspberry Pi OS (previously called Raspbian) and make sure you update and upgrade:

```bash
sudo apt update && sudo apt upgrade
```

Make sure you have git installed:

```bash
git --version || sudo apt install git
```

To run scoreman-deck on your raspberry-pi you have to install wiringPi:

```bash
sudo apt install gpio
```

If you use a Raspberry Pi 4B I recommend to apply a patch because the lastest version on the repos doesnt support it:

```bash
wget https://project-downloads.drogon.net/wiringpi-latest.deb
sudo dpkg -i wiringpi-latest.deb
```

Then:

```bash
git clone https://github.com/ananas-dev/scoreman-deck
cd scoreman-deck
make && make install
```