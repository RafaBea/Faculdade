/*
==================================================================================

                               Jogo da Forca

==================================================================================
Empresa: Nome da empresa:TechTwo
Equipe de Programadores:
               Nome do Primeiro: Rafaela Beatriz Gutierrez Oliveira RA: 191009
               Nome do segundo: Bianca R. R. Cesaretto RA: 180155

Curso: Engenharia de Computação
Data de início do projeto: 01/12/2022
----------------------------------------------------------------------------------
Descrição do Programa:
		Esse programa foi realizado a partir da linguagem de programação C. Nosso objetivo foi criar um
		jogo da forca, onde dois usuários podem participar e se divertir com o desafio. Nós utilizamos
		diversas funções, sendo algumas delas os laços de repetição e vetores. Nós tivemos que utilizar
		outras bibliotecas para conseguirmos utilizar a função strings e utilizar os acentos que temos
		na língua portuguesa.
Versão do programa: 1.4
Melhorias da versão: Melhorias na funcao jogo, no procedimento forma, melhorias na parte estética do jogo,
					 melhorias na funcao main, também foram adicionados novos comentários e a correção de
					 bugs no switch() case, da funcao main.
Data de lançamento da versão: 09/12/22
==================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

//FUNCAO MENU.
void menu()
{
    setlocale(LC_ALL, "Portuguese");

	printf("J O G O    D A");
	printf("\t\n______");
	printf("\t\n|     |");
	printf("\t\n|     O");
	printf("\t\n|    /|\\");
	printf("\t\n|    / \\");
	printf("\t\n|");
	printf("\t\n|");
	printf("\t\n| F O R C _\n");

	printf("\t\t\n\n[COMO JOGAR-1]\n");
	printf("\t\t\n  [JOGAR-2]\n");
	printf("\nJogador informe uma opção [1]ou[2]: ");
}

//FUNÇÃO REGRAS.
int regras()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao, escolha=1;
	
	while(escolha==1)
	{
		system("cls");
		printf("\n----------------------------------------------  REGAS E INSTRUÇÕES  -------------------------------------------------");
		printf("\n1- O Jogo da Forca permite apenas 2 participantes.\n");
		printf("\n2- Os jogadores devem escolher, entre si, quem será o jogador 1 e quem será o jogador 2.\n");
		printf("\n3- Após feita a escolha, o JOGADOR 1 deve propor um tema e, sem o JOGADOR 2 olhar, deve escrever uma palavra secreta.\n");
		printf("\n4- O JOGADOR 2 deve informar letras, na tentativa de acertar a palavra.\n"); 
		printf("\n5- O JOGADOR 2 pode errar no máximo 7 letras, caso ele nao acerte a palavra, o JOGADOR 1 ganha a partida.\n"); 
		printf("\n6- Caso o JOGADOR 2 acerte a palavra antes de cometer 7 erros, ele ganha. Caso contrario, perde.\n");
		printf("\n7- Se estão prontos? Se aceitaram o desafio, então eu lhes desejo boa sorte e cuidado para não se enforcarem......\n");
		printf("\n---------------------------------------------------------------------------------------------------------------------");
		printf("\n\n[VOLTAR-1]\n");
		printf("\nJogador informe uma opção [1]: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:	
				return opcao;
				break;
		default:
			system("cls");
			printf("\nEscolha invalida!");
			printf("\n\n[VOLTAR-1]\n");
			printf("\nJogador informe uma opção [1]: ");
			scanf("%d", &opcao);
			if(opcao ==1)
			{
				return opcao;
			}
			
		}
	}
	return opcao;	
}

//PROCEDIMENTO VIDA - mostra a situaçao da forca conforme os erros.
void forma(int vida)
{
	if(vida==0)
	{
		printf("\t\n_________");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
	}
	if(vida==1)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
	}
	else if(vida==2)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|       O");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
	}
	else if(vida==3)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|       O");
		printf("\t\n|       |");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
	}
	else if(vida==4)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|       O");
		printf("\t\n|      /|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");	
	}
	else if(vida==5)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|       O");
		printf("\t\n|      /|\\");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");	
	}
	else if(vida==6)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|       O");
		printf("\t\n|      /|\\");
		printf("\t\n|      /");
		printf("\t\n|");
		printf("\t\n|");
		printf("\t\n|");	
	}
	else if(vida==7)
	{
		printf("\t\n_________");
		printf("\t\n|       |");
		printf("\t\n|       O");
		printf("\t\n|      /|\\");
		printf("\t\n|      / \\");
		printf("\t\n|");
		printf("\t\n|   JOGARDOR 2");
		printf("\t\n|  VOCE PERDEU!\n");	
	}
}

//PROCEDIMENTO LET_JA_DIG
void let_ja_dig(char letra[], int tam)
{
	int i;
	printf("\n\nLetras já informadas: \n");
	for(i=0;i<tam;i++)
	{
		printf("%c ", letra[i]);
	}
	printf("\n");
}
//FUNÇÃO VERIFICA_LETRA
int verifica_letra(char letra, char letras[30])
{
	int i=0;
	for(i=0;i<30;i++)
	{
		if(letra==letras[i])
		{
			return 1;
		}
	}
	return 0;
}
//FUNCAO JOGO.
int jogo()
{
	setlocale(LC_ALL, "Portuguese");

    //DECLARANDO VARIÁVEIS.
    char pal_secreta[100], tema[50], linha[100], espaco[100], letras_digitadas[30];
    char letra, resp;
    int forca, i, erro=0, tentativa=0, chances=7, n_erro=0, cont_let=0;

	//REQUERINDO O TEMA E A PALAVRA SECRETA.
	system("cls");
	printf("\n\tJOGADOR 1:\n");
	printf("\nInforme o tema: ");
	fgets(tema,50,stdin);
	fflush(stdin);
	printf("\nAgora, jogador 2 informe a palavra secreta: ");
	fgets(pal_secreta,100,stdin);
	fflush(stdin);

	//REMOVENDO O CARACTERE \0 QUE ESTA A MAIS NA VARIÁVEL PAL_SECRETA.
	pal_secreta[strlen(pal_secreta)-1] = '\0';

	//ATRIBUINDO EM STRINGS O "-" E "_" DE ACORDO COM A QUANTIDADE DE LETRAS E ESPAÇOS NA PAL_SECRETA.
	strcpy(linha, pal_secreta);

	while(pal_secreta[i]!='\0')
	{
		if(pal_secreta[i]==' ')
		{
			espaco[i] = '-';
		}
		else
		{
			linha[i] = '_';
		}
		i++;
	}
	
		//COMEÇANDO O JOGO.
	while(1)
	{
		//MOSTRANDO O TEMA.
		system("cls");
		printf("TEMA: %s", tema);
		//MOSTRANDO AS CHANCES RESTANTES DO JOGADOR 2.
		printf("\n\tJOGADOR 2:\n");
		printf("\nSuas chances restantes: %d\n ", chances);
		forma(tentativa);
		printf("\n");
		
		//MOSTRANDO NA TELA O "_" E "-".
		for(int i=0;i<strlen(linha);i++)
		{
		
			if(linha[i]==' ')
			{
				printf("- ");
			}
			else
			{
				printf("%c ", linha[i]);
			}
		}
		//CHAMANDO A FUNÇÃO LET_JA_DIG.
		let_ja_dig(letras_digitadas,cont_let);
	
		//REQUERINDO UMA LETRA DO JOGADOR 2.
		printf("\n\nJogador 2, informe uma letra: ");
		scanf(" %c", &resp);
		resp= tolower(resp);
		
		//VERIFICANDO SE A LETRA JA FOI INFORMADA ANTERIORMENTE.
		if(verifica_letra(resp,letras_digitadas))
		{
			printf("\nEssa letra ja foi informada, tente informar outra!\n");
			system("pause");
			n_erro--;
			erro--;
			chances++;	
			tentativa--;
	
		}
		else
		{
			letras_digitadas[cont_let]= resp;
			cont_let++;
		}
		
		//VERIFICANDO SE A LETRA INFORMADA PERTENCE A PALAVRA SECRETA.
		int acerto_ou_erro=1;
		for(int i=0;i<strlen(linha);i++)
		{
			if(resp==pal_secreta[i])
			{
				linha[i]=resp;
				acerto_ou_erro=0;//Se o jogador acertar a letra, acerto_ou_erro recebe 0, se não, continua valendo 1.
			}
		}
		
		//ATUALIZANDO OS VALORES DE CHANCE, ERRO, N_ERRO E TENTATIVA, CASO O JOGADOR 2 TENHA ERRADO.
		if(acerto_ou_erro==1)
		{
			n_erro++;
			erro++;
			chances--;	
			tentativa++;
		}
		//VERIFICANDO SE O JOGADOR 2 ACERTOU A PALAVRA.
		if(strcmp(linha,pal_secreta)==0)
		{
			//SE SIM, O JOGO ACABA E O JOGADOR 2 GANHA.
			system("cls");
			printf("\nO JOGADOR 2 GANHOU, PARABÉNS!\n");
			printf("\nA palavra era: %s\n", pal_secreta);
			printf("\nErros do jogador 2: %d", n_erro);
			forma(tentativa);
			break;
		}
		//VERIFICANDO SE O JOGADOR CHEGOU NO MÁXIMO DE ERROS.
		if(erro==7)
		{
			//SE SIM, O JOGO ACABA E O JOGADOR 1 GANHA.
			system("cls");
			printf("O JOGADOR 1 GANHOU, PARABÉNS!\n");
			printf("\nA palavra era: %s\n", pal_secreta);
			printf("\nErros do jogador 2: %d", n_erro);
			forma(tentativa);
			break;
		}
	}
	return forca;
}

//FUNÇÃO MAIN	
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	//DECLARAÇÃO DE VARIÁVEIS
	int escolha=1, opcao;
	
	menu();//CHAMANDO A FUNÇÃO MENU.
	
	//REQUERINDO AO JOGADOR UMA OPÇÃO DO MENU.
	scanf("%d", &opcao);
	fflush(stdin);
	
	//CÓDIGO, QUE DE ACORDO COM A OPCAO ESOLHIDA, IRÁ CHAMAR A FUNÇÃO REGRAS OU A FUNÇÃO JOGO.
	while(escolha)
	{
		switch(opcao)
		{
			case 1:
				regras();
				system("cls");
				return main();
				break;
			
			case 2:
				jogo();
				escolha=0;
				break;
		default:
			printf("\nOpção inválida!");
			printf("\nDigite uma opção novamente: \n\n");
			main();	

		}	
	}
	
	return 0;
}
