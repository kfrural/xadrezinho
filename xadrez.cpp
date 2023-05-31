#include <iostream>
#include <ctype.h>

using namespace std;
void vTabuleiro(char peca[8][8]){
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

void vPeca(char peca){
	cout<<"\n"<<endl;
	switch (peca){
	case 'T':
		cout<<"Torre branca"<<endl;
		break;
	case 'C':
        cout<<"Cavalo branco"<<endl;
        break;
	case 'B':
		cout<<"Bispo branco"<<endl;
		break;
	case 'Q':
		cout<<"Rainha branca"<<endl;
		break;
	case 'K':
		cout<<"Rei branco"<<endl;
		break;
	case 'P':
		cout<<"Peão branco"<<endl;
		break;
	case 't': // minusculas branca
		cout<<"Torre preto"<<endl;
		break;
	case 'c':
		cout<<"Cavalo preto"<<endl;
		break;
	case 'b':
		cout<<"Bispo preto"<<endl;
		break;
	case 'q':
		cout<<"Rainha preto"<<endl;
		break;
	case 'k':
		cout<<"Rei preto"<<endl;
		break;
	case 'p':
		cout<<"Peão preto"<<endl;
		break;
	}
	cout<<endl;
}
void saiu(char peca, char *bf, char *pf){
	int nPretiradas=0;
	int nBretiradas=0;
	if (isupper(peca))//verifica se esse trem ta maiusculo ou n
	{
		nBretiradas++;
		cout<<"Brancas Retiradas: "<<nBretiradas<<endl;
		for (int i=0;i<nBretiradas;i++){
			if (bf[i] == 'x')
				bf[i] = peca;
			cout<<"[%c]"<<bf[i]<<endl;
		}
	}else{
		nPretiradas++;
		cout<<"pretas Retiradas: "<<nPretiradas<<endl;
		for (int i=0;i<nPretiradas;i++){
			if (pf[i] == 'x')
				pf[i] = peca;
			cout<<"[%c]"<<pf[i]<<endl;
		};
	}
	cout<<endl;
}

int main()
{
    void vPeca(char peca);
	void vTabuleiro(char peca[8][8]);
	void saiu(char pecaSaiu, char *pf, char *bf);
	char tabuleiro[8][8];
	char pecaSaiu;
	char pretaSaiu[16] = {'x'};
	char brancaSaiu[16] = {'x'};
	char *bf;
	char *pf;
	char pOrigem;
	char pFinal;
	int pol=0;
	int poc=0;
	int pfl=0;
	int pfc=0;
	int player=1;
	pf = pretaSaiu;
	bf = brancaSaiu;

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
	do{
		vTabuleiro(tabuleiro);
		do{
			if (player == 1){
				cout<<"\t\t Maiuscula = Branca e minuscula = Preta\n"<<endl;
				cout<<"JOGADOR 01\nEscolha uma peça Branca aí sô"<<endl;
				do{
					cout<<"Linha : ";
					cin>>pol;
					cout<<"Coluna: ";
					cin>>poc;
					--pol;
					--poc;
					if (!isupper(tabuleiro[pol][poc])){
						cout<<"Cê é o branco sô!!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				} while (!isupper(tabuleiro[pol][poc]));
				do{
					cout<<"\nEscolha onde cê quer a peça"<<endl;
					cout<<"Linha : ";
					cin>>pfl;
					cout<<"Coluna: ";
					cin>>pfc;
					--pfl;
					--pfc;
					if (isupper(tabuleiro[pfl][pfc])){
						cout<<"Cê é o preto sô!!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				} while (isupper(tabuleiro[pfl][pfc]));
				player=2;
			}else{
				cout<<"JOGADOR 02\nEscolha uma peça preto aí sô"<<endl;
				do{
					cout<<"Linha : ";
					cin>>pol;
					cout<<"Coluna: ";
					cin>>poc;
					--pol;
					--poc;
					if (isupper(tabuleiro[pol][poc])){
						cout<<"Cê é o preto sô!!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				}while(isupper(tabuleiro[pol][poc]));
				do{
					cout<<"\nEscolha onde cê quer a peça"<<endl;
					cout<<"Linha : ";
					cin>>pfl;
					cout<<"Coluna: ";
					cin>>pfc;
					--pfl;
					--pfc;
					if(!isupper(tabuleiro[pfl][pfc]))
					{
						cout<<"Cê é o branco sô!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				}while(isupper(tabuleiro[pol][poc]));
				player=1;
			}
			if (tabuleiro[pol][poc] == ' ')
				cout<<"\nNum tem essa posição não sô"<<endl;
		} while (tabuleiro[pol][poc] == ' ');
		pOrigem = tabuleiro[pol][poc];
		cout<<"Você escolheu: ";
		vPeca(pOrigem);
		pFinal = tabuleiro[pfl][pfc];
		cout<<"Você escolheu: ";
		vPeca(pFinal);
		if (!isupper(tabuleiro[pfl][pfc]) && isupper(tabuleiro[pol][poc]) && player == 2){
			pecaSaiu = tabuleiro[pfl][pfc];
			if (tabuleiro[pfl][pfc] == 'k')
				cout<<"\n\nXEQUE MATE!!!\n"<<endl;
			else if (tabuleiro[pfl][pfc] == ' '){
				tabuleiro[pfl][pfc] = pOrigem;
				tabuleiro[pol][poc] = ' ';
			}else{
				tabuleiro[pfl][pfc] = pOrigem;
				tabuleiro[pol][poc] = ' ';
			}
		}
		if (isupper(tabuleiro[pfl][pfc]) && !isupper(tabuleiro[pol][poc]) && player == 1){
			pecaSaiu = tabuleiro[pfl][pfc];
			if (tabuleiro[pfl][pfc] == 'K')
				cout<<"\n\nXEQUE MATE!!!\n"<<endl;
			else if (tabuleiro[pfl][pfc] == ' '){
				tabuleiro[pfl][pfc] = pOrigem;
				tabuleiro[pol][poc] = ' ';
			}else{
				tabuleiro[pfl][pfc] = pOrigem;
				tabuleiro[pol][poc] = ' ';
			}
		}
		cout<<"Cê removeu: ";
		vPeca(pecaSaiu);
		saiu(pecaSaiu, bf, pf);
		cout<<"peças retirada foi "<<pecaSaiu;
	} while (pecaSaiu != 'k' || pecaSaiu != 'K');


    return 0;
}
