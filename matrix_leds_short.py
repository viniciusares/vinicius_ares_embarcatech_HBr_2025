from machine import Pin
import neopixel

NUM_LEDS = 25
PIN = 7
np = neopixel.NeoPixel(Pin(PIN), NUM_LEDS)

# Simplified matrix mapping (only two LEDs)
LED_MATRIX = { "A": 12, "B": 7 }  # Example positions

def leds(led, r=20, g=20, b=20):
    if led in LED_MATRIX:
        np[LED_MATRIX[led]] = (r, g, b)
        np.write()

def apagar():
    np.fill((0,0,0))
    np.write()

# Example usage
leds("A", 50, 50, 0)  # Turns on LED A in yellow
leds("B", 0, 50, 50)  # Turns on LED B in cyan