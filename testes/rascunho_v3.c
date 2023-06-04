#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //necessário para usar setlocale
#include<string.h>


//Structs

typedef struct
{
    int dia;
    int mes;
    int ano;

} data;

typedef struct
{
    int id;
    int quant;
    data data_registro;

} material;
typedef struct{
    char nome[777];
    char endereco[777];
    material materiais[5];

} fornecedor;

typedef struct{
int id;
char ende_pc[30];
material materiais[5];
} ponto_coleta;

//Função material integrada com fornecedores e ponto de coleta TA FUNCIONANDO

void CadastroMaterial(material *materiais, int contador, fornecedor *lista_forne, int ind_forne, ponto_coleta *lista_pontos, int ind_ponto)
{   
    static int indice_aux;
 
    static char tipo_material;

    static int op_origem;

    static char nome_do_forne[30];
    
    printf("\nOrigem:\n(1) Fornecedor\n(2) Ponto de Coleta\n");
    scanf("%d",&op_origem);

    if(op_origem == 1){
        
    }

    printf("Qual o nome do fornecedor?\n");
    scanf(" %s",&nome_do_forne);

    for(int i=0;i<= ind_forne;i++){
        if (strcmp(lista_forne[i].nome, nome_do_forne) == 0) {

            indice_aux = i;
             break;
        }
    }
  
    printf("\nQual material você deseja cadastrar? ");
    printf("\n(a) Papelão\n(b) Papel\n(c) Vidro\n(d) Metal\n(e) Lixo eletronico\n");
    scanf(" %c", &tipo_material);

    switch (tipo_material)
    {
        case 'a':
            
            if (op_origem==1){
                printf("\nDigite a quantidade de papelão que foi recebido (em kg): ");
                scanf("%d", &lista_forne[indice_aux].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_forne[indice_aux].materiais[contador].data_registro.dia, &lista_forne[indice_aux].materiais[contador].data_registro.mes, &lista_forne[indice_aux].materiais[contador].data_registro.ano);
                
            }
                // ponto coleta
            else if (op_origem==2){
                printf("\nDigite a quantidade de papelão que foi recebido (em kg): ");
                scanf("%d", &lista_pontos[indice_aux].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_pontos[ind_ponto].materiais[contador].data_registro.dia, &lista_pontos[indice_aux].materiais[contador].data_registro.mes, &lista_pontos[indice_aux].materiais[contador].data_registro.ano);
            }

        
            break;
            
        case 'b':
            
            if (op_origem==1){
                printf("\nDigite a quantidade de papel que foi recebido (em kg): ");
                scanf("%d", &lista_forne[ind_forne].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_forne[indice_aux].materiais[contador].data_registro.dia, &lista_forne[indice_aux].materiais[contador].data_registro.mes, &lista_forne[indice_aux].materiais[contador].data_registro.ano);
                
            }
                // ponto coleta
            else if (op_origem==2){
                printf("\nDigite a quantidade de papel que foi recebido (em kg): ");
                scanf("%d", &lista_pontos[ind_ponto].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_pontos[indice_aux].materiais[contador].data_registro.dia, &lista_pontos[indice_aux].materiais[contador].data_registro.mes, &lista_pontos[indice_aux].materiais[contador].data_registro.ano);
            }
            break;
        
        case 'c':
            
            if (op_origem==1){
                printf("\nDigite a quantidade de vidro que foi recebido (em kg): ");
                scanf("%d", &lista_forne[ind_forne].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_forne[indice_aux].materiais[contador].data_registro.dia, &lista_forne[indice_aux].materiais[contador].data_registro.mes, &lista_forne[indice_aux].materiais[contador].data_registro.ano);
                
            }
                // ponto coleta
            else if (op_origem==2){
                printf("\nDigite a quantidade de vidro que foi recebido (em kg): ");
                scanf("%d", &lista_pontos[ind_ponto].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_pontos[indice_aux].materiais[contador].data_registro.dia, &lista_pontos[indice_aux].materiais[contador].data_registro.mes, &lista_pontos[indice_aux].materiais[contador].data_registro.ano);
            }
            break;
            
        case 'd':
            
            if (op_origem==1){
                printf("\nDigite a quantidade de metal que foi recebido (em kg): ");
                scanf("%d", &lista_forne[ind_forne].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_forne[indice_aux].materiais[contador].data_registro.dia, &lista_forne[indice_aux].materiais[contador].data_registro.mes, &lista_forne[indice_aux].materiais[contador].data_registro.ano);
                
            }
                // ponto coleta
            else if (op_origem==2){
                printf("\nDigite a quantidade de metal que foi recebido (em kg): ");
                scanf("%d", &lista_pontos[ind_ponto].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_pontos[indice_aux].materiais[contador].data_registro.dia, &lista_pontos[indice_aux].materiais[contador].data_registro.mes, &lista_pontos[indice_aux].materiais[contador].data_registro.ano);
            }
            break;
            
        case 'e':
            
            if (op_origem==1){
                printf("\nDigite a quantidade de lixo eletrônico que foi recebido (em kg): ");
                scanf("%d", &lista_forne[indice_aux].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_forne[indice_aux].materiais[contador].data_registro.dia, &lista_forne[indice_aux].materiais[contador].data_registro.mes, &lista_forne[indice_aux].materiais[contador].data_registro.ano);
                
            }
                // ponto coleta
            else if (op_origem==2){
                printf("\nDigite a quantidade de lixo eletrônico que foi recebido (em kg): ");
                scanf("%d", &lista_pontos[ind_ponto].materiais[contador].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &lista_pontos[ind_ponto].materiais[contador].data_registro.dia, &lista_pontos[indice_aux].materiais[contador].data_registro.mes, &lista_pontos[indice_aux].materiais[contador].data_registro.ano);
            }
            break;
            
        break;
        
    }
    
     contador+=1;

    
    static char resp;
    
    printf("\n(s) Realizar novo cadastramento? (Digite 's' para sim ou qualquer tecla para sair) \n");
    scanf(" %c", &resp);
    
    if (resp == 's')
    {
        CadastroMaterial(materiais, contador, lista_forne, ind_forne, lista_pontos, ind_ponto);
    }

    else
    {
       printf("\nOperação finalizada com sucesso =D \n");
    }
}

// Funções ponto coleta

void escreverListaPontos(ponto_coleta *lista_pontos, int i) {
    FILE *arquivo;
    arquivo = fopen("lista_pontos_coleta.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

       // Escrever ID do ponto de coleta
    fputs("Nome: ", arquivo);
    fprintf(arquivo, "%d", lista_pontos[i].id);
    // fputs(lista_pontos[i].id, arquivo);
    fputs("\n", arquivo);

    // Escrever endereço do ponto de coleta
    fputs("Endereço: ", arquivo);
    fputs(lista_pontos[i].ende_pc, arquivo);
    fputs("\n\n", arquivo);
    fputs("-----------\n", arquivo);

    

    fclose(arquivo);
}

void CadastroPontoColeta(ponto_coleta *lista_pontos_coleta, int i){
    
    srand(time(NULL));
  
    lista_pontos_coleta[i].id = rand(); 
    

    printf("insira o endereço do ponto de coleta: ");
    
    scanf(" %[^\n]",lista_pontos_coleta[i].ende_pc);
   
    printf("O id do ponto de coleta registrado será: %d", lista_pontos_coleta[i].id);
    
    escreverListaPontos(lista_pontos_coleta, i);
    

}

void AtualizaPontoColeta(ponto_coleta *lista_pontos, int i){
    int id;
    printf("Insira o id do ponto de coleta: ");
    scanf("%d", &id);
    for(int j = 0; j < i + 1; j++){
        if (lista_pontos[j].id == id){
            printf("Insira o novo endereço do ponto de coleta: ");
            scanf("%s", lista_pontos[j].ende_pc);
        }
    }
    printf("Informação atualizada com sucesso!");
}

void MenuPontoColeta(ponto_coleta *lista_pontos, char op_aba, int i, char resp){       //função com as ações referentes a pontos de coleta.
    
       
    switch(op_aba){

       
        case 'a':
              CadastroPontoColeta(lista_pontos, i);
             
              printf("\nDeseja realizar outra operação na aba de pontos de coleta? (s)sim (n)não: ");
              scanf(" %c", &resp);
              i+=1;
              if (resp == 's'){
                printf("(a)Cadastrar Ponto de Coleta\n(b)Atualizar Informações\n");
                scanf(" %c", &op_aba);
                MenuPontoColeta(lista_pontos, op_aba, i, resp);}
              break;
       
        case 'b':
            

            AtualizaPontoColeta(lista_pontos, i);

            printf("\nDeseja realizar outra operação na aba de pontos de coleta? (s)sim (n)não: ");
            scanf(" %c", &resp);

              if (resp == 's'){
                printf("(a)Cadastrar Ponto de Coleta\n(b)Atualizar Informações:\n");
                scanf(" %c", &op_aba);
                MenuPontoColeta(lista_pontos, op_aba, i, resp);}
            break;
    }
}

//Funções fornecedor
void escreverListaFornecedores(fornecedor *lista_fornecedores, int i) {
    FILE *arquivo;
    arquivo = fopen("fornecedores.csv", "a");

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

void CadastroFornecedor(fornecedor *lista_fornecedores, int i) {
    printf("\nInsira o nome do fornecedor: ");
    scanf(" %[^\n]",lista_fornecedores[i].nome);

    printf("Insira o endereço do fornecedor: ");
    scanf(" %[^\n]",lista_fornecedores[i].endereco);


    escreverListaFornecedores(lista_fornecedores, i);

    i+=1;
}

void AtualizaFornecedor(fornecedor *lista_fornecedores, int id){
    int tamanho = sizeof(lista_fornecedores[0]) / sizeof(fornecedor); 
    char novo_endereco[200];
    for(int j=0; j< tamanho+1;j++){
        if (strcmp(lista_forne[i].nome, nome_do_forne) == 0) {
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
    int contador = 0;
    material materiais[100];
  
//Menu Principal
setlocale(LC_ALL,"Portuguese");
int ind_forne = 0;
int p_index = 0;

ponto_coleta lista_pontos[100];
fornecedor lista_fornecedores[100];
char resp_forne = 's';
char op_menu_p;
char op_aba;

do{
printf("\n---Bem vindo(a) ao Sistema Ecowise---\n\n");
printf("*Menu Principal*\n\n");
printf("Selecione a aba que você quer acessar:\n\n");
printf("(a)Materiais\n(b)Fornecedores\n(c)Pontos de Coleta\n(d)Relatórios\n");

  scanf(" %c",&op_menu_p);

switch(op_menu_p){
  case 'a': // Materiais
    printf("(a)Cadastrar material\n(b)Atualizar material\n");
    scanf(" %c",&op_aba);
    CadastroMaterial(materiais, contador, lista_fornecedores,ind_forne, lista_pontos, p_index);
    break;
  
  case 'b': //Fornecedores
    
    printf("\n(a)Cadastrar Fornecedor\n(b)Atualizar Informações\n");
    scanf(" %c",&op_aba);
    MenuFornecedor(lista_fornecedores, op_aba, ind_forne);
  break;

  case 'c': // Pontos de Coleta
    printf("(a)Cadastrar Ponto de Coleta\n(b)Atualizar Informações\n");
    scanf(" %c",&op_aba);
    MenuPontoColeta(lista_pontos,op_aba, p_index, op_aba);
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
