#ifndef READFILE_H
#define READFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record Record;

//Estrutura Record armazena a palavra do dicinário e sua descrição
struct Record{
    char *word;
    char *description;
};

int countChar(const char* filename); //conta a quantidade de caracteres no arquivo e retorna esse valor
int countLine(const char* filename); //conta a quantidade de linhas no arquivo e retorna esse valor
void tokeia(char *vet,Record *item); //Separa os valores em item campo da struct ITEM
void readf(const char* filename,char * line,const int cont); //lê o arquivo e copia o conteúdo para a string line
char* readfBest(const char* filename, const int cont); //lê o arquivo e retorna o conteúdo, atualizado para uma versão "mais correta"

#endif