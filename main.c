#include "projeto_4.h"
#include <stdio.h>
#include <string.h>

int main(){
    banco lista_B[MAX_CLIENTES];
    int opcao;
    int pos = 0;
    int cod;

    cod = Carregar_conta(lista_B, &pos);

    do{
            printf("\nDigite (entre 0 a 7) uma das opcoes abaixo: \n");
            printf("1. Adicionar um novo cliente: \n");
            printf("2. Apagar a conta de um cliente: \n");
            printf("3. Listar os cliente: \n");
            printf("4. Realizar um debito: \n");
            printf("5. Realizar um deposito: \n");
            printf("6. Mostrar o extrato do cliente: \n");
            printf("7. Transferencias entre clientes: \n");
            printf("\n");
            
            
            scanf("%d", &opcao);
            
            switch(opcao){
            case 1:
                Novo_Cliente(lista_B, &pos);
                break;

            case 2:
                Apaga_Cliente(lista_B, &pos);
                break;

            case 3:
                Listar_Cliente(lista_B, &pos);
                break;

            case 4:   
                {
                    transacao historico;
                    Debito_Cliente(lista_B, &pos, &historico);
                    break;
                }
            
            case 5:
                {
                    transacao historico;
                    Desposito_Cliente(lista_B, &pos, &historico);
                    break;
                }
        
            case 6:
                Extrato_Cliente(lista_B, &pos);
                break;

            case 7:
                {
                    transacao historico;
                    Transferencias_Clientes(lista_B, &pos, &historico);
                    break;
                }
            
            case 0:
                cod = Salvar_conta(lista_B, &pos);
                    if (cod != 0) {
                        printf("Erro ao salvar a conta.\n");
                    }
                    printf("___- Programa finalizado!! -___\n");
                    break;
                
            default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
            }

                
        
        }while(opcao != 0);
    //if(cod == 1){  

        

    //} 

    return 0;
}

