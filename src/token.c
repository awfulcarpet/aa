#include <stdlib.h>
#include <stdio.h>

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

struct Token *
tokenize(char *buf)
{
	return NULL;
}

void
print_tokens(struct Token *head)
{
	while (head != NULL) {
		printf("%d %d\n", head->type, head->val);
		head = head->next;
	}
}
