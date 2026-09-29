# Challenge 04 - PWM Fade

## Objective

Use PWM to control the brightness of an LED based on the reading from a potentiometer.

## Platform

- ESP32
- Wokwi Simulator
- Arduino IDE

## Components Used

- ESP32 Development Board
- Potentiometer
- LED

## Working

The potentiometer value is read using the ESP32 analog input.

The analog value is mapped to a PWM brightness value from 0 to 255.

The PWM value is then used to control the brightness of the LED.

When the potentiometer value changes, the LED brightness changes accordingly.

The potentiometer value and LED brightness are also displayed on the Serial Monitor.

## Wokwi Simulation

https://wokwi.com/projects/476471856283277313

## Output

The LED brightness changes according to the potentiometer reading.

The Serial Monitor displays the potentiometer value and corresponding brightness value.

## Challenge Status

Completed
