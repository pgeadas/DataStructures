/*
 * BST.h
 *
 *      Author: pedro geadas
 */

#ifndef BST_H_
#define BST_H_
/***BST: Binary Search Tree *****
 * (In Portuguese ABP: Arvore Binaria de Pesquisa*/

typedef struct nodeabp *PtNodeABP;
struct nodeabp {
	PtNodeABP PtLeft;
	PtNodeABP PtRight;
	int *PtElem;
	int *nodesLeft;
	int *nodesRight;
	int *height;
};

//tree methods
int Height(PtNodeABP pRoot);
int Max(int a, int b);
void DestroyNoABP(PtNodeABP *ppint) ;
PtNodeABP CreateNoABP(int pelem);
void InOrderTraversal(PtNodeABP pRoot);

//problem specific methods
void LOAD(PtNodeABP *pRoot, int sum, int nLoads);
int SAVE(PtNodeABP *pRoot, int pelem) ;

#endif /* BST_H_ */
