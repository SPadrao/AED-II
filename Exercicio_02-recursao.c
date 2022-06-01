/* 
Programa: Exercício 2
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>
int v;

int compra (int d, int p){

    if (d >= p){
        return d/p;
    }
}

int vale (int livros, int vales){

    if (v > vales){
        return livros;
    } 
    else{
        livros++;
        vales -= v - 1;
        vale(livros, vales);
    }
}

int main (){

    long int N, d, p, i = 1, livrosD, livrosV;
 
    //printf("Quantas acoes deseja realizar?\n");
    scanf("%d\n", &N);
 
    while(i <= N && N <= 10){
            
        scanf("%d %d %d", &d, &p, &v);

        livrosD = compra(d, p); 
        
        livrosV = vale(livrosD, livrosD); 
        
        printf("%d\n", livrosV);

        i++;
    }
    return 0;
}