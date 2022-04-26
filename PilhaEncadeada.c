#include <stdio.h>
#include <stdlib.h>
 
 typedef struct{
 	char site[40],data[40];
 }tdado;
 typedef struct no{
 	tdado dado;
 	struct no *prox;
 }tno;
 typedef struct{
 	tno *topo;
 }tpilha;
 
//-------------------------
void inicializa(tpilha *p){
	p->topo = NULL;
}
//--------------------------
int push(tpilha *p, tdado x){
	tno *novo;
	novo = malloc(sizeof(tno));
	if(novo == NULL) // erro ao alocar
		return 0;
	novo->prox = p->topo;
	novo->dado = x; 
	p->topo = novo;
	return 1;
}
//--------------------------
tdado pop(tpilha *p){
	tno *aux;
	aux = p->topo; // aux para liberar a mem
	p->topo = p->topo->prox;
	tdado x = aux->dado; // guardando o dado para devolver para o usuario
    free(aux);
	return x;
}
//-----------------------------
int isEmpty(tpilha p){
	return p.topo == NULL?1:0;
	// if(p.topo==NULL)
	//   return 1;
	//else
	//    return 0;
}
//---------------------------
void mostraPilha(tpilha p){
	while(p.topo!=NULL){
		printf("%s | %s ->",p.topo->dado.site,
							p.topo->dado.data);
		p.topo = p.topo->prox;					
	}// fim while
	printf("\n");
}
//-------------------------------------
tdado peek (tpilha p){
	return p.topo -> dado;
}
//---------
int menu(){
	int op;
	printf("*** Estrutura de Dados I - Pilha Encadeada ****\n");
	printf("1-Push (Inserir)\n");
	printf("2-Pop (Remover)\n");
	printf("3-Top (Olhar Topo)\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------
int main(){
	tpilha p1;
	tdado x;
	int op;
	inicializa(&p1);
	do{
		mostraPilha(p1);
		printf("Topo:%d\n",p1.topo); // ver valor topo
		op = menu();
		switch(op){
			case 1: printf("Dado para inserir[Site Data]:");
			fflush(stdin);
					gets(x.site);
			fflush(stdin);
					gets(x.data);
					if(   push(&p1,x) ==1 )  
					  printf("Site %s acessado :)\n", x.site);
					else
					  printf("Stack overflow :(\n"); 
			break;
			case 2: if(!isEmpty(p1)) {
				       x = pop(&p1); 
				       if(!isEmpty(p1)) 
			 		   printf("Saindo de %s, voltando para o site %s\n",
								x.site, peek(p1).site);
								else
								printf("Saindo de %s, historico vazio\n",
								x.site);
				     }// fim if vazio
				     else
				       printf("Stack empty :(\n");
				break;
			case 3:if(!isEmpty(p1)) {
				       x = peek(p1); 
			 		   printf("Topo do historico: %s\n :(\n",x.site);
				     }// fim if vazio
				     else
				       printf("Stack empty :(\n");
			 break;	
			case 0: printf("Saindo .... ;)\n");	    
		}// fim switch
	    getch(); // system("pause");
	    system("cls");
	}while(op!=0);

	return 0;
}
