#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //necessário para usar setlocale
#include<string.h>


//Structs
typedef struct{
    int id;
    char nome[777];
    char endereco[777];
} fornecedor;

void escreverListaFornecedores(fornecedor *lista_fornecedores, int i) {
    FILE *arquivo;
    arquivo = fopen("fornecedores.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

       // Escrever nome do fornecedor
    fputs("Nome: ", arquivo);
    fputs(lista_fornecedores[i].nome, arquivo);
    fputs("\n", arquivo);

    // Escrever endereço do fornecedor
    fputs("Endereço: ", arquivo);
    fputs(lista_fornecedores[i].endereco, arquivo);
    fputs("\n\n", arquivo);

    fclose(arquivo);
}

  

//Funções fornecedor
void CadastroFornecedor(fornecedor *lista_fornecedores, int i) {
    printf("\nInsira o nome do fornecedor: ");
    scanf(" %[^\n]",lista_fornecedores[i].nome);

    printf("Insira o endereço do fornecedor: ");
    scanf(" %[^\n]",lista_fornecedores[i].endereco);

    escreverListaFornecedores(lista_fornecedores, i);
}

void AtualizaFornecedor(fornecedor *lista_fornecedores, int id){
    int tamanho = sizeof(lista_fornecedores[0]) / sizeof(fornecedor); 
    char novo_endereco[200];
    for(int j=0; j< tamanho+1;j++){
        if(lista_fornecedores[j].id == id){
            printf("Insira o novo endereço do fornecedor: ");
            scanf("%s",novo_endereco);

            strcpy(novo_endereco, lista_fornecedores[j].nome);
        }
    }
    printf("Informação atualizada com sucesso!");

  
}

void MenuFornecedor(fornecedor *lista_fornecedores, char opcao , int i){

  switch(opcao){
    case 'a':
    CadastroFornecedor(lista_fornecedores, i);
    break;

    case 'b':
    AtualizaFornecedor(lista_fornecedores, i);
    break;
  }

    //Possibilidade de realizar alguma operação novamente
    printf("\nDeseja realizar outra operação na aba de fornecedores? (s) sim (n)não\n");
    scanf("%c",&opcao);  

}



int main() {

    char linha[177];
    int t_csv = 100;
    FILE* arquivo1;
    int count = 0;
    fornecedor *fornecedores = malloc(t_csv * sizeof(fornecedor));


    arquivo1 = fopen("fornecedores.csv", "r");
    if(arquivo1 == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while(count < t_csv)
    {
        if(fgets(linha, sizeof(linha), arquivo1) == NULL)
        {
            break;
        }
        sscanf(linha, "%d;%[^;];%[^\n]",
            &fornecedores[count].id,
            fornecedores[count].nome,
            fornecedores[count].endereco);

        // fornecedores[count].id = count + 1;

        count++;
    }
    fclose(arquivo1);
  
//Menu Principal
setlocale(LC_ALL,"Portuguese");
int i = 0;

fornecedor lista_fornecedores[100];
char resp_forne = 's';
char op_menu_p;
char op_aba;

do{
printf("\n---Bem vindo(a) ao Sistema Ecowise---\n\n");
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
    
    printf("\n(a)Cadastrar Fornecedor\n(b)Atualizar Informações\n");
    scanf(" %c",&op_aba);
    int inteiro;
    if(op_aba == 'b'){
        printf("ID: ");
        scanf("%d", &inteiro);
    }
    MenuFornecedor(lista_fornecedores, op_aba, inteiro);
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
    printf("\nQuer realizar uma nova operação? (s)sim (n)não:");
    scanf(" %c",&resp_forne);
    
}while(resp_forne == 's');

  
  return 0;
}
