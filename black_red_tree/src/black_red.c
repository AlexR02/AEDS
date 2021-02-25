/** C implementation for 
	Red-Black Tree Insertion 
	This code is provided by 
	costheta_z modified by 
    Alex Raimundo de Oliveira.
    Original code in: 
    https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/ **/

#include <stdio.h> 
#include <stdlib.h> 
#include "black_red.h"
#include "ReadFile.h"
#define COUNT 10

Node *root = NULL;

void setRoot(Node *node){
	root = node;
}

Node* getRoot(){
	return root;
}

Node* newNode(Record r){
	Node *temp = (Node*)malloc(sizeof(Node)); 
	temp->r = NULL; 
	temp->l = NULL; 
	temp->p = NULL; 
	temp->record.word = r.word;
	temp->record.description = r.description; 
	temp->color = Red; 
	
	return temp;
}

// function to perform BST insertion of a node 
Node* insert(Node *trav, Node *temp){ 
	/*strcmp(const char *str1, const char *str2), 
	serve para comparar duas strings e retorna:
		< 0 se str1 menor que str2
		> 0 se str1 maior que str2
		= 0 se str1 igual a str2 */
	int compare = 0;
	if(trav != NULL && temp->record.word != NULL && trav->record.word != NULL)
		compare = strcmp(temp->record.word,trav->record.word); 
	
	// If the tree is empty, 
	// return a new node 
	if (trav == NULL) 
		return temp; 
	
	// Otherwise recur down the tree
	if (compare < 0){ 
		trav->l = insert(trav->l, temp); 
		trav->l->p = trav; 
	}else if (compare > 0){ 
		trav->r = insert(trav->r, temp); 
		trav->r->p = trav; 
	} 

	// Return the (unchanged) node pointer 
	return trav; 
} 

// Function performing right rotation 
// of the passed node 
void rightrotate(Node *temp) 
{ 
	Node *left = temp->l; 
	temp->l = left->r; 
	if (left->r != NULL) 
		left->r->p = temp; 
	left->p = temp->p; 
	if (!temp->p) 
		root = left; 
	else if (temp == temp->p->r) 
		temp->p->r = left; 
	else
		temp->p->l = left; 
	left->r = temp; 
	temp->p = left; 
} 

// Function performing left rotation 
// of the passed node 
void leftrotate(Node *temp) 
{ 
	Node *right = temp->r; 
	temp->r = right->l; 
	if (right->l != NULL) 
		right->l->p = temp; 
	right->p = temp->p; 
	if (!temp->p) 
		root = right; 
	else if (temp == temp->p->l) 
		temp->p->l = right; 
	else
		temp->p->r = right; 
	right->l = temp; 
	temp->p = right; 
} 

// This function fixes violations 
// caused by BST insertion 
void insertFixup(Node *root, Node *pt){ 
	Node *parent_pt = NULL; 
	Node *grand_parent_pt = NULL; 

	while ((pt != root) && (pt->color != Black) 
		&& (pt->p->color == Red)) 
	{ 
		parent_pt = pt->p; 
		grand_parent_pt = pt->p->p; 

		/* Case : A 
			Parent of pt is left child 
			of Grand-parent of 
		pt */
		if (parent_pt == grand_parent_pt->l) 
		{ 

			Node *uncle_pt = grand_parent_pt->r; 

			/* Case : 1 
				The uncle of pt is also red 
				Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == Red) 
			{ 
				grand_parent_pt->color = Red; 
				parent_pt->color = Black; 
				uncle_pt->color = Black; 
				pt = grand_parent_pt; 
			} 

			else { 

				/* Case : 2 
					pt is right child of its parent 
					Left-rotation required */
				if (pt == parent_pt->r) { 
					pt = parent_pt;
					leftrotate(pt); 
					//parent_pt = pt->p; 
				} 

				/* Case : 3 
					pt is left child of its parent 
					Right-rotation required */
				parent_pt->color = Black; 
				grand_parent_pt->color = Red;
				rightrotate(grand_parent_pt); 
				//int t = parent_pt->color;
				//pt = parent_pt; 
			} 
		} 

		/* Case : B 
			Parent of pt is right 
			child of Grand-parent of 
		pt */
		else { 
			Node *uncle_pt = grand_parent_pt->l; 

			/* Case : 1 
				The uncle of pt is also red 
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == Red)) 
			{ 
				grand_parent_pt->color = Red; 
				parent_pt->color = Black; 
				uncle_pt->color = Black; 
				pt = grand_parent_pt; 
			} 
			else { 
				/* Case : 2 
				pt is left child of its parent 
				Right-rotation required */
				if (pt == parent_pt->l) { 
					pt = parent_pt; 
					rightrotate(pt); 
					//parent_pt = pt->p; 
				} 

				/* Case : 3 
					pt is right child of its parent 
					Left-rotation required */
				
				parent_pt->color = Black;
				grand_parent_pt->color = Red;
				leftrotate(grand_parent_pt); 
				//int t = parent_pt->color;  
				//pt = parent_pt; 
			} 
		} 
	} 

	root->color = Black; 
} 

//Funções para imprimir a árvore com a descrição
void central(Node *trav) 
{ 
	if (trav == NULL) 
		return; 
	central(trav->l); 
	printf("%s: %s\n", trav->record.word, trav->record.description); 
	central(trav->r); 
}

void preOrdem(Node *trav){
    if(!(trav == NULL)){
        printf("%s: %s\n", trav->record.word, trav->record.description);
        preOrdem(trav->l);
        preOrdem(trav->r);
    }
}

void posOrdem(Node *trav){
    if(!(trav == NULL)){
        posOrdem(trav->l);
        posOrdem(trav->r);
        printf("%s: %s\n", trav->record.word, trav->record.description);
    }
}
//Funções para imprimir a árvore com as cores
void centralColor(Node *trav) 
{ 
	if (trav == NULL) 
		return; 
	centralColor(trav->l); 
	if(trav->color == Black){
		printf("Black: ");
	}
	else if(trav->color == Red){
		printf("Red: ");
	}
	printf("%s\n", trav->record.word); 
	centralColor(trav->r); 
}

void preOrdemColor(Node *trav){
    if(!(trav == NULL)){
		if(trav->color == Black){
		printf("Black: ");
		}
		else if(trav->color == Red){
		printf("Red: ");
		}
        printf("%s\n", trav->record.word);
        preOrdemColor(trav->l);
        preOrdemColor(trav->r);
    }
}

void posOrdemColor(Node *trav){
    if(!(trav == NULL)){
        posOrdemColor(trav->l);
        posOrdemColor(trav->r);
		if(trav->color == Black){
		printf("Black: ");
		}
		else if(trav->color == Red){
		printf("Red: ");
		}
        printf("%s\n", trav->record.word);
    }
}

void print2DUtil(Node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->r, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++){
        printf("  "); 
	}
	if(root->color == Black){
		printf("Black: ");
	}
	else if(root->color == Red){
		printf("Red: ");
	}
    printf("%c%c%c\n", root->record.word[0],root->record.word[1],root->record.word[2]); 
  
    // Process left child 
    print2DUtil(root->l, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(Node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 