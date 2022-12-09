#include <stdio.h>
#include <string.h>



struct pilha{
  int item[1000];
  int quantidade;
};

struct fila{
  int item[200];
  int quantidade;
};

void inicializarPilha(struct pilha * pilha){
    memset(pilha, 0, sizeof(struct pilha));
}

void inicializarFila(struct fila * fila){
    memset(fila, 0, sizeof(struct fila));
}

int pop(struct pilha * pilha){
    if(pilha -> quantidade == 0){
        return -2;
    }
    return pilha -> item[--pilha -> quantidade];
}

int push(struct pilha * pilha){

  int valor = 1;

  while(valor > 0){
    printf("Digite o número que deseja adicionar na pilha: ");
      scanf("%d", &valor);
     if (valor <= 0){
       return -1;
     }
   else { 
    pilha -> item[pilha -> quantidade++] = valor;
   }     
  }
  
    return 0;
}


void listagemInicial(struct pilha * pilha){
    
  int i = 0;

  if(!pilha -> quantidade){
    printf("\nA pilha A está vazia.\n");
    return;
}

    printf("\nPilha A:\n");
    
    for(i = pilha -> quantidade - 1; i >= 0; i--){
     printf("%dª Posição: %d\n", i + 1, pilha -> item[i]);
  }
}

int PI(struct fila * fila, int valor){
    
    fila -> item[fila -> quantidade++] = valor;
  
    return 0;
}


int enqueueParImpar(struct fila * filaPar, struct fila * filaImpar,  struct pilha * pilhaInicial){
    
  int i = 0;

   for(i = 0; i < pilhaInicial -> quantidade; i++){
    if (pilhaInicial -> item[i] % 2 == 0){ 
     PI(filaPar, pilhaInicial -> item[i]);
   }
     else {
       PI(filaImpar, pilhaInicial -> item[i]);
     }
  }   

    return 0;
}

void listagemPar(struct fila * fila){
    
  int i = 0;

  if(!fila -> quantidade){
    printf("\nA Fila Par está vazia.\n");
    return;
}

    printf("\nFila Par:\n");
    
    for(i = 0; i <= fila -> quantidade - 1; i++){
     printf("%dª Posição: %d\n", i + 1, fila -> item[i]);
  }
}

void listagemImpar(struct fila * fila){
    
  int i = 0;

  if(!fila -> quantidade){
    printf("\nA Fila Ímpar está vazia.\n");
    return;
}

    printf("\nFila Ímpar:\n");
    
    for(i = 0; i <= fila -> quantidade - 1; i++){
     printf("%dª Posição: %d\n", i + 1, fila -> item[i]);
  }
}


int main(void){
    
   struct pilha pilhaInicial;
   struct fila filaPar;
   struct fila filaImpar;

   inicializarPilha(&pilhaInicial);
   inicializarFila(&filaPar);
   inicializarFila(&filaImpar);

   push(&pilhaInicial);
   listagemInicial(&pilhaInicial);

   enqueueParImpar(&filaPar, &filaImpar, &pilhaInicial);
   listagemPar(&filaPar);
   listagemImpar(&filaImpar);


    return 0;
}