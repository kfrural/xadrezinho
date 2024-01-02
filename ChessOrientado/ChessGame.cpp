#include "ChessGame.h"



void ChessGame::imprimirTabuleiro(char peca[8][8]) {
   cout<<"\n\nPeças brancas"<<endl;
    cout<<"    1   2   3   4   5   6   7   8"<<endl;
    cout<<"  --------------------------------"<<endl;
    for(int i=0;i<8;i++){
        cout<<i+1<<"| ";
        for(int j=0;j<8;j++){
            cout<<"["<<peca[i][j]<<"] ";
        }
        cout<<endl;
    }
    cout<<"Peças pretas\n"<<endl;
}

void ChessGame::criarTabuleiro() {
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
    
    cout<<"\n\n\n\n \t\t|\t\t P=Peao\t\t\t|\n\t\t|\t\t T=Torre\t\t|\n\t\t|\t\t C=Cavalo\t\t|\n\t\t|\t\t B=Bispo\t\t|\n\t\t|\t\t K=Rei\t\t\t|\n\t\t|\t\t Q=Rainha\t\t|\n\t\t\t\t"<<endl;
    

    for(int i=2;i<6;i++){
        for(int j=0;j<8;j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

bool ChessGame::verificaJogadorTimeCorreto(int l, int c, int player) {
    if(isupper(tabuleiro[l][c])==1 && player == 1){
        return true;
    }else{
        return false;
    }
}

bool ChessGame::verificarMovimentoPeao(int l_origem, int c_origem, int l_destino, int c_destino) {
   int player = isupper(tabuleiro[l_origem][c_origem]) ? 1 : -1;
    int direcao = player > 0 ? 1 : 1;

    if(l_destino == l_origem + direcao){
        if(c_destino == c_origem && tabuleiro[l_destino][c_destino] == ' '){
            return true;
        }else if(abs(c_destino - c_origem) == 1 && isupper(tabuleiro[l_destino][c_destino]) != player){
            return true;
        }
    }else if(l_destino == l_origem + 2 * direcao && l_origem == 1 && tabuleiro[l_origem + direcao][c_origem] == ' ' && tabuleiro[l_destino][c_destino] == ' '){
        return true;
    }

    return false;
}

bool ChessGame::verificarMovimentoTorre(int l_origem, int c_origem, int l_destino, int c_destino) {
    if(l_destino == l_origem || c_destino == c_origem){
        int movimento_l = (l_destino > l_origem) - (l_destino < l_origem);
        int movimento_c = (c_destino > c_origem) - (c_destino < c_origem);

        for(int l = l_origem + movimento_l, c = c_origem + movimento_c; l != l_destino || c != c_destino; l += movimento_l, c += movimento_c){
            if(tabuleiro[l][c] != ' '){
                return false;
            }
        }

        return true;
    }

    return false;
}

bool ChessGame::verificarMovimentoCavalo(int l_origem, int c_origem, int l_destino, int c_destino) {
   int movimento_l = abs(l_destino - l_origem);
    int movimento_c = abs(c_destino - c_origem);

    if((movimento_l == 2 && movimento_c == 1) || (movimento_l == 1 && movimento_c == 2)){
        if(tabuleiro[l_destino][c_destino] == ' ' || isupper(tabuleiro[l_origem][c_origem]) != isupper(tabuleiro[l_destino][c_destino])){
            return true;
        }
    }

    return false;
}

bool ChessGame::verificarMovimentoBispo(int l_origem, int c_origem, int l_destino, int c_destino) {
   int movimento_l = abs(l_destino - l_origem);
    int movimento_c = abs(c_destino - c_origem);

    if(movimento_l == movimento_c){
        int movimento_l_dir = (l_destino > l_origem) - (l_destino < l_origem);
        int movimento_c_dir = (c_destino > c_origem) - (c_destino < c_origem);

        for(int l = l_origem + movimento_l_dir, c = c_origem + movimento_c_dir; l != l_destino || c != c_destino; l += movimento_l_dir, c += movimento_c_dir){
            if(tabuleiro[l][c] != ' '){
                return false;
            }
        }

        return true;
    }

    return false;
}

bool ChessGame::verificarMovimentoRainha(int l_origem, int c_origem, int l_destino, int c_destino) {
   int movimento_l = abs(l_destino - l_origem);
    int movimento_c = abs(c_destino - c_origem);

    if(movimento_l == movimento_c){
        int movimento_l_dir = (l_destino > l_origem) - (l_destino < l_origem);
        int movimento_c_dir = (c_destino > c_origem) - (c_destino < c_origem);

       for(int l = l_origem + movimento_l_dir, c = c_origem + movimento_c_dir; l != l_destino || c != c_destino; l += movimento_l_dir, c += movimento_c_dir){
            if(tabuleiro[l][c] != ' '){
                return false;
            }
        }

        return true;
    }

    if(l_destino == l_origem || c_destino == c_origem){
        int movimento_l_dir = (l_destino > l_origem) - (l_destino < l_origem);
        int movimento_c_dir = (c_destino > c_origem) - (c_destino < c_origem);

       for(int l = l_origem + movimento_l_dir, c = c_origem + movimento_c_dir; l != l_destino || c != c_destino; l += movimento_l_dir, c += movimento_c_dir){
            if(tabuleiro[l][c] != ' '){
                return false;
            }
        }

        return true;
    }

    return false;
}

bool ChessGame::verificarMovimentoRei(int l_origem, int c_origem, int l_destino, int c_destino) {
   int movimento_l = abs(l_destino - l_origem);
    int movimento_c = abs(c_destino - c_origem);

    if((movimento_l <= 1 && movimento_c <= 1) && (movimento_l != 0 || movimento_c != 0)){
        return true;
    }

    return false;
}

void ChessGame::escolhaJogada(int player) {
    char pecaSaiu;
    bool movimentoValido = false;
    do{
        if(player ==1){
            cout<<"\t\t Maiuscula = Branca e minuscula = Preta\n"<<endl;
			cout<<"JOGADOR 01\nEscolha uma peça Branca aí sô"<<endl;
			do{
			    cout << "Linha origem : ";
                cin >> l_origem;
                cout <<"Coluna origem: ";
                cin >> c_origem;
                --l_origem;
                --c_origem;
                if(l_origem < 0 || c_origem < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                } 
                if(!isupper(tabuleiro[l_origem][c_origem])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout<<"Digite novamente"<<endl;
                }  
			}while(!isupper(tabuleiro[l_origem][c_origem]));
			do{
			    cout << "Linha destino : ";
                cin >> l_destino;
                cout <<"Coluna destino: ";
                cin >> c_destino;
                --l_destino;
                --c_destino;
                if(l_destino < 0 || c_destino < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                }
                if(isupper(tabuleiro[l_destino][c_destino])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout<<"Digite novamente"<<endl;
                }
                char peca = tabuleiro[l_origem][c_origem];
                switch (peca){
                    case 'P':
                        movimentoValido = verificarMovimentoPeao(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'T':
                        movimentoValido = verificarMovimentoTorre(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'C':
                        movimentoValido = verificarMovimentoCavalo(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'B':
                        movimentoValido = verificarMovimentoBispo(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'Q':
                        movimentoValido = verificarMovimentoRainha(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'K':
                        movimentoValido = verificarMovimentoRei(l_origem, c_origem, l_destino, c_destino);
                        break;
                    default:
                        movimentoValido = false;
                        break;
                }

                if(!movimentoValido){
                    cout << "Movimento invalido para a peca selecionada!" << endl;
                }

            }while(!movimentoValido);
			player = -1;
			system("clear");
        }else{
            cout<<"JOGADOR 02\nEscolha uma peça preto aí sô"<<endl;
            do{
                cout << "Linha origem : ";
                cin >> l_origem;
                cout <<"Coluna origem: ";
                cin >> c_origem;
                --l_origem;
                --c_origem;
                if(l_origem < 0 || c_origem < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                } 
                if(isupper(tabuleiro[l_origem][c_origem])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout<<"Digite novamente"<<endl;
                } 
            }while(isupper(tabuleiro[l_origem][c_origem]));
            do{
               cout << "Linha destino : ";
                cin >> l_destino;
                cout <<"Coluna destino: ";
                cin >> c_destino;
                --l_destino;
                --c_destino;
                if(l_destino < 0 || c_destino < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                }
                if(!isupper(tabuleiro[l_destino][c_destino])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout <<"Digite novamente"<<endl;
                } 
                char peca = tabuleiro[l_origem][c_origem];
                switch (peca){
                    case 'P':
                        movimentoValido = verificarMovimentoPeao(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'T':
                        movimentoValido = verificarMovimentoTorre(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'C':
                        movimentoValido = verificarMovimentoCavalo(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'B':
                        movimentoValido = verificarMovimentoBispo(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'Q':
                        movimentoValido = verificarMovimentoRainha(l_origem, c_origem, l_destino, c_destino);
                        break;
                    case 'K':
                        movimentoValido = verificarMovimentoRei(l_origem, c_origem, l_destino, c_destino);
                        break;
                    default:
                        movimentoValido = false;
                        break;
                }

                if(movimentoValido){
                    cout << "Movimento invalido para a peca selecionada!" << endl;
                }
            }while(isupper(tabuleiro[l_destino][c_destino]));
            player =1;
            system("clear");
        }
        if(tabuleiro[l_origem][c_origem] == ' ')
        cout<<"\nNum tem essa posição não sô"<<endl;
    }while(tabuleiro[l_origem][c_origem] == ' ');
    if(!isupper(tabuleiro[l_destino][c_destino]) && isupper(tabuleiro[l_origem][c_origem]) && player == -1){
        pecaSaiu = tabuleiro[l_destino][c_destino];
        if(tabuleiro[l_destino][c_destino] == 'k')
            cout<<"\n\nXEQUE MATE!!!\n"<<endl;
    }
    if(isupper(tabuleiro[l_destino][c_destino]) && !isupper(tabuleiro[l_origem][c_origem]) && player == 1){
        pecaSaiu = tabuleiro[l_destino][c_destino];
        if(tabuleiro[l_destino][c_destino] == 'K')
            cout<<"\n\nXEQUE MATE!!!\n"<<endl;
    }
    if(pecaSaiu == 'k' || pecaSaiu == 'K'){
		    exit(0);
		}

}

void ChessGame::movimentoDaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
   char peca = tabuleiro[linhaOrigem][colunaOrigem];    
    tabuleiro[linhaDestino][colunaDestino] = peca;

    //limpar local antigo
    tabuleiro[linhaOrigem][colunaOrigem] = ' ';
}
