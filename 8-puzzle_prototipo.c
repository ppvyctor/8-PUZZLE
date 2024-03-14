#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include "biblioteca/movimentacao.h"
#include "biblioteca/IA.h"


int main()
{
    setlocale(LC_ALL, "portuguese");
    //se a movimentação não estiver dando certo, tente tricar o ' ' por " ".
    int estado_perfeito[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, -9}}, estado[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, -9}}, veric, loops, number, random, opcao, opcao2, identificador;
    double complexidade;
    char movim[1], res[1];
    Nivel *list, *aux;// *apagar;
    Arvore *Resultado;

    printf("BEM VINDO AO 8-PUZZLE!!\n\n");
    system("pause");
    do
    {
        loops = 0;
        opcao2 = 0;

        do
        {
            system("cls");
            printf("Escolha uma das opções abaixo.\n");
            printf("\t1) Resolver o puzzle.\n ");
            printf("\t2) IA resolverá o puzzle.\n\n");
            printf("Digite a escolha desejada ao lado: ");
            scanf("%d", &opcao);
            system("cls");
            if(opcao < 0 || opcao > 2)
            {
                printf("OOOPS!!! opção inválida, por favor tente novamente.\n\n");
                system("pause");
            }
        }while (opcao < 0 || opcao > 2);

        if(opcao == 2)
        {
            do
            {
                system("cls");
                printf("Escolha como deseja embaralhar o 8-puzzle.\n");
                printf("\t1) Embaralhe você mesmo\n ");
                printf("\t2) Embaralhamento automático.\n\n");
                printf("Digite a escolha desejada ao lado: ");
                scanf("%d", &opcao2);
                system("cls");
                if(opcao2 < 0 || opcao2 > 2)
                {
                    printf("OOOPS!!! opção inválida, por favor tente novamente.\n\n");
                    system("pause");
                }
            }while (opcao2 < 0 || opcao2 > 2);
        }

        if(opcao2 == 1)
        {
            while(1)
            {
                printf("\n\tPara realizar a movimentação, utilize os botões W, A, S, D.\n\n");
                for(int i = 0; i < 3; i++)
                {
                    printf("\t\t[");
                    for(int x = 0; x < 3; x++)
                    {
                        if(estado[i][x] == -9)
                        {
                            printf(" ");
                        }
                        else
                        {
                            printf("%i", estado[i][x]);
                        }
                        if (x != 2)
                        {
                            printf("  ");
                        }
                    }
                    printf("]\t\t[");
                    for(int x = 0; x < 3; x++)
                    {
                        if(estado_perfeito[i][x] == -9)
                        {
                            printf(" ");
                        }
                        else
                        {
                            printf("%i", estado_perfeito[i][x]);
                        }
                        if (x != 2)
                        {
                            printf("  ");
                        }
                    }
                    printf("]\n");
                }
                //alterar daqui
                printf("\nDigite \"W, S, A ou D\" para realizar uma movimentação, ou se preferir, digite \"e ou E\" para a digitação: ");
                scanf("%s", &movim[0]);
                movim[0] = toupper(movim[0]);
                random = 0;
                if(movim[0] == 'E')
                {
                    system("cls");
                    break;
                }
                switch(movim[0])
                {
                    case 'W':
                        up(estado, &random);
                        break;
                    case 'S':
                        down(estado, &random);
                        break;
                    case 'D':
                        right(estado, &random);
                        break;
                    case 'A':
                        left(estado, &random);
                        break;
                    default:
                        printf("\nOOOOOPS!!! O comando dado não corresponde corretamento com o solicitado.\n");
                        printf("Por favor tente novamente.\n\n");
                        system("pause");
                }
                if(random == 1)
                {
                    printf("OOOPS!!! não se consegue mais realizar este movimento, por favor tente novamente!!!\n\n");
                    system("pause");
                }
                system("cls");
            }
        }
        else
        {
            do
            {
                system("cls");
                printf("Defina a seed do embaralhamento.\n");
                printf("Seed: ");
                scanf("%lf", &complexidade);
                if(complexidade < 1)
                {
                    printf("Por favor, digite um nível de complexidade maior ou igual a 1.\n\n");
                    system("pause");
                }
                system("cls");
            }while(complexidade < 1);

            printf("\t\tEMBARALHANDO...\n");
            srand(complexidade);
            while(loops <= 500)
            {
                number = (rand() % 4) + 1;
                if (number == 1)
                {
                    up(estado, &random);
                }
                else
                {
                    if(number == 2)
                    {
                        down(estado, &random);
                    }
                    else
                    {
                        if(number == 3)
                        {
                            right(estado, &random);
                        }
                        else
                        {
                            if(number == 4)
                            {
                                left(estado, &random);
                            }
                        }
                    }
                }
                loops++;
            }
            system("cls");
        }

        if(opcao == 1)
        {

            veric = 1;
            while(veric != 0)
            {
                printf("\n\tPara realizar a movimentação, utilize os botões W, A, S, D.\n\n");
                for(int i = 0; i < 3; i++)
                {
                    printf("\t\t[");
                    for(int x = 0; x < 3; x++)
                    {
                        if(estado[i][x] == -9)
                        {
                            printf(" ");
                        }
                        else
                        {
                            printf("%i", estado[i][x]);
                        }
                        if (x != 2)
                        {
                            printf("  ");
                        }
                    }
                    printf("]\t\t[");
                    for(int x = 0; x < 3; x++)
                    {
                        if(estado_perfeito[i][x] == -9)
                        {
                            printf(" ");
                        }
                        else
                        {
                            printf("%i", estado_perfeito[i][x]);
                        }
                        if (x != 2)
                        {
                            printf("  ");
                        }
                    }
                    printf("]\n");
                }
                //alterar daqui
                printf("\nDigite ao lado para onde deseja realizar a movimentação: ");
                scanf("%s", &movim[0]);
                movim[0] = toupper(movim[0]);
                random = 0;
                switch(movim[0])
                {
                    case 'W':
                        up(estado, &random);
                        break;
                    case 'S':
                        down(estado, &random);
                        break;
                    case 'D':
                        right(estado, &random);
                        break;
                    case 'A':
                        left(estado, &random);
                        break;
                    default:
                        printf("\nOOOOOPS!!! O comando dado não corresponde corretamento com o solicitado.\n");
                        printf("Por favor tente novamente.\n\n");
                        system("pause");
                }
                if(random == 1)
                {
                    printf("OOOPS!!! não se consegue mais realizar este movimento, por favor tente novamente!!!\n\n");
                    system("pause");
                }
                //até aqui
                veric = verificador(estado, estado_perfeito);

                system("cls");
            }

            printf("\n\nPARABÉNS!!! VOCÊ CONCLUIR O 8-PUZZLE!!!\n");
            printf("OBRIGADO POR JOGAR, CASO TENHA INTERESSE EM JOGAR NOVAMENTE DIGITE QUALQUER COISA DIFERENTE DE \"n OU N\": ");
            scanf("%s", &res[0]);
            res[0] = toupper(res[0]);
        }
        else
        {
            /*
            0 - estado inicial
            1 - Para subir
            2 - para decer
            3 - para ir para a direita
            4 - para ir para a esquerda
            */
            system("cls");
            printf("AGUARDE!!\nA IA NÃO É UM ROBÔ COMO VOCÊ PARA RESOLVER ESTE PROBLEMA TÃO RÁPIDO!!!");
            list = Cria_nivel();
            aux = Cria_nivel();
            list = newNo(list, NULL, estado);
            veric = 1;
            identificador = 0;
            while(1)
            {
                for(; list != NULL; list = list->prox)
                {
                    random = 0;
                    for(int i = 0; i < 3; i++)
                    {
                        for(int x = 0; x < 3; x++)
                        {
                            estado[i][x] = list->nos_nivel->Estado[i][x];
                        }
                    }
                    up(estado, &random);
                    if(random == 0)
                    {
                        aux = newNo(aux, list, estado);
                        veric = verificador(estado, estado_perfeito);
                        if(veric == 0) break;
                        down(estado, &random);
                    }
                    else
                    {
                        random = 0;
                    }
                    down(estado, &random);
                    if(random == 0)
                    {
                        aux = newNo(aux, list, estado);
                        veric = verificador(estado, estado_perfeito);
                        if(veric == 0) break;
                        up(estado, &random);
                    }
                    else
                    {
                        random = 0;
                    }
                    left(estado, &random);
                    if(random == 0)
                    {
                        aux = newNo(aux, list, estado);
                        veric = verificador(estado, estado_perfeito);
                        if(veric == 0) break;
                        right(estado, &random);
                    }
                    else
                    {
                        random = 0;
                    }
                    right(estado, &random);
                    if(random == 0)
                    {
                        aux = newNo(aux, list, estado);
                        veric = verificador(estado, estado_perfeito);
                        if(veric == 0) break;
                        left(estado, &random);
                    }
                    else
                    {
                        random = 0;
                    }
                }
                if(veric == 0) break;

                for(; aux != NULL; aux = aux->prox)
                {
                    //free(apagar);
                    if((aux->nos_nivel->Estado[0][0] == 1 && aux->nos_nivel->Estado[0][1] == 2) && aux->nos_nivel->Estado[0][2] == 3)
                    {
                        identificador = 1;
                        list = newNo(list, aux, aux->nos_nivel->Estado);
                    }
                    else
                    {
                        if(identificador == 0)
                        {
                            list = newNo(list, aux, aux->nos_nivel->Estado);
                        }
                    }
                }
            }
            free(aux->prox);
            aux->prox = NULL;
            Resultado = NULL;
            for(; aux->nos_nivel != NULL; aux->nos_nivel = aux->nos_nivel->anterior)
            {
                Resultado = inputArvore(Resultado, aux->nos_nivel->Estado);
            }
            for(; Resultado != NULL; Resultado = Resultado->anterior)
            {
                system("cls");
                for(int i = 0; i < 3; i++)
                {
                    printf("\t\t[");
                    for(int x = 0; x < 3; x++)
                    {
                        if(Resultado->Estado[i][x] == -9)
                        {
                            printf(" ");
                        }
                        else
                        {
                            printf("%i", Resultado->Estado[i][x]);
                        }
                        if (x != 2)
                        {
                            printf("  ");
                        }
                    }
                    printf("]\t\t[");
                    for(int x = 0; x < 3; x++)
                    {
                        if(estado_perfeito[i][x] == -9)
                        {
                            printf(" ");
                        }
                        else
                        {
                            printf("%i", estado_perfeito[i][x]);
                        }
                        if (x != 2)
                        {
                            printf("  ");
                        }
                    }
                    printf("]\n");
                }
                Sleep(500);
            }
            printf("\n");
            system("pause");
            free(aux);
            free(list);
            free(Resultado);
            system("cls");

            printf("Digite qualquer coisa diferente de \"n ou N\" ao lado para volta ao menu principal: ");
            scanf("%s", &res[0]);
            res[0] = toupper(res[0]);
            if(res[0] == 'N')
            {
                printf("\nObrigado por jogar o 8-PUZZLE!!!\n");
                printf("VOLTE SEMPREEE!!!\n\n");
                system("pause");
            }
        }
    }while(res[0] != 'N');
    return 0;
}
