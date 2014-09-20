#include <stdio.h>
#include <unistd.h>
#include "gpio.h"

int main() {
    printf("Starting LittleCrane\n");

    gpio_setup_io();
    gpio_direction_output(7);
    gpio_direction_output(8);

    gpio_clear(8);

    for (;;) {
        gpio_set(7);
        usleep(400);

        gpio_clear(7);
        usleep(400);
    }
}