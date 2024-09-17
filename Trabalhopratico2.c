//UFCD 783 | Programacao em C/C++ - ciclos e decis�es
//Trabalho pratico 2 realizado por:
//Patricia Sousa

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Funcao levantar_dinheiro

int levantar_dinheiro(int saldo){
	int opcao = 0, quantia = 0;
	do {
		do {
			printf("\n 1| Levantar Dinheiro \n\n");
			printf("\n 1| 10 EUR ");
			printf("\n 2| 20 EUR ");
			printf("\n 3| 50 EUR ");
			printf("\n 4| 100 EUR ");
			printf("\n 5| 200 EUR ");
			printf("\n 6| Outras quantias ");
			printf("\n 7| Voltar ao menu anterior ");
			printf("\n");
			printf("\n");
			printf("\n A opcao: ");
			scanf_s("%d", &opcao);

			if (opcao < 1 || opcao > 7)
			{
				printf("\n A opcao que selecionou nao esta disponivel. \n");
			}

		} while (opcao < 1 || opcao > 7);
		switch (opcao){
		case 1:
			if (saldo - 10 <= 0)
			{
				printf("\n Nao dispoe de saldo suficiente para continuar com a operacao. Consulte o seu saldo. \n\n");
			}
			else 
			{
				saldo -= 10;
				printf("\n Levantou 10 EUR. \n\n");
			}
			break;
		case 2:
			if (saldo - 20 <= 0)
			{
				printf("\n Nao dispoe de saldo suficiente para continuar com a operacaoo. Consulte o seu saldo. \n\n");
			}
			else
			{
				saldo -= 20;
				printf("\n Levantou 20 EUR. \n\n");
			}
			break;
		case 3:
			if (saldo - 50 <= 0)
			{
				printf("\n Nao dispoe de saldo suficiente para continuar com a operacaoo. Consulte o seu saldo. \n\n");
			}
			else
			{
				saldo -= 50;
				printf("\n Levantou 50 EUR. \n\n");
			}
			break;
		case 4:
			if (saldo - 100 <= 0)
			{
				printf("\n Nao dispoe de saldo suficiente para continuar com a operacao. Consulte o seu saldo. \n\n");
			}
			else
			{
				saldo -= 100;
				printf("\n Levantou 100 EUR. \n\n");
			}
			break;
		case 5:
			if (saldo - 200 <= 0)
			{
				printf("\n Nao dispoe de saldo suficiente para continuar com a operacao. Consulte o seu saldo. \n\n");
			}
			else
			{
				saldo -= 200;
				printf("\n Levantou 200 EUR. \n\n");
			}
			break;
		case 6:
			system("cls");
			printf("\n\n 6| Outras quantias ");
			printf("\n\n Introduza a quantia a levantar: ");
			scanf_s("%d", &quantia);
			if (saldo - quantia < 0 )
			{
				printf("\n\n Nao dispoe de saldo suficiente para continuar com a operacao. Consulte o seu saldo. \n\n");
			}
			else if(quantia > 200)
			{
				printf("\n So pode levantar um maximo de 200 EUR por operacao. \n");
			}
			else if (quantia <= 0)
			{
				printf("\n Deve inserir um valor para levantamento valido. \n");
			}
			else
			{
				saldo -= quantia;
				printf("\n\n Levantou %d EUR. \n\n", quantia);
			}
			break;
		case 7: break;
		default: printf("\n A opcaoo que selecionou nao esta disponivel."); break;
		}
	} while (opcao != 7);

	//printf("\n Saldo atual de: %d \n", saldo); //para testar a atualizacao de saldo.

	return saldo;
}

//Funcao depositar_dinheiro

int depositar_dinheiro(int saldo){
	int quantia = 0;
	printf("\n 2| Depositar dinheiro \n");
	printf("\n Introduza um valor a depositar entre 1 e 500 EUR. \n");
	printf("\n Introduza o montante a depositar: ");
	scanf_s("%d", &quantia);
	if (quantia <= 0 || quantia > 500)
	{
		printf("\n O montante a depositar tem de ser um valor entre 1 e 500 EUR. \n");
	}
	else
	{
		saldo += quantia;
		printf("\n Depositou %d EUR. \n", quantia);
	}
	//printf("\n Saldo atual de: %d \n", saldo); //para testar a atualizacao de saldo.
	return saldo;
}

//Procedimento consultar_saldo

void consultar_saldo(int saldo){

	printf("\n 3| Consultar saldo \n\n");
	printf("\n O saldo atual da sua conta e de: %d EUR \n", saldo);

}

//Funcao principal

void main(){
	setlocale(LC_CTYPE, "Portuguese");

	int saldo = 1000, opcao = 0;

	do{
		do {
			printf("\n");
			printf(" _______________________________________________________________________________________________________\n");
			printf("\n");
			printf(" Curso    | Tecnico de Informatica - Sistemas \n");
			printf(" UFCD 783 | Programacaoo em C/C++ - Ciclos e Decisoes \n");
			printf(" Trabalho pratico 2: Maquina de levantamento de dinheiro \n");
			printf(" _______________________________________________________________________________________________________\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n 1| Levantar Dinheiro ");
			printf("\n 2| Depositar Dinheiro ");
			printf("\n 3| Consultar Saldo ");
			printf("\n 4| Sair do programa ");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n A opcaoo: ");
			scanf_s("%d", &opcao);

			if (opcao < 1 || opcao > 4)
			{
				printf("\n A opcao que selecionou nao esta disponivel. \n");
			}

		} while (opcao < 1 || opcao > 4);

		switch (opcao)
		{
		case 1: 
			system("cls");
			saldo = levantar_dinheiro(saldo); 
			break;
		case 2: 
			system("cls");
			saldo = depositar_dinheiro(saldo); 
			break;
		case 3: 
			system("cls");
			consultar_saldo(saldo); 
			break;
		case 4: exit(0); break;
		default: printf("\n A opaoo que selecionou nao esta disponivel. \n");
			break;
		}
	} while (opcao != 4);
}