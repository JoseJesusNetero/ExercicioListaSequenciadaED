#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//José Jesus

int NumElem = 0;

typedef struct Lista{
    int Elementos;
    struct Lista *prox;
    
}ListaInteiros;

// Função de Inicializar
ListaInteiros* Inicializar(void){
    return NULL;
}

//Função de Inserir
ListaInteiros* Inserir(ListaInteiros *ali, int Elementos){
    //for(int b = 1; b <= Quantidade; b++){
    ListaInteiros *Novo = (ListaInteiros*)malloc(sizeof(ListaInteiros));
    Novo -> Elementos = Elementos;
   
    //Novo -> NumElem++;
    NumElem++;
    Novo -> prox = ali;
    return Novo;    
    //}
    
}

//Funçao de Busca
ListaInteiros* Busca(ListaInteiros* ali, int a){
    ListaInteiros *p;
    int Contando = 0;// Nao esta funcionando esse Contando
    for (p = ali; p!= NULL; p = p-> prox) {
        if(p -> Elementos == a){
           printf("O numero %d está na posição %d\n", p-> Elementos, NumElem);
           Contando++;
           return p;
            }
    }

    if (Contando == 0){
            printf("Nao existe esse valor\n");
            
        } 

    return NULL;
    }
    
//Função para Excluir
ListaInteiros* Excluir(ListaInteiros* ali, int a){
    ListaInteiros* Antes = NULL;
    ListaInteiros* p = ali;
    while (p != NULL && p -> Elementos != a){
        Antes = p;
        p = p -> prox;
    }
    if (p == NULL) return ali;
    if(Antes == NULL) ali = p -> prox;
    else Antes -> prox = p -> prox;
    return ali;
    }  
    
int main() {
    int NumerodeElementos, Preencher, Valores,Pesquisar, Colocacao;
    
    ListaInteiros* Original;
    Original = Inicializar();  // Inicializa lista como vazia

    printf("Digite quantos elementos voce quer preencher\n");
    scanf("%d", &Preencher);

//Inserindo os Dados
    for(NumerodeElementos = 1; NumerodeElementos <= Preencher; NumerodeElementos++){    
        printf("Informe o proximo Valor\n");
        scanf("%d", &Valores);
        Original = Inserir(Original, Valores);
        }
   
    printf("Informe o Valor a ser pesquisado e daremos ele com sua respectiva localizacao\n");
    scanf("%d", &Pesquisar);

    Busca(Original, Pesquisar);

    printf("Diga o elemento que deseja excluir\n");
    scanf("%d", &Pesquisar);
    Excluir(Original, Pesquisar);

    printf("Verifique agora se o elemento que você pediu ainda consta\n ");
    printf("Digite o valor verificar\n");
    scanf("%d", &Pesquisar);
    Busca(Original, Pesquisar);
    
    return 0;
    }


