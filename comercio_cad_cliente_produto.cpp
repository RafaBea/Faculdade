#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//informação do cliente
		//total da fatura do cartão
//Relatórios
	//Total de vendas do empreendimento
	//Total de vendar por cliente
using namespace std;

void menu()
{
	cout << "===========MENU==========" << endl;
	cout << "Cadastrar cliente     - 1" << endl;
	cout << "Cadastrar produtos    - 2" << endl;
	cout << "Cadastro de venda     - 3" << endl;
	cout << "Atualizar estoque     - 4" << endl;
	cout << "Informação de cliente - 5" << endl;
	cout << "Relatório             - 6" << endl;
	cout << "Sair do sistema       - 7" << endl;
	
	cout << "\nEscolha uma opção: ";
}

struct Cliente
{
	char nome[40];
	int codigo;
};

Cliente *cad_cliente(int *nClientes)
{
	Cliente *cadastro = new Cliente[20];
	char escolha;
	*nClientes=0;
	
	system("cls");
	for(int i=0; i<20;i++)
	{
		cout<<"-----CADASTRO DE CLIENTE-----\n\n";	
		cout<<"Informe o nome do cliente a ser cadastrado: ";
		fflush(stdin);
		fgets(cadastro[i].nome, 40, stdin);
		cout<<"\nInforme um codigo para o cliente: ";
		cin>>cadastro[i].codigo;
		
		cout<<"\n\n------DADOS DO CADRASTRO-----\n";
		cout<<"\nNome: " << cadastro[i].nome;
		cout<<"Código: " << cadastro[i].codigo<<endl;
		cout<<"\ncliente cadastrado!\n";
		(*nClientes) ++;
	
		cout<<"Deseja cadastrar um novo cliente?(s/n):";
		cin>>escolha;	
		if(escolha == 's')
		{
			system("cls");
			continue;
		}
		else
		{
			break;
		}
	}
	cout<<"\n\n";
	system("pause");
	system("cls");
	return cadastro;
}

struct produto
{
	char nome[30];
	int cod;
	int qtdEstoque;
	float preco;
};

produto *novo_produto(int *qtd)
{
	produto *cadProduto = new produto[20];
	char escolha;
	*qtd=0;
	
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		cout<<"-----CADASTRO DE PRODUTO-----\n\n";
		cout<<"Nome do produto: ";
		fflush(stdin);
		fgets(cadProduto[i].nome, 30, stdin);
		cout<<"Código do produto: ";
		cin>>cadProduto[i].cod;
		cout<<"Preço: ";
		cin>>cadProduto[i].preco;
		cout<<"Quantidade no estoque: ";
		cin>>cadProduto[i].qtdEstoque;
		(*qtd) ++;
		
		cout<<"\n\nDeseja cadastrar um novo produto?(s/n)";
		cin>>escolha;	
		if(escolha == 's')
		{
			system("cls");			
			continue;
		}
		else
		{
			break;
		}
	}
	system("pause");
	system("cls");
	return cadProduto;
}

void cadastro_venda(Cliente *cadastro, produto *vendaP, int *qtdP, int *nCliente)
{
	char verNome[40], nProd[30], escolha;
	int verCodigo, qtd, pag, vendas[*nCliente]={0}, vendaCartao[*nCliente]={0}, tVenda[*nCliente]={0};
	float vCompra[qtd], vTotal =0, cartao[*nCliente], faturaCartao = 0;
	system("cls");
	cout << "Nome do cliente: ";
	fflush(stdin);
	fgets(verNome, 40, stdin);
	cout << "\nCódigo do cliente: ";
    cin >> verCodigo;

    int encontrado = -1;
    for (int i = 0; i < *nCliente; i++)
    {
        if (strcmp(cadastro[i].nome, verNome) == 0 && cadastro[i].codigo == verCodigo)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1)
    {
        do
        {
            cout << "\n\nInforme o nome do produto: ";
			fflush(stdin);
			fgets(nProd, 30, stdin);
			cout << "\nQuantidade a ser comprada produto: ";
			cin >> qtd;

			int aux = -1;
			for (int i = 0; i < *qtdP; i++)
			{
				if (strcmp(vendaP[i].nome, nProd) == 0)
				{
					aux = i;
					break;
				}
			}
			if (aux != -1)
			{
				if (vendaP[aux].qtdEstoque >= qtd)
				{
					vendaP[aux].qtdEstoque -= qtd;
					vCompra[aux] = vendaP[aux].preco * qtd;
					vTotal += vCompra[aux];
					cout << "\nValor da compra: " << vCompra[aux];
				}
				else
				{
					cout << "\nQuantidade insuficiente no estoque\n";
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "Produto não encontrado!\n";
				system("pause");
				system("cls");
			}

			cout << "\n\nDeseja adicionar outro produto?(s/n):";
			cin >> escolha;
			system("cls");
			
			if(escolha !='s')
			{
				cout<<"-----PAGAMENTO-----\n";
				cout<<"|1- Dinheiro|\n";
				cout<<"|2- Débito  |\n";
				cout<<"|3- Cartão  |\n";
				cout<<"\nInforme a forma de pagamento: ";
				cin>>pag;
				
				switch (pag)
                {
                    case 1:
                        cout << "\nForma de pagamento escolhida: Dinheiro\n" << endl;
                        cout << "\nValor Total: " << vTotal << endl;
                        vendas[encontrado] += 1;
                        cout << "Total de vendas: " << vendas[encontrado] << endl;
                        break;
                    case 2:
                        cout << "Forma de pagamento escolhida: Débito\n" << endl;
                        cout << "\nValor Total: " << vTotal << endl;
                        vendas[encontrado] += 1;
                        cout << "Total de vendas: " << vendas[encontrado] << endl;
                        break;
                    case 3:
                        cout << "Forma de pagamento escolhida: Cartão a prazo\n" << endl;
                        cout << "\nValor Total: " << vTotal << endl;
                        cout << "\nFatura do cartão: " << faturaCartao << endl;
                        cout << "Total de vendas: " << tVenda[encontrado] << endl;
                        break;
                    default:
                        cout << "Opção inválida!";
                }
                tVenda[encontrado] = vendas[encontrado] + vendaCartao[encontrado];
			}
		} while (escolha == 's'); 
        system("pause");
		system("cls");
    }
    else
    {
        cout << "Cliente não encontrado!" << endl;
    }
	
}

void at_estoque(produto *produtos, int *qtd)
{
	char nProduto[30];
	int adcEstoque;
	system("cls");
	cout<<"Deseja atualizar a quantidade de qual produto:";

	for(int i=0; i<*qtd; i++)
	{
		cout<<"\nProduto: "<<produtos[i].nome;
		cout<<"Quantidade atual: "<<produtos[i].qtdEstoque<<endl;
	}

	cout<<"\nInforme o nome do produto: ";
	fflush(stdin);
	fgets(nProduto, 30, stdin);

	int encontrado = -1;
	for(int i=0; i<*qtd; i++)
	{
		if(strcmp(produtos[i].nome, nProduto) == 0)
		{
			encontrado = i;
			break;
		}
	}

	if(encontrado != -1)
	{
		cout<<"Informe a quantidade que deseja adicionar: ";
		cin>>adcEstoque;
		produtos[encontrado].qtdEstoque += adcEstoque;
	}
	else
	{
		cout<<"Esse produto não existe!"<<endl;
	}

	for(int i=0; i<*qtd; i++)
	{
		cout<<"\nProduto: "<<produtos[i].nome;
		cout<<"Quantidade atual: "<<produtos[i].qtdEstoque<<endl;
	}

	system("pause");
	system("cls");
}
void infCliente(Cliente *dadosCliente, int nCliente)
{
	char buscaNome[40], escolha;
	do
	{
		cout<<"Clientes cadastrados: "<<endl;
		for(int i=0; i<nCliente;i++)
		{
			cout<<dadosCliente[i].nome<<endl;	
		}
		
		cout<<"Informe o nome do cliente para obter mais informações: ";
		fflush(stdin);
		fgets(buscaNome, 40, stdin);
		system("cls");
		
		int encontrado = -1;
		for(int j = 0; j < nCliente; j++)
		{
			if(strcmp(dadosCliente[j].nome, buscaNome) == 0)
			{
				encontrado = j;
				break;	
			}	
		}
		if(encontrado != -1)
		{
			cout<<"====Dados do cliente===\n";
			cout<<"Nome: "<<dadosCliente[encontrado].nome<<endl;
			cout<<"Código: "<<dadosCliente[encontrado].codigo<<endl;
			cout<<"\nFatura: "<<endl;
		}
		else
		{
			cout<<"Nome inválido!\n";
		}
		
		cout<<"\nDeseja ver os dados de outro cliente?(s/n)";
		cin>>escolha;
		system("cls");	
	}while(escolha == 's');
}

void relatorio(Cliente *clientes, int *nClientes, produto *produtos, int *qtdProdutos)
{
	system("cls");
    FILE *arquivo = fopen("relatorio.txt", "w");

    if (arquivo != NULL)
    {
		fprintf(arquivo,"\n------RELATÓRIO DE CLIENTES CADASTRADOS------\n");
        cout << "\n------RELATÓRIO DE CLIENTES CADASTRADOS------\n";
        for (int i = 0; i < *nClientes; i++)
        {
        	fprintf(arquivo,"Nome: %s", clientes[i].nome);
        	fprintf(arquivo,"Código: %d\n", clientes[i].codigo);
        	fprintf(arquivo,"\n\n");
        	
            cout<<"Nome: "<<clientes[i].nome;
            cout<<"Código: "<<clientes[i].codigo<<endl;
            cout<<"\n\n";
        }

		fprintf(arquivo,"\n------RELATÓRIO DE PRODUTOS------\n");
        cout << ("\n------RELATÓRIO DE PRODUTOS------\n");
        for (int i = 0; i < *qtdProdutos; i++)
        {
        	fprintf(arquivo,"\nNome do Produto: %s", produtos[i].nome);
        	fprintf(arquivo,"Código: %d\n", produtos[i].cod);
        	fprintf(arquivo,"Quantidade em estoque: %d\n", produtos[i].qtdEstoque);
        	fprintf(arquivo,"Preço: R$ %.2f\n", produtos[i].preco);
        	
            cout<<"Nome: "<<produtos[i].nome;
            cout<<"Código: "<<produtos[i].cod<<endl;
            cout<<"Quantidade em estoque: "<<produtos[i].qtdEstoque<<endl;
            cout<<"Preço: "<<produtos[i].preco<<endl;
            cout<<"\n\n";
        }

        fclose(arquivo);
        cout<<"Relatório gerado com sucesso!"<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"Não foi possível abrir o arquivo!"<<endl;
        system("pause");
        system("cls");
    }
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int op, qtd, nCliente;
	char escolha;
	Cliente *cliente;
	produto *Produto;
	
	while(true)
	{
		menu();
		cin>>op;
		
		switch (op)
		{
		case 1:
			cliente = cad_cliente(&nCliente);
			break;
		case 2:
			Produto = novo_produto(&qtd);
			break;
		case 3:
			cadastro_venda(cliente, Produto, &qtd, &nCliente);
			break;
		case 4:
			at_estoque(Produto, &qtd);
			break;
		case 5: 
			infCliente(cliente, nCliente);
			break;
		case 6:
			relatorio(cliente, &nCliente, Produto, &qtd);
			break;
		case 7:
			system("cls");
			cout<<"Tem certeza que que encerrar o programa? (s/n)";
			cin>>escolha;
			
			if(escolha == 's' || escolha == 'S')
			{
				return 0;
			}
			system("cls");	
			break;	
		default:
			cout<<"Opção inválida!"<<endl;
		}
	}
	return 0;
}


