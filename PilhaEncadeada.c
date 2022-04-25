#include <stdio.h>
#include <stlib.d>

typedef struct {
	char site[40],
	data[40];	
}tdado;

typedef struct{
	tdado dado;
	struct no *prox;//capaz de apontar para outro nó
}tno;

typedef struct{
	tno *topo;
}tpilha;

//-----------------
void inicializa(tpilha *p){
	p->topo = NULL;
}
//-----------------
int push(tpilha *p, tdadp x){
	tno *novo;
	novo = malloc(sizeoff(tno));
	if(novo == NULL) //erro ao alocar 
	novo->prox = p->topo;
	novo->dado = x;
	p->topo = novo;
	return 1;
}
//-----------------
tdado pop(p.pilha *p){
	tno *aux;
	aux = p->topo;//aux para liberar a memória
	p->topo = p->topo->prox;
	tdado x = aux->dado;//guardando o dado para devolver para o usuário
	free(aux);//libera a memória
	return x;	
}
//-----------------
int isEmpty(tpilha p){
	return p.topo == NULL?1:0;
	/*if(p.toppo == NULL)
	     return 1;
	  else
	     return 0; */	
}
//-----------------
void mostra(tpilha p){
	while (p.topo != NULL){
		printf("%s | %s ->",p.topo->dado.site,
		                    p.topo->dado.data);
		p.topo = p.topo->prox;
	}	                
	}//Fim while
	printf("\n");
}
//------------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I - Fila Estatica ****\n");
	printf("1-Enqueue (Inserir)\n");
	printf("2-Dequeue (Remover)\n");
	printf("3-Inicio e Fim\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------------
int main(){
	tfila f1;
	tdado x;
	int op;
	inicializa(&f1);
	do{
		printf("Inicio[%d] | Fim[%d]\n",f1.ini,f1.fim);
		
		mostra(f1);
		op = menu();
		switch(op){
			case 1: printf("Entre com o nome e idade:");
					fflush(stdin);
					gets(x.nome);
					scanf("%d",&x.idade);
					if(   enqueue(&f1,x) ==1 )  
					  printf("Dado inserido :)\n");
					else
					  printf("Vagas esgotadas :(\n"); 
			break;
			case 2: if(!isEmpty(f1)) {
				       x = dequeue(&f1); 
			 		   printf("Dado removido:%s:%d\n",x.nome,x.idade);
				     }// fim if vazio
				     else
				       printf("Queue empty :(\n");
				break;
			case 3:
			 break;	
			case 0: printf("Saindo ....\n");	    
		}// fim switch
	    getch(); // system("pause");
	    system("cls");
	}while(op!=0);

	return 0;
}
