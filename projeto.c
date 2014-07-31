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

};

struct Arv {
     struct No *info;
     struct No *esq;
      struct No *dir;
     struct arv *acima;
     struct arv *esquerda;
     struct arv *direita;

};

typedef struct Arv arv;

void criarArvore(arv *pRaiz){
    pRaiz->acima = NULL;
    (pRaiz)->info=NULL;
    (pRaiz)->esq = NULL;
    (pRaiz)->dir = NULL;


}

void busca(arv *pRaiz){

char nome[10];
printf("Informe o nome desejado: ");
scanf("%s", &nome);

if(nome[0] < pRaiz->info->nome[0]){
    if (strcmp(nome , pRaiz->esq)==0 ) {

       printf("\n%s\n",pRaiz->esq->nome);
       printf("\n%s\n",pRaiz->esq->sexo);
       printf("\n%s\n",pRaiz->esq->pai);
       printf("\n%s\n",pRaiz->esq->mae);
       printf("\n%s\n",pRaiz->esq->conj);
       printf("\n%s\n",pRaiz->esq->sconj);
       printf("\n%s\n",pRaiz->esq->filho);
       printf("\n%s\n",pRaiz->esq->irmao);

    }
    else {
        printf("Nome nao encontrado");
    }

}
if(nome[0] > pRaiz->info->nome[0]){
    if (strcmp(nome , pRaiz->dir)==0 ) {

       printf("\n%s\n",pRaiz->dir->nome);
       printf("\n%s\n",pRaiz->dir->sexo);
       printf("\n%s\n",pRaiz->dir->pai);
       printf("\n%s\n",pRaiz->dir->mae);
       printf("\n%s\n",pRaiz->dir->conj);
       printf("\n%s\n",pRaiz->dir->sconj);
       printf("\n%s\n",pRaiz->dir->filho);
       printf("\n%s\n",pRaiz->dir->irmao);

    }
    else {
        printf("Nome nao encontrado");
    }

}


    if (strcmp(nome , pRaiz->info)==0 ) {

         printf("\n%s\n",pRaiz->info->nome);
         printf("\n%s\n",pRaiz->info->sexo);
         printf("\n%s\n",pRaiz->info->pai);
         printf("\n%s\n",pRaiz->info->mae);
         printf("\n%s\n",pRaiz->info->conj);
         printf("\n%s\n",pRaiz->info->sconj);
         printf("\n%s\n",pRaiz->info->filho);
         printf("\n%s\n",pRaiz->info->irmao);

    }
    else {
        printf("Nome nao encontrado");
    }




}


void exibirPreOrdem(arv *pRaiz){
    if(pRaiz!= NULL){

        printf("\n%s\n", pRaiz->info->nome);
        printf("\n%s\n",pRaiz->esquerda);
        printf("\n%s\n",pRaiz->direita);

    }
}
void insere(arv *pRaiz, struct No *aux)
{


  if((pRaiz)->info == NULL){
        (pRaiz)->esq = NULL;
        (pRaiz)->dir = NULL;
        (pRaiz)->info = aux;
}
    else
    {

           if(aux->nome[0] <= pRaiz->info->nome[0])
        {
            (pRaiz)->esq = aux;
        }
         if(aux->nome[0] > pRaiz->info->nome[0])
        {
            (pRaiz)->dir = aux;
        }
    }
}



void registra(arv *pRaiz){


struct No *aux =(struct No *) malloc(sizeof(struct No));
char a[10];

printf("\nInforme o nome: ");
fflush(stdin);
gets  (aux->nome);
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
          busca(pRaiz);
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
