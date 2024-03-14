#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <stdio.h>
#include <stdlib.h>

int* posicao_vazio(int estado[3][3])
{
    static int pos[2];
    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            if(estado[i][x] == -9)
            {
                pos[0] = i;
                pos[1] = x;
                return pos;
                //aqui está sendo retirnado em i, qual matriz o vazio está, e em x, está sendo retornado em qual posição o mesmo se encontra.
            }
        }
    }
    return NULL;
}
void up(int estado[3][3], int *random)
{
    int apoio;
    int* pos = posicao_vazio(estado);
    if(pos[0] > 0)
    {
        apoio = estado[pos[0] - 1][pos[1]];
        estado[pos[0] - 1][pos[1]] = estado[pos[0]][pos[1]];
        estado[pos[0]][pos[1]] = apoio;
    }
    else
    {
        *random = 1;
    }
}
void down(int estado[3][3], int *random)
{
    int apoio;
    int* pos = posicao_vazio(estado);
    if(pos[0] < 2)
    {
        apoio = estado[pos[0] + 1][pos[1]];
        estado[pos[0] + 1][pos[1]] = estado[pos[0]][pos[1]];
        estado[pos[0]][pos[1]] = apoio;
    }
    else
    {
        *random = 1;
    }
}
void right(int estado[3][3], int *random)
{
    int apoio;
    int* pos = posicao_vazio(estado);
    if(pos[1] < 2)
    {
        apoio = estado[pos[0]][pos[1] + 1];
        estado[pos[0]][pos[1] + 1] = estado[pos[0]][pos[1]];
        estado[pos[0]][pos[1]] = apoio;
    }
    else
    {
        *random = 1;
    }
}
void left(int estado[3][3], int *random)
{
    int apoio;
    int* pos = posicao_vazio(estado);
    if(pos[1] > 0)
    {
        apoio = estado[pos[0]][pos[1] - 1];
        estado[pos[0]][pos[1] - 1] = estado[pos[0]][pos[1]];
        estado[pos[0]][pos[1]] = apoio;
    }
    else
    {
        *random = 1;
    }
}
int verificador(int estado[3][3], int estado_perfeito[3][3])
{
    int estados_iguais = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            if(estado[i][x] == estado_perfeito[i][x]) estados_iguais++;
        }
    }
    if(estados_iguais == 9) return 0;
    return 1;
}


#endif