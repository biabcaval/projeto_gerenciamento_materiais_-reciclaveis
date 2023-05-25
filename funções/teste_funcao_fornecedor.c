#pragma execution_character_set("utf-8")

#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //necessário para usar setlocale
#include<string.h>

//Structs
typedef struct{
char nome[30];
char ende_forne[50];
} fornecedor;


//Funções
void CadastroFornecedor(fornecedor *lista_fornecedores,int i){
    printf("Insira o nome do fornecedor: ");
    scanf(" %s", lista_fornecedores[i].nome);

    printf("Insira o endereço do ponto de coleta: ");
    scanf(" %s", lista_fornecedores[i].ende_forne);
}

/*void AtualizaFornecedor(fornecedor *lista_fornecedores, int i, int id){
    for(int j=0; j< i+1;j++){
        if(lista_fornecedores[j].id == id){
            printf("Insira o novo endereço do fornecedor: ");
            scanf("%s",lista_fornecedores[i].ende_forne);
        }
    }
    printf("Informação atualizada com sucesso!");

  
}*/

void MenuFornecedor(fornecedor *lista_fornecedores, char opcao , int i){

  switch(opcao){
    case 'a':
    CadastroFornecedor(lista_fornecedores, i);
    break;

    /*case 'b':
    AtualizaFornecedor(fornecedor *lista_fornecedores, int i);
    break;
  }*/

    //Possibilidade de realizar alguma operação novamente
    printf("\nDeseja realizar outra operação na aba de fornecedores? (s) sim (n)não\n");
    scanf("%c",&opcao);  

}
}
int main() {
  
//Menu Principal
setlocale(LC_ALL,"Portuguese");
int i = 0;

fornecedor lista_fornecedores[100];
char resp_forne = 's';
char op_menu_p;
char op_aba;


printf("---Bem vindo(a) ao Sistema Ecowise---\n\n");
printf("*Menu Principal*\n\n");
printf("Selecione a aba que você quer acessar:\n\n");
printf("(a)Resíduos\n(b)Fornecedores\n(c)Pontos de Coleta\n(d)Relatórios\n");

  scanf(" %c",&op_menu_p);

switch(op_menu_p){
  case 'a': // Materiais
    printf("(a)Cadastrar material\n(b)Atualizar material\n");
    scanf(" %c",&op_aba);
    //chamar função
    break;
  
  case 'b': //Fornecedores
    
    printf("(a)Cadastrar Fornecedor\n(b)Atualizar Informações\n");
    scanf(" %c",&op_aba);
    MenuFornecedor(lista_fornecedores, op_aba, i);
  /*do {  
  MenuFornecedor(op_aba, i);
  
//} while (resp_forne == 's');

    printf("Deseja fazer outra operação no Menu Fornecedores?\n");
  scanf(" %c", &resp_forne);  // Lê o caractere dentro do loop
  i++;*/
    //chamar função
  break;

  case 'c': // Pontos de Coleta
    printf("(a)Cadastrar Ponto de Coleta\n(b)Atualizar Informações\n");
    scanf(" %c",&op_aba);
    //chamar função
  break;

  case 'd': //Relatórios
    printf("(a)Estatísticas\n(b)Lista de Pontos de Coleta\n(c)Lista de Fornecedores\n");
    //chamar função
  break;
}
    printf("Quer realizar uma nova operaçãp?");
    scanf("%c",&op_menu_p);

  return 0;
}
