#include <esp_idf_version.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "libesp.h"

static const char *TAG = "libesp";

void util_wait_micros(int64_t micros) {
    int64_t then = esp_timer_get_time();
    while (esp_timer_get_time() - then <= micros) {
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
    }
}

void util_wait_for_keypress() {
    // Clear the buffer
    while (fgetc(stdin) != EOF)
        vTaskDelay(10 / portTICK_PERIOD_MS);

    // Now wait until next key
    while (fgetc(stdin) == EOF)
        vTaskDelay(10 / portTICK_PERIOD_MS);
}

void util_log_idf_version() {
    ESP_LOGW(TAG, "%d.%d.%d", ESP_IDF_VERSION_MAJOR, ESP_IDF_VERSION_MINOR, ESP_IDF_VERSION_PATCH);
}