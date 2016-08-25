/*
 * methods.c
 *
 *  Created on: 25/08/2016
 *      Author: pedro
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


/**
Insertion.
**/
int SAVE(int x, Head *head) {
	Node *no, *actual, *prev;
	no = (Node *) malloc(sizeof(Node));
	if (no != NULL && head->size == 0)/**1record**/
	{
		no->info = x;
		no->next = NULL;
		head->size = 1;
		head->loadPos = 1;
		head->header = no;
	} else {
		actual = head->header;
		prev = NULL;
		/*insert values*/
		no->next = NULL;
		no->info = x;
		head->size++;

		while (actual != NULL && no->info > actual->info) {
			prev = actual;
			actual = actual->next;
		}
		if (prev == NULL) {
			no->next = head->header;
			head->header = no;
		} else {
			no->next = actual;
			prev->next = no;
		}
	}

	return 0;
}
/**list initialization**/
Head *InitializeList(void) {
	Node *element;
	Head *head;
	element = (Node *) malloc(sizeof(Node));
	head = (Head *) malloc(sizeof(Head));
	if (element == NULL || head == NULL)
		return NULL;

	element->info = 0;
	element->next = NULL;
	head->size = 0;
	head->header = element;

	return head;
}

void PrintList(Head *head) {
	Node *element = head->header;
	if (head->size > 0) {
		printf("%d nodes.\n", head->size);
		while (element != NULL) {
			printf("%d\n", element->info);
			element = element->next;
		}
	} else
		printf("Empty list\n");
}

void DestroyList(Head *head) {
	Node *element = head->header, *aux = NULL;

	while (element != NULL) {
		aux = element;
		element = element->next;
		head->header = element;
		free(aux);
	}
	head->size = 0;
	head = NULL;
	free(head);
}

void LOAD(Head *head) {
	Node* no;
	int i;
	no = head->header;

	if (head->LoadsMissing > 0) {
		for (i = 0; i < head->loadPos - 1; i++) {
			no = no->next;
		}
		printf("%d\n", no->info);
		return;
	}
}
