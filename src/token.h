#include <stdint.h>

enum TYPE {
	INSTR,
	NUM,
	ADR,
	REG,
};

/* queue */
struct Token {
	enum TYPE type;
	uint8_t val; /* value of num/adr/reg or the opcode */

	struct Token *next;
};

struct Token * tokenize(char *buf);
struct Token * enqueue(struct Token *head, enum TYPE type, uint8_t val);
struct Token * dequeue(struct Token **head);
void print_tokens(struct Token *head);
