void CadastroFornecedor(fornecedor *lista_fornecedores,int i){
    printf("Insira o nome do fornecedor: ");
    scanf("%d", &lista_fornecedores[i].id);

    printf("Insira o endereço do ponto de coleta: ");
    scanf("%s", &lista_fornecedores[i].ende_forne);
}

void AtualizaFornecedor(fornecedor *lista_fornecedores, int i, int id){
    for(int j=0; j< i+1;j++){
        if(lista_fornecedores[j].id == id){
            printf("Insira o novo endereço do fornecedor: ");
            scanf("%s",lista_fornecedores[i].ende_forne);
        }
    }
    printf("Informação atualizada com sucesso!");

  
}

void MenuFornecedor(fornecedor *lista_fornecedores, char opcao , int i){

  switch(opcao){
    case 'a':
    CadastroFornecedor(fornecedor *lista_fornecedores, int i, int id);
    break;

    case 'b':
    AtualizaFornecedor(fornecedor *lista_fornecedores, int i);
    break;
  }

    //Possibilidade de realizar alguma operação novamente
    printf("\nDeseja realizar outra operação na aba de fornecedores? (s) sim (n)não\n");
    scanf("%c",&opcao);

    if (opcao == 's')
        MenuPontoColeta(lista_fornecedores, opcao, i);
    break;

}