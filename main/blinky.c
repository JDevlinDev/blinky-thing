#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "sdkconfig.h"

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
static esp_err_t s_esp_err;

/***********************************************
* Function Declarations
*************************************************/
static esp_err_t blink_led(void);  // toggles the led on or off
static esp_err_t configure_led(void); // initial config

/***********************************************
* Application Entrypoint
*************************************************/
void app_main(void)
{
   // Configure the GPIO and exit the program if there are errors
   s_esp_err = configure_led();
   if (s_esp_err == ESP_OK) {
      while (s_esp_err == ESP_OK) {
         ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
         if (blink_led() == ESP_OK) {
            s_led_state = !s_led_state;
            vTaskDelay(BLINK_PERIOD / portTICK_PERIOD_MS);
         }
       }
       ESP_LOGE(TAG, "Failed to blink good.\n");
   }
   
   ESP_LOGE(TAG, "Failed to configure GPIO %d. Exiting...\n", BLINK_PIN);
}

/***********************************************
* Function Definitions
*************************************************/
esp_err_t blink_led(void)
{
   // sets GPIO level and returns the ESP_OK if it had success
   return gpio_set_level(BLINK_PIN, s_led_state);
}

static esp_err_t configure_led(void)
{
   // Reset GPIO pin 
   s_esp_err = gpio_reset_pin(BLINK_PIN);
   if (s_esp_err != ESP_OK) {
      ESP_LOGE(TAG, "\t-Could not reset GPIO %d. Config failed...\n");
      return s_esp_err;
   }

   // Set GPIO MODE as OUTPUT
   s_esp_err = gpio_set_direction(BLINK_PIN, GPIO_MODE_OUTPUT);
   if (s_esp_err != ESP_OK) {
      ESP_LOGE(TAG, "\t-Could not set GPIO %d direction. Config failed...\n");
      return s_esp_err;
   }

   // Print success message.
   ESP_LOGI(TAG, "Example configured to blink GPIO %d!", BLINK_PIN);
   return s_esp_err;
}
