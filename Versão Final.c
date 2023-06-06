#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //para o setlocale
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
    int quant;
    data data_registro;

} material;

typedef struct
{
    char nome[777];
    char endereco[777];
    material materiais[5];

} fornecedor;

typedef struct
{
int id;
char ende_pc[30];
material materiais[5];
} ponto_coleta;


//Funções fornecedor
void escreverListaFornecedores(fornecedor *lista_fornecedores, int i, char tipo_material, material *materiais) {
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
    fputs("\n", arquivo);

     switch(tipo_material){
        case 'a':
        fputs("Material: Papelão", arquivo);
        break;
        case 'b':
        fputs("Material: Papel", arquivo);
        break;
        case 'c':
        fputs("Material: Vidro", arquivo);
        break;
        case 'd':
        fputs("Material: Metal", arquivo);
        break;
        case 'e':
        fputs("Material: Lixo eletrônico", arquivo);
        break;
    }
    
    fprintf(arquivo, "\nQuantidade: %d kg", materiais[i].quant);
    fprintf(arquivo, "\nData de Registro: %d/%d/%d", materiais[i].data_registro.dia, materiais[i].data_registro.mes, materiais[i].data_registro.ano);
    fputs("\n\n-----------\n\n", arquivo);

    fclose(arquivo);

}

void CadastroFornecedor(fornecedor *lista_fornecedores, int i, material *materiais) {
    printf("\nInsira o nome do fornecedor: ");
    scanf(" %[^\n]",lista_fornecedores[i].nome);

    printf("Insira o endereço do fornecedor: ");
    scanf(" %[^\n]",lista_fornecedores[i].endereco);

     static char tipo_material;
    
   printf("\nQual material você deseja cadastrar? ");
    printf("\n(a) Papelão\n(b) Papel\n(c) Vidro\n(d) Metal\n(e) Lixo eletronico\n");
    scanf(" %c", &tipo_material);

    switch (tipo_material)
    {
        case 'a':
            
            
                printf("\nDigite a quantidade de papelão que foi recebido (em kg): ");
                scanf("%d", &materiais[i].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
                
       
        
            break;
            
        case 'b':
            
                printf("\nDigite a quantidade de papel que foi recebido (em kg): ");
                scanf("%d", &materiais[i].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
                
            break;
        
        case 'c':
            
            
                printf("\nDigite a quantidade de vidro que foi recebido (em kg): ");
                scanf("%d", &materiais[i].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
                
            
           break;
            
        case 'd':
            
                printf("\nDigite a quantidade de metal que foi recebido (em kg): ");
                scanf("%d", &materiais[i].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
                
            break;
            
        case 'e':
                printf("\nDigite a quantidade de lixo eletrônico que foi recebido (em kg): ");
                scanf("%d", &materiais[i].quant);

                printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
            break;
            
        break;
        
    }
    escreverListaFornecedores(lista_fornecedores,i,tipo_material, materiais);
     i+=1;
    
}


//Funções pontos de coleta
void escreverListaPontos(ponto_coleta *lista_pontos, int i, char tipo_material, material *materiais) {
    FILE *relatorio_pontos;
    relatorio_pontos = fopen("lista_pontos_coleta.txt", "a");

    if (relatorio_pontos == NULL) {
        printf("Erro ao criar o relatorio_pontos.\n");
        return;
    }

       // Escrever ID do ponto de coleta
    fputs("ID: ", relatorio_pontos);
    fprintf(relatorio_pontos, "%d", lista_pontos[i].id);
    
    fputs("\n", relatorio_pontos);

    // Escrever endereço do ponto de coleta
    fputs("Endereço: ", relatorio_pontos);
    fputs(lista_pontos[i].ende_pc, relatorio_pontos);
    fputs("\n", relatorio_pontos);
    
    switch(tipo_material){
        case 'a':
        fputs("Material: Papelão", relatorio_pontos);
        break;
        case 'b':
        fputs("Material: Papel", relatorio_pontos);
        break;
        case 'c':
        fputs("Material: Vidro", relatorio_pontos);
        break;
        case 'd':
        fputs("Material: Metal", relatorio_pontos);
        break;
        case 'e':
        fputs("Material: Lixo eletrônico", relatorio_pontos);
        break;
    }
    
    fprintf(relatorio_pontos, "\nQuantidade: %d kg", materiais[i].quant);
    fprintf(relatorio_pontos, "\nData de Registro: %d/%d/%d", materiais[i].data_registro.dia, materiais[i].data_registro.mes, materiais[i].data_registro.ano);
    fputs("\n\n-----------\n\n", relatorio_pontos);
    fclose(relatorio_pontos);
}


void CadastroPontoColeta(ponto_coleta *lista_pontos_coleta, int i, material *materiais){
    
    srand(time(NULL));
  
    lista_pontos_coleta[i].id = rand(); 
    

    printf("insira o endereço do ponto de coleta: ");
    
    scanf(" %[^\n]",lista_pontos_coleta[i].ende_pc);
   
    printf("O id do ponto de coleta registrado será: %d", lista_pontos_coleta[i].id);
    
    static char tipo_material;
    
    printf("\n\nQual material você deseja cadastrar? ");
    printf("\n(a) Papelão\n(b) Papel\n(c) Vidro\n(d) Metal\n(e) Lixo eletronico\n");
    scanf(" %c", &tipo_material);

    switch (tipo_material)
    {
        case 'a':
            
            printf("\nDigite a quantidade de papelão que foi recebido (em kg): ");
            scanf("%d", &materiais[i].quant);
        
            printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
            break;
            
        case 'b':
            
            printf("\nDigite a quantidade de papel que foi recebido (em kg): ");
            scanf("%d", &materiais[i].quant);
        
            printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
            break;
        
        case 'c':
            
            printf("\nDigite a quantidade de vidro que foi recebido (em kg): ");
            scanf("%d", &materiais[i].quant);
        
            printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
            break;
            
        case 'd':
            
            printf("\nDigite a quantidade de metal que foi recebido (em kg): ");
            scanf("%d", &materiais[i].quant);
        
            printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
            break;
            
        case 'e':
            
            printf("\nDigite a quantidade de lixo eletrônico que foi recebido (em kg): ");
            scanf("%d", &materiais[i].quant);
        
            printf("\nDigite a data em que a coleta foi feita (Escreva: DD MM AAAA): ");
            scanf("%d %d %d", &materiais[i].data_registro.dia, &materiais[i].data_registro.mes, &materiais[i].data_registro.ano);
            break;
            
        break;
        
    }
    

    escreverListaPontos(lista_pontos_coleta, i, tipo_material, materiais);

     (i)++;
    
}


void imprimirArquivo(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        putchar(caractere);
    }
    
    fclose(arquivo);
}

int main() 
{
    
    setlocale(LC_ALL,"Portuguese");
    int ind_forne = 0;
    int p_index = 0;
    
    ponto_coleta lista_pontos[100];
    fornecedor lista_fornecedores[100];
    material materiais[100];
    char resp_forne = 's';
    char op_menu_p;
    char op_aba;
     
     printf("\n---Nossas Boas Vindas ao Sistema Ecowise---\n");
     
    do{
       
        printf("\n*Menu Principal*\n\n");
        printf("Selecione o menu desejado:\n\n");
        printf("(a)Fornecedores\n(b)Pontos de Coleta\n");
        
          scanf(" %c",&op_menu_p);
        
        switch(op_menu_p)
        {
            case 'a': //Fornecedores
            
            printf("\n(a)Cadastrar Material em Fornecedor\n(b)Histórico de fornecedores\n");
            scanf(" %c",&op_aba);
            if(op_aba == 'a') CadastroFornecedor(lista_fornecedores, ind_forne, materiais);
                        
            else if(op_aba == 'b') {
                printf("\n");
                imprimirArquivo("fornecedores.txt");}
            break;
            
            
            case 'b': // Pontos de Coleta
            printf("\n(a)Cadastrar Material em Ponto de Coleta\n(b)Histórico de Pontos de coletas\n");
            scanf(" %c",&op_aba);
            if(op_aba == 'a') CadastroPontoColeta(lista_pontos, p_index, materiais);

            else if(op_aba == 'b') {
                printf("\n");
                imprimirArquivo("lista_pontos_coleta.txt");}
            break;

            
        }
            printf("\nQuer realizar uma nova operação? (s)sim (n)não: ");
            scanf(" %c",&resp_forne);
            
    }while(resp_forne == 's');
    
    printf("\n\nFim do Registro");
    
    return 0;
}