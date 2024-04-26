#ifndef PROJETO_2_BANCO_H
#define PROJETO_2_BANCO_H

#define MAX_NOME 40
#define MAX_CPF 11
#define MAX_


int Contador = 0;

typedef struct {
    char Nome[40];
    char CPF[11];
    char tipo_de_conta[5];
    int valor_inicial;
    int senha_do_usuario;
} banco;

typedef struct {
    char Nome[100];
    char CPF[11];
    int Saldo[100000];
} cliente;


void Novo_Cliente( banco lista_B[], int*pos);

void Apaga_Cliente( banco lista_B[], int*pos);

void Listar_Cliente( banco lista_B[], int pos);

void Debito_Cliente( banco lista_B[], int*pos);

void Desposito_Cliente( banco lista_B[], int*pos);

void Extrato_Cliente( banco lista_B[], int*pos);

void Transferencias_Clientes( banco lista_B[], int*pos);


#endif //PROJETO_2_BANCO_H