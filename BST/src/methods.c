/*
 * methods.c
 *
 *      Author: pedro geadas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BST.h"

#ifndef METHODS_C_
#define METHODS_C_

int Height(PtNodeABP pRoot) {
	if (pRoot == NULL)
		return 0;
	else
		return *pRoot->height;
}

int Max(int a, int b) {
	return a > b ? a : b;
}

void DestroyNoABP(PtNodeABP *ppint) {
	free((*ppint)->PtElem); /*free element*/
	free(*ppint); /*free node*/
	*ppint = NULL;
}

PtNodeABP CreateNoABP(int pelem) {
	PtNodeABP NoABP;

	if ((NoABP = (PtNodeABP) malloc(sizeof(struct nodeabp))) == NULL) {
		return NULL;
	}
	if ((NoABP->PtElem = (int *) malloc(sizeof(int))) == NULL) {
		free(NoABP);
		return NULL;
	}
	if ((NoABP->height = (int *) malloc(sizeof(int))) == NULL) {
		free(NoABP);
		return NULL;
	}
	if ((NoABP->nodesLeft = (int *) malloc(sizeof(int))) == NULL) {
		free(NoABP);
		return NULL;
	}
	if ((NoABP->nodesRight = (int *) malloc(sizeof(int))) == NULL) {
		free(NoABP);
		return NULL;
	}

	*NoABP->height = 1;
	*NoABP->nodesLeft = 0;
	*NoABP->nodesRight = 0;
	*NoABP->PtElem = pelem; /*copy value*/
	NoABP->PtLeft = NULL; /*left is NULL*/
	NoABP->PtRight = NULL; /*right is NULL*/

	return NoABP;
}

/*Not used in the problem solving, just for debug and check how the tree is if needed.*/
void InOrderTraversal(PtNodeABP pRoot) {
	if (pRoot != NULL) {
		InOrderTraversal(pRoot->PtLeft);
		printf("Number:%d, height %d, nodesLeft: %d, nodesRight: %d\n",
				*pRoot->PtElem, *pRoot->height, *pRoot->nodesLeft,
				*pRoot->nodesRight);
		InOrderTraversal(pRoot->PtRight);
	}
}

void LOAD(PtNodeABP *pRoot, int sum, int nLoads) {
	if (*(*pRoot)->nodesLeft + sum + 1 < nLoads) {
		sum += *(*pRoot)->nodesLeft + 1;
		LOAD(&(*pRoot)->PtRight, sum, nLoads);
	} else if (*(*pRoot)->nodesLeft + sum + 1 == nLoads) {
		printf("%d\n", *(*pRoot)->PtElem);
	} else {
		LOAD(&(*pRoot)->PtLeft, sum, nLoads);
	}
}

int SAVE(PtNodeABP *pRoot, int pelem) {
	if ((*pRoot) == NULL) /*inserir o elemento*/
	{
		if ((*pRoot = CreateNoABP(pelem)) == NULL){
			return 1;/*if it fails*/
		}
	} else if (*(*pRoot)->PtElem >= pelem) {
		SAVE(&(*pRoot)->PtLeft, pelem);
		*(*pRoot)->nodesLeft += 1;
	} else {
		SAVE(&(*pRoot)->PtRight, pelem);
		*(*pRoot)->nodesRight += 1;
	}

	*(*pRoot)->height = 1 + Max(Height((*pRoot)->PtLeft),
			Height((*pRoot)->PtRight));

	return 0; /*ok*/
}

#endif /* METHODS_C_ */
