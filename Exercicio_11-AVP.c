/* 
Programa: Exercício 09 - Árvore Vermelha e Preto - Inserção
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define RED 1
#define BLACK 0

typedef struct No{
    int info, cor;
    struct No *esq, *dir;
}TRB;

int cor(TRB *aux){
    if(aux == NULL)
        return BLACK;
    else
        return aux->cor;
}

void trocaCor(TRB *aux){
    aux->cor = !aux->cor;
    if(aux->esq)
        aux->esq->cor = !aux->esq->cor;
    if(aux->dir)
        aux->dir->cor = !aux->dir->cor;
}

TRB* rotacionaEsquerda(TRB *main){
    TRB *aux = main->dir;
    main->dir = aux->esq;
    aux->esq = main;
    aux->cor = main->cor;
    main->cor = RED;
    return aux;
}

TRB* rotacionaDireita(TRB *main){
    TRB* aux = main->esq;
    main->esq = aux->dir;
    aux->dir = main;
    aux->cor = main->cor;
    main->cor = RED;
    return aux;
}

TRB* balancear(TRB* main){
    //  nó Vermelho é sempre filho à esquerda
    if( cor(main->dir) == RED )
        main = rotacionaEsquerda(main);

    //  Filho da direita e neto da esquerda são vermelhos
    if( (main->esq && cor(main->dir) == RED) && (cor(main->esq->esq) == RED) )
        main = rotacionaDireita(main);

    //  2 filhos Vermelhos: troca cor!
    if( (cor(main->esq) == RED) && (cor(main->dir) == RED) )
        trocaCor(main);

    return main;
}

TRB* consulta(TRB *raiz, int num){
    if(raiz){ //verifica se a arvore é nula ou se ja percorreu a arvore toda
        if(num == raiz->info)
            return raiz;
        else if (num<raiz->info)
            return consulta(raiz->esq, num);
        else
            return consulta(raiz->dir, num);
    }
    return NULL;
}

TRB* insereNO(TRB *main, int num, int *resp){
    if(!main){
        TRB *aux = (TRB *)malloc(sizeof(TRB));
        if(!aux){
            *resp = 0;
            return NULL;
        }

        aux->info = num;
        aux->cor = RED;
        aux->dir = aux->esq = NULL;
        *resp = 1;
        return aux;
    }

    if(num == main->info)
        *resp = 0;  //  Valor duplicado
    else{
        if(num < main->info)
            main->esq = insereNO(main->esq, num, resp);
        else
            main->dir = insereNO(main->dir, num, resp);
    }

    //  nó Vermelho é sempre filho à esquerda
    if( (cor(main->dir) == RED) && (cor(main->esq) == BLACK) )
        main = rotacionaEsquerda(main);

    //  Filho e Neto são vermelhos
    //  Filho vira pai de 2 nós vermelhos
    if( (cor(main->esq) == RED) && (cor(main->esq->esq) == RED) )
        main = rotacionaDireita(main);

    //  2 filhos Vermelhos: troca cor!
    if( (cor(main->esq) == RED) && (cor(main->dir) == RED) )
        trocaCor(main);

    return main;
}

int inserir(TRB **main, int num){
    int resp;

    *main = insereNO(*main, num, &resp);
    if(*main)
        (*main)->cor = BLACK;

    return resp;
}

/*int BlackHeight(TRB* aux) { 
     if (aux == NULL)    
           return 1;     
     int leftBlackHeight = BlackHeight(aux->esq); 
     if (leftBlackHeight == 0) 
           return leftBlackHeight; 
     int rightBlackHeight = BlackHeight(aux->dir); 
     if (rightBlackHeight == 0) 
           return rightBlackHeight; 
     if (leftBlackHeight != rightBlackHeight) 
           return 0; 
     else 
           return leftBlackHeight + aux->IsBlack() ? 1 : 0; 
}*/

int altura(TRB *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esqq = altura(raiz->esq);
        int dirr = altura(raiz->dir);
        if(esqq>dirr)
            return esqq+1;
        else
            return dirr+1;
    }
}

int alturaNo (TRB *aux, int chave){// para encontrar o tamanho da árvore a partir de um nó
    TRB *no = consulta (aux, chave);
    if (no)
        return altura(no);
    else    
        return -1; 
}

void printAltura (TRB* aux){
  if (aux->esq == NULL && aux->dir != NULL)
    printf("%d, 0, %d\n", altura(aux), altura(aux->dir));
  else if (aux->dir == NULL && aux->esq != NULL)
    printf("%d, %d, 0\n", altura(aux), altura(aux->esq));
  else if (aux->dir == NULL && aux->esq == NULL)
    printf("%d, 0, 0\n", altura(aux));
  else
    printf("%d, %d, %d\n",altura(aux), altura(aux->esq) + 1, altura(aux->dir) + 1);
}

int main (){

    TRB* arvore = NULL;

    int chave, chave2, chave3;
 
    while (1){ //insere os valores na árvore até q o valor seja negativo
        scanf("%d", &chave);
        if (chave < 0) 
            break;
        inserir(&arvore, chave);
    }
 
    printAltura(arvore); 
    
    while (1){ //busca os valores desejados
        if (chave2 >= 0){
            if (consulta (arvore, chave2))   printAltura(consulta (arvore, chave2));
            //printf("%d, %d, %d\n",altura(consulta (arvore, chave2)), altura(consulta (arvore->esq, chave2)) , altura(consulta (arvore->dir, chave2)) );
        else
            inserir(&arvore, chave2);
 
            scanf("%d", &chave2);
        }
        else        
            break;
    }
    
    scanf("%d", &chave3); //valor q se deseja encontrar a altura
 
    if (consulta(arvore, chave3)) 
        printf("ok");
    else
        printf("Valor nao encontrado");
    
    return 0;
}