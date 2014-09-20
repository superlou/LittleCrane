#include <stdio.h>
#include <unistd.h>
#include "gpio.h"
#include "stepper.h"

int main() {
    printf("Starting LittleCrane\n");

    gpio_setup_io();
    gpio_direction_output(7);
    gpio_direction_output(8);

    stepper_init();

    for (;;) {
        stepper_set_position(200);
        sleep(2);
        stepper_set_position(0);
        sleep(2);
        stepper_set_position(-200);
        sleep(2);
    }
}