/* TAD PilhaCh = pilha de caracteres */
/*
  Arquivo: PilhaChar.h
  Autor: Lisbete Madsen Barbosa
  Date: 11/10/09 10:34
  Descrição: Define e implementa o tipo de dados PilhaCh
  que pode guardar até MaxPilha caracteres.
*/

#include "Booleano.h"
#define MaxPilhaCh 80
#define ghost '$'
#define Sinal 0
typedef struct {
      int topo;
      char tabela[MaxPilhaCh];
} PilhaCh;

/* construtores */
void criarPilhaChVazia(PilhaCh *);
/* acesso */
char acessarTopoPilhaCh(PilhaCh *);
bool verificarPilhaChVazia(PilhaCh *);
bool verificarPilhaChCheia(PilhaCh *);
/* manipulação */
void pushPilhaCh(PilhaCh *, char);
void popPilhaCh(PilhaCh *);


void criarPilhaChVazia(PilhaCh *ap){
     ap->topo = Sinal;
}

char acessarTopoPilhaCh(PilhaCh *ap){
    int k;
    char x;
    if (ap->topo == Sinal) x = ghost;
    else {k = ap->topo - 1; x = ap->tabela[k];}
    return x;
}     

bool verificarPilhaChVazia(PilhaCh *ap){
     bool vazia;
     if (ap->topo == Sinal) vazia = TRUE; else vazia = FALSE;
     return vazia;
}

bool verificarPilhaChCheia(PilhaCh *ap){
     bool cheia;
     if (ap->topo == MaxPilhaCh) cheia = TRUE; else cheia = FALSE;
     return cheia;
}

void pushPilhaCh(PilhaCh *ap, char ch){
     int k;
     if(ap->topo != MaxPilhaCh){
                 k = ap->topo;
                 ap->tabela[k] = ch;
                 ap->topo = k + 1;
     }
}

void popPilhaCh(PilhaCh *ap){
     int k;
     if (ap->topo != Sinal){
                   k = ap->topo;
                   ap->topo = k-1;
     }                   
}

