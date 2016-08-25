#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main() {
	Head *head;
	int numCaixas, i, numEl, numLoads, j = 0;
	int *loads, *elems, x;

	scanf("%d", &numCaixas);

	while (numCaixas > 0) {
		head = InitializeList();
		j = 0;

		scanf("%d %d", &numEl, &numLoads);

		loads = (int *) malloc(numLoads * sizeof(int));
		elems = (int *) malloc(numEl * sizeof(int));

		head->LoadsMissing = numLoads;
		head->loadPos = 1;

		/*Save to array numbers got from input*/
		for (i = 0; i < numEl; i++) {
			scanf("%d", (elems + i));
		}
		/*Save to array the loads from input*/
		for (i = 0; i < numLoads; i++) {
			scanf("%d", (loads + i));
		}
		/*While there are numbers to insert, do it and check if it is LOAD time.*/
		for (i = 0; i < numEl; i++)
		{
			SAVE(*(elems + i), head);

			for (x = 0; x < numLoads; x++)
			{
				if (*(loads + j) > head->size) {
					break;
				} else {
					LOAD(head);
					head->loadPos++; /*update load position in list*/
					j++;/*update load index being tested*/
					head->LoadsMissing--; /*update the number of missing loads*/
				}
			}
		}

		numCaixas--;
		DestroyList(head);
		if (numCaixas > 0)
			printf("\n");
	}

	return 0;
}
