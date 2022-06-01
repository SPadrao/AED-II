/* 
Programa: Jogo das Bolhas
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>
#include <stdlib.h>
int cont = 0;

int bubbleSort (int sequencia[], int N){

    int i, j, aux;

    for(i = 0; i < N; i++){
        for (j = 0; j < N - 1 - i;j++){
            if (sequencia[j] > sequencia[j + 1]){
                aux = sequencia[j];
                sequencia[j] = sequencia[j + 1];
                sequencia[j + 1] = aux;
                cont++;
            }
        }
    }

    return cont;
}

int main (){

    int N, i, sequencia[1000];
 
    //tamanho do vetor
    scanf("%d\n", &N);

    if (N > 0 && N <= 1000){
        for (i = 0; i < N; i++){
            scanf("%d", &sequencia[i]);
        }
    }
    
    if (bubbleSort(sequencia, N) % 2 == 0){
        for (i = 0; i < N; i++){
            printf("%d ", sequencia[i]);
        }
        printf("\nCarlos");
    }
    else{
        for (i = 0; i < N; i++){
            printf("%d ", sequencia[i]);
        }
        printf("\nMarcelo");
    }
    
    return 0;
}