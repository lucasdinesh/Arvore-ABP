struct TNodoA{
 char palavra[20];
 char lema[20];
 struct TNodoA *esq;
 struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

int comp;
char l[20];
char linha[1000];
char *palavra, *lema;
char separador[30];

pNodoA* cria_arvore(void);
pNodoA* InsereArvore(pNodoA *a, char palavra[], char lema[]);
pNodoA* OrdenaDic (char *argv[], pNodoA* a);
char* procuraPalavra(pNodoA *a, char palavra[]);
void converteLemas (pNodoA *a, char *argv[]);
