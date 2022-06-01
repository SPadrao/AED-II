/* 
Programa: Exercício 13 - Tabela Hash
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>
#include <stdlib.h>
int TAM;

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));
    No *aux = l->inicio; 

    if(novo){
        novo->chave = valor;
        novo->proximo = NULL;

        if(l->tam == 0){
            l->inicio = novo;
            l->tam++;
        }
        else{ 
            while(aux->proximo != NULL) 
                aux = aux->proximo;
            aux->proximo = novo;        
        }
    }
}

No* retirar_na_lista(Lista *l, int valor){
    No *aux, *remover = NULL;

    if(l->inicio){
        if(l->inicio->chave == valor){
            remover = l->inicio;
            l->inicio = remover->proximo;
            l->tam--;
        }
        else{
            aux = l->inicio;
            while(aux->proximo && aux->proximo->chave != valor)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                l->tam--;
            }
        }
    }

    return remover;
}

int buscar_na_lista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor)
        aux = aux->proximo;
    if(aux)
        return aux->chave;
    return 0;
}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    //printf(" Tam: %d: ", l->tam);
    while(aux){
        printf(" %d", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[]){
    int i;

    for(i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_na_lista(&t[id], valor);
}

void retirar(Lista t[], int valor){
    int id = funcaoHash(valor);
    retirar_na_lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}

void imprimir(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}  

void printJudge (Lista t[], int num){
    int id = funcaoHash(num);
    printf("[%d]", num);
    imprimir_lista (&t[id]);
}

int main (){

    int chave, chave2, chave3, M; 	

    scanf("%d", &M);
    TAM = M;
    Lista tabela[M];

    inicializarTabela(tabela);
 
    while (1){ //insere os inputs até ser negativo
        scanf("%d", &chave);
        if (chave < 0) 
            break;
        
        inserir(tabela,chave);
    }
    
    scanf("%d", &chave2); //busca o input: se achar remove, se n printa a mensagem
    if (busca(tabela, chave2) == chave2)
        retirar(tabela, chave2);
    else
        printf("Valor nao encontrado\n");
    
    scanf("%d", &chave3); 
    printJudge(tabela, chave3);//printa a linha na tabela

    return 0;
}