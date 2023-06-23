#include <iostream>
#include<stdlib.h>

using namespace std;

char tabuleiro[8][8];
int l_origem, l_destino, c_origem, c_destino;

void imprimirTabuleiro(char peca[8][8]){
    cout<<"\n\nPeças brancas"<<endl;
    cout<<"    1   2   3   4   5   6   7   8"<<endl;
    cout<<"  --------------------------------"<<endl;
    for (int i=0;i<8;i++){
        cout<<i+1<<"| ";
        for (int j=0;j<8;j++){
            cout<<"["<<peca[i][j]<<"] ";
        }
        cout<<endl;
    }
    cout<<"Peças pretas\n"<<endl;
}

/*
    cria o tabuleiro com as pecas na posicao inicial
*/
void criarTabuleiro(){
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
    

    for (int i=2;i<6;i++){
        for (int j=0;j<8;j++){
            tabuleiro[i][j] = ' ';
        }
    }

}

bool verificaJogadorTimeCorreto(int l, int c, int player){
    if (isupper(tabuleiro[l][c])==1 && player == 1){
        return true;
    }else{
        return false;
    }
}

void escolhaJogada(int player){
    char pecaSaiu;
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
                if (l_origem < 0 || c_origem < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                } 
                if(!isupper(tabuleiro[l_origem][c_origem])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout<<"Digite novamente"<<endl;
                }  
			}while (!isupper(tabuleiro[l_origem][c_origem]));
			do{
			    cout << "Linha destino : ";
                cin >> l_destino;
                cout <<"Coluna destino: ";
                cin >> c_destino;
                --l_destino;
                --c_destino;
                if (l_destino < 0 || c_destino < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                }
                if(isupper(tabuleiro[l_destino][c_destino])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout<<"Digite novamente"<<endl;
                }
			}while(isupper(tabuleiro[l_destino][c_destino]));
			player = -1;
			system("clear");
        }else {
            cout<<"JOGADOR 02\nEscolha uma peça preto aí sô"<<endl;
            do{
               cout << "Linha origem : ";
                cin >> l_origem;
                cout <<"Coluna origem: ";
                cin >> c_origem;
                --l_origem;
                --c_origem;
                if (l_origem < 0 || c_origem < 0 ){
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
                if (l_destino < 0 || c_destino < 0 ){
                    cout <<"Posicao invalida"<<endl;
                    cout <<"Digite novamente"<<endl;
                }
                if(!isupper(tabuleiro[l_destino][c_destino])){ 
                    cout <<"Voce esta mexendo em peca que nao eh sua!"<<endl;
                    cout<<"Digite novamente"<<endl;
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



void movimentoDaJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    char peca = tabuleiro[linhaOrigem][colunaOrigem];    
    tabuleiro[linhaDestino][colunaDestino] = peca;

    //limpar local antigo
    tabuleiro[linhaOrigem][colunaOrigem] = ' ';

}



/*
    - criar Tabuleiro
    - imprimirTabuleiro
    - Comecao o jogo
         -  Jogador 1, escolhe jogada
            - pecaOrigem
            - pecaFinal
         -  movimentoDaJogada
         -  Jogador 2, escolhe jogada
         -  movimentoDaJogada

*/


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
    }while(true); //este é do-while da dinamica do jogo
    
    return 0;
}
