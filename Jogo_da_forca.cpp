/*
==================================================================================

                               Jogo da Forca

==================================================================================
Empresa: Nome da empresa:TechTwo
Equipe de Programadores:
               Nome do Primeiro: Rafaela Beatriz Gutierrez Oliveira RA: 191009
               Nome do segundo: Bianca R. R. Cesaretto RA: 180155

Curso: Engenharia de Computa��o
Data de in�cio do projeto: 01/12/2022
----------------------------------------------------------------------------------
Descri��o do Programa:
		Esse programa foi realizado a partir da linguagem de programa��o C. Nosso objetivo foi criar um
		jogo da forca, onde dois usu�rios podem participar e se divertir com o desafio. N�s utilizamos
		diversas fun��es, sendo algumas delas os la�os de repeti��o e vetores. N�s tivemos que utilizar
		outras bibliotecas para conseguirmos utilizar a fun��o strings e utilizar os acentos que temos
		na l�ngua portuguesa.
Vers�o do programa: 1.4
Melhorias da vers�o: Melhorias na funcao jogo, no procedimento forma, melhorias na parte est�tica do jogo,
					 melhorias na funcao main, tamb�m foram adicionados novos coment�rios e a corre��o de
					 bugs no switch() case, da funcao main.
Data de lan�amento da vers�o: 09/12/22
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
	printf("\nJogador informe uma op��o [1]ou[2]: ");
}

//FUN��O REGRAS.
int regras()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao, escolha=1;
	
	while(escolha==1)
	{
		system("cls");
		printf("\n----------------------------------------------  REGAS E INSTRU��ES  -------------------------------------------------");
		printf("\n1- O Jogo da Forca permite apenas 2 participantes.\n");
		printf("\n2- Os jogadores devem escolher, entre si, quem ser� o jogador 1 e quem ser� o jogador 2.\n");
		printf("\n3- Ap�s feita a escolha, o JOGADOR 1 deve propor um tema e, sem o JOGADOR 2 olhar, deve escrever uma palavra secreta.\n");
		printf("\n4- O JOGADOR 2 deve informar letras, na tentativa de acertar a palavra.\n"); 
		printf("\n5- O JOGADOR 2 pode errar no m�ximo 7 letras, caso ele nao acerte a palavra, o JOGADOR 1 ganha a partida.\n"); 
		printf("\n6- Caso o JOGADOR 2 acerte a palavra antes de cometer 7 erros, ele ganha. Caso contrario, perde.\n");
		printf("\n7- Se est�o prontos? Se aceitaram o desafio, ent�o eu lhes desejo boa sorte e cuidado para n�o se enforcarem......\n");
		printf("\n---------------------------------------------------------------------------------------------------------------------");
		printf("\n\n[VOLTAR-1]\n");
		printf("\nJogador informe uma op��o [1]: ");
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
			printf("\nJogador informe uma op��o [1]: ");
			scanf("%d", &opcao);
			if(opcao ==1)
			{
				return opcao;
			}
			
		}
	}
	return opcao;	
}

//PROCEDIMENTO VIDA - mostra a situa�ao da forca conforme os erros.
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
	printf("\n\nLetras j� informadas: \n");
	for(i=0;i<tam;i++)
	{
		printf("%c ", letra[i]);
	}
	printf("\n");
}
//FUN��O VERIFICA_LETRA
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

    //DECLARANDO VARI�VEIS.
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

	//REMOVENDO O CARACTERE \0 QUE ESTA A MAIS NA VARI�VEL PAL_SECRETA.
	pal_secreta[strlen(pal_secreta)-1] = '\0';

	//ATRIBUINDO EM STRINGS O "-" E "_" DE ACORDO COM A QUANTIDADE DE LETRAS E ESPA�OS NA PAL_SECRETA.
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
	
		//COME�ANDO O JOGO.
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
		//CHAMANDO A FUN��O LET_JA_DIG.
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
				acerto_ou_erro=0;//Se o jogador acertar a letra, acerto_ou_erro recebe 0, se n�o, continua valendo 1.
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
			printf("\nO JOGADOR 2 GANHOU, PARAB�NS!\n");
			printf("\nA palavra era: %s\n", pal_secreta);
			printf("\nErros do jogador 2: %d", n_erro);
			forma(tentativa);
			break;
		}
		//VERIFICANDO SE O JOGADOR CHEGOU NO M�XIMO DE ERROS.
		if(erro==7)
		{
			//SE SIM, O JOGO ACABA E O JOGADOR 1 GANHA.
			system("cls");
			printf("O JOGADOR 1 GANHOU, PARAB�NS!\n");
			printf("\nA palavra era: %s\n", pal_secreta);
			printf("\nErros do jogador 2: %d", n_erro);
			forma(tentativa);
			break;
		}
	}
	return forca;
}

//FUN��O MAIN	
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	//DECLARA��O DE VARI�VEIS
	int escolha=1, opcao;
	
	menu();//CHAMANDO A FUN��O MENU.
	
	//REQUERINDO AO JOGADOR UMA OP��O DO MENU.
	scanf("%d", &opcao);
	fflush(stdin);
	
	//C�DIGO, QUE DE ACORDO COM A OPCAO ESOLHIDA, IR� CHAMAR A FUN��O REGRAS OU A FUN��O JOGO.
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
			printf("\nOp��o inv�lida!");
			printf("\nDigite uma op��o novamente: \n\n");
			main();	

		}	
	}
	
	return 0;
}
