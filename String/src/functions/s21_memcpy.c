#include "s21_string.h"

// копириует в dest n байтов из src
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    byte *ptr_dest = (byte *)dest;
    byte *ptr_src = (byte *)src;
    while (n--) {
      *ptr_dest++ = *ptr_src++;
    }
  }
  return dest;
}