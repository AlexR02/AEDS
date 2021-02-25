/** C implementation for 
	Red-Black Tree Insertion 
	This code is provided by 
	costheta_z modified by 
    Alex Raimundo de Oliveira.
    Original code in: 
    https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/ **/

#ifndef REDBLACK_H
#define REDBLACK_H

#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "ReadFile.h"

//Define Black como false and Red coom true para facilitar a implementação
#define Black false
#define Red true

//Define a estrutura Node
typedef struct Node Node;

// Structure to represent each 
// node in a red-black tree 
struct Node{ 
	Record record; // data 
	bool color; // true-Red, false-Black 
	Node * p; // parent 
	Node * r; // right-child 
	Node * l; // left child 
}; 

Node* newNode(Record r);
Node* insert(Node *trav, Node *temp);
void rightrotate(Node *temp);
void leftrotate(Node *temp);
void insertFixup(Node *root, Node *pt); 
void setRoot(Node *node);
Node* getRoot();
Record search(char *word);

//funções apenas para printar
void central(Node *tree);
void preOrdem(Node *tree);
void posOrdem(Node *tree);
void centralColor(Node *tree);
void preOrdemColor(Node *tree);
void posOrdemColor(Node *tree);
void print2DUtil(Node *root, int space);
void print2D(Node *root);

#endif