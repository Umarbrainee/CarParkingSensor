# Arduino Car Parking Sensor
**Tinkercad Project Link:**  
[https://www.tinkercad.com/things/8X8ctl3j0ue-carparking-sensor?sharecode=ZMTOxCNtBenuLr0HTT8puMtHmOnyRJXyukXnUVJYBGI](https://www.tinkercad.com/things/8X8ctl3j0ue-carparking-sensor?sharecode=ZMTOxCNtBenuLr0HTT8puMtHmOnyRJXyukXnUVJYBGI)

This project is an ultrasonic-based car parking assist system for
Arduino.\
It uses five LEDs to visually indicate how close a vehicle is to a wall
or obstacle.\
As the vehicle moves closer, LEDs progressively turn on. Once the final
LED is activated, a buzzer sounds to alert the driver that the car has
reached a preset parking distance.

## Features

-   Uses an ultrasonic sensor to measure distance.
-   Five LEDs light up one by one as distance decreases.
-   A buzzer activates at the closest safe parking point.
-   LED trigger distances and behavior can be customized in the Arduino
    code.
-   Ideal for garages, small parking spaces, or DIY vehicle assist
    projects.

## Customization

You can modify: - When each LED turns on. - The buzzer activation
point. - LED colors, brightness, and arrangement.

## Purpose

This README provides an overview of how the parking sensor behaves.\
The actual Arduino code inside the repository defines the specific LED
behavior, timing, and buzzer activation.
