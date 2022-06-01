/* 
Programa: Exercício 08 - Árvore Binária de Busca
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/
#include <stdio.h>
#include <stdlib.h>
int flag; 

typedef struct no{ 
    int valor;
    struct no *direita, *esquerda, *pai;
}NoArv;

void printTree (NoArv *aux){
    if (aux != NULL){
        printTree (aux->esquerda);
        printf("%d ", aux->valor);
        printTree(aux->direita);
    }
}

NoArv* inserir(NoArv *raiz, int num, int pai){ 
    if(raiz == NULL){ //se o nó é raiz ou está no local certo pra inserir após recursão
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        aux->pai = pai;
        //printf("endereco: %d ", aux);
        //printf("pai: %d\n", aux->pai);
        return aux;
    }
    else{
        if(num < raiz->valor){ //se o valor for menor, será inserido na esquerda
            int pai = raiz;
            raiz->esquerda = inserir(raiz->esquerda, num, pai); 
        }
        else{
            int pai = raiz; 
            raiz->direita = inserir(raiz->direita, num, pai);
        }
        
        return raiz;
    }
}

NoArv* busca(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor) //quando encontrar o valor, retorna
            return raiz;
        else if(num < raiz->valor) //se o valor buscado for menor q o valor atual, eu busco na esquerda
            return busca(raiz->esquerda, num);
        else
            return busca(raiz->direita, num);
    }
    return NULL;
}

// o problema aqui são os dangling pointers após remoção
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                //raiz->pai->direita = NULL;
                //raiz->pai->esquerda = NULL;
                raiz = NULL;
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    NoArv *aux = raiz->direita;
                    while(aux->esquerda != NULL)
                        aux = aux->esquerda;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    raiz->direita = remover(raiz->direita, chave);
                    return raiz;
                }
                else{ int x;
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL){ x = 0;
                        aux = raiz->esquerda;
                    }
                    else{ x = 1;
                        aux = raiz->direita;
                    }
                    /*if (x = 0)
                        raiz->pai->esquerda = NULL;
                    else 
                        raiz->pai->direita = NULL;*/
                    free(raiz);
                    raiz = NULL;
                    return aux;
                }
            }
        } else { //aqui buscamos o valor
            if(chave < raiz->valor) //se o valor a remover for menor q o nó atual, mando o nó da esquerda
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

int alturaDoNo(NoArv *raiz){ //retorna a maior altura da arvore a partir da raiz
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = alturaDoNo(raiz->esquerda); 
        int dir = alturaDoNo(raiz->direita);
        if(esq > dir){
            flag = 0;
            return esq+1; 
        }
        else{
            flag = 1;
            return dir+1;
        }
    }
}

int alturaMenor(NoArv *raiz){ //retorna a menor altura da arvore a partir da raiz
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = alturaDoNo(raiz->esquerda); 
        int dir = alturaDoNo(raiz->direita);
        if(esq < dir){
            return esq+1; 
        }
        else
            return dir+1;
    }
}

int alturaNo (NoArv *aux, int chave){// para encontrar o tamanho da árvore a partir de um nó
    NoArv *no = busca (aux, chave);
    if (no)
        return alturaDoNo (no);
    else {
        printf("Valor nao encontrado");
        flag = 2;
        return -1;
    }
}

int alturaNoMenor (NoArv *aux, int chave){ //para encontrar o menor tamanho de um nó
    NoArv*no = busca (aux, chave);
    if (no)
        return alturaMenor (no);
    else {
        printf("Valor nao encontrado");
        flag = 2;
        return -1;
    }
}

int main(){ 

    NoArv *arvore = NULL;

    int chave, chave2, chave3;

    while (1){ //insere os valores na árvore até q o valor seja negativo
        scanf("%d", &chave);
        if (chave < 0) 
            break;
        arvore = inserir(arvore, chave, NULL);
    }

    int r = alturaDoNo(arvore); //r é a altura máxima da árvore
    printf("%d,", r);

    //esq deve ser printado primeiro
    if(flag == 0) //se flag = 0, esq é o valor maior (igual ao valor máx)
        printf(" %d, %d\n", r, alturaMenor(arvore));
    else if(flag == 1) //se flag = 1, esq é o valor menor
        printf(" %d, %d\n", alturaMenor(arvore), r); 

    printTree(arvore); printf("\n");
    
    while (1){ //busca os valores desejados, se encontrados são retirados, se não são inseridos
        if (chave2 >= 0){
            if (busca (arvore, chave2))
                arvore = remover (arvore, chave2);
            else
                arvore = inserir(arvore, chave2, NULL);

            scanf("%d", &chave2);
        }
        else        
            break;
    }

    scanf("%d", &chave3); //valor q se deseja encontrar a altura

    int r2 = alturaNo(arvore, chave3);
    
    if (flag != 2){ //se o valor desejado estiver na árvore
        printf("%d,", r2);
        if(flag == 0)
            printf(" %d, %d\n", r2, alturaNoMenor(arvore, chave3));
        else if(flag == 1)
            printf(" %d, %d\n", alturaNoMenor(arvore, chave3), r2);
    }
    //printTree(arvore);
    
    return 0;
}