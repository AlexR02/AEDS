// driver code 
#include "red_black.h"

const char* arquivo = "palavras.txt";

int main(){

    int caracteres = countChar(arquivo);
    int linhas = countLine(arquivo);
    char *palavra = readfBest(arquivo, caracteres);
    Record *itens = (Record*)malloc(sizeof(Record)*linhas);
    tokeia(palavra,itens);

	for (int i = 0; i < linhas; i++) { 

		//newNode(Record r) serve apenas para inicializar um novo node
		Node *temp = newNode(itens[i]);
        //printf("\n\n%s: %s", temp->record.word, temp->record.description);
		// calling function that performs bst insertion of 
		// this newly created node 
		setRoot(insert(getRoot(), temp)); 

		// calling function to preserve properties of rb 
		// tree 
		insertFixup(getRoot(), temp); 
	} 

	int opcoes = 1;

	while(opcoes != 0){
		printf("Escolha uma das opções para a visualização do dicionário:\n");
		printf("0 - Sair do menu de impressão\n");
		printf("1 - Imprime o dicionário em ordem alfabética(Caminhamento central)\n");
		printf("2 - Caminhamento pré-ordem\n");
		printf("3 - Caminhamento pós-ordem\n");
		printf("4 - Árvore em 2d\n");
		printf("5 - Escolha uma palavra para para ver seu significado\n");
		printf("\nOpção: ");
		scanf("%d", &opcoes);
		switch (opcoes){
			case 1:{
				printf("Caminhamento central\n");
				central(getRoot());
				printf("\n\n");
			}break;

			case 2:{
				printf("Caminhamento pré-ordem\n");
				preOrdem(getRoot());
				printf("\n\n");
			}break;

			case 3:{
				printf("Caminhamento pós-ordem\n");
				posOrdem(getRoot());
				printf("\n\n");
			}break;

			case 4:{
				printf("Árvore em 2d\n");
				print2D(getRoot());
			}break;

			case 5:{
				printf("Escolha a palavra: \n\n");
				central(getRoot());
				printf("\n\n");
				char *word = (char*)malloc(sizeof(char));
				printf("Insira sua escolha(EM MAIÚSCULO) >> ");
				scanf("%s", word);
				Record aux = search(word);
				printf("\n%s: %s\n\n", aux.word, aux.description);
			}break;

			case 0:{
				printf("\nSaindo do menu!!\n\n");
			}break;

			default:
				printf("\nOpção inválida. Escolha novamente\n\n");
			break;
		}
	}
	return 0; 
}
