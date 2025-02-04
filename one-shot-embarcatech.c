#include <stdio.h>
#include "pico/stdlib.h"

// Defines
#define BLUE_LED_PIN 11
#define RED_LED_PIN 12
#define GREEN_LED_PIN 13
#define BUTTON_PIN 5

// Declaração de variáveis e vetor globais
uint8_t led_pin[3] = {BLUE_LED_PIN, 
                      RED_LED_PIN, 
                      GREEN_LED_PIN}; // Organiza os pinos
uint8_t led_atual = 0;                // Controla o led que está sendo apagado no momento
bool led_active = false;              // Indica se o LED está atualmente aceso (para evitar múltiplas ativações)

// Cabeçalhos das funções
void led_init(uint gpio);
void button_init(uint gpio);
int64_t turn_off_callback(alarm_id_t id, void *user_data);

int main() {

    stdio_init_all();

    // Inicialização e configuração dos componentes a serem utilizados
    led_init(BLUE_LED_PIN);
    led_init(RED_LED_PIN);
    led_init(GREEN_LED_PIN);
    button_init(BUTTON_PIN);

    while (true)     {
        // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
        if (gpio_get(BUTTON_PIN) == 0 && !led_active) {
            // Adiciona um pequeno atraso para debounce, evitando leituras errôneas.
            sleep_ms(50);

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BUTTON_PIN) == 0) {
                // Liga o LED configurando o pino LED_PIN para nível alto.
                gpio_put(BLUE_LED_PIN, 1);
                gpio_put(RED_LED_PIN, 1);
                gpio_put(GREEN_LED_PIN, 1);

                // Define 'led_active' como true para indicar que o LED está aceso.
                led_active = true;
                led_atual = 0;

                // Agenda um alarme para desligar o LED após 3 segundos (3000 ms).
                // A função 'turn_off_callback' será chamada após esse tempo.
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        // Introduz uma pequena pausa de 10 ms para reduzir o uso da CPU.
        // Isso evita que o loop seja executado muito rapidamente e consuma recursos desnecessários.
        sleep_ms(10);
    }
    return 0;
}

// Função que inicializa o pino de LED e configura como saída
void led_init(uint gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

// Função que inicializa o pino do botão e configura como entrada e pull up
void button_init(uint gpio) {
    gpio_init(gpio);             // inicializa o botão
    gpio_set_dir(gpio, GPIO_IN); // configura o botão como entrada
    gpio_pull_up(gpio);          // habilita o pull up interno
}

// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {

    if (led_atual < 3) {
        gpio_put(led_pin[led_atual], 0);
        led_atual++;

        if (led_atual < 3) {
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        } else {
            led_active = false;
        }
    }

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}