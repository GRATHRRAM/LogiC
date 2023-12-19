#ifndef STRC_H
#define STRC_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct bits
{
    bool *bit;
    size_t len;
} bits;


void STRC_Alloc_Bites  (bits *BITES, size_t len);
void STRC_ReAlloc_Bites(bits *BITES, size_t len);
void STRC_Align(bits *Main, bits Ret);

void STRC_Alloc_Bites(bits *BITES, size_t len) {
    BITES->bit = (bool*) malloc(sizeof(bool) * len);
    BITES->len  = len;
}

void STRC_ReAlloc_Bites(bits *BITES, size_t len) {
    BITES->bit = (bool*) realloc(BITES->bit, sizeof(bool) * len);
    BITES->len  = len;
}

void STRC_Align(bits *Main, bits Ret) {
    STRC_ReAlloc_Bites(Main, Ret.len);
    Main->bit = Ret.bit;
}
#endif // !STRC_H