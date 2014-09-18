#include <stdio.h>
#include <unistd.h>
#include "gpio.h"

int main() {
    printf("Starting LittleCrane\n");

    gpio_setup_io();
    gpio_direction_output(7);

    for (;;) {
        printf("Setting\n");
        gpio_set(7);
        sleep(2);

        printf("Clearing\n");
        gpio_clear(7);
        sleep(2);
    }
}