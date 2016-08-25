/*
 * LinkedList.h
 *
 *  Created on: 25/08/2016
 *      Author: pedro
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/**Struct definition**/
typedef struct _no {
	int info;
	struct _no *next;
} Node;

typedef struct _head {
	Node *header;
	int loadPos;
	int LoadsMissing;
	int size;
} Head; /* of list*/

Head *InitializeList(void);
void PrintList(Head *head);
void DestroyList(Head *head);
int SAVE(int x, Head *head);
void LOAD(Head *head);

#endif /* LINKEDLIST_H_ */
