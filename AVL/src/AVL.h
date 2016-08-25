/*
 * AVL.h
 *
 *      Author: pedro geadas
 */

#include "globals.h"

#ifndef AVL_H_
#define AVL_H_

typedef struct noavl *PtNoAVL;
struct noavl {
	PtNoAVL PtLeft;
	PtNoAVL PtRight;
	int *PtElem;
	int *nodesLeft;
	int *nodesRight;
	int *height;
};

//tree methods
int Max(int a, int b);
int Height(PtNoAVL pRoot);
void RotationSimpleRight(PtNoAVL *pRoot);
void RotationSimpleLeft(PtNoAVL *pRoot);
void RotationDoubleRL(PtNoAVL *pRoot);
void RotationDoubleLR(PtNoAVL *pRoot);
void BalanceTree(PtNoAVL *pRoot);
void InOrderTraversal(PtNoAVL pRoot);

//problem specific methods
int SAVE(PtNoAVL *pRoot, int pelem);
void LOAD(PtNoAVL *pRoot, int somaNos);

#endif /* AVL_H_ */
