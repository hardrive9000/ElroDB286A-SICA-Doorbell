# Elro DB286A SICA (Argentina) Doorbell

Several years ago, wireless doorbells became popular, mainly due to their simplicity of installation and practically zero maintenance since, due to their low power consumption, the batteries have a long life.
But what do we do if we want to play "ring raje" without risks? I mean, what do we do if we need to install more than one transmitter for accessibility reasons? There is only one transmitter in the kit. This is where the ineffable software-defined radio appears that will help us to clone the transmitter.
We will do a quick unboxing and review of a wireless doorbell manufactured by a well-known electrical products brand here in Argentina and with the help of a software defined radio USB receiver, a Wemos D1 Mini board and a 433MHz RF transmitter module with a high gain DIY antenna, we will see how to perform a REPLAY attack.

## Schematic

![schematic](/Schematic/rf433_doorbell_schematic.png)

## Code

### Arduino/RF433_Doorbell
Source code used in the video. Tested with a Wemos D1 Mini board (ESP8266) and compatible with any Arduino board. Compatible with the ATtiny13A microcontroller (Int. RC Osc. 9.6MHz) although not very well optimized.

### AVR C/RF433_Doorbell
Source code written 100% in AVR C specially optimized for ATtiny13A. It occupies only 280 bytes (27.34%). Recommended code for production use. In the Release folder you will find the hex file ready to burn.
ATtiny13A Fuses (Int. RC Osc. 9.6MHz)
L: 0x7A
H: 0xFF

## Videotutorial

[![video](https://img.youtube.com/vi/Pp0GVWaTra8/0.jpg)](https://www.youtube.com/watch?v=Pp0GVWaTra8)
