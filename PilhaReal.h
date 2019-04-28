/* TAD Pilha = pilha de reais */
/*
  Arquivo: PilhaReal.h
  Autor: Lisbete Madsen Barbosa
  Date: 11/10/09 10:58
  Descrição: Define e implementa o tipo de dados Pilha
  que pode guardar até MaxPilha números reais. 
*/

#include "Booleano.h"
#define MaxPilha 80
#define Sinal 0
#define fantasma -9999.99
typedef struct {
      int topo;
      float tabela[MaxPilha];
} Pilha;

/* construtores */
void criarPilhaVazia(Pilha *);
/* acesso */
float acessarTopo(Pilha *);
bool verificarPilhaVazia(Pilha *);
bool verificarPilhaCheia(Pilha *);
/* manipulação */
void pushPilha(Pilha *, float);
void popPilha(Pilha *);


void criarPilhaVazia(Pilha *ap){
     ap->topo = Sinal;
}


float acessarTopo(Pilha *ap){
    int k;
    float y;
    if (ap->topo == Sinal) y = fantasma;
    else {k = ap->topo - 1; y = ap->tabela[k];}
    return y;
}     

bool verificarPilhaVazia(Pilha *ap){
     bool vazia;
     if (ap->topo == Sinal) vazia = TRUE; else vazia = FALSE;
     return vazia;
}

bool verificarPilhaCheia(Pilha *ap){
     bool cheia;
     if (ap->topo == MaxPilha) cheia = TRUE; else cheia = FALSE;
     return cheia;
}

void pushPilha(Pilha *ap, float y){
     int k;
     if(ap->topo != MaxPilha){
                 k = ap->topo;
                 ap->tabela[k] = y;
                 ap->topo = k + 1;
     }
}

void popPilha(Pilha *ap){
     int k;
     if (ap->topo != Sinal){
                   k = ap->topo;
                   ap->topo = k-1;
     }                   
}

