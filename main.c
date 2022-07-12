#include "funcs.h"

/*
Autor: Camylla de Lima
https://www.linkedin.com/in/camylla-lima-/
*/

int main(int argc, char*argv[]) {

  setlocale(LC_ALL, "Portuguese");
  agenda a; 
  a.total = 0;

  do{
    menu();
    scanf(" %d", &op);
    getchar();

    switch(op){

      case 1:
        system("clear");
        printf("Quantos contatos deseja adicionar? ");
        scanf(" %d", &qtd);
        fflush(stdin);
        getchar();
        for(i=0; i<qtd; i++){
          inserirContato(&a, cadastrarContato());
            
        }
        
        
      break;

      case 2:
        system("clear");
        printf("Procurar por [1] - Nome ou [2] - CPF? ");
        scanf(" %d", &opc);
        fflush(stdin);
        getchar();

        if(opc == 1){
          printf("\nNome a ser procurado: ");
					fflush(stdin);
					fgets(vetor, 100, stdin);
					apagar(vetor);
					system("clear");
					idc = procurarContato(&a, vetor, 1);
        } else{
          printf("\nCPF a ser procurado: ");
					fflush(stdin);
					fgets(vetor, 50, stdin);
					apagar(vetor);
          system("clear");
					idc = procurarContato(&a, vetor, 2);
        }

        if(idc == -1){
					printf("Não encontrado! \n\n");
				}else{
					printf("Contato encontrado! \n\n");
					imprimirContato(a.contatos[idc]);
				}
      break;

      case 3:
        system("clear");
				printf("Nome do contato a ser alterado: ");
				fflush(stdin);
				fgets(vetor, 100, stdin);
				apagar(vetor);
				idc = procurarContato(&a, vetor, 1);
				printf("\n");
				imprimirContato(a.contatos[idc]);
				printf("O que deseja alterar? \n [1] - Nome \n [2] - CPF \n [3] - RG \n [4] - Idade \n [5] - DDD \n [6] - Telefone \n [7] - Email \n [8] - UF \n [9] - CEP \n [10] - Cidade \n [11] - Rua \n [12] - Bairro \n");
				scanf(" %d", &op2);
        getchar();
				alterarContato(&a, idc, op2);	
				system("clear");
				printf("Contato alterado com sucesso!");
				printf("\n\n");
				imprimirContato(a.contatos[idc]);
			break;
      
      case 4:
				system("clear");
				printf("|\t\t\t\t\t\tAGENDA\t\t\t\t\t\t|\n");
        printf("----------------------------------------------------\n");
				imprimirLista(&a);
        printf("----------------------------------------------------\n");
				printf("Total de contatos: %d\n\n", a.total);
			break;
					
			case 5:
				system("clear");
				printf("Nome do contato a ser excluído: ");
				fflush(stdin);
				fgets(vetor, 50, stdin);
				apagar(vetor);
				idc = procurarContato(&a, vetor, 1);
				excluirContato(&a, idc);
				system("clear");
        printf("Contato excluído com sucesso!");
			break;
				
			case 6:
				exit(0);
			break;
			default:
        printf("ERRO");
				system("clear");
				break;
		}
	
}while(op!=6);

	return 0;

}
