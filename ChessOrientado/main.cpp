#include "ChessGame.h"

int main()
{
   criarTabuleiro();
   imprimirTabuleiro(tabuleiro);

   int player = 1;
   do{               
       escolhaJogada(player);
       movimentoDaJogada(l_origem, c_origem, l_destino, c_destino);
       imprimirTabuleiro(tabuleiro);
       player *= -1;   
   }while(true); 

   return 0;
}
