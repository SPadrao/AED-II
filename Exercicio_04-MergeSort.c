/* 
Programa: Exercício 04 - Inspirado em Merge Sort
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>
int cont = 0;

void pares (int v[], int inicio, int meio, int fim, int k){

  int i = meio, j = fim;

  //dividido em 2, compararemos o da esquerda com o da direita
  while (inicio <= i && meio + 1 <= j){ 
    if(v[j] * k < v[i] & inicio <= i){ //atendendo os requisitos, incrementamos o contador
      cont += j - (meio + 1) + 1; //se um elemento da esquerda pode fazer par com um da direita, todos da direita...
      //...antes dele também fazem par. ex: [0 1 5] [1 2 4]: se 5 faz par com 4, também faz com quem está antes dele
      i--;
    }
    else if (meio + 1 <= j)
      j--;
  }
}

void merge (int v[], int inicio, int meio, int fim, int k){

  int x = inicio, y = meio + 1, aux = 0, vaux[fim - inicio + 1];
 
  //faz a comparação para ordenar
  while(x <= meio && y <= fim){
    if(v[x] <= v[y]){
      vaux[aux] = v[x];
      x++;
    }
    else{
      vaux[aux] = v[y];
      y++; 
    }
    aux++; 
  }
 
  //se sobrou elementos na esquerda
  while(x <= meio){ 
    vaux[aux] = v[x];
    aux++;x++; 
  }
 
  //se sobrou elementos na direita
  while(y <= fim){ 
    vaux[aux] = v[y];
    aux++;y++; 
  }

  //joga o vetor ordenado do vaux no vetor original
  for(aux = inicio; aux <= fim; aux++) 
    v[aux] = vaux[aux - inicio];
}
  
//aqui, iremos dividir em 2 o nosso vetor, depois fazer os pares, e por ultimo, ordenar
void mergeSort(int v[], int inicio, int fim, int k){

  if (inicio < fim) {
    
    int meio = inicio + (fim - inicio) / 2;
  
    mergeSort(v, inicio, meio, k);
    mergeSort(v, meio + 1, fim, k);

    pares(v, inicio, meio, fim, k);
  
    merge(v, inicio, meio, fim, k);
  }
}

int main(){

  int N, i, v[100000], K;
 
  //tamanho do vetor
  scanf("%d\n", &N);

  //inteiro
  scanf("%d\n", &K);

  if (N > 1 && N <= 100000){
      for (i = 0; i < N; i++){
          scanf("%d", &v[i]);
      }
  }

  mergeSort (v, 0, N - 1, K);

  /*for(i = 0; i < N; i++) 
    printf("%d ", v[i]);*/

  printf("%d", cont);

  return 0;
}