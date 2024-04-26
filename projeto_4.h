#ifndef PROJETO_2_BANCO_H
#define PROJETO_2_BANCO_H

#define MAX_CLIENTES 1000
#define MAX_NOME 40
#define MAX_CPF 12
#define MAX_TIPO_DE_CONTA 6
#define MAX_SENHA_USUARIO 50


typedef struct {
    char Nome[MAX_NOME];
    char CPF[MAX_CPF];
    char tipo_de_conta[MAX_TIPO_DE_CONTA];
    int valor_inicial;
    char senha_do_usuario[MAX_SENHA_USUARIO];
} banco;

//typedef struct {
//    char Nome[100];
//    char CPF[11];
//    int Saldo[100000];
//} cliente;


int Novo_Cliente( banco lista_B[], int *pos);

int Apaga_Cliente( banco lista_B[], int *pos);

int Listar_Cliente( banco lista_B[], int *pos);

int Debito_Cliente( banco lista_B[], int *pos);

int Desposito_Cliente( banco lista_B[], int *pos);

int Extrato_Cliente( banco lista_B[], int *pos);

int Transferencias_Clientes( banco lista_B[], int *pos);


#endif //PROJETO_2_BANCO_H