#ifndef __LIB_LIBESP_H
#define __LIB_LIBESP_H

#include <esp_err.h>
#include <stdint.h>

// DANGER: `micros` should be small to avoid WDT triggers.
void util_wait_micros(int64_t micros);

void util_wait_for_keypress();

void util_log_idf_version();

esp_err_t util_stack_overflow_check();

void util_stack_print_remaining();

#endif
