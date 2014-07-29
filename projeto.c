#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
     char nome[10];
     char sexo[10];
     char pai[10];
     char mae[10];
     char conj[10];
     char filho[10];
     char irmao[10];
     char sconj[10];
     int idade;
};

struct Arv {
     struct No *info;
     struct arv *acima;
     struct arv *esquerda;
     struct arv *direita;

};

typedef struct Arv arv;

void criarArvore(arv *pRaiz){
    pRaiz->acima = NULL;

}



void exibirPreOrdem(arv *pRaiz){
    if(pRaiz != NULL){
        printf("\n%s", pRaiz->info->nome);
        exibirPreOrdem(pRaiz->esquerda);
        exibirPreOrdem(pRaiz->direita);
    }
}

void insere(arv *pRaiz, struct No *aux)
{

  if(pRaiz->acima == NULL){
        (pRaiz)->esquerda = NULL;
        (pRaiz)->direita = NULL;
        (pRaiz)->info = aux;
}
    else
    {
        if(pRaiz->info->nome[0] <= aux->nome[0])
        {
            insere(&(pRaiz)->esquerda, aux);
        }
        if(pRaiz->info->nome[0] > aux->nome[0])
        {
            insere(&(pRaiz)->direita, aux);
        }
    }
}

void registra(arv *pRaiz){

char *pai, *mae, *conj, *filho, *irmao, *sconj;
int *idade;
struct No *aux =(struct No *) malloc(sizeof(struct No));
char a[10];

printf("\nInforme o nome: ");
fflush(stdin);
gets  (aux->nome);
printf("\nInforme a idade: ");
scanf ("%d",&aux->idade);
fflush(stdin);
printf("\nInforme o sexo: ");
gets  (aux->sexo);
fflush(stdin);
printf("\nInforme o pai: ");
gets  (aux->pai);
fflush(stdin);
printf("\nInforme o mae: ");
gets  (aux->mae);
fflush(stdin);
printf("\nInforme o irmao:  ");
gets  (aux->irmao);
strcpy(a, aux->irmao);
fflush(stdin);
printf("\nInforme o(a) conjuge: ");
gets  (aux->conj);
fflush(stdin);
printf("\nInforme o sexo do(a) conjuge: ");
gets  (aux->sconj);
fflush(stdin);

if(strcmp(aux->sexo, aux->sconj) == 0){
 printf("\nNao pode casar e nem ter filhos\n");
}
if(strcmp(aux->sexo, aux->sconj) != 0) {
printf("\nInforme o filho:  ");
gets  (aux->filho);
}

strcpy(aux->irmao, a);
insere(pRaiz, aux);
printf("\nRegistrado!\n");

}

void imprime(arv *pRaiz)
{
puts(pRaiz->info->nome);
printf("%i\n",pRaiz->info->idade);
puts(pRaiz->info->sexo);
puts(pRaiz->info->pai);
puts(pRaiz->info->mae);
puts(pRaiz->info->conj);
puts(pRaiz->info->sconj);
puts(pRaiz->info->filho);
puts(pRaiz->info->irmao);
}

void menu(arv *pRaiz)
{
    int op;
    do
  {
    system("cls");
    puts("\tMENU");
    puts("");
    puts("\t1 - Registrar individuo");
    puts("\t2 - Consultar individuo");
    puts("\t3 - Sair");
    printf("\nDigite a op%c%co: ",135,198);
    scanf("%i",&op);
    switch(op)
    {
      case 1:
        {
            system("cls");
            registra(pRaiz);
            system("pause");
            break;
        }
      case 2:
        {
          imprime(pRaiz);
          system("pause");
          break;
        }
      case 3:
        {
            return 0;
        }
      default:
        {
          printf("\tOp%c%co inv%clida\n",135, 198, 160);
          system("pause");
        }
    }
  }while(1);
}



int main()
{
    arv *arvore = (arv*)malloc(sizeof (arv));


    criarArvore(arvore);
    menu(arvore);


}
