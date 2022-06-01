/* 
Programa: Exercício 05 - Quick Sort
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>

void troca(int *i, int *j) {

    int aux = *i;
    *i = *j;
    *j = aux;
}

int particiona(int v[], int inicio, int fim) {
  
    int pivo = v[fim];
    int i = (inicio - 1);

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i + 1], &v[fim]);

    return (i + 1);
}

int quickSort (int v[], int inicio, int fim, int k){

    if (inicio < fim){
        int pivo = particiona (v, inicio, fim);
        if(k < pivo){
            quickSort (v, inicio, pivo - 1, k);}
        else if(pivo < k){ 
            quickSort (v, pivo + 1, fim, k);}
        else 
            return v[k];
    }
}

void print(int v[], int N, int k){

    int i, j = 0;

    while(j < k - 1) 
        j++;

    printf("%do menor elemento eh o %d\n", k, v[j]);

    for(i = 0; i < N; i++) 
        printf("%d ", v[i]);
}

int main(){

    int N, i, v[100000], K;
 
    //xo menor elemento  
    scanf("%d\n", &K);

    //tamanho do vetor
    scanf("%d\n", &N);

    if (N > 1 && N <= 100000){
        for (i = 0; i < N; i++)
            scanf("%d", &v[i]);
    }
    
    quickSort(v, 0, N - 1, K - 1);
    print(v, N, K);

    return 0;
}