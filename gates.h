#ifndef GATES_H
#define GATES_H
#include <stdbool.h>

bool not (bool bit);
bool and (bool bit1, bool bit2);
bool nand(bool bit1, bool bit2);
bool or  (bool bit1, bool bit2);
bool nor (bool bit1, bool bit2);
bool xor (bool bit1, bool bit2);
bool xnor(bool bit1, bool bit2);


bool not (bool bit) {
	return !bit;
}

bool and (bool bit1, bool bit2) {
	if (bit1 == 1 && bit2 == 1) return 1;
	else return 0;
}

bool nand(bool bit1, bool bit2) {
	if (bit1 == 1 && bit2 == 1) return 0;
	else return 1;
}

bool or (bool bit1, bool bit2) {
	if (bit1 == 0 && bit2 == 0) return 0;
	else return 1;
}

bool nor(bool bit1, bool bit2) {
	if (bit1 == 0 && bit2 == 0) return 1;
	else return 0;
}

bool xor (bool bit1, bool bit2) {
	if (bit1 == 0 && bit2 == 0 ||
		bit1 == 1 && bit2 == 1) return 0;
	else return 1;
}

bool xnor(bool bit1, bool bit2) {
	if (bit1 == 0 && bit2 == 0 ||
		bit1 == 1 && bit2 == 1) return 1;
	else return 0;
}
#endif // !GATES_H