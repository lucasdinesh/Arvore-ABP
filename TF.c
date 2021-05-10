#include <stdio.h>
#include <stdlib.h>
#include "TF.H"
#include <math.h>
#include <string.h>

pNodoA* cria_arvore(void)
{
    return NULL;
}

pNodoA* InsereArvore(pNodoA *a, char palavra[], char lema[])
{
    if (a == NULL)
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        strcpy(a->palavra, palavra) ;
        strcpy(a->lema, lema) ;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (strcmp(a->palavra, palavra) > 0)
        a->esq = InsereArvore(a->esq,palavra, lema);
    else
        a->dir = InsereArvore(a->dir,palavra, lema);
    return a;
}

pNodoA* OrdenaDic (char *argv[], pNodoA* a)
{
    strcpy(separador," ,.&*%\?!;/'@\"$#=><()][}{:\n\t");
    FILE *dicionario;

    dicionario = fopen (argv[1], "r"); // abre o arquivo para leitura -- argv[1] é o primeiro parâmetro após o nome do arquivo.
    if (dicionario == NULL) //se não conseguiu abrir o arquivo
    {
        printf ("Erro ao abrir o arquivo %s", argv[1]);
        return NULL;
    }
    else // arquivo de entrada OK
    {
        while (fgets(linha,1000,dicionario))
        {
            palavra = strtok (linha, separador); //considera qquer caractere não alfabético como separador
            lema = strtok (NULL, separador);
            a=InsereArvore(a,palavra, lema);
        }
    }

    fclose(dicionario);
    return a;
}

char* procuraPalavra(pNodoA *a, char p[])
{
    while (a!=NULL )
    {
        comp++;
        if (strcmp(a->palavra,p)==0)
        {
            comp++;
            return a->lema;
        }
        else
        {
            comp++;
            if (strcmp(a->palavra,p)>0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return p;
}

void converteLemas (pNodoA *a, char *argv[])
{
    strcpy(separador," ,.&*%\?!;/'@\"$#=><()][}{:\n\t");

    FILE * entrada;
    FILE * saida;

    entrada = fopen (argv[2], "r"); // abre o arquivo de entrada

    saida = fopen(argv[3], "w");    // abre o arquivo gerado para a saida

    //percorre todo o arquivo lendo linha por linha
    while (fgets(linha,1000,entrada))
    {
        strlwr(linha);      // converte para minusculas
        palavra = strtok (linha, separador); // considera qquer caractere não alfabético como separador
        while (palavra != NULL)
        {
            strcpy(l, procuraPalavra(a, palavra));  // a variavel l recebe o lema da palavra enviada para a função caso a palavra possua lema, caso não possua, recebe a propria palavra

            fprintf(saida,"%s ", l);    // imprime a palavra recebida ou seu lema, caso tiver

            palavra = strtok (NULL, separador);
        }
        fprintf(saida,"\n");
    }

    printf("\nArquivo %s gerado com sucesso.\n",argv[3]);

    printf("\nForam realizadas %d comparações.\n", comp);

    fclose (entrada); //fecha os arquivos
    fclose (saida);
}
