#include <pthread.h>
#include <stdio.h>
#include "stepper.h"

pthread_t update_thread;
int position = 0;
int goal_position = 0;
int min_update_period = 800;

void stepper_step_cw() {
    gpio_set(8);

    gpio_set(7);
    usleep(1);
    gpio_clear(7);
    position++;
}

void stepper_step_ccw() {
    gpio_clear(8);

    gpio_set(7);
    usleep(100);
    gpio_clear(7);
    position--;
}

void *update_stepper(void *arg) {
    int error;
    int sleep;

    for (;;) {
        error = position - goal_position;

        if (error < 0) {
            stepper_step_cw();
        } else if (error > 0) {
            stepper_step_ccw();
        };

        sleep = min_update_period;

        usleep(sleep);
    }
}

void stepper_init() {
    int thread_status;

    gpio_clear(8);

    thread_status = pthread_create(&update_thread, NULL, update_stepper, NULL);
    if (thread_status != 0) {
        printf("Failed to create stepper update thread.\n");
    }
}

void stepper_set_position(int new_goal) {
    goal_position = new_goal;
}