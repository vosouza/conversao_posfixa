/* função obterToken, comando switch e tipo enumerado */
/*
  Arquivo: Token.h
  Autor: Lisbete Madsen Barbosa
  Date: 11/10/09 10:34
  Descrição: Define o tipo enumerado TokenIn e implementa
  a função obterToken que serve para identificar o tipo de
  caractere em uma expressão.
*/

#include <stdio.h>

typedef enum{PaE,PaD,OpA,OpM,Ident,TerM} TokenIn;

TokenIn obterToken(char);
void mostrarTipos();

void mostrarTipos(){
     char ch;
     TokenIn to;
     printf("Tipos definidos em TokenIn: \n\n");
     for(to=PaE; to<=TerM; to++){
        switch (to){
              case PaE: printf("tipo %d - PaE   = Parenteses Esquerdo \n",to);break;
              case PaD: printf("tipo %d - PaD   = Parenteses Direito  \n",to);break;
              case OpA: printf("tipo %d - OpA   = Operador Aditivo (+ ou -) \n",to);break;
              case OpM: printf("tipo %d - OpM   = Operador Multiplicativo (* ou /) \n",to);break;
              case Ident: printf("tipo %d - Ident = Identificador (letra) \n",to);break;
              case TerM: printf("tipo %d - TerM  = Terminal (ponto e virgula ;) \n",to);
               }
     printf("\n");
     }
}

TokenIn obterToken(char ch){
        TokenIn result;
        switch (ch){
              case '(': result = PaE;break;
              case ')': result = PaD;break;
              case ';': result = TerM;break;
              case '*': result = OpM;
              case '/': result = OpM;break;
              case '+': result = OpA;
              case '-': result = OpA;break;
              default: result = Ident;
               }
        return result;
}
