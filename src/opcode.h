#include <stdint.h>

struct Opcode {
	char *mnumonic;
	uint8_t opcode;
	uint8_t n_arg;
};
int get_optype(char *instr);
