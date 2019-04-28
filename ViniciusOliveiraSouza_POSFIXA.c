/* CONVERS�O INFIXA-POSFIXA E AVALIA��O POSFIXA */
/*
  Arquivo: ATIVIDADE POSFIXA.c
  Autor: voc�
  Date: 01/11/16 15:39
  Descri��o: Exemplo de leitura de diversas express�es infixas de um arquivo texto
  armazenamento em uma matriz de caracteres, convers�o para nota��o posfixa e
  avalia��o da posfixa.
*/

#include <stdio.h>       // aqui encontram-se as fun��es de io para arquivos e tamb�m o NULL
#include <string.h>      // aqui est�o as fun��es para processar strings
#include "Booleano.h"    // aqui est� a declara��o do tipo bool
#include "PilhaChar.h"   // aqui est� o tipo pilha de caracteres
#include "Token.h"        // obten��o de tokens

#include "PilhaReal.h"   // aqui est� o tipo pilha de reais
#include "ListaR.h"      // aqui est� o tipo lista de reais
#define erro 9999.99

#define pv ';'

//interface
 void mostrar(char m[21][81],int);
 void obterInfixa(char m[21][81],int,int,char p[81]);
 void converter(char A[21],char B[81]);

 float avaliarPosfixa(char B[81],ListaReal);

int main(){
	char linha[81];         	// o array linha � usada como vari�vel de entrada na fun��o fscanf
	char Matrizinfixa[21][81];	// a matriz infixa armazena at� 20 cadeias de caracteres
    char posfixa[81],infixa[81];
	FILE *entrada;          	// entrada � o pointer para o arquivo de entrada

    ListaReal Valores;
    float valor;
	char * tituloINF = "INFIXA";
    char * tituloPOS = "POSFIXA";
    int i,n,lin,col,nlinhas;

    Valores = construirLista(26);
    mostrarLista(Valores);

	entrada = fopen("INFIXA.txt","r");  // o arquivo expInfixa.txt pode conter at� 20 express�es
	if (entrada == NULL) {
                printf("\n arquivo de dados inexistente \n\n");
    }
    else {
        printf("arquivo INFIXA.txt encontrado... ");
        lin = 0; nlinhas = 0;
        while(fscanf(entrada, "%80s", linha)==1){	// l� at� 80 caracteres e guarda da string linha
                   nlinhas = nlinhas +1;    		// conta o n�mero de linhas lidas no arquivo
                   n = strlen(linha);       		// n = comprimento da linha
                   lin = lin + 1;           		// na matriz infixa, a primeira cadeia vai para a linha 1
                   for(i=0;i<=n-1;i++){ 			// cada caractere da string ser� copiado na coluna i da matriz
                       Matrizinfixa[lin][i]=linha[i];
        			} // fim for

        } // fim while
        fclose(entrada);
        printf("numero de linhas = %d \n\n",nlinhas);
        mostrar(Matrizinfixa,nlinhas);
// aqui come�a a convers�o e avalia��o
		printf("\n %25s   %25s\n",tituloINF,tituloPOS);
        for(i=1;i<=nlinhas;i++){
                                obterInfixa(Matrizinfixa,nlinhas,i,infixa);
                                converter(infixa,posfixa);
                                valor = avaliarPosfixa(posfixa,Valores);
                                printf("\n %25s   %25s",infixa,posfixa);
//                                printf("   %f ",valor);
        } // fim for
    } // fim else
    printf("\n\n");
	return 0;
}

//implementa��es

void mostrar(char matriz[11][81],int m){
    int lin,col;
    for(lin=1; lin <= m; lin++){
               col = -1;
               printf("  %4d)  ",lin);
               do {
                   col = col+1;
                   printf("%c",matriz[lin][col]);
               } while (matriz[lin][col] != pv);
               printf("\n");
    } // fim for
    printf("\n");
}

void obterInfixa(char matriz[11][81],int m,int li,char inf[81]){
    int col;
    col = -1;
    if ((li > 0) && (li <= m)){
		do {
          col = col+1;
          inf[col] = matriz[li][col];
    	} while (matriz[li][col] != pv);
    }
    inf[col+1]='\0';
}

void converter(char inf[81],char pos[81]){
    bool ok;
    PilhaCh S;
    TokenIn to,toS;
    int j,col,t;
    char ch,chS;

    j = 0;     t = strlen(inf);   criarPilhaChVazia(&S);

    for(col=0;col<=t;col++){
        ch =  inf[col];   to = obterToken(ch);
        switch (to){
                 case PaE: { pushPilhaCh(&S,to);break;}
                 case OpA: { pushPilhaCh(&S,to);break;}
                 case OpM: { pushPilhaCh(&S,to);break;}
                 case TerM:{ pushPilhaCh(&S,to);break;}
                 case PaD: { pushPilhaCh(&S,to);break;}
                 default:  { pushPilhaCh(&S,to);break;}
        } // fim switch
    } // fim for
    pos[j]='\0';
}


float avaliarPosfixa(char pos[81],ListaReal L){
     float result,v1,v2,v;
     Pilha S;
     int n,i,nP,p;	// nP = tamanho da Posfixa,  n = tamanho da tabela de valores, p = posi��o do caractere na tabela de valores
     char ch;
     TokenIn to;
     n = obterTamanho(L);
     if (n==0) result = erro;
     else {
               criarPilhaVazia(&S);
               nP = strlen(pos);
               for(i=0;i<nP;i++){
                                 ch = pos[i]; to = obterToken(ch);
                                 if (to == Ident) {
                                                  p = ch-64;
                                                  v = obterElemento(L,p);
                                                  pushPilha(&S,v);
                                 }
                                 else {

                                 } // fim else
               }  // fim for
               result = acessarTopo(&S);
     }  // fim else
     return result;
}

