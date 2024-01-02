#include "ChessGame.h"

int main()
{
    ChessGame ChessGame;
    ChessGame.criarTabuleiro();
    ChessGame.imprimirTabuleiro(ChessGame.tabuleiro);

   int player = 1;
   do{               
       ChessGame.escolhaJogada(player);
       ChessGame.movimentoDaJogada(ChessGame.l_origem, ChessGame.c_origem, ChessGame.l_destino, ChessGame.c_destino);
       ChessGame.imprimirTabuleiro(ChessGame.tabuleiro);
       player *= -1;   
   }while(true); 

   return 0;
}
