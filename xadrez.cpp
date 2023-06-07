#include <iostream>
#include<stdlib.h>

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
void saiu(char peca, char *brancaFora, char *pretaFora){
	int pretasRetiradas=0;
	int brancasRetiradas=0;
	if (isupper(peca)){//verifica se esse trem ta maiusculo ou n
		brancasRetiradas++;
		cout<<"Brancas Retiradas: "<<brancasRetiradas<<endl;
		for (int i=0;i<brancasRetiradas;i++){
			if (brancaFora[i] == 'x')
				brancaFora[i] = peca;
			cout<<brancaFora[i]<<endl;
		}
	}else{
		pretasRetiradas++;
		cout<<"pretas Retiradas: "<<pretasRetiradas<<endl;
		for (int i=0;i<pretasRetiradas;i++){
			if (pretaFora[i] == 'x')
				pretaFora[i] = peca;
			cout<<pretaFora[i]<<endl;
		}
	}
	cout<<endl;
}
char tabuleiro[8][8];

void printTabuleiro(){
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
	
}



int main()
{
    void vPeca(char peca);
	void vTabuleiro(char peca[8][8]);
	void saiu(char pecaSaiu, char *pretaFora, char *brancaFora);
	char pecaSaiu;
	char pretaSaiu[16] = {'x'};
	char brancaSaiu[16] = {'x'};
	char *brancaFora;
	char *pretaFora;
	char pOrigem;
	char pFinal;
	int pecaOrigemLinha=0;
	int pecaOrigemColuna=0;
	int pecaFinalLinha=0;
	int pecaFinalColuna=0;
	int player=1;
	pretaFora = pretaSaiu;
	brancaFora = brancaSaiu;
	
	printTabuleiro();
	
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
					cin>>pecaOrigemLinha;
					cout<<"Coluna: ";
					cin>>pecaOrigemColuna;
					--pecaOrigemLinha;
					--pecaOrigemColuna;
					if (!isupper(tabuleiro[pecaOrigemLinha][pecaOrigemColuna])){
						cout<<"Cê é o branco sô!!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				} while (!isupper(tabuleiro[pecaOrigemLinha][pecaOrigemColuna]));
				do{
					cout<<"\nEscolha onde cê quer a peça"<<endl;
					cout<<"Linha : ";
					cin>>pecaFinalLinha;
					cout<<"Coluna: ";
					cin>>pecaFinalColuna;
					--pecaFinalLinha;
					--pecaFinalColuna;
					if (isupper(tabuleiro[pecaFinalLinha][pecaFinalColuna])){
						cout<<"Cê é o preto sô!!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				} while (isupper(tabuleiro[pecaFinalLinha][pecaFinalColuna]));
				player=2;
				system("clear");
			}else{
				cout<<"JOGADOR 02\nEscolha uma peça preto aí sô"<<endl;
				do{
					cout<<"Linha : ";
					cin>>pecaOrigemLinha;
					cout<<"Coluna: ";
					cin>>pecaOrigemColuna;
					--pecaOrigemLinha;
					--pecaOrigemColuna;
					if (isupper(tabuleiro[pecaOrigemLinha][pecaOrigemColuna])){
						cout<<"Cê é o preto sô!!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				}while(isupper(tabuleiro[pecaOrigemLinha][pecaOrigemColuna]));
				do{
					cout<<"\nEscolha onde cê quer a peça"<<endl;
					cout<<"Linha : ";
					cin>>pecaFinalLinha;
					cout<<"Coluna: ";
					cin>>pecaFinalColuna;
					--pecaFinalLinha;
					--pecaFinalColuna;
					if(!isupper(tabuleiro[pecaFinalLinha][pecaFinalColuna])){
						cout<<"Cê é o branco sô!"<<endl;
						cout<<"Digite novamente"<<endl;
					}
				}while(isupper(tabuleiro[pecaFinalLinha][pecaFinalColuna]));
				player=1;
				system("clear");
			}
			if (tabuleiro[pecaOrigemLinha][pecaOrigemColuna] == ' ')
				cout<<"\nNum tem essa posição não sô"<<endl;
		}while(tabuleiro[pecaOrigemLinha][pecaOrigemColuna] == ' ');
		pOrigem = tabuleiro[pecaOrigemLinha][pecaOrigemColuna];
		pFinal = tabuleiro[pecaFinalLinha][pecaFinalColuna];
		if (!isupper(tabuleiro[pecaFinalLinha][pecaFinalColuna]) && isupper(tabuleiro[pecaOrigemLinha][pecaOrigemColuna]) && player == 2){
			pecaSaiu = tabuleiro[pecaFinalLinha][pecaFinalColuna];
			if (tabuleiro[pecaFinalLinha][pecaFinalColuna] == 'k')
				cout<<"\n\nXEQUE MATE!!!\n"<<endl;
			else if (tabuleiro[pecaFinalLinha][pecaFinalColuna] == ' '){
				tabuleiro[pecaFinalLinha][pecaFinalColuna] = pOrigem;
				tabuleiro[pecaOrigemLinha][pecaOrigemColuna] = ' ';
			}else{
				tabuleiro[pecaFinalLinha][pecaFinalColuna] = pOrigem;
				tabuleiro[pecaOrigemLinha][pecaOrigemColuna] = ' ';
			}
		}
		
		if (isupper(tabuleiro[pecaFinalLinha][pecaFinalColuna]) && !isupper(tabuleiro[pecaOrigemLinha][pecaOrigemColuna]) && player == 1){
			pecaSaiu = tabuleiro[pecaFinalLinha][pecaFinalColuna];
			if (tabuleiro[pecaFinalLinha][pecaFinalColuna] == 'K')
				cout<<"\n\nXEQUE MATE!!!\n"<<endl;
			else if (tabuleiro[pecaFinalLinha][pecaFinalColuna] == ' '){
				tabuleiro[pecaFinalLinha][pecaFinalColuna] = pOrigem;
				tabuleiro[pecaOrigemLinha][pecaOrigemColuna] = ' ';
			}else{
				tabuleiro[pecaFinalLinha][pecaFinalColuna] = pOrigem;
				tabuleiro[pecaOrigemLinha][pecaOrigemColuna] = ' ';
			}
		}
		if(pecaSaiu == 'k' || pecaSaiu == 'K'){
		    exit(0);
		}
	}while (pecaSaiu != 'k' || pecaSaiu != 'K');
    
    return 0;
}
