void MenuFornecedor(char escolha, int i){
  fornecedor Fornecedores[30];

  switch(escolha){
    case 'a':
    printf("Digite o nome do fornecedor: \n");
        scanf("%s",Fornecedores[i].nome);
    printf("Digite o endereço do fornecedor: \n");
        scanf("%s",Fornecedores[i].ende_forne);
    break;

    case 'b':
    printf("Atualize o nome do fornecedor:\n");
      scanf("%s",Fornecedores[i].nome);
    printf("Atualize o endereço do fornecedor:\n");
        scanf("%s",Fornecedores[i].ende_forne);
    break;
  }

  printf("%s\n",Fornecedores[i].nome);
  printf("%s",Fornecedores[i].ende_forne);
}