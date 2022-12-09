#include <stdio.h>
#include <string.h>



struct fila{
  int item[200];
  int quantidade;
};


void inicializar(struct fila * fila){
    memset(fila, 0, sizeof(struct fila));
}


int enqueue(struct fila * fila, int valor){
    
    fila -> item[fila -> quantidade++] = valor;
  
    return 0;
}


void listagemA(struct fila * fila){
    
  int i = 0;

  if(!fila -> quantidade){
    printf("\nA fila A está vazia.\n");
    return;
}

    printf("\nFila A:\n");
    
    for(i = 0; i <= fila -> quantidade - 1; i++){
     printf("%dª Posição: %d\n", i + 1, fila -> item[i]);
  }
}

void listagemB(struct fila * fila){
    
  int i = 0;

  if(!fila -> quantidade){
    printf("\nA fila B está vazia.\n");
    return;
}

    printf("\nFila B:\n");
    
    for(i = 0; i <= fila -> quantidade - 1; i++){
     printf("%dª Posição: %d\n", i + 1, fila -> item[i]);
  }
}

int enqueueC(struct fila * fila, int valor){
    
    fila -> item[fila -> quantidade++] = valor;
  
    return 0;
}


int enqueueFilaC(struct fila * filaFinal, struct fila * filaInicial){
    
  int i = 0;

   for(i = 0; i < filaInicial -> quantidade; i++){
     enqueueC(filaFinal, filaInicial -> item[i]);
  }   

    return 0;
}

void listagemC(struct fila * fila){
    
  int i = 0;

  if(!fila -> quantidade){
    printf("\nA fila C está vazia.\n");
    return;
}

    printf("\nfila C:\n");
    
    for(i = 0; i <= fila -> quantidade - 1; i++){
     printf("%dª Posição: %d\n", i + 1, fila -> item[i]);
  }
}


void crescente(struct fila * fila){
  int i = 0;
  int j = 0;
  int aux = 0;

    for(i = 0; i < fila -> quantidade; i++){
      for(j = i + 1; j < fila -> quantidade; j++){
        if(fila -> item[i] > fila -> item[j]){
                aux = fila -> item[i];
                fila -> item[i] = fila -> item[j];
                fila -> item[j] = aux;
   }
  }
 }
}

void decrescente(struct fila * fila){
  int i = 0;
  int j = 0;
  int aux = 0;

    for(i = 0; i < fila -> quantidade; i++){
      for(j = i + 1; j < fila -> quantidade; j++){
        if(fila -> item[i] > fila -> item[j]){
                aux = fila -> item[i];
                fila -> item[i] = fila -> item[j];
                fila -> item[j] = aux;
   }
  }
 }
}


int main(void){
    
   struct fila filaA;
   struct fila filaB;
   struct fila filaC;

   inicializar(&filaA);
   inicializar(&filaB);
   inicializar(&filaC);

   enqueue(&filaA, 1);
   enqueue(&filaA, 3);
   enqueue(&filaA, 5);
   enqueue(&filaA, 7);
   enqueue(&filaA, 9);
   enqueue(&filaA, 11);
   enqueue(&filaA, 13);
   enqueue(&filaA, 15);
   enqueue(&filaA, 17);
   enqueue(&filaA, 19);

   listagemA(&filaA);
   
   enqueue(&filaB, 0);
   enqueue(&filaB, 2);
   enqueue(&filaB, 4);
   enqueue(&filaB, 6);
   enqueue(&filaB, 8);
   enqueue(&filaB, 10);
   enqueue(&filaB, 12);
   enqueue(&filaB, 14);
   enqueue(&filaB, 16);
   enqueue(&filaB, 18);

   listagemB(&filaB);

   enqueueFilaC(&filaC, &filaA);
   enqueueFilaC(&filaC, &filaB);

   crescente(&filaC);
   listagemC(&filaC);

    return 0;
}