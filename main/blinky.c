#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

/***********************************************
* Constants
*************************************************/
static const char *TAG = "BLINKY";
static const gpio_num_t BLINK_PIN = 23;
static const uint16_t BLINK_PERIOD = 800; // blink period in milliseconds

/***********************************************
* Static Vars
*************************************************/
static uint8_t s_led_state = 0;  // to toggle the LED state on (1 for HIGH) or off (0 for LOW)

/***********************************************
* Function Declarations
*************************************************/
static void blink_led(void);  // toggles the led on or off
static void configure_led(void); // initial config

/***********************************************
* Application Entrypoint
*************************************************/
void app_main(void)
{
   configure_led();

   while (1) {
      ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
      blink_led();
        s_led_state = !s_led_state;
        vTaskDelay(BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}

/***********************************************
* Function Definitions
*************************************************/
static void blink_led(void)
{
   // sets the GPIO level to s_led_state
   gpio_set_level(BLINK_PIN, s_led_state);
}

static void configure_led(void)
{
   ESP_LOGI(TAG, "Example configured to blink GPIO %d!", BLINK_PIN);
   gpio_reset_pin(BLINK_PIN);
   gpio_set_direction(BLINK_PIN, GPIO_MODE_OUTPUT);
}
