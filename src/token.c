#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "opcode.h"
extern char *optypes[];

/* appends new token to linked list and returns head */
struct Token *
enqueue(struct Token *head, enum TYPE type, uint8_t val) {
	if (head == NULL) {
		head = calloc(1, sizeof(struct Token));

		head->next = NULL;
		head->type = type;
		head->val = val;

		return head;
	}

	struct Token *tmp = head;
	while (tmp->next != NULL) tmp = tmp->next;

	struct Token *new = calloc(1, sizeof(struct Token));
	new->val = val;
	new->type = type;
	new->next = NULL;
	tmp->next = new;

	return head;
}

/* returns token at the front of queue, modifies head */
struct Token *
dequeue(struct Token **head)
{
	struct Token *tmp = *head;

	*head = (*head)->next;

	return tmp;
}

char *
strtok_r(char *buf, char *delim, char **save_ptr)
{
	for (int i = 0; buf[i] != '\0'; i++) {
		for (int j = 0; delim[j] != '\0'; j++) {
			if (buf[i] == delim[j]) {
				buf[i] = '\0';
				*save_ptr = buf + i + 1;
				return buf;
			}
		}
	}
	return NULL;
}

/* converts int version of decimal string into real decimal
 * ex: num = 10
 * returns 16
*/
static int
strhex_to_dec(char *num, int len) {
	int n = 0;
	for (int i = 0; i < len; i++) {
		int x = 0;
		int e = len - i - 1;

		if (num[i] >= '0' && num[i] <= '9') {
			x = num[i] - '0';
		}
		if (num[i] >= 'a' && num[i] <= 'f') {
			x = num[i] - 'a' + 10;
		}

		n += x * pow(16, e);
	}
	return n;
}

static struct Token *
enqueue_literal(struct Token *head, char *num_str)
{
	int len = strlen(num_str);
	head = enqueue(head, NUM, strhex_to_dec(num_str, 2));

	/* we have two byte num */
	if (len > 2) {
		head = enqueue(head, NUM, strhex_to_dec(num_str + 2, 2));
	}
	return head;
}

static struct Token *
enqueue_reg(struct Token *head, char *reg)
{
	if (!strcmp(reg, "SP")) {
		return enqueue(head, REG, SP);
	}

	if (!strcmp(reg, "PSW")) {
		return enqueue(head, REG, PSW);
	}

	if (reg[0] >= 'A' && reg[0] <= 'E')
		return enqueue(head, REG, reg[0] - 'A');

	return enqueue(head, REG, reg[0] - 'a');
}

struct Token *
tokenize(char *buf)
{
	struct Token *head = NULL;
	char *line_ptr = NULL;
	char *line = strtok_r(buf, "\n", &line_ptr);
	do {
		char *tok = strtok(line, " ");
		do {
			/* skip rest of line if comments */
			if (tok[0] == ';') {
				break;
			}

			/* two arg */
			char *i = NULL;
			if ((i = strchr(tok, ',')) != NULL) {
				if (tok[0] == '$') {
					head = enqueue_literal(head, &tok[1]);
				} else {
					head = enqueue_reg(head, tok);
				}

				if (i[1] == '$') {
					head = enqueue_literal(head, i + 2);
				} else {
					head = enqueue_reg(head, i + 1);
				}
				continue;
			}

			/* num */
			if (tok[0] == '$') {
				head = enqueue_literal(head, &tok[1]);
				continue;
			}

			/* is it a instruction? */
			if (strlen(tok) >= 2 && strlen(tok) <= 4 && strncmp(tok, "SP", strlen(tok))) {
				head = enqueue(head, INSTR, get_optype(tok));
				continue;
			}

			/* there should only be regs remaining */
			head = enqueue_reg(head, tok);
		} while ((tok = strtok(NULL, " ")) != NULL);
	} while ((line = strtok_r(line_ptr, "\n", &line_ptr)) != NULL);
	return head;
}

void
print_tokens(struct Token *head)
{
	char *type[] = {
		"INSTR",
		"NUM",
		"REG",
	};
	while (head != NULL) {
		if (head->type == INSTR) {
			printf("%s %s\n", type[head->type], optypes[head->val]);

		} else
			printf("%s %d\n", type[head->type], head->val);
		head = head->next;
	}
}
