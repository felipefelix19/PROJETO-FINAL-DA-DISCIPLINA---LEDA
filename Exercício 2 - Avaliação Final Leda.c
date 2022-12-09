#include <stdio.h>
#include <string.h>


typedef struct Node{
  int number;
  struct Node *next;
} Node;

typedef struct{
  Node *head; 
  Node *tail; 
  int max_items;
  int qty;
} Queue;

Queue *inicializar(){

  int tamanho;

  printf("Digite o tamanho desejado da fila: ");
    scanf("%d", &tamanho);
  
  Queue *pointer = malloc(sizeof(Queue));

  pointer -> head = NULL;
  pointer -> tail = NULL;
  pointer -> qty = 0;
  pointer -> max_items = tamanho;

  return pointer;
}


void enqueue(Queue *pointer){
  
  if(pointer -> qty == pointer -> max_items){
    printf("\nA fila está cheia.\n");
  return 0;  
  }

  int numero = 0;
  
  printf("\nDigite o número que deseja adicionar: ");
    scanf("%d", &numero);
  
  Node *proximo = malloc(sizeof(Node));
  proximo -> number = numero;
  proximo -> next = NULL;

  if (pointer -> qty == 0){
    pointer -> head = proximo;
  } 
  else{
    pointer -> tail -> next = proximo;
  }

  pointer -> tail = proximo;
  pointer -> qty++;

}

void dequeue(Queue *pointer){


  if(pointer -> qty == 0){
    printf("\nA fila está vazia.\n");
    return 0;
   }

  Node *descarte = pointer -> head;

  if(pointer -> head -> next != NULL){
    pointer -> head = pointer -> head -> next;
  } 
  else{
    pointer -> head = NULL;
  }
  
  pointer -> qty--;
  free(descarte);
  
}

int tamanhoFila(Queue *pointer){
  
  printf("\nO tamanho da fila é: %d\n", pointer -> qty);
  
  return 0;
}

int checarCheia(Queue *pointer){
  
  if(pointer -> qty == pointer -> max_items){
    printf("\nA fila está cheia.\n");
  }  
  else{
    printf("\nHá espaço na fila.\n");
  }
  
}

int checarVazia(Queue *pointer){

  if(pointer -> qty == 0){
    printf("\nA fila está vazia.\n");
  }
  else{
    printf("\nHá itens na fila\n");
  }
  
}


void listagem(Queue *pointer){

  if(pointer -> qty == 0){
    printf("\nA fila está vazia.\n");
    return 0;
   }
  

  Node *head = pointer -> head;


  for(int i = 0; i < head; i++){
    printf("%d\n", head -> number);
    head = head -> next;
  }

}


int main(void){
  
  int opcao;
  Queue *fila;

  fila = inicializar();

  while (opcao != 7) {
    printf("\nEscolha uma opção:\n");
    printf("[1] - Inserir\n");
    printf("[2] - Retirar\n");
    printf("[3] - Listar\n");
    printf("[4] - Quantidade de Itens\n");
    printf("[5] - Verificar Fila Cheia\n");
    printf("[6] - Verificar Fila Vazia\n");
    printf("[7] - Verificar Número\n");
    printf("[8] - Sair\n");
    printf("Opção: ");
      scanf("%d",&opcao);
        if (opcao == 1) {
          enqueue(fila);
        }  
        if (opcao == 2) {
          dequeue(fila); 
        }
        if (opcao == 3){
          printf("\n");
          listagem(fila);
        }
        if (opcao == 4){
         tamanhoFila(fila);
        }
        if (opcao == 5){
         checarCheia(fila);
        }
        if (opcao == 6){
         checarVazia(fila);
        }
        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7) {
          printf("\n\n======== OPÇÃO INVÁLIDA ========\n\n");
        }
  }
  
  return 0;