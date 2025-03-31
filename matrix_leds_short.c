#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

#define LED_PIN 7
PIO pio = pio0;
uint sm;

// Simplified mapping: Two LEDs
const uint8_t LED_A = 12, LED_B = 7;

void set_led(uint8_t led, uint8_t r, uint8_t g, uint8_t b) {
    uint32_t color = (g << 16) | (r << 8) | b;
    pio_sm_put_blocking(pio, sm, color << 8u);
}

int main() {
    stdio_init_all();
    uint offset = pio_add_program(pio, &ws2812_program);
    sm = pio_claim_unused_sm(pio, true);
    ws2812_program_init(pio, sm, offset, LED_PIN, 800000, false);

    set_led(LED_A, 50, 50, 0);  // Yellow
    set_led(LED_B, 0, 50, 50);  // Cyan

    return 0;
}