#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "TF.H"
#include <math.h>


int main(int argc, char *argv[]) //argc conta o n�mero de par�metros e argv armazena as strings correspondentes aos par�mentros digitados
{
    setlocale(LC_ALL,""); //para imprimir corretamente na tela os caracteres acentuados

    pNodoA *AVL;

    if (argc!=4)  //o numero de parametros esperado � 3: nome do programa (argv[0]), nome do arq de entrada(argv[1]), nome do arq de saida(argv[2])
    {
        printf ("N�mero INCORRETO de par�metros.\n Para chamar o programa digite: exemplo <arq_entrada> <arq_saida>\n");
        return 1;
    }
    else{

        AVL = cria_arvore();
        AVL = OrdenaDic(argv, AVL);
        comp = 0;
        converteLemas (AVL, argv);
    }

        return 0;
}

