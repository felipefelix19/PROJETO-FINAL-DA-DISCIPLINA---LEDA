#include <stdio.h>
#include <string.h>

typedef struct Node {
  int number;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
  int max_items;
  int qty;
} Stack;

Stack *inicializacao(){

  int tamanho;

  printf("Digite o tamanho desejado da pilha: ");
    scanf("%d", &tamanho);
  
  Stack *pointer = malloc(sizeof(Stack));

  pointer -> top = NULL;
  pointer -> qty = 0;
  pointer -> max_items = tamanho;

  return pointer;
}

void push(Stack *pointer){

  int numero;

  printf("\nDigite um número: ");
    scanf("%d", &numero);
  
  if(pointer -> qty == pointer -> max_items){
    printf("\nA pilha está cheia.\n");
  } 

  Node *proximo = malloc(sizeof(Node));
    proximo -> number = numero;
    proximo -> next = NULL;

  if(pointer -> qty != 0){
    proximo -> next = pointer -> top;
  }  
    pointer -> top = proximo;
    pointer -> qty++;
}

void pop(Stack *pointer) {

  if(pointer -> qty == 0){
    printf("\nA pilha está vazia.\n");
    return 0;
  }

  Node *descarte = pointer -> top;

  pointer -> top = pointer -> top -> next;
  pointer -> qty--;
  free(descarte);
}

void listagem(Stack *pointer) {

  if(pointer -> qty == 0){
    printf("\nA pilha está vazia.\n");
    return 0;
  }

  Node *topo = pointer -> top;

  for(int i = 0; i < pointer -> max_items; i++){
    printf("%d\n", topo -> number);
    topo = topo -> next;
  }

}


int tamanhoPilha(Stack *pointer){
  printf("\nO tamanho da pilha é: %d\n", pointer -> qty);

  return 0;
}

int checarCheia(Stack *pointer){

  if(pointer -> qty == pointer -> max_items){
    printf("\nA pilha está cheia.\n");
  }  
  else{
    printf("\nHá espaço na pilha.\n");
  }
  
  return 0;
}
  

int checarVazia(Stack *pointer){
  
  if(pointer -> qty == 0){
    printf("\nA pilha está vazia.\n");
  }
  else{
    printf("\nHá itens na pilha\n");
  }

  return 0;
}

int verificarNumero(Stack *pointer) {
  
  Node *topo = pointer -> top;
  int numero;
  
  printf("Digite o número que deseja procurar: ");
    scanf("%d", numero);

  for(int i = 0; i < pointer -> max_items; i++){
    if(numero == topo -> number){
      return printf("O número requisitado está na pilha.");
    }  
    topo = topo -> next; 
  } 
  return printf("Número não encontrado.");
}





int main(void){
  
  int opcao, numero;
  Stack *pilha;

  pilha = inicializacao();

  while (opcao != 8) {
    printf("\nEscolha uma opção:\n");
    printf("[1] - Empilhar\n");
    printf("[2] - Desempilhar\n");
    printf("[3] - Listar\n");
    printf("[4] - Quantidade de Itens\n");
    printf("[5] - Verificar Pilha Cheia\n");
    printf("[6] - Verificar Pilha Vazia\n");
    printf("[7] - Verificar Número\n");
    printf("[8] - Sair\n");
    printf("Opção: ");
      scanf("%d",&opcao);
        if (opcao == 1) {
          push(pilha);
        }  
        if (opcao == 2) {
          pop(pilha); 
        }
        if (opcao == 3){
          printf("\n");
          listagem(pilha);
        }
        if (opcao == 4){
         tamanhoPilha(pilha);
        }
        if (opcao == 5){
         checarCheia(pilha);
        }
        if (opcao == 6){
         checarVazia(pilha);
        }
        if(opcao == 7){
          verificarNumero(pilha);
        }
        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7 && opcao != 8) {
          printf("\n\n======== OPÇÃO INVÁLIDA ========\n\n");
        }
  }
  
  return 0;
}