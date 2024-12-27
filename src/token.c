#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token.h"

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
 * ex: dechex = 10
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

			/* num */
			if (tok[0] == '$') {
				int len = strlen(&tok[1]);
				head = enqueue(head, NUM, strhex_to_dec(&tok[1], 2));

				/* we have two byte num */
				if (len > 2) {
					head = enqueue(head, NUM, strhex_to_dec(&tok[3], 2));
				}
			}

			printf("%s\n", tok);
		} while ((tok = strtok(NULL, " ")) != NULL);
			printf("\n");
	} while ((line = strtok_r(line_ptr, "\n", &line_ptr)) != NULL);

	print_tokens(head);
	return head;
}

void
print_tokens(struct Token *head)
{
	while (head != NULL) {
		printf("%d %02x\n", head->type, head->val);
		head = head->next;
	}
}
