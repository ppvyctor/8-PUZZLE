#ifndef IA_H
#define IA_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "movimentacao.h"

/*
 1 - Para subir
 2 - para decer
 3 - para ir para a direita
 4 - para ir para a esquerda
 */

typedef struct ARVORE
{
    int Estado[3][3];
    /*indicação de movimento, assimilação do espaço com esse movimento, caminho passado...*/
    struct ARVORE *anterior;
    /*ponteiros para determinação de outros nos...*/
    /*up = 1 , down = 2, right = 3, left = 4...*/
} Arvore;

typedef struct LISTA
{
    Arvore *nos_nivel;
    struct LISTA *prox;
} Nivel;
/*estrutura para definir os nos que estao dentro do nivel para evitar a volta a niveis anteriores...*/

Nivel* Cria_nivel()
{
    return NULL;
}

/*funcoes de criacao...*/
Arvore* inputArvore(Arvore* tree, int estado[3][3])
{
    //tente mudar de int para short
    int i, x;
    Arvore *tree_aux;
    tree_aux = (Arvore*)malloc(sizeof(Arvore));
    tree_aux->anterior = tree;
    for(i = 0; i < 3; i++)
    {
        for(x = 0; x < 3; x++)
        {
            tree_aux->Estado[i][x] = estado[i][x];
        }
    }
    return tree_aux;
}

Nivel* newNo(Nivel *list, Nivel *list2, int estado[3][3])
{
    Nivel *list_aux;
    list_aux = (Nivel*)malloc(sizeof(Nivel));
    list_aux->prox = list;
    if(list == NULL)
    {
        list_aux->nos_nivel = inputArvore(NULL, estado);
    }
    else
    {
        list_aux->nos_nivel = inputArvore(list2->nos_nivel, estado);
    }
    return list_aux;
}

#endif 