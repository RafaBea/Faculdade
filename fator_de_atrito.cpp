/*
==================================================================================

                         Calculador de Fator de Atrito

==================================================================================
Empresa: Nome da empresa: Techfour
Equipe de Programadores:
               Bianca Rezende Rodrigues Casaretto
               Bryan Ryu Suzuki Lo
               Rafaela Beatriz Gutierrez Oliveira
               Vinicius da C. Teixeira
Curso: Engenharia de Computação
Data de inicio do projeto: 09/10/2022
----------------------------------------------------------------------------------
Descricao do Programa: 
		Este programa tem como funcao calcular o fator de atrito em sistemas com 
        escoamento interno de fluidos, alem de determinar o tipo de escoamento em 
        determinada tubulacao, apartir de dados como, diametro da tubulacao, vazao, 
        fluido e tipo de material da tubulacao, o programa entrega de forma simples
        e rapida o resultado para qualquer situacao, possuindo uma interface de facil 
        entendimento e pratica, para qualquer sistema que necessite essa aplicacao.   
         
Versao do programa: 1.5
Melhorias da versao: Implementado melhorias nos calculos executados pelo programa,
                      organizacao do algoritmo para um facil entendimento do mesmo
                      e melhoria na descricao e comentarios do programa.

Data de lancamento da versao: 17/10/22
==================================================================================
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    //Declaracao das variaveis.
    float diametro, vazao, pi, velocidade, massa, visc, rug, f, f_chute, erro;
    int fluido, material;
    double area, re;

    //Requerindo valores de diametro e vazao.
	printf("\n----CALCULADOR DE FATOR DE ATRITO----");
    printf("\n\nInforme o diametro da tubulacao: ");
    scanf("%f", &diametro);
    printf("\nInforme a vazao do escoamento: ");
    scanf("%f", &vazao);
    system("cls");

    //Calculando a area da secao transversal do escoamento.
    pi= 3.14159;
    area= (pi * pow(diametro, 2))/4;

    //Calculando a velocidade media.
    velocidade= vazao/area;

    //Informando opcoes de fluidos para o usuario.
    printf("\nSelecione o fluido que esta escoando de acordo com a seguinte tabela:");
    printf("\nATENCAO: caso deseje informar outro fluido, sera necessario apresentar os valores para massa e viscosidade.");

    printf("\n------FLUIDO-----");
    printf("\n|1- Agua        |");
    printf("\n|2- Ar Seco     |");
    printf("\n|3- Etanol      |");
    printf("\n|4- Glicerina   |");
    printf("\n|5- Mercurio    |");
    printf("\n|6- Oleo SAE 30 |");
    printf("\n|7- OUTRO       |");
    printf("\n-----------------\n");
    scanf("%d", &fluido);
    system("cls");

    //Atribuindo de acordo com o fluido valores de massa, viscosidade e calculando o numero de reynolds.
    switch(fluido)
    {
        case 1:
            massa= 998.2;
            visc= 1.00;
            re= (massa * velocidade * diametro)/visc;

            break;
        case 2:
            massa= 1.189; 
            visc= 1.83;
            re= (massa * velocidade * diametro)/visc;

            break;
        case 3:
            massa= 789;
            visc= 1.19;
            re= (massa * velocidade * diametro)/visc;

            break;
        case 4:
            massa= 1260;
            visc= 1.49;
            re= (massa * velocidade * diametro)/visc;

            break;
        case 5:
            massa= 13550;
            visc= 1.56;
            re= (massa * velocidade * diametro)/visc;

            break;
        case 6:
            massa= 891;
            visc= 0.29;
            re= (massa * velocidade * diametro)/visc;

            break;
    default:
        printf("\nInforme a massa do fluido: ");
        scanf("%f", &massa);
        printf("\nInforme a viscosidade do fluido: ");
        scanf("%f", &visc);
        re= (massa * velocidade * diametro)/visc;
    }
    system("cls");

    //Informando opcoes de materiais para o usuario.
    printf("Agora voce devera escolher o material da sua tubulacao.\n\n");
    system("pause");
    system("cls");

    printf("\n|1- Aco carbono comercial novo                                |");
    printf("\n|2- Aco laminado novo                                         |");
    printf("\n|3- Aco soldado novo                                          |");
    printf("\n|4- Aco soldado moderadamente oxidado                         |");
    printf("\n|5- Aco laminado revestido de asfalto                         |");
    printf("\n|6- Aco galvanizado com costura                               |");
    printf("\n|7- Ferro fundido novo                                        |");
    printf("\n|8- Ferro fundido com leve oxidacao                           |");
    printf("\n|9- Ferro fundido velho                                       |");
    printf("\n|10- Ferro fundido centrifugado                               |");
    printf("\n|11- Ferro fundido com revestimento asfaltico                 |");
    printf("\n|12- Ferro fundido oxidado                                    |");
    printf("\n|13- Concreto centrifugado novo                               |");
    printf("\n|14- Concreto armado liso com varios anos de uso              |");
    printf("\n|15- Concreto com acabamento normal                           |");
    printf("\n|16- Cobre, latao, aco revestido de epoxi, tubos extrusados   |");
    printf("\n|17- Vidro, PVC, plasticos em geral                           |");
    printf("\n|18- OUTRO                                                    |\n");
    scanf("%d", &material);
    system("cls");

    //Atribuindo valores de rugosidade de acordo com o material da tubulacao.
    switch(material)
    {
        case 1:
            rug= 0.045/1000;

            break;
        case 2:
            rug= 0.04/1000;

            break;
        case 3:
            rug= 0.05/1000; 

            break;
        case 4:
            rug= 0.4/1000;

            break;
        case 5:
            rug= 0.05/1000;

            break;
        case 6:
            rug= 0.15/1000;

            break;
        case 7:
            rug= 0.26/1000;

            break;
        case 8:
            rug= 0.30/1000;

            break;
        case 9:
            rug= 3/1000;

            break;
        case 10:
            rug= 0.05/1000;

            break;
        case 11:
            rug= 0.12/1000;

            break;
        case 12:
            rug= 1/1000;

            break;
        case 13:
            rug= 0.16/1000;

            break;
        case 14:
            rug= 0.20/1000;

            break;
        case 15:
            rug= 1/1000;

            break;
        case 16:
            rug= 0.0015/1000;

            break;
        case 17:
            rug= 0/1000;

            break;
    default:
        printf("Voce selecionou OUTRO, sera necessario informar o valor da rugosidade do material, em METROS.\n\n");
        system("pause");
        system("cls"); 
        printf("\nInforme o valor da rugosidade do material: ");
        scanf("%f", &rug);
        system("cls");
    }

    //Calculando e informando o fator de atrito para escoamento laminar. 
    if(re < 2300)
    {
        printf("\nTipo de escoamento: LAMINAR");
        f= 64/re;
        printf("\nFator de atritro: %.2f", f);
    }
    else
    {
        //calculando e informando o fator de atrito para escoamento turbulento.
        printf("\nTipo de escoamento: TURBULENTO");
        f_chute = 5;
        erro = 1;
        while(erro>0.01)
        {
            f = 1/((-2) * log10((rug/diametro)/3.7) + (2.51 / (re * sqrt(f_chute))));//Formula para escoamento turbulento.
            f = pow(f, 2);
            erro = fabs(((f-f_chute)/f));
            f_chute = f;
        }
        printf("\nFator de atrito: %.3f", f);
    }

	return 0;
    
}
