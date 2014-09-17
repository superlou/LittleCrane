#include <stdio.h>
#include "gpio.h"

int main() {
    printf("Starting LittleCrane\n");

    gpio_setup_io();
    gpio_direction_output(7);

    for (;;) {
    }
}