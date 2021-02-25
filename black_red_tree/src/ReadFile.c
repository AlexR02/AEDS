#include "ReadFile.h"//Inclui a declaração da função de leitura e as structs

FILE *file;

int countChar(const char* filename){ //conta a quantidade de caracteres no arquivo e retorna esse valor
    int cont = 0;
    file = fopen(filename, "r");
    char aux;
    if(!file){
        printf("Não foi possível abrir este arquivo.\n");
        exit(-1);
    }
    while(!feof(file)){
        fscanf(file,"%c",&aux);
        cont++;
    }
    fclose(file);
    return cont;
}

int countLine(const char* filename){  //conta a quantidade de linhas no arquivo e retorna esse valor
    int cont = 0;
    file = fopen(filename, "r");
    char aux;
    if(!file){
        printf("Não foi possível abrir este arquivo.\n");
        exit(-1);
    }
    while(!feof(file)){
        fscanf(file,"%c",&aux);
        if(aux == '\n')
            cont++;
    }
    fclose(file);
    return cont-1;
}

void readf(const char* filename,char * line,const int cont){ //lê o arquivo e copia o conteúdo para a string line
    file = fopen(filename, "r");
    char aux, linha[cont];
    for(int i=0;i<cont;i++){
        fscanf(file, "%c", &aux);
        linha[i] = aux; 
    }
    fclose(file);
    strcpy(line,linha);
}

char* readfBest(const char* filename, const int cont){ //lê o arquivo e retorna o conteúdo, atualizado para uma versão "mais correta"
    file = fopen(filename, "r");
    char aux, *linha = (char*)malloc(cont*sizeof(char));
    for(int i=0;i<cont;i++){
        fscanf(file, "%c", &aux);
        linha[i] = aux; 
    }
    fclose(file);
    return linha;    
}

void tokeia(char *vet, Record *rec){ //Separa os valores em item campo da struct ITEM 
    char *tokeiado;
    const char dell[2] = {'=','\n'};
    char **aux = (char**)malloc(sizeof(char*)*2);
    tokeiado = strtok(vet, dell);
    while(tokeiado != NULL){
        int i;
        for(i = 0;i<2;i++){
            aux[i] = tokeiado;
            tokeiado = strtok(NULL, dell);
        }
        rec->word = aux[0];
        rec->description = aux[1];
        rec++;
    }
}
