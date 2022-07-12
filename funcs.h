#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

/*
Autor: Camylla de Lima
https://www.linkedin.com/in/camylla-lima-/
*/

//***************VARIAVÉIS***************

int i, op, op2, opc, qtd, tel, idc;
char vetor[50];

//****************STRUCTS*****************

//Informações do Contato
  typedef struct {
    //Dados pessoais
      char nome[100];
      char cpf[20];
      char rg[16];
      char idade[3];

    //Dados telefone
      char ddd[4];
      char numero[10];
      char email[80];

    //Dados endereço 
      char uf[3];
      char cep[9];
      char cidade[100];
      char rua[100];
      char bairro[100];
      
    } contato;

// Agenda
  typedef struct{

    contato contatos[100];
    int total;

  } agenda;

//*****************FUNÇÕES*****************

//Apagando
void apagar(char*str){
  int i = 0;
  while(str[i] != '\0' && str[i] != '\n')
    i++;
  str[i] = '\0';
}

//Insere Contato na Agenda
void inserirContato(agenda *a, contato c){

  a->contatos[a->total] = c;
  a->total++;
}

//Função de Cadastro do Contato
contato cadastrarContato(){

  contato cont;
    //Cadastrando Pessoa

      //Nome
        printf("\nNome: ");
        fflush(stdin);
        fgets(cont.nome, 100, stdin);
        getchar();
        apagar(cont.nome);
        
        
      //CPF
        printf("\nCPF [apenas números]: ");
        fflush(stdin);
        fgets(cont.cpf, 20, stdin);
        getchar();
        apagar(cont.cpf);
        
  
      //RG
        printf("\nRG [apenas números]: ");
        fflush(stdin);
        fgets(cont.rg, 16, stdin);
        getchar();
        apagar(cont.rg);
        

      //Idade
        printf("\nIdade: ");
        fflush(stdin);
        fgets(cont.idade, 3, stdin);
        getchar();
        apagar(cont.idade);
        
  
    //Cadastrando Telefone
    
      //DDD
        printf("\nDDD: ");
        fflush(stdin);
        fgets(cont.ddd, 4, stdin);
        getchar();
        apagar(cont.ddd);
        
  
      //Número
        printf("\nTelefone: ");
        fflush(stdin);
        fgets(cont.numero, 10, stdin);
        getchar();
        apagar(cont.numero);
        

      //Email
        printf("\nEmail: ");
        fflush(stdin);
        fgets(cont.email, 80, stdin);
        getchar();
        apagar(cont.email);
        

    //Cadastrando Endereço
    
      //Estado
        printf("\nDigite:\t[RO] - Rondônia\n\t\t[AC] - Acre\n\t\t[AM] - Amazonas\n\t\t[RR] - Roraima\n\t\t[PA] - Pará\n\t\t[AP] - Amapá\n\t\t[TO] - Tocantins\n\t\t[MA] - Maranhão\n\t\t[PI] - Piauí\n\t\t[CE] - Ceará\n\t\t[RN] - Rio Grande do Norte\n\t\t[PB] - Paraíba\n\t\t[PE] - Pernambuco\n\t\t[AL] - Alagoas\n\t\t[SE] - Sergipe\n\t\t[BA] - Bahia\n\t\t[MG] - Minas Gerais\n\t\t[ES] - Espírito Santo\n\t\t[RJ] - Rio de Janeiro\n\t\t[SP] - São Paulo\n\t\t[PR] - Paraná\n\t\t[SC] - Santa Catarina\n\t\t[RS] - Rio Grande do Sul\n\t\t[MS] - Mato Grosso do Sul\n\t\t[MT] - Mato Grosso\n\t\t[GO] - Goiás\n\t\t[DF] - Distrito Federal\n\n\nUF: ");
        fflush(stdin);
        fgets(cont.uf, 3, stdin);
        getchar();
        apagar(cont.uf);
        
    
      //CEP
        printf("\nCEP [apenas números]: ");
        fflush(stdin);
        fgets(cont.cep, 9, stdin);
        getchar();
        apagar(cont.cep);
        
    
      //Cidade
        printf("\nCidade: ");
        fflush(stdin);
        fgets(cont.cidade, 100, stdin);
        getchar();
        apagar(cont.cidade);
        
    
      //Rua
        printf("\nRua: ");
        fflush(stdin);
        fgets(cont.rua, 100, stdin);
        getchar();
        apagar(cont.rua);
        
    
      //Bairro
        printf("\nBairro: ");
        fflush(stdin);
        fgets(cont.bairro, 100, stdin);
        getchar();
        apagar(cont.bairro);
        
    
    //Limpando a tela e concluindo cadastro
      system("clear");
      printf("\nCadastro concluído com sucesso!\n\n");

  return cont;
}

//Imprime Contato
void imprimirContato(contato c){
  printf("\n\n");
  printf("Nome:                           %s\n", c.nome);
  printf("CPF:                            %s\n", c.cpf);
  printf("RG:                             %s\n", c.rg);
  printf("Idade:                          %s\n", c.idade);
  printf("DDD:                            %s\n", c.ddd);
  printf("Telefone:                       %s\n", c.numero);
  printf("Email:                          %s\n", c.email);
  printf("UF:                             %s\n", c.uf);
  printf("CEP:                            %s\n", c.cep);
  printf("Cidade:                         %s\n", c.cidade);
  printf("Rua:                            %s\n", c.rua);
  printf("Bairro:                         %s\n", c.bairro);
  printf("\n");
}

//Altera Contato
void alterarContato(agenda*a, int x, int opcao){

  switch(opcao){

    case 1:
      printf("Novo nome: ");
      fflush(stdin);
      fgets(a->contatos[x].nome, 100, stdin);
      apagar(a->contatos[x].nome);
    break;

    case 2:
      printf("Novo CPF: ");
      fflush(stdin);
      fgets(a->contatos[x].cpf, 20, stdin);
      apagar(a->contatos[x].cpf);
    break;

    case 3:
      printf("Novo RG: ");
      fflush(stdin);
      fgets(a->contatos[x].rg, 16, stdin);
      apagar(a->contatos[x].rg);
    break;

    case 4:
      printf("Nova idade: ");
      fflush(stdin);
      fgets(a->contatos[x].idade, 3, stdin);
      apagar(a->contatos[x].idade);
    break;

    case 5:
      printf("Novo DDD: ");
      fflush(stdin);
      fgets(a->contatos[x].ddd, 4, stdin);
      apagar(a->contatos[x].ddd);
    break;

    case 6:
      printf("Novo telefone: ");
      fflush(stdin);
      fgets(a->contatos[x].numero, 10, stdin);
      apagar(a->contatos[x].numero);
    break;

    case 7:
      printf("Novo email: ");
      fflush(stdin);
      fgets(a->contatos[x].email, 80, stdin);
      apagar(a->contatos[x].email);
    break;

    case 8:
      printf("Novo UF: ");
      fflush(stdin);
      fgets(a->contatos[x].uf, 3, stdin);
      apagar(a->contatos[x].uf);
    break;

    case 9:
      printf("Novo CEP: ");
      fflush(stdin);
      fgets(a->contatos[x].cep, 9, stdin);
      apagar(a->contatos[x].cep);
    break;

    case 10:
      printf("Nova cidade: ");
      fflush(stdin);
      fgets(a->contatos[x].cidade, 100, stdin);
      apagar(a->contatos[x].cidade);
    break;

    case 11:
      printf("Nova rua: ");
      fflush(stdin);
      fgets(a->contatos[x].rua, 100, stdin);
      apagar(a->contatos[x].rua);
    break;

    case 12:
      printf("Novo bairro: ");
      fflush(stdin);
      fgets(a->contatos[x].bairro, 100, stdin);
      apagar(a->contatos[x].bairro);
    break;

    default:
      printf("Opção inválida!");
    break; 
  }

}

//Imprime Lista de contato
void imprimirLista(const agenda*a){
    int i;
    for(i=0; i<a->total; i++){
      imprimirContato(a->contatos[i]);
      printf("----------------------------------------------------\n");
    }
}

//Menu de opções
void menu(){
  printf("\n\tO que deseja fazer?\n\n");
  printf("[1] - Adicionar Novo Contato\n");
  printf("[2] - Procurar Contato\n");
  printf("[3] - Alterar Contato\n");
  printf("[4] - Listar Contatos\n");
  printf("[5] - Excluir Contato\n");
  printf("[6] - Sair\n\n");
}

//Comparando Nome
int comparaNome(contato a, char vetor[]){
  return strcmp(a.nome, vetor);
}

//Comparando CPF
int comparaCPF(contato a, char vetor[]){
  return strcmp(a.cpf, vetor);
}

//Procurando Contato
int procurarContato(const agenda*a, char vetor[], int opc){
  int i;
  
  if(opc == 1)
  {
    for(i=0; i<a->total; i++){
          if(comparaNome(a->contatos[i], vetor) == 0){
            return i;
          }
        }
        return -1;
  }
  else
  {
    for(i=0; i<a->total; i++){
          if(comparaCPF(a->contatos[i], vetor) == 0){
            return i;
          }
        }
        return -1;
  }     

}

//Excluindo Contato
void excluirContato(agenda*a, int i){
  contato contVazio;
  a->contatos[i].nome[0] = '\0';
  a->contatos[i].cpf[0] = '\0';
  a->contatos[i].rg[0] = '\0';
  a->contatos[i].idade[0] = '\0';
  a->contatos[i].ddd[0] = '\0';
  a->contatos[i].numero[0] = '\0';
  a->contatos[i].email[0] = '\0';
  a->contatos[i].uf[0] = '\0';
  a->contatos[i].cep[0] = '\0';
  a->contatos[i].cidade[0] = '\0';
  a->contatos[i].rua[0] = '\0';
  a->contatos[i].bairro[0] = '\0';
  a->contatos[i] = a->contatos[i+1];
  a->contatos[i+1] = contVazio;
  a->total--;
}
