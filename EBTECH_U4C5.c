#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN_RED 13
#define LED_PIN_BLUE 12
#define LED_PIN_GREEN 11

bool callback_timer(struct repeating_timer *t) {
    printf("Mudança de Cor\n");

    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_BLUE, 0);
    gpio_put(LED_PIN_GREEN, 0);

static int estado_semaforo = 0;


    switch (estado_semaforo) {
        case 0:
            gpio_put(LED_PIN_BLUE, 1);
            estado_semaforo = 1;
            break;
        case 1:
            gpio_put(LED_PIN_GREEN, 1);
            estado_semaforo = 2;
            break;
        case 2:
            gpio_put(LED_PIN_RED, 1);
            estado_semaforo = 0;
            break;
    }
    return true;
}

int main(){
    stdio_init_all();
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, callback_timer, NULL, &timer);
    gpio_put(LED_PIN_RED, 1);

    
    while (1) {
        sleep_ms(1000);
        printf("Se passou um Segundo!(1)\n");
    }
}
