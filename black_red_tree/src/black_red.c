#include "black_red.h"

#define Black false //Black
#define Red true  //Red

//Cria nós para facilitar a manipulação
Node* newNode(int r){
    Node *node = (Node*)malloc(sizeof(Node));
    node->record.key = r;
    node->color = Red;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;

    return node;
}

//*tree está se referindo à raiz.

void insert(Node **tree, Node *z){
    Node *y = NULL;
    Node *x = *tree; 
    while(x != NULL){
        y = x;
        if(z->record.key < x->record.key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y == NULL)
        *tree = z;
    else if(x != NULL){
        if(z->record.key < x->record.key)
            y->left = z;
    }
    else
        y->right = z;
    z->left = NULL;
    z->right = NULL;
    z->color = Red;
    insertFixup(tree,z);
}

void insertFixup(Node **tree, Node *z){
    if(z->parent != NULL){
        while(z->parent->color == Red){
            if(z->parent == z->parent->parent->left){
                Node *y = z->parent->parent->right;
                if(y->color == Red){
                    z->parent->color = Black;
                    y->color = Black;
                    z->parent->parent->color = Red;
                    z = z->parent->parent;
                }
                else if(z == z->parent->right){
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                rightRotate(tree, z);
            }
            else{
                Node *y = z->parent->parent->left;
                if(y->color == Red){
                    z->parent->color = Black;
                    y->color = Black;
                    z->parent->parent->color = Red;
                    z = z->parent->parent;
                }
                else if(z == z->parent->left){
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                rightRotate(tree, z);
            }
        }
    }
    (*tree)->color = Black;
}

void leftRotate(Node **tree, Node *x){
    Node *y = x->right; //Define y e recebe a subárvore à direita de x
    x->right = y->left; //Transforma a subárvore à direita de x na esquerda de y
    if(y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent; //Liga o pai de x a y
    if(x->parent == NULL)
        *tree = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;
    y->left = x; //Coloca o x à esquerda de y
    x->parent = y;
}

void rightRotate(Node **tree, Node *x){
    Node *y = x->left; //Define y e recebe a subárvore à esquerda de x
    x->left = y->right; //Transforma a subárvore à esquerda de x na direita de y
    if(y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent; //Liga o pai de x a y
    if(x->parent == NULL)
        *tree = y;
    else if(x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x; //Coloca o x à direita de y
    x->parent = y;
}

//Funções para imprimir a árvore
void central(Node *tree){
    if(!(tree == NULL)){
        central(tree->left); 
        printf("%d  ", tree->record.key);
        central(tree->right); 
    }
}

void preOrdem(Node *tree){
    if(!(tree == NULL)){
        printf("%d  ", tree->record.key);
        preOrdem(tree->left);
        preOrdem(tree->right);
    }
}

void posOrdem(Node *tree){
    if(!(tree == NULL)){
        posOrdem(tree->left);
        posOrdem(tree->right);
        printf("%d  ", tree->record.key);
    }
}

//Funções para imprimir apenas as cores da árvore
void centralColor(Node *tree){
    if(!(tree == NULL)){
        centralColor(tree->left); 
        if(tree->color == true)
            printf("Red, ");
        else
            printf("Black, ");
        centralColor(tree->right); 
    }
}

void preOrdemColor(Node *tree){
    if(!(tree == NULL)){
        if(tree->color == true)
            printf("Red, ");
        else
            printf("Black, ");
        preOrdemColor(tree->left);
        preOrdemColor(tree->right);
    }
}

void posOrdemColor(Node *tree){
    if(!(tree == NULL)){
        posOrdemColor(tree->left);
        posOrdemColor(tree->right);
        if(tree->color == true)
            printf("Red, ");
        else
            printf("Black, ");
    }
}

int main(){
    int n = 7; 
    int a[7] = { 7, 6, 5, 4, 3, 2, 1 }; 
    Node *tree = NULL;

    for(int i=0;i<n;i++){
        Node *aux = newNode(a[i]);
        insert(&tree, aux);
    }
    central(tree);
    printf("\n");
    centralColor(tree);
    printf("\n");
    return 0;
}