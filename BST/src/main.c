/*
 * BST.h
 *
 *      Author: pedro geadas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BST.h"

int j, loadPos;

int main() {
	int numBoxes, *loads = NULL, *elems = NULL, numEl, numLoads, i, x;
	PtNodeABP pRoot = NULL;

	scanf("%d", &numBoxes);

	while (numBoxes > 0) {
		j = 0, loadPos = 1;
		pRoot = NULL;
		scanf("%d %d", &numEl, &numLoads);

		loads = (int *) malloc(numLoads * sizeof(int));
		elems = (int *) malloc(numEl * sizeof(int));

		for (i = 0; i < numEl; i++) {
			scanf("%d", (elems + i)); /*save read elements to array*/
		}

		for (i = 0; i < numLoads; i++) {
			scanf("%d", (loads + i)); /*save loads to another array*/
		}

		/*While there are numbers to insert, do it and check if it is LOAD time.*/
		for (i = 0; i < numEl; i++)
		{
			if (j > numLoads)
				break;

			SAVE(&pRoot, *(elems + i));

			for (x = 0; x < numLoads; x++) {
				if (*(loads + j) == i + 1) {
					LOAD(&pRoot, 0, loadPos);
					loadPos++;
					j++;
				} else
					break;
			}
		}

		if (numBoxes > 1)
			printf("\n");

		numBoxes--;
	}

	return 0;
}
