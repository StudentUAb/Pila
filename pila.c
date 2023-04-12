#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da pilha
struct Pilha {
	int topo; /* pocição do elemento topo */
	int capa; /* capacidade da pilha */
	int *pElem; /* ponteiro para o vetor de elementos */
};

// Funções da pilha
void criarpilha( struct Pilha *p, int c ){
   p->topo = -1;
   p->capa = c;
   p->pElem = (int*) malloc (c * sizeof(int));
}

int estavazia ( struct Pilha *p ){
   if( p-> topo == -1 )
      return 1;   // true
   else
      return 0;   // false
}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;
}

void empilhar ( struct Pilha *p, int v){

	p->topo++;
	p->pElem [p->topo] = v;

}

int desempilhar ( struct Pilha *p ){
   int aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

int retornatopo ( struct Pilha *p ){
   return p->pElem [p->topo];
}

// Programa principal
int main(){
    // Declaração da pilha
	struct Pilha minhapilha;
	int capacidade, op;
	int valor;

    // Inicialização da pilha
	printf( "\nCapacidade da pilha(quantos valores inteiros vai introduzir)? " );
	scanf( "%d", &capacidade );

    // Criação da pilha
	criarpilha (&minhapilha, capacidade);

    // Menu de opções
	while( 1 ){ /* loop infinito */
		printf("\n1- Empilhar (push)\n");
		printf("2- Desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
        printf("4- Mostrar valores da pila \n");
		printf("5- sair\n");
		printf("\nIntroduzir opcao? ");
		scanf("%d", &op);

        // Seleção da opção
		switch (op){

			case 1: //push
				if( estacheia( &minhapilha ) == 1 )
					printf("\nPILHA CHEIA! \n");
				else {
					printf("\nVALOR? ");
					scanf("%d", &valor);
					empilhar (&minhapilha, valor);
				}
				break;

			case 2: //pop
				if ( estavazia(&minhapilha) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else{
					valor = desempilhar (&minhapilha);
					printf ( "\n%d DESEMPILHADO!\n", valor );
				}
				break;

			case 3: // mostrar o topo da pila
				if ( estavazia (&minhapilha) == 1 )
					printf( "\nPILHA VAZIA!\n" );
				else {
					valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %d\n", valor );
				}
				break;

            case 4: // mostrar a pilha inteira
                if ( estavazia (&minhapilha) == 1 )
                    printf( "\nPILHA VAZIA!\n" );
                else {
                    printf ( "\nPILHA:\n" );
                    for (int i = minhapilha.topo; i >= 0; i--)
                        printf ( "%d\n", minhapilha.pElem[i] );
                }
                break;
                        // sair
                        case 5: 
                            exit(0);
                        // opção inválida
                        default: printf( "\nOPCAO INVALIDA! \n" );
                    }
                }               
}