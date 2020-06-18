#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

No *criaArvoreCodigoMorse(){
    FILE *arq = fopen("arvoreMorse.txt","r");
    FILE *arqCaracteres = fopen("arvoreMorseCaracteres.txt","r");
    int i = 0;
    char simbol[10];
    char caminho[10] = "";
    No *raiz = criaNo();
    No *a = raiz;

    if (arq == NULL){
        return NULL;
    }

    // PERCORRO TODO ARQUIVO MORSE.TXT
    while (!feof(arq)){
        // PASSO TODO CÓDIGO DE UMA LETRA PARA VARIÁVEL SIMBOL
        fscanf(arq, "%s", &simbol);
        // PERCORRO CHAR POR CHAR DESSE CÓDIGO PARA CRIAR ARVORE
        for (i = 0; i < strlen(simbol); i++){
            // AO ENCONTRAR UM '.' AVANÇO PARA ESQUERDA
            if (simbol[i] == '.'){
                if (a->esq == NULL)
                    a->esq= criaNo();
                a = a->esq;
                strcat(caminho,".");
            // AO ENCONTRAR UM '-' AVANÇO PARA DIREITA
            } else if (simbol[i] == '-'){
                if (a->dir == NULL)
                    a->dir = criaNo();
                a = a->dir;
                strcat(caminho,"-");
            }
        }
        a->info = getc(arqCaracteres);
        strcpy(a->caminho,caminho);
        strcpy(caminho,"");
        a = raiz;
    }
    fclose(arq);
    fclose(arqCaracteres);
    return raiz;
}

void morseToText(No *arvoreMorse, char *filename){
    FILE *arq = fopen(filename,"r");
    FILE *arqTraduzido = fopen("deMorseParaTexto.txt","w");
    No *a = arvoreMorse;
    int i = 0;
    char simbol[10];

    if (arq == NULL || arqTraduzido == NULL){
        return;
    }

    // PERCORRO TODO ARQUIVO MORSETOTEXT.TXT
    while (!feof(arq)){
        // SIMBOL RECEBE OS CARACTERES DA VEZ
        fscanf(arq, "%s", &simbol);

        // PERCORRO CHAR POR CHAR PARA ENCONTRAR LETRA CORRESPONDENTE NA ÁRVORE
        for (i = 0; i < strlen(simbol); i++){
            // AO ENCONTRAR UM '.' AVANÇO PARA ESQUERDA
            if (simbol[i] == '.'){
                a = a->esq;
            // AO ENCONTRAR UM '-' AVANÇO PARA DIREITA
            } else if (simbol[i] == '-'){
                a = a->dir;
            }
        }
        // ESCREVE EM MEU ARQUIVO LETRA QUE SEQUÊNCIA DE CÓDIGO CORRESPONDE
        fprintf(arqTraduzido,"%c", a->info);
        a = arvoreMorse;
    }

    fclose(arq);
    fclose(arqTraduzido);
}

void textToMorse(No *arvoreMorse, char *filename){
    FILE *arq = fopen(filename,"r");
    FILE *arqTraduzido = fopen("deTextoParaMorse.txt","w");
    No *a = arvoreMorse;
    int i = 0;
    char letra;

    if (arq == NULL || arqTraduzido == NULL){
        return;
    }

    do{
        letra = getc(arq);
        if (letra == ' '){
            fprintf(arqTraduzido, "%s", " / ");
        } else if (letra != ' ' && letra != -1) {
            strcpy(retorno,"");
            pertence(a, letra);
            fprintf(arqTraduzido, " %s", retorno);
        }
    } while (letra != EOF);

    fclose(arq);
    fclose(arqTraduzido);
}
int main()
{
    No *a = (No*) criaArvoreCodigoMorse();
    //imprime(a);
    morseToText(a, "morse.txt");
    //textToMorse(a, "texto.txt");
    return 0;
}
