#include "projeto_4.h"
#include <stdio.h>
#include <string.h>

int Novo_Cliente( banco lista_B[], int*pos){
    if(*pos < MAX_CLIENTES){
        printf("--> Digite o seu nome: \n");
        scanf("%s", lista_B[*pos].Nome);

        printf("--> Digite o seu CPF: \n");
        scanf("%s", lista_B[*pos].CPF);
        
        printf("--> Digite o tipo de conta: \n");
        scanf("%s", lista_B[*pos].tipo_de_conta);

        printf("--> Digite o valor inicial da conta: \n");
        scanf("%d", &lista_B[*pos].valor_inicial);

        printf("--> Digite a senha do usuario: \n");
        scanf("%s", lista_B[*pos].senha_do_usuario);

        printf("\n-_-_- Cliente salvo com sucesso!! -_-_-\n");

        *pos = *pos + 1;
    }
}

int Apaga_Cliente( banco lista_B[], int*pos){
    char CPF_excluido[MAX_CPF];
    char senha_excluido[MAX_SENHA_USUARIO];

    if(*pos > 0){
        printf("digite o CPF a ser excluido: \n");
        scanf("%s", CPF_excluido);

        printf("digite a senha do CPF a ser excluido: \n");
        scanf("%s", senha_excluido);

        for(int i = 0 ; i < *pos ; i++){
            if (strcmp(CPF_excluido, lista_B[i].CPF) == 0 && strcmp(senha_excluido, lista_B[i].senha_do_usuario) == 0) {
                for (int j = i; j < (*pos) - 1; j++) {
                    lista_B[j] = lista_B[j + 1];
                }
                (*pos)--;
                printf(" -_-_- Cliente deletado com sucesso!! -_-_-\n");
                return 0;
            }
        }
    }
    else{
        printf("A lista esta vazia..\n");
    }
}

int Listar_Cliente( banco lista_B[], int *pos){
    if(*pos > 0){
        printf("\nLista de clientes abaixo: \n");

        for(int i = 0 ; i < *pos ; i++){
            printf("\n Cliente: %d\n", i + 1);
            printf("--> Nome: %s\n", lista_B[i].Nome);
            printf("--> CPF: %s\n", lista_B[i].CPF);
            printf("--> Tipo de conta: %s\n", lista_B[i].tipo_de_conta);
            printf("--> Valor inicial: %d\n", lista_B[i].valor_inicial);
            printf("\n");
        }
    }
    else{
        printf("A lista esta vazia..\n");
    }
}

int Debito_Cliente( banco lista_B[], int *pos, transacao *historico){
    char CPF_debito[MAX_CPF];
    char senha_debito[MAX_SENHA_USUARIO];
    int valor_debito_comum;
    int valor_debito_plus;

    if(*pos > 0){
        printf("digite o CPF a ser debitado: \n");
        scanf("%s", CPF_debito);

        printf("digite a senha do CPF a ser debitado: \n");
        scanf("%s", senha_debito);

        for(int i = 0 ; i < *pos ; i++){
            if(strcmp(CPF_debito, lista_B[i].CPF) == 0 && strcmp(senha_debito, lista_B[i].senha_do_usuario) == 0){
                if(strcmp(lista_B[i].tipo_de_conta, "comum") == 0){
                    if(lista_B[i].valor_inicial >= -1000){
                        printf("digite a quantia a ser debitada: \n");
                        scanf("%d", &valor_debito_comum);

                        valor_debito_comum = valor_debito_comum * 5 / 100 + valor_debito_comum;
                  
                        lista_B[i].valor_inicial = lista_B[i].valor_inicial - valor_debito_comum;

                        strcpy(lista_B[i].historico[lista_B[i].num_transacoes].Tipo , "Débito");
                        lista_B[i].historico[lista_B[i].num_transacoes].valor = valor_debito_comum;
                        lista_B[i].num_transacoes++;

                        printf(" -_-_- Debito feito com sucesso -_-_-  \n");
                    }
                    else{
                        printf("O seu saldo atual não permite fazer o debito desejado.. \n");
                    }
                }
                else if(strcmp(lista_B[i].tipo_de_conta, "plus") == 0){
                    if(lista_B[i].valor_inicial >= -5000){
                        printf("digite a quantia a ser debitada: \n");
                        scanf("%d", &valor_debito_plus);

                        valor_debito_plus = valor_debito_plus * 3 / 100 + valor_debito_plus;

                        lista_B[i].valor_inicial = lista_B[i].valor_inicial - valor_debito_plus;

                        strcpy(lista_B[i].historico[lista_B[i].num_transacoes].Tipo , "Débito");
                        lista_B[i].historico[lista_B[i].num_transacoes].valor = valor_debito_plus;
                        lista_B[i].num_transacoes++;

                        printf(" -_-_- Debito feito com sucesso -_-_-  \n");
                    }
                    else{
                        printf("O seu saldo atual não permite fazer o debito desejado.. \n");
                    }
                }
                else{
                    printf("A conta foi mal cadastrada ( nao ha tipo de conta )..\n");
                }
            }
            else{
                printf("Senha ou CPF incorreto.. \n");
            }
        }
    }
    else{
        printf("A lista esta vazia..\n");
    }
}
    
int Desposito_Cliente( banco lista_B[], int *pos, transacao *historico){
    char CPF_deposito[MAX_CPF];
    int valor_deposito;
    
    if(*pos > 0){
        printf("Digite o CPF da conta a ser depositada: \n");
        scanf("%s", CPF_deposito);
        
        for(int i = 0 ; i < *pos ; i++){
            if(strcmp(CPF_deposito, lista_B[i].CPF) == 0){
                printf("Digite o valor a ser depositado: \n");
                scanf("%d", &valor_deposito);

                strcpy(lista_B[i].historico[lista_B[i].num_transacoes].Tipo, "Depósito");
                lista_B[i].historico[lista_B[i].num_transacoes].valor = valor_deposito;
                lista_B[i].num_transacoes++;

                lista_B[i].valor_inicial = lista_B[i].valor_inicial + valor_deposito;
            }
            else{
                printf("O CPF inserido não corresponde a nenhum CPD cadastrado.. \n");
            }

        }
    }
}
    
int Extrato_Cliente( banco lista_B[], int *pos){
    char CPF_extrato[MAX_CPF];
    char senha_extrato[MAX_SENHA_USUARIO];
    char extrato_arquivo[100];

    if(*pos > 0){
        printf("Digite o CPF do cliente em questao para que seja gerado o extrato: ");
        scanf("%s", CPF_extrato);

        printf("Digite a senha do cliente em questao para que seja gerado o extrato: ");
        scanf("%s", senha_extrato); 
        
        for(int i = 0 ; i < *pos ; i++){
            if(strcmp(CPF_extrato, lista_B[i].CPF) == 0 && strcmp(senha_extrato, lista_B[i].senha_do_usuario) == 0){
            printf("\nGerando extrato para o cliente %s...\n", lista_B[i].Nome);
                
                sprintf(extrato_arquivo, "extrato_%s.txt", lista_B[i].CPF);
                FILE *arquivo = fopen(extrato_arquivo, "w");

                if (arquivo == NULL) {
                    printf("Erro ao criar o arquivo de extrato.\n");
                    return 0; 
                }

                fprintf(arquivo, "Extrato para o cliente: %s\n", lista_B[i].Nome);
                fprintf(arquivo, "CPF: %s\n", lista_B[i].CPF);
                fprintf(arquivo, "Tipo de conta: %s\n", lista_B[i].tipo_de_conta);
                fprintf(arquivo, "Saldo atual: %d\n", lista_B[i].valor_inicial);
                fprintf(arquivo, "Histórico de transacoes:\n");

                for (int j = 0; j < lista_B[i].num_transacoes; j++) {
                    fprintf(arquivo, "Transação %d: Tipo: %s, Valor: %d\n", j + 1, lista_B[i].historico[j].Tipo, lista_B[i].historico[j].valor);
                }

                fclose(arquivo);
                printf("Extrato gerado com sucesso. Verifique o arquivo '%s'.\n", extrato_arquivo);
                return 1;
            }
            else{
                printf("CPF e/ou senha incorreto/s.. \n");

            }
                
        }
    }
    else{
        printf("A lista esta vazia.. \n");
    }
}


int Transferencias_Clientes( banco lista_B[], int *pos, transacao *historico){
    char CPF_origem[MAX_CPF];
    char CPF_destinatario[MAX_CPF];
    char senha_origem[MAX_SENHA_USUARIO];
    int valor_transferido;

    if(*pos > 0){
        printf("\nDigite o seu CPF: ");
        scanf("%s", CPF_origem);

        printf("\nDigite a sua senha: ");
        scanf("%s", senha_origem);

        for(int i = 0 ; i < *pos ; i++){
            if(strcmp(CPF_origem, lista_B[i].CPF) == 0 && strcmp(senha_origem, lista_B[i].senha_do_usuario) == 0){
                printf("\nDigite o CPF do destinatario: \n");
                scanf("%s", CPF_destinatario);

                for(int j = 0 ; j < *pos ; j++){
                    if(strcmp(CPF_destinatario, lista_B[j].CPF) == 0){
                        printf("\nDigite o valor a ser transferido: \n");
                        scanf("%d", &valor_transferido);

                        if(valor_transferido > 0){
                            
                            strcpy(lista_B[i].historico[lista_B[i].num_transacoes].Tipo, "Transferência Enviada");
                            lista_B[i].historico[lista_B[i].num_transacoes].valor = valor_transferido;
                            lista_B[i].num_transacoes++;

                            lista_B[i].valor_inicial -= valor_transferido;


                            strcpy(lista_B[j].historico[lista_B[j].num_transacoes].Tipo, "Transferência Recebida");
                                lista_B[j].historico[lista_B[j].num_transacoes].valor = valor_transferido;
                                lista_B[j].num_transacoes++;

                                lista_B[j].valor_inicial += valor_transferido;

                        }
                        else{
                            printf("O valor trasferido deve ser positivo.. \n");
                        }
                    }
                    else{
                        printf("CPF ou senha do destinatario invalido.. \n");
                    }
                }
            }
            else{
                printf("CPF ou senha de origem invalido.. \n");
            }
        }

    }

    
}

int Salvar_conta(banco lista_B[], int *pos){
    FILE *arquivo = fopen("dados_banco.bin", "wb");
    
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.. \n");
        return 0;
    }
    else{
        fwrite(lista_B, sizeof(banco), *pos, arquivo);
        fclose(arquivo);
        
        return 1;
    }
    
}

int Carregar_conta(banco lista_B[], int *pos){
    FILE *arquivo = fopen("dados_banco.bin", "rb");
    
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.. \n");
        *pos = 0;
        return 0;
    }
    else{
        *pos = fread(lista_B, sizeof(banco), MAX_CLIENTES, arquivo);
        fclose(arquivo);

        return 1;
    }

}


