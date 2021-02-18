#ifndef BLACKRED_H
#define BLACKRED_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
    int key;
    int value;
};

struct Tree{
    Record rec;
    Tree *esq, *dir;
    bool cor;
    Tree *pai;
};

#endif