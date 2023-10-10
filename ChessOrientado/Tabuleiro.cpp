#include "Tabuleiro.h"

Tabuleiro:: Tabuleiro(){
    tabuleiro[][];
}

char Tabuleiro:: getTabuleiro(){
    return tabuleiro[][];
}

void Tabuleiro:: setTabuleiro(char tabuleiro[][]){
    this-> tabuleiro[][] = tabuleiro[][];
}

void Tabuleiro:: criarTabuleiro(){
    tabuleiro[0][0] = 'T'; // torre
    tabuleiro[0][1] = 'C'; // cavalo
    tabuleiro[0][2] = 'B'; // bispo
    tabuleiro[0][3] = 'Q'; // rainha
    tabuleiro[0][4] = 'K'; // rei
    tabuleiro[0][5] = 'B'; // bispo
    tabuleiro[0][6] = 'C';
    tabuleiro[0][7] = 'T';
    tabuleiro[1][0] = 'P'; // peão
    tabuleiro[1][1] = 'P';
    tabuleiro[1][2] = 'P';
    tabuleiro[1][3] = 'P';
    tabuleiro[1][4] = 'P';
    tabuleiro[1][5] = 'P';
    tabuleiro[1][6] = 'P';
    tabuleiro[1][7] = 'P';
    tabuleiro[6][0] = 'p';
    tabuleiro[6][1] = 'p';
    tabuleiro[6][2] = 'p';
    tabuleiro[6][3] = 'p';
    tabuleiro[6][4] = 'p';
    tabuleiro[6][5] = 'p';
    tabuleiro[6][6] = 'p';
    tabuleiro[6][7] = 'p';
    tabuleiro[7][0] = 't';
    tabuleiro[7][1] = 'c';
    tabuleiro[7][2] = 'b';
    tabuleiro[7][3] = 'q';
    tabuleiro[7][4] = 'k';
    tabuleiro[7][5] = 'b';
    tabuleiro[7][6] = 'c';
    tabuleiro[7][7] = 't';
    
    cout << "\n\n\n\n \t\t|\t\t P=Peao\t\t\t|\n\t\t|\t\t T=Torre\t\t|\n\t\t|\t\t C=Cavalo\t\t|\n\t\t|\t\t B=Bispo\t\t|\n\t\t|\t\t K=Rei\t\t\t|\n\t\t|\t\t Q=Rainha\t\t|\n\t\t\t\t" << endl;
    

    for(int i = 2; i < 6; i++){
        for(int j = 0; j < 8; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void Tabuleiro::printTabuleiro(){
    cout << "\n\nPeças brancas" << endl;
    cout << "    1   2   3   4   5   6   7   8" << endl;
    cout << "  --------------------------------" << endl;
    for(int i = 0; i < 8; i++){
        cout << i+1 << "| ";
        for(int j = 0; j < 8; j++){
            cout << "[" << peca[i][j] << "] ";
        }
        cout << endl;
    }
    cout << "Peças pretas\n" << endl;
}

void Tabuleiro:: movimentoDaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
     char peca = tabuleiro[linhaOrigem][colunaOrigem];    
    tabuleiro[linhaDestino][colunaDestino] = peca;

    //limpar local antigo
    tabuleiro[linhaOrigem][colunaOrigem] = ' ';
}