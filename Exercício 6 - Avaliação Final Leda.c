#include <stdio.h>

typedef struct {
  int safraVinho;
  int especial;
  int posicaoVinho;
  char nomeProduto[50]; 
  char paisOrigem[50];
  char tipoUva[50];
  int numero;
} Vinho;


Vinho *listaVinhos, *listaEspecial, *listaNE;
int tamanhoLista = 0, tamanhoEspecial = 0, tamanhoNE = 0, counter = 0;







Vinho registroVinho();
void alocacaoVinho(Vinho);
void exibirInformacoes(int posicao);
void exibirLista();
void encaminhamento();
void abrirEspecial();
void abrirNE();
void exibirCA();
void exibirCR();
void exibirNum();












int main(void) {
  int opcao = 0;
  while (opcao != 7) {
    printf("\nEscolha uma opção:\n");
    printf("[1] - Registrar Vinho\n");
    printf("[2] - Listar Vinhos\n");
    printf("[3] - Abrir Vinho Para Ocasião Especial\n");
    printf("[4] - Abrir Vinho Para Ocasião Não-Especial\n");
    printf("[5] - Listar 5 Vinhos Mais Antigos\n");  
    printf("[6] - Listar 5 Vinhos Mais Recentes\n");
    printf("[7] - Fechar o Programa\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
      alocacaoVinho(registroVinho());
    }  
    if (opcao == 2) {
      exibirLista();      
    }
    if (opcao == 3){
      abrirEspecial();
    }
    if (opcao == 4){
      abrirNE();
    }
    if (opcao == 5){
      exibirCA();
    }
    if (opcao == 6){
      exibirCR();
    }
    if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7) {
      printf("\n\n======== OPÇÃO INVÁLIDA ========\n\n");
    }
  }
  return 0;
}








Vinho registroVinho(){
  Vinho vinho;
  int especial = 0;
  
    printf("\nEste vinho é para uma ocasião especial?\n");
    printf("[1] - Sim\n");
    printf("[2] - Não\n");
    printf("Opção: ");
      scanf("%d%*c", &vinho.especial);
  
    printf("\n\nDigite o nome do vinho: ");
      scanf("%[^\n]%*c", &vinho.nomeProduto);
    printf("Digite o país de origem: ");
     scanf("%[^\n]%*c", &vinho.paisOrigem);
    printf("Digite o tipo da uva utilizada: ");
     scanf("%[^\n]%*c", &vinho.tipoUva);
    printf("Digite a safra do vinho: ");
     scanf("%d%*c", &vinho.safraVinho);

  vinho.numero++;

  return vinho;
}




void alocacaoVinho(Vinho vinho){
  
  listaVinhos = (Vinho *)realloc(
      listaVinhos, (tamanhoLista + 1) * sizeof(Vinho));

  if (listaVinhos == NULL) {
    printf("\n\n======== FALHA AO SALVAR VINHO ========\n\n");
  } 
  else {
    listaVinhos[tamanhoLista] = vinho;
    tamanhoLista++;

    if (vinho.especial == 1){
    listaEspecial = (Vinho *)realloc(
      listaEspecial, (tamanhoLista + 1) * sizeof(Vinho));

    if (listaEspecial == NULL) {
    printf("\n\n======== FALHA AO SALVAR VINHO ESPECIAL ========\n\n");
  }
   else { 
    listaEspecial[tamanhoEspecial] = vinho;
    tamanhoEspecial++;
   }  
  }
    if (vinho.especial == 2){
    listaNE = (Vinho *)realloc(
      listaNE, (tamanhoLista + 1) * sizeof(Vinho));

    if (listaNE == NULL) {
    printf("\n\n======== FALHA AO SALVAR VINHO NÃO-ESPECIAL ========\n\n");
  }  
   else{
    listaNE[tamanhoNE] = vinho;
    tamanhoNE++;
   }   
  }
 }
}



void exibirInformacoes(int posicao) {
  printf("\nNome do Vinho: %s\n", listaVinhos[posicao].nomeProduto);
  printf("País de Origem: %s\n", listaVinhos[posicao].paisOrigem);
  printf("Tipo da Uva: %s\n", listaVinhos[posicao].tipoUva);
  printf("Ano da Safra: %d\n", listaVinhos[posicao].safraVinho);
}





void exibirLista() {
  for (int i = tamanhoLista - 1; i >= 0; i--) {
    exibirInformacoes(i);
  }
}


void exibirNum() {
  for (int i = tamanhoLista - 1; i >= 0; i--) {
    printf("NE: %d // L: %d\n", listaNE[i].numero, listaVinhos[i].numero);
  }
}


void abrirEspecial(){
  if(tamanhoEspecial == 0){
    printf("\nNão há vinhos especiais para serem abertos.\n");
  }  
  else{
    --tamanhoEspecial;
    printf("O vinho aberto foi o %s.\n", listaEspecial[tamanhoEspecial].nomeProduto);
      for(int i = 0; i < tamanhoLista; i++){
        if(listaEspecial[tamanhoEspecial].numero == listaVinhos[i].numero){
          for(int j = i; j < tamanhoLista; j++){
            listaVinhos[j] = listaVinhos[j + 1];
          }
        }
      }
    --tamanhoLista;
  }
}

void abrirNE(){
  if(tamanhoNE <= 0){
    printf("\nNão há vinhos não-especiais para serem abertos.\n");
  }
  else{
   --tamanhoNE;
    counter = 0;
    printf("\nO vinho aberto foi o %s.\n", listaNE[counter].nomeProduto);
    for(int a = tamanhoLista; a >= 0; a--){
        if(listaVinhos[a].numero == listaNE[counter].numero){
          for(int b = a; b < tamanhoLista; b++){
            listaVinhos[b] = listaVinhos[b + 1];
          }
        }
      }
     for(counter = 0; counter < tamanhoNE; counter++){
       listaNE[counter] = listaNE[counter + 1];
     }
    --tamanhoLista;
  }
}

void exibirCA(){
  for (int i = 0; i < 5; i++){
    exibirInformacoes(i);
  }
}

void exibirCR(){
  for (int i = tamanhoLista - 1; i > tamanhoLista - 6; i--){
    exibirInformacoes(i);
  }
}