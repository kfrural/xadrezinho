#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <iostream>
#include <cctype>

using namespace std;

class ChessGame {
    public:
        void imprimirTabuleiro(char peca[8][8]);
        void criarTabuleiro();
        bool verificaJogadorTimeCorreto(int l, int c, int player);
        bool verificarMovimentoPeao(int l_origem, int c_origem, int l_destino, int c_destino);
        bool verificarMovimentoTorre(int l_origem, int c_origem, int l_destino, int c_destino);
        bool verificarMovimentoCavalo(int l_origem, int c_origem, int l_destino, int c_destino);
        bool verificarMovimentoBispo(int l_origem, int c_origem, int l_destino, int c_destino);
        bool verificarMovimentoRainha(int l_origem, int c_origem, int l_destino, int c_destino);
        bool verificarMovimentoRei(int l_origem, int c_origem, int l_destino, int c_destino);
        void escolhaJogada(int player);
        void movimentoDaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

    
        char tabuleiro[8][8];
        int l_origem, l_destino, c_origem, c_destino;

};

#endif
