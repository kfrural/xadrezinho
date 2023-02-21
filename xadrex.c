#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(int argc, char *argv[])

{

	setlocale(LC_ALL, "portugues");

	void vPeca(char peca);

	void vTabuleiro(char peca[8][8]);

	char saiu(char pecaSaiu, char *pf, char *bf);

	char tabuleiro[8][8], pecaSaiu, pretaSaiu[16] = {'x'}, brancaSaiu[16] = {'x'}, *bf, *pf, pOrigem, pFinal;

	int i, j, pol, poc, pfl, pfc, player = 1;

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
	tabuleiro[6][7] = 'P';
	tabuleiro[7][0] = 't';
	tabuleiro[7][1] = 'c';
	tabuleiro[7][2] = 'b';
	tabuleiro[7][3] = 'q';
	tabuleiro[7][4] = 'k';
	tabuleiro[7][5] = 'b';
	tabuleiro[7][6] = 'c';
	tabuleiro[7][7] = 't';

	printf("\n\n\n\n \t\t|\t\t P=Peao\t\t\t|\n\t\t|\t\t T=Torre\t\t|\n\t\t|\t\t C=Cavalo\t\t|\n\t\t|\t\t B=Bispo\t\t|\n\t\t|\t\t K=Rei\t\t\t|\n\t\t|\t\t Q=Rainha\t\t|\n\t\t\t\t\n");

	for (i = 2; i < 6; i++)
	{

		for (j = 0; j < 8; j++)
		{

			tabuleiro[i][j] = ' ';
		}
	}

	do
	{

		vTabuleiro(tabuleiro);

		do
		{

			if (player == 1)
			{

				printf("\t\t Maiuscula = Branca e minuscula = Preta\n\n");

				printf("JOGADOR 01\nEscolha uma peça Branca aí sô\n");

				do
				{

					printf("Linha : ");

					scanf("%i", &pol);

					printf("Coluna: ");

					scanf("%i", &poc);

					--pol;

					--poc;

					if (!isupper(tabuleiro[pol][poc]))
					{

						printf("Cê é o branco sô!!\n");

						printf("Digite novamente\n");
					}

				} while (!isupper(tabuleiro[pol][poc]));

				do
				{

					printf("\nEscolha onde cê quer a peça\n");

					printf("Linha : ");

					scanf("%i", &pfl);

					printf("Coluna: ");

					scanf("%i", &pfc);

					--pfl;

					--pfc;

					if (isupper(tabuleiro[pfl][pfc]))
					{

						printf("Cê é o preto sô!!\n");

						printf("Digite novamente\n");
					}

				} while (isupper(tabuleiro[pfl][pfc]));

				player = 2;
			}

			else
			{

				printf("JOGADOR 02\nEscolha uma peça preto aí sô\n");

				do
				{

					printf("Linha : ");

					scanf("%i", &pol);

					printf("Coluna: ");

					scanf("%i", &poc);

					--pol;

					--poc;

					if (isupper(tabuleiro[pol][poc]))
					{

						printf("Cê é o preto sô!!\n");

						printf("Digite novamente\n");
					}

				} while (isupper(tabuleiro[pol][poc]));

				do
				{

					printf("\nEscolha onde cê quer a peça\n");

					printf("Linha : ");

					scanf("%i", &pfl);

					printf("Coluna: ");

					scanf("%i", &pfc);

					--pfl;

					--pfc;

					if (!isupper(tabuleiro[pfl][pfc]))
					{

						printf("Cê é o branco sô!!n");

						printf("Digite novamente\n");
					}

				} while (isupper(tabuleiro[pol][poc]));

				player = 1;
			}

			if (tabuleiro[pol][poc] == ' ')

				printf("\nNum tem essa posição não sô\n");

		} while (tabuleiro[pol][poc] == ' ');

		pOrigem = tabuleiro[pol][poc];

		printf("Você escolheu: ");

		vPeca(pOrigem);

		pFinal = tabuleiro[pfl][pfc];

		printf("Você escolheu: ");

		vPeca(pFinal);

		printf("peca dest %c peca or %c \n", pFinal, pOrigem);

		if (!isupper(tabuleiro[pfl][pfc]) && isupper(tabuleiro[pol][poc]) && player == 2)
		{

			pecaSaiu = tabuleiro[pfl][pfc];

			if (tabuleiro[pfl][pfc] == 'k')

				printf("\n\nXEQUE MATE!!!\n\n");

			else if (tabuleiro[pfl][pfc] == ' ')
			{

				tabuleiro[pfl][pfc] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}

			else
			{

				tabuleiro[pfl][pfc] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}
		}

		if (isupper(tabuleiro[pfl][pfc]) && !isupper(tabuleiro[pol][poc]) && player == 1)
		{

			pecaSaiu = tabuleiro[pfl][pfc];

			if (tabuleiro[pfl][pfc] == 'K')

				printf("\n\nXEQUE MATE!!!\n\n");

			else if (tabuleiro[pfl][pfc] == ' ')
			{

				tabuleiro[pfl][pfc] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}

			else
			{

				tabuleiro[pfl][pfc] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}
		}

		printf("Cê removeu: ");

		vPeca(pecaSaiu);

		saiu(pecaSaiu, pf, bf);

		printf("peças retirada foi %c \n", pecaSaiu);

	} while (pecaSaiu != 'k' || pecaSaiu != 'K');
}

void vTabuleiro(char peca[8][8])
{

	int i, j;

	printf("\n\nPeças brancas\n");

	printf("    1   2   3   4   5   6   7   8\n");

	printf("  --------------------------------\n");

	for (i = 0; i < 8; i++)
	{

		printf("%i| ", i + 1);

		for (j = 0; j < 8; j++)
		{

			printf("[%c] ", peca[i][j]);
		}

		printf("\n");
	}

	printf("Peças pretas\n\n");
}

void vPeca(char peca)
{

	printf("\n");

	switch (peca)
	{

	case 'T':

		printf("Torre branca");

		break;

	case 'C':

		printf("Cavalo branco");

		break;

	case 'B':

		printf("Bispo branco");

		break;

	case 'Q':

		printf("Rainha branca");

		break;

	case 'K':

		printf("Rei branco");

		break;

	case 'P':

		printf("Peão branco");

		break;

	case 't': // minusculas branca
		printf("Torre preto");

		break;

	case 'c':

		printf("Cavalo preto");

		break;

	case 'b':

		printf("Bispo preto");

		break;

	case 'q':

		printf("Rainha preto");

		break;

	case 'k':

		printf("Rei preto");

		break;

	case 'p':

		printf("Peão preto");

		break;
	}

	printf("\n");
}

char saiu(char peca, char *pf, char *bf)
{

	int i = 0, nBretiradas = 0, nPretiradas = 0;

	if (isupper(peca))
	{

		nPretiradas++;

		printf("Brancas Retiradas: %i: ", nPretiradas);

		for (i = 0; i < nPretiradas; i++)
		{

			if (pf[i] == 'x')

				pf[i] = peca;

			printf("[%c]", pf[i]);
		}
	}

	else
	{

		nBretiradas++;

		printf("pretas Retiradas: %i: ", nBretiradas);

		for (i = 0; i < nBretiradas; i++)
		{

			if (bf[i] == 'x')

				bf[i] = peca;

			printf("[%c]", bf[i]);

			i++;
		};
	}

	printf("\n");
}
