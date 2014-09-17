#ifndef GPIO_H_

#include <stdint.h>

void gpio_setup_io();
void gpio_direction_output(uint8_t pin);
void gpio_direction_input(uint8_t pin);
void gpio_set(uint8_t pin);
void gpio_clear(uint8_t pin);

#endif
