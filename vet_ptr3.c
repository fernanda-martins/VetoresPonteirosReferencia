#define MAX 20

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// vamos evitar uso de variáveis globais

// cabeçalho das funções
void preencheVetor(int [MAX]);
void mostraVetor(int [MAX]);
void inverteVetor(int [MAX]);
void inverteVetorPtr(int [MAX]);
void trocaInt(int *, int *);

int main () {
    int v[MAX];
    preencheVetor(v);
    printf("Vetor sorteado de %d posicoes:\n", MAX);
    mostraVetor(v);

    inverteVetor(v);
    printf("\nVetor invertido:\n");
    mostraVetor(v);
    
    inverteVetorPtr(v);
    printf("\nVetor voltado a origem:\n");
    mostraVetor(v);
    return 0;
}

// ARRAY sempre é passagem de parâmetros por REFERÊNCIA ou seja, ao manipula o parâmetro v está alterando o array v da main
void preencheVetor(int v[MAX]){
    int i;  // variável local a main (locais ficam na pilha)
    srand(time(NULL));
    for (i=0; i<MAX; i++){
        v[i] = 10 + rand()%90; // manipulan o rand para dar [10..99]
    }
}

void mostraVetor(int v[MAX]){
    int i;  
    for (i=0; i<MAX; i++){
        printf("%d " , v[i]);
    }
    printf("\n");
}

void inverteVetor(int v[MAX]){
    int e, d;
    e = 0; // esquerda do vetor
    d = MAX - 1;  // direita do vetor 
    do {
        
        trocaInt(&v[e], &v[d]); // efetua a troca usando passagem de parâmetros por REFERENCIA
        e++;                    
        d--;
    } while (e < d); // até se cruzarem
    
    // possivel for
    // for (e=0, d=MAX-1; e < d; e++, d--)
}

void inverteVetorPtr(int v[MAX]){
    int *e, *d;
    e = &v[0]; // esquerda recebe endereco do primeiro elemento do vetor
    d = &v[MAX - 1];  // direita recebe endereco do ultimo elemento do vetor
    do {
        trocaInt(e, d); 
                
        e++;  // incrementa ponteiro para proximo inteiro, ou seja pula 4 bytes                  
        d--; // decrementar ponteiro para inteiro anterior, ou seja, volta 4 bytes
    } while (e < d); // até se cruzarem
}

// usando PONTEIRO de modo explícito
// passagem de PARAMETROS por REFERENCIA
// caso contrario, tipos primitivos
// é passage  de PARAMETRO por VALOR (ocorre uma cópia)
void trocaInt(int *a, int *b){
    int aux;
    //printf("Chegou %d e %d \n", *a, *b);
    aux = *a;
    *a = *b;
    *b = aux;
    //printf("Saindo assim %d e %d \n\n", *a, *b);

    // prints para visualizar os passos
}