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

	int i, j, pol, poc, lpd, cpd, player = 1;

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

				printf("\t\t Maiuscula = Preta e minuscula = branca\n\n");

				printf("JOGADOR 01\nEscolha uma peça preta aí sô\n");

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

						printf("Cê é o preto sô!!\n");

						printf("Digite novamente\n");
					}

				} while (!isupper(tabuleiro[pol][poc]));

				do
				{

					printf("\nEscolha onde cê quer a peça\n");

					printf("Linha : ");

					scanf("%i", &lpd);

					printf("Coluna: ");

					scanf("%i", &cpd);

					--lpd;

					--cpd;

					if (isupper(tabuleiro[lpd][cpd]))
					{

						printf("Cê é o branco sô!!\n");

						printf("Digite novamente\n");
					}

				} while (isupper(tabuleiro[lpd][cpd]));

				player = 2;
			}

			else
			{

				printf("JOGADOR 02\nEscolha uma peça branca aí sô\n");

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

						printf("Cê é o branco sô!!\n");

						printf("Digite novamente\n");
					}

				} while (isupper(tabuleiro[pol][poc]));

				do
				{

					printf("\nEscolha onde cê quer a peça\n");

					printf("Linha : ");

					scanf("%i", &lpd);

					printf("Coluna: ");

					scanf("%i", &cpd);

					--lpd;

					--cpd;

					if (!isupper(tabuleiro[lpd][cpd]))
					{

						printf("Cê é o preto sô!!n");

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

		pFinal = tabuleiro[lpd][cpd];

		printf("Você escolheu: ");

		vPeca(pFinal);

		printf("peca dest %c peca or %c \n", pFinal, pOrigem);

		if (!isupper(tabuleiro[lpd][cpd]) && isupper(tabuleiro[pol][poc]) && player == 2)
		{

			pecaSaiu = tabuleiro[lpd][cpd];

			if (tabuleiro[lpd][cpd] == 'k')

				printf("\n\nXEQUE MATE!!!\n\n");

			else if (tabuleiro[lpd][cpd] == ' ')
			{

				tabuleiro[lpd][cpd] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}

			else
			{

				tabuleiro[lpd][cpd] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}
		}

		if (isupper(tabuleiro[lpd][cpd]) && !isupper(tabuleiro[pol][poc]) && player == 1)
		{

			pecaSaiu = tabuleiro[lpd][cpd];

			if (tabuleiro[lpd][cpd] == 'K')

				printf("\n\nXEQUE MATE!!!\n\n");

			else if (tabuleiro[lpd][cpd] == ' ')
			{

				tabuleiro[lpd][cpd] = pOrigem;

				tabuleiro[pol][poc] = ' ';
			}

			else
			{

				tabuleiro[lpd][cpd] = pOrigem;

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

	printf("\n\nPeças pretas\n");

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

	printf("Peças brancas\n\n");
}

void vPeca(char peca)
{

	printf("\n");

	switch (peca)
	{

	case 'T':

		printf("Torre preta");

		break;

	case 'C':

		printf("Cavalo preta");

		break;

	case 'B':

		printf("Bispo preta");

		break;

	case 'Q':

		printf("Rainha preta");

		break;

	case 'K':

		printf("Rei preta");

		break;

	case 'P':

		printf("PeC#o preta");

		break;

	case 't': // minusculas branca
		printf("Torre branca");

		break;

	case 'c':

		printf("Cavalo branco");

		break;

	case 'b':

		printf("Bispo branco");

		break;

	case 'q':

		printf("Rainha branca");

		break;

	case 'k':

		printf("Rei branco");

		break;

	case 'p':

		printf("PeC#o branco");

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

		printf("pretas Retiradas: %i: ", nPretiradas);

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

		printf("Brancas Retiradas: %i: ", nBretiradas);

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
