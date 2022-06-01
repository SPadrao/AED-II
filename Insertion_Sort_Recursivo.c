/* 
Programa: Insertion Sort Recursivo
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>
int cont = 0;

void insertionSortRecursivo (int sequencia[], int N, int x){

    int aux, i;
    
    if(N <= 1)
        return;
    
    insertionSortRecursivo(sequencia, N - 1, x);

    aux = sequencia[N - 1];
    i = N - 2;
    
    cont++;
    x -= cont;
    printf("%d ", x); 
    printf("%d ", aux);

    while(i >= 0 && sequencia[i] > aux){
        sequencia[i + 1] = sequencia[i];
        i--;
    }
    
    sequencia[i + 1] = aux;
    printf("%d\n", i + 1);
}

void mostraSequencia (int sequencia[], int N){

    int i;

    for(i = 0; i < N; i++)
        printf("%d ", sequencia[i]);
}

int main()
{
    int N, i, sequencia[1000], x;
 
    //tamanho do vetor
    scanf("%d\n", &N);
    x = N;

    if (N > 0 && N <= 1000){
        for (i = 0; i < N; i++){
            scanf("%d", &sequencia[i]);
        }
    }

    insertionSortRecursivo(sequencia, N, x);
    mostraSequencia(sequencia, N);

    return 0;
}
