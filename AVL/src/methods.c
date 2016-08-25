/*
 * methods.c
 *
 *      Author: pedro geadas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "AVL.h"

#ifndef METHODS_C_
#define METHODS_C_

int Max(int a, int b) {
	return a > b ? a : b;
}

void DestroyNoAVL(PtNoAVL *ppint) {
	free((*ppint)->PtElem); /*frees element*/
	free(*ppint); /*and the node*/
	*ppint = NULL;
}

PtNoAVL CreateNoAVL(int pelem) {
	PtNoAVL NoAVL;

	if ((NoAVL = (PtNoAVL) malloc(sizeof(struct noavl))) == NULL)
		return NULL;

	if ((NoAVL->PtElem = (int *) malloc(sizeof(int))) == NULL) {
		free(NoAVL);
		return NULL;
	}
	if ((NoAVL->height = (int *) malloc(sizeof(int))) == NULL) {
		free(NoAVL);
		return NULL;
	}
	if ((NoAVL->nodesLeft = (int *) malloc(sizeof(int))) == NULL) {
		free(NoAVL);
		return NULL;
	}
	if ((NoAVL->nodesRight = (int *) malloc(sizeof(int))) == NULL) {
		free(NoAVL);
		return NULL;
	}

	*NoAVL->height = 0;
	*NoAVL->nodesLeft = 0;
	*NoAVL->nodesRight = 0;
	*NoAVL->PtElem = pelem; /*copy the element*/
	NoAVL->PtLeft = NULL;
	NoAVL->PtRight = NULL;

	return NoAVL;
}

int Height(PtNoAVL pRoot) {
	if (pRoot == NULL)
		return 0;
	else
		return *(pRoot->height);
}

/*Not used in the problem solving, just for debug and check how the tree is if needed.*/
void InOrderTraversal(PtNoAVL pRoot) {
	if (pRoot != NULL) {
		InOrderTraversal(pRoot->PtLeft);
		printf("Number:%d, Height %d, nodesLeft: %d, nodesRight: %d\n",
				*pRoot->PtElem, *pRoot->height, *pRoot->nodesLeft,
				*pRoot->nodesRight);
		InOrderTraversal(pRoot->PtRight);
	}
}

void BalanceTree(PtNoAVL *pRoot) {
	int HeightLeft, HeightRight;

	/*empty sub-tree*/
	if (*pRoot == NULL)
		return;

	HeightLeft = Height((*pRoot)->PtLeft);
	HeightRight = Height((*pRoot)->PtRight);

	/*left subtree unbalanced*/
	if (HeightLeft - HeightRight == 2)
	{
		HeightLeft = Height((*pRoot)->PtLeft->PtLeft);
		HeightRight = Height((*pRoot)->PtLeft->PtRight);
		if (HeightLeft >= HeightRight)
			RotationSimpleRight(pRoot);
		else
			RotationDoubleLR(pRoot);
	} else if (HeightRight - HeightLeft == 2) { //left
		HeightRight = Height((*pRoot)->PtRight->PtRight);
		HeightLeft = Height((*pRoot)->PtRight->PtLeft);

		if (HeightRight >= HeightLeft)
			RotationSimpleLeft(pRoot);
		else
			RotationDoubleRL(pRoot);
	} else
		*(*pRoot)->height = HeightLeft > HeightRight ? HeightLeft + 1 : HeightRight + 1;

}

void RotationDoubleRL(PtNoAVL *pRoot) {
	RotationSimpleRight(&(*pRoot)->PtRight);
	RotationSimpleLeft(pRoot);
}

void RotationDoubleLR(PtNoAVL *pRoot) {
	RotationSimpleLeft(&(*pRoot)->PtLeft);
	RotationSimpleRight(pRoot);
}

void RotationSimpleLeft(PtNoAVL *pRoot) {
	int HeightLeft, HeightRight, nosAux;

	PtNoAVL No = (*pRoot)->PtRight;/*node to swap*/

	nosAux = *No->nodesLeft; /*save No's left nodes, that will be in the right side of Root*/

	*No->nodesLeft = ((*(*pRoot)->nodesLeft) + 1) + nosAux;/*number of No's left nodes, are the Root's left nodes plus the Root itself*/

	(*pRoot)->PtRight = No->PtLeft; /*Root right side will be the No's left side*/
	No->PtLeft = *pRoot; /*No's left node is now the new root*/

	*(*pRoot)->nodesRight = nosAux; /*Number of nodes in the right side of the Root and the previous number of nodes in the left side of No*/


	/*update heights*/
	HeightLeft = Height((*pRoot)->PtLeft);
	HeightRight = Height((*pRoot)->PtRight);

	*(*pRoot)->height = HeightLeft > HeightRight ? HeightLeft + 1 : HeightRight + 1; /*greater between left and right*/

	HeightLeft = *(*pRoot)->height;
	HeightRight = Height(No->PtRight);

	*No->height = HeightLeft > HeightRight ? HeightLeft + 1 : HeightRight + 1;

	*pRoot = No;

}

void RotationSimpleRight(PtNoAVL *pRoot) {
	int HeightLeft, HeightRight, nosAux;

	PtNoAVL No = (*pRoot)->PtLeft;/*node to swap*/

	nosAux = *No->nodesRight; /*save No's right nodes, that will be in the left side of Root*/

	*No->nodesRight = ((*(*pRoot)->nodesRight) + 1) + nosAux;/*number of No's right nodes, are the Root's right nodes plus the Root itself*/

	(*pRoot)->PtLeft = No->PtRight; /*Root left side will be the No's right side*/
	No->PtRight = *pRoot; /*No's right node is now the new root*/

	*(*pRoot)->nodesLeft = nosAux; /*Number of nodes in the left side of the Root and the previous number of nodes in the right side of No*/


	/*update heights*/
	HeightLeft = Height((*pRoot)->PtLeft);
	HeightRight = Height((*pRoot)->PtRight);

	*(*pRoot)->height = HeightLeft > HeightRight ? HeightLeft + 1 : HeightRight + 1; /*greater between left and right*/

	HeightLeft = Height(No->PtLeft);
	HeightRight = *(*pRoot)->height;

	*No->height = HeightLeft > HeightRight ? HeightLeft + 1 : HeightRight + 1;

	*pRoot = No;

}

int SAVE(PtNoAVL *pRoot, int pelem) {

	if ((*pRoot) == NULL) /*insert element*/
	{
		if ((*pRoot = CreateNoAVL(pelem)) == NULL)
			return 1;

	} else if (*(*pRoot)->PtElem >= pelem) {
		SAVE(&(*pRoot)->PtLeft, pelem);
		*(*pRoot)->nodesLeft += 1;
	} else {
		SAVE(&(*pRoot)->PtRight, pelem);
		*(*pRoot)->nodesRight += 1;
	}

	/**(*pRoot)->height=1+max(Height((*pRoot)->PtLeft),Height((*pRoot)->PtRight));*/

	BalanceTree(pRoot);

	return 0; /*ok*/
}

void LOAD(PtNoAVL *pRoot, int sumNodes) {
	/*printf("LOADPOS: %d\n", nLoads);
	 printf("LeftNodes: %d, RightNodes %d\n",*(*pRoot)->nodesLeft, *(*pRoot)->nodesRight);
	 printf("Sum: %d\n",soma);*/
	if (*(*pRoot)->nodesLeft + sumNodes + 1 < loadPos) {
		sumNodes += *(*pRoot)->nodesLeft + 1;
		/*printf("Right Sum %d\n",sumNodes);*/
		LOAD(&(*pRoot)->PtRight, sumNodes);
	} else if (*(*pRoot)->nodesLeft + sumNodes + 1 == loadPos) {
		printf("%d\n", *(*pRoot)->PtElem);
	} else {
		/*printf("Left\n");*/
		LOAD(&(*pRoot)->PtLeft, sumNodes);
	}

}

#endif /* METHODS_C_ */
