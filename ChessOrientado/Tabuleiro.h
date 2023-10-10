#include <iostream>

using namespcae std;

class Tabuleiro{
    private:
        char tabuleiro[8][8];
    public:
        Tabuleiro();

        char getTabuleiro();
        void setTabuleiro(char tabuleiro[][]);

        void criarTabuleiro();
        void printTabuleiro();
        void movimentoDaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};