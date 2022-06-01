/* 
Programa: Exercício 14 - Árvore B
Sabrina Santos Padrão RA:150544
ICT - UNIFESP - N
*/

#include<stdlib.h>
#include<stdio.h>
#define M 2
#define MM  (M * 2) //Ordem -1
#define FALSE 0
#define TRUE  1
int cont = 0;
int flag = 0;

typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;

typedef struct TipoPagina* TipoApontador;
typedef struct TipoPagina {
  short n;
  TipoRegistro r[MM];
  TipoApontador p[MM + 1];
} TipoPagina;

void Inicializa(TipoApontador *Dicionario)
{  *Dicionario = NULL; }

void Pesquisa(TipoRegistro *x, TipoApontador Ap)
{ long i = 1;
  if (Ap == NULL) 
  { printf("Valor nao encontrado\n");
    flag = 1;
    return;
  }
  while (i < Ap->n && x->Chave > Ap->r[i-1].Chave) i++;
  if (x->Chave == Ap->r[i-1].Chave) 
  { *x = Ap->r[i-1];
    return;
  }
  if (x->Chave < Ap->r[i-1].Chave) 
  Pesquisa(x, Ap->p[i-1]);
  else Pesquisa(x, Ap->p[i]);
} 

void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir)
{ short NaoAchouPosicao;
  int k;
  k = Ap->n;  NaoAchouPosicao = (k > 0);
  while (NaoAchouPosicao) 
    { if (Reg.Chave >= Ap->r[k-1].Chave) 
      { NaoAchouPosicao = FALSE;
        break;
      }
      Ap->r[k] = Ap->r[k-1];
      Ap->p[k+1] = Ap->p[k];
      k--;
      if (k < 1) NaoAchouPosicao = FALSE;
    }
  Ap->r[k] = Reg; 
  Ap->p[k+1] = ApDir;
  Ap->n++;
} 

void Ins(TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno,  TipoApontador *ApRetorno)
{ long i = 1; // Posição provavel do vetor em que novo indice sera inserido
  long j;
  TipoApontador ApTemp;

  if (Ap == NULL) // Critério de parada da recursão. Pode ser usado para arvore vazia, arvore com espaço em folhas ou arvore que explode
  { *Cresceu = TRUE; (*RegRetorno) = Reg; (*ApRetorno) = NULL;
    return;
  }

  while (i < Ap->n && Reg.Chave > Ap->r[i-1].Chave)  i++; // Percorrendo vetores dos nós para encontrar valor maior (ou igual) que o novo indice
  
  if (Reg.Chave == Ap->r[i-1].Chave) 
  { printf(" Erro: Registro ja esta presente\n"); *Cresceu = FALSE;
    return;
  }

  if (Reg.Chave < Ap->r[i-1].Chave) i--; // Como o valor nao é igual, só pode ser maior, entao volta-se uma posição

  Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno); // Chama-se recursivo para descer na arvore

  if (!*Cresceu) return;

  if (Ap->n < MM)   /* Pagina tem espaco */
    { InsereNaPagina(Ap, *RegRetorno, *ApRetorno); // Chama insere na página pq tem esoaço
      *Cresceu = FALSE;
      return;
    }

  /* Overflow: Pagina tem que ser dividida */ // Página nao tem espaço suficiente
  ApTemp = (TipoApontador)malloc(sizeof(TipoPagina)); // Cria nova pagina pra ser raiz da subarvore que vem do split
  ApTemp->n = 0;  ApTemp->p[0] = NULL; // Ela começa com zero indices e primeiro filho pra NULL
    if (i < M + 1) 
    { InsereNaPagina(ApTemp, Ap->r[MM-1], Ap->p[MM]);
      Ap->n--;
      InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    } 
    else InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
    for (j = M + 2; j <= MM; j++) 
      InsereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j]);
    Ap->n = M;  ApTemp->p[0] = Ap->p[M+1];
    *RegRetorno = Ap->r[M];  *ApRetorno = ApTemp;
}

void Insere(TipoRegistro Reg, TipoApontador *Ap)
{ short Cresceu;
  TipoRegistro RegRetorno;
  TipoPagina *ApRetorno, *ApTemp;
  Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno); // Chamando funcao insere auxiliar
  if (Cresceu)  /* Arvore cresce na altura pela raiz */
  { ApTemp = (TipoPagina *)malloc(sizeof(TipoPagina)); // Criando nova raiz
    ApTemp->n = 1;  // Definindo que a nova raiz só terá um índice
    ApTemp->r[0] = RegRetorno; // Definindo valor do unico indice da raiz
    ApTemp->p[1] = ApRetorno; // Definindo filho da direita da raiz, resultado do split que causou explosao no tamanho
    ApTemp->p[0] = *Ap;   // Definindo filho da esquerda da raiz, resultado do split que causou explosao no tamanho 
    *Ap = ApTemp; // Enderençando nova raiz
  }
}

void contaElementos(TipoApontador p, int nivel, TipoRegistro x)
{ long i; int flag2 = 0;
  if (p == NULL) return;

  for (i = 0; i < p->n; i++){
    if (p->r[i].Chave == x.Chave)
      flag2 = 1;
  }

  if (flag2 == 1)
    cont = i;

  nivel++;
  for (i = 0; i <= p->n; i++)
    contaElementos(p->p[i], nivel, x);
} 

void conta(TipoApontador p, TipoRegistro x)
{ int  n = 0; contaElementos(p, n, x); } 

void ImprimeR(TipoApontador p, int nivel)
{ long i; int cont2 = 0;
  if (p == NULL) return;
  
  for (i = 0; i < p->n; i++)
    cont2++;
  
  printf("%d\n", cont2);
} 

void ImprimeRaiz(TipoApontador p)
{ int  n = 0; ImprimeR(p, n); }  

int main(){

  TipoRegistro x;
  TipoPagina *D;
  Inicializa(&D);

  scanf("%ld", &x.Chave);
  getchar();

  while (x.Chave >= 0){
    Insere(x, &D);
    scanf("%ld", &x.Chave);
    getchar();
  }
  ImprimeRaiz(D);
  
  scanf("%ld", &x.Chave);
  getchar();

  Pesquisa(&x, D);
  conta(D, x);

  if(flag == 0)
    printf("%d", cont);
  
  return 0;
}