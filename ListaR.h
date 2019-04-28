/* TAD ListaReal */
/*
  Arquivo: ListaR.h
  Autor: Pato Donald
  Date: 09/09/13 13:17
  Descrição: Implementa o tipo Lista de números reais.
*/
#define fantasmareal -9999.99
#include "Booleano.h"
#define Max 30
typedef struct {
        int comprimento;
        float tabela[Max];
} ListaReal;

//Interface
    ListaReal criarLista();                        // criar uma lista vazia
    ListaReal construirLista(int);             // está pronta    				
    int obterTamanho(ListaReal);                   // obter o tamanho da lista	
    float obterElemento(ListaReal, int);             // obter o item de ordem p		
    void mostrarLista(ListaReal);                  // está pronta
    bool verificarListaVazia(ListaReal);
    ListaReal inserirNoFim(ListaReal,float);          // inserir um item no final da lista			


//Implementações

ListaReal criarLista(){
          ListaReal L;
          L.comprimento = 0;
          return L;
}

ListaReal construirLista(int n){
         ListaReal listaA;
         int i,t;
         if (n==0)listaA.comprimento = n;
         else {
               if((n > 0) && (n < Max))t = n; 
               else t = Max-1;
               listaA.comprimento = t;
               for(i=1;i<=t;i++) listaA.tabela[i] = i;
         }
         return listaA;
}

bool verificarListaVazia(ListaReal L){
     bool vazia;
     vazia = FALSE;
     if (L.comprimento == 0) vazia = TRUE;
     return vazia;
}

void mostrarLista(ListaReal s1){
     int k, n;
     n = s1.comprimento;
     if (n==0) printf(" \n lista vazia \n");
     else { 
            printf("\n"); 
            for(k=1;k<=n;k++)printf(" %.2f ", s1.tabela[k]);
     }
     printf("\n");
}


int obterTamanho(ListaReal L){
    int c;
    c = L.comprimento;
    return c;
}

float obterElemento(ListaReal L, int p){
    float item;
    int t;
    t = L.comprimento;
    if((p>=1)&&(p<=t)) item = L.tabela[p]; else item = fantasmareal;    
    return item;
}

ListaReal inserirNoFim(ListaReal L,float y){
         int t;
         t = L.comprimento;
         L.tabela[t+1] = y;
         L.comprimento = t+1;
         return L;
}
