/* 
Programa: Exercício 1
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include <stdio.h>

//função que verifica se o número é primo
int ehPrimo (int X){

    int divisor, cont = 0;

    if (X > 0){
        for (divisor = 1; divisor <= X; divisor++){
        
            if ((X % divisor) == 0)
                cont++;  
        }  
    
        if (cont == 2)
            return 1;
        else    
            return 0;
    }
}

int main (){

    int N, i = 1, X;
 
    //printf("Quantas acoes deseja realizar?\n");
    scanf("%d\n", &N);
 
    while(i <= N && N <= 10){
            
        scanf("%d", &X);

        if (ehPrimo(X) == 1)
            printf("%d 1\n", X);
        else
            printf("%d 0\n", X); 

        i++;
    }
}