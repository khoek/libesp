#ifndef __LIB_LIBESP_H
#define __LIB_LIBESP_H

#include <esp_err.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// DANGER: `micros` should be small to avoid WDT triggers.
void util_wait_micros(int64_t micros);

void util_wait_for_keypress();

void util_log_idf_version();

esp_err_t util_stack_overflow_check();

void util_stack_print_remaining();

static __always_inline bool util_unterm_str_matches(const char* st, const char* sut, size_t sut_len) {
    return !strncmp(st, sut, sut_len) && st[sut_len] == '\0';
}

#endif
