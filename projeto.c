/* ***************************************************************

    Autor: Felipe Baruch, Pablo Oliveira, Ramon Mascarenhas.
    Inicio: 27/07/2014
    Ultima alteracao: 31/07/2014
    Nome: Arvore Genealógica
    Funcao: O programa deve conter dois modulos de acesso, um que permita ao usuario cadastrar individuos
    e informações de parentescos do mesmo em uma estrutura de dados dinamica do tipo arvore e outro modulo
    que permita ao usuario consultar algum individuo da arvore através do nome, disponibilizando as informações
    de parentesco deste individuo na tela.
    *************************************************************** */



///Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Estrutura em que vai se basear as informações a serem inseridas
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
///Estrutura em que se baseia a arvore, tendo 3 ponteiros que apontam para a informação, para esquerda e para direita respectivamente
struct Arv {
     struct No *info;
     struct No *esq;
     struct No *dir;
};

typedef struct Arv arv; ///Definição do tipo da arvore

///Indice de funções do programa
void criarArvore(arv *pRaiz);
void busca(arv *pRaiz);
void insere(arv *pRaiz, struct No *aux);
void registra(arv *pRaiz);
void menu(arv *pRaiz);


///Função responsavel por inicializar a arvore, apontando seus tres ponteiros para nulo
void criarArvore(arv *pRaiz){ 
    (pRaiz)->info=NULL;
    (pRaiz)->esq = NULL;
    (pRaiz)->dir = NULL;
}

///Função responsavel por buscar na arvore por algum nome que o usuario de como entrada para a consulta
void busca(arv *pRaiz){

char nome[10];

printf("Informe o nome desejado: ");
scanf("%s", &nome);
///As condições a seguir são para verificar se o nome consultado está em algum dos tres ponteiros principais da estrutura
if(nome[0] < pRaiz->info->nome[0]){
    if (strcmp(nome , pRaiz->esq)==0 ) {

       printf("\nNome: %s\n",pRaiz->esq->nome);
       printf("\nSexo: %s\n",pRaiz->esq->sexo);
       printf("\nPai: %s\n",pRaiz->esq->pai);
       printf("\nMãe: %s\n",pRaiz->esq->mae);
       printf("\nConjugue: %s\n",pRaiz->esq->conj);
       printf("\nSexo do(a) Conjugue: %s\n",pRaiz->esq->sconj);
       printf("\nFilho(se tiver): %s\n",pRaiz->esq->filho);
       printf("\nIrmão: %s\n",pRaiz->esq->irmao);

    }
    else {
        printf("\nNome nao registrado!\n");
    }

}
if(nome[0] > pRaiz->info->nome[0]){
    if (strcmp(nome , pRaiz->dir)==0 ) {

       printf("\nNome: %s\n",pRaiz->dir->nome);
       printf("\nSexo: %s\n",pRaiz->dir->sexo);
       printf("\nPai: %s\n",pRaiz->dir->pai);
       printf("\nMãe: %s\n",pRaiz->dir->mae);
       printf("\nConjugue: %s\n",pRaiz->dir->conj);
       printf("\nSexo do(a) Conjugue: %s\n",pRaiz->dir->sconj);
       printf("\nFilho(se tiver): %s\n",pRaiz->dir->filho);
       printf("\nIrmão: %s\n",pRaiz->dir->irmao);

    }
    else {
        printf("\nNome nao registrado!\n");
    }

}


    if (strcmp(nome , pRaiz->info)==0 ) {

       printf("\nNome: %s\n",pRaiz->info->nome);
       printf("\nSexo: %s\n",pRaiz->info->sexo);
       printf("\nPai: %s\n",pRaiz->info->pai);
       printf("\nMãe: %s\n",pRaiz->info->mae);
       printf("\nConjugue: %s\n",pRaiz->info->conj);
       printf("\nSexo do(a) Conjugue: %s\n",pRaiz->info->sconj);
       printf("\nFilho(se tiver): %s\n",pRaiz->info->filho);
       printf("\nIrmão: %s\n",pRaiz->info->irmao);

    }
    else {
        printf("\nNome nao registrado!\n");
    }




}


///Função responsavel por inserir um elemento na arvore
void insere(arv *pRaiz, struct No *aux)
{

///A seguinte condição irá comparar se a casa atual é nulo e irá inserir a informação
  if((pRaiz)->info == NULL){
        (pRaiz)->esq = NULL;
        (pRaiz)->dir = NULL;
        (pRaiz)->info = aux;
}
    else///Se não irá inserir na esquerda ou direita dependendo da ordem que devera ser seguida
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


///Função responsavel por receber as informações do individuo a ser inserido pelo usuario
void registra(arv *pRaiz){


struct No *aux =(struct No *) malloc(sizeof(struct No));///Alocação do novo elemento a ser inserido
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
insere(pRaiz, aux); ///Chamada da função de inserção
printf("\nRegistrado!\n");

}


///Função responsavel por dizponibilizar a interface de acesso do usuario, recebendo uma opção do mesmo e acessando as outras funções através dessa opção
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
            registra(pRaiz);///Chamada da função de registrar
            system("pause");
            break;
        }
      case 2:
        {
          busca(pRaiz);///Chamada da função que buscará um individuo por nome
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



int main()///Função principal
{
    arv *arvore = (arv*)malloc(sizeof (arv));///Criação da arvore e alocação de memoria da mesma


    criarArvore(arvore);///Chamada da função que inicializa a arvore
    menu(arvore);///Chamada do menu


}
