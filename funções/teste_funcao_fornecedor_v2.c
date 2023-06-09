#include<stdio.h>
#include<string.h>

typedef struct{
int id;
char ende_pc[30];
} ponto_coleta;

// função que cria lista dos pontos de coleta

void escreverListaPontos(ponto_coleta *lista_pontos, int i) {
    FILE *arquivo;
    arquivo = fopen("pontos_coleta.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

       // Escrever nome do ponto
    fputs("Id: ", arquivo);
    fputs(lista_pontos[i].id, arquivo);
    fputs("\n", arquivo);

    // Escrever endereço do ponto
    fputs("Endereço: ", arquivo);
    fputs(lista_pontos[i].ende_pc, arquivo);
    fputs("\n\n", arquivo);

    fclose(arquivo);
}



// função de cadastro de um ponto de coleta
void CadastroPontoColeta(ponto_coleta *lista_pontos, int i){
  
    lista_pontos[i].id = i;

    printf("insira o endereço do ponto de coleta: ");
    //scanf(" %s", lista_pontos[i].ende_pc);
    scanf(" %[^\n]",lista_pontos[i].ende_pc);
   
    printf("O id do ponto de coleta registrado será: %d", lista_pontos[i].id);
    //escreverListaPontos(lista_pontos, lista_pontos[i].id);
    

}

// função que atualiza um ponto de coleta
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

            printf("\nDeseja realizar outra operação na aba de pontos de coleta? (s)sim (n)não");
            scanf(" %c", &resp);

              if (resp == 's'){
                printf("(a)Cadastrar Ponto de Coleta\n(b)Atualizar Informações\n");
                scanf(" %c", &op_aba);
                MenuPontoColeta(lista_pontos, op_aba, i, resp);}
            break;
    }
}




int main(void) {
char resp = 's';
char op_menu_p;
char op_aba;
int p_index = 0;

ponto_coleta lista_pontos[3];  
//Menu Principal



printf("---Bem vindo(a) ao Sistema Ecowise---\n\n");
printf("*Menu Principal*\n\n");
printf("Selecione a aba que você quer acessar:\n\n");
printf("(a)Resíduos\n(b)Fornecedores\n(c)Pontos de Coleta\n(d)Relatórios\n");

scanf(" %c", &op_menu_p);

switch(op_menu_p){
  case 'a': // Resíduos
    printf("(a)Cadastrar material\n(b)Atualizar material: ");
    scanf(" %c",&op_aba);
    //chamar função
    break;
 
  case 'b': //Fornecedores
    printf("(a)Cadastrar Fornecedor\n(b)Atualizar Informações: \n");
    scanf(" %c",&op_aba);
    //chamar função
  break;

  case 'c': // Pontos de Coleta
    printf("(a)Cadastrar Ponto de Coleta\n(b)Atualizar Informações: \n");
    scanf(" %c",&op_aba);
    MenuPontoColeta(lista_pontos, op_aba, p_index, resp);
   
   
  break;

  case 'd': //Relatórios
    printf("(a)Estatísticas\n(b)Lista de Pontos de Coleta\n(c)Lista de Pontos de Coleta: \n");
    //chamar função
  break;
}

  return 0;
}
