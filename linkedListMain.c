#include <stdio.h>
#include <stdlib.h>
//Declaração da struct principal utilizada.
struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;
//--------------------------------
int tam;
/*Variável global que possui o tamanho atual da 
Linked List.*/
//Definição das funções utilizadas no programa.
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);
//--------------------------------
int main(void){
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){//if(LISTA==NULL)
		/*Se LISTA for igual a NULL,isso indica que
		malloc não encontrou espaço na memória dis
		ponível para a alocação de dados.*/
		printf("Sem memoria disponivel!\n");
		exit(1);//Programa encerra aqui.
	}else{
 		inicia(LISTA);
		/*Inicia a lista (ver linha ).*/ 
		int opt;
		do{
			opt=menu();
			system("cls");
			/*Mostra ao usuário as opções
			disponíveis e pega uma escolhida
			por ele (ver linha ).*/
			opcao(LISTA,opt);
			system("pause");
			system("cls");
			/*Chama a função opcao(),que dá os 
			caminhos possíveis para a rotina 
			principal seguir,passando 
			como argumentos,o próprio ponteiro
			que aponta para a lista e a opção 
			escolhida pelo usuário.*/
		}while(opt);
		/*Esse comando while será executado 
		até opt ser igual a zero.Quando isso
		ocorrer,será quebrado.*/
		free(LISTA);
		/*Quando opt for igual a zero,significa
		que o usuário escolheu finalizar a exe
		cução do programa.A função free() libera
		o espaço de memória utilizado para 
		conter a Linked List.*/
	}
	return 0;
}

void inicia(node *LISTA){
	LISTA->prox = NULL;
	tam=0;
}
/*Faz com que o próximo (primeiro) elemento da lista 
seja NULL e define a variável global tam (tamanho da 
lista) como 0.Deve ser usada,primeiramente,a função libera().*/
  
int menu(void){
	int opt;
	printf("Escolha uma opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar lista\n");
	printf("2. Exibir lista\n");
	printf("3. Adicionar node no inicio\n");
	printf("4. Adicionar node no final\n");
	printf("5. Escolher onde inserir\n");
	printf("6. Retirar do inicio\n");
	printf("7. Retirar do fim\n");
	printf("8. Escolher de onde tirar\n");
	printf("Opcao: "); scanf("%d", &opt);
	return opt;
}
/*Oferece ao usuário,opções para manipulação de uma Linked List.
Após pegar a opção escolhida pelo usuário,retorna-a.*/

void opcao(node *LISTA, int op){
	node *tmp;
	/*Guarda um nó de lista tempo
	rariamente.*/
	switch(op){
		case 0:
			libera(LISTA);
			break;
		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;
		case 2:
			exibe(LISTA);
			break;
		case 3:
			insereInicio(LISTA);
			break;
		case 4:
			insereFim(LISTA);
			break;
		case 5:
			insere(LISTA);
			break;
		case 6:
			tmp=retiraInicio(LISTA);
			printf("Retirado: %3d\n\n", tmp->num);
			break;
		case 7:
			tmp=retiraFim(LISTA);
			printf("Retirado: %3d\n\n", tmp->num);
			break;
		case 8:
			tmp=retira(LISTA);
			printf("Retirado: %3d\n\n", tmp->num);
			break;
		default:
			printf("Comando invalido\n\n");
	}	
}
/*Através de um comando condicional múltiplo
switch,faz a seleção das opções mostradas ao 
usuário no menu de opções,utilizando as funções
criadas neste código para guiar a rotina principal
do programa.*/

int vazia(node *LISTA){
	if(LISTA->prox == NULL) return 1;
	else return 0;
}
/*Se o próximo (primeiro) elemento da lista é 
NULL,isso implica que ela está vazia,então 
retorna 1,do contrário,0.*/

node *aloca(){
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		/*Se novo==NULL,malloc disse que não 
		há memória suficiente para alocar.*/
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: ");
		scanf("%d", &novo->num);
	}
	return novo;
}
/*Aloca de modo dinâmico,espaço na memória
para conter um novo elemento,que será aponta
do por um ponteiro,e o retorna.*/

void insereFim(node *LISTA){
	node *novo=aloca();
	/*novo recebe um novo elemento de lista
	com espaço alocado na memória.*/
	novo->prox = NULL;
	/*Sempre o elemento após o último da 
	lista é NULL.*/
	if(vazia(LISTA))
		LISTA->prox=novo;
		/*Se a lista está sem elementos,
		seu primeiro passa a ser o 
		nó novo*/
	else{
		node *tmp = LISTA->prox;
		/*tmp é um elemento temporário,
		que irá percorrer toda a lista
		em busca do último elemento em
		ligação. Quando isso é alcançado,
		ele atribue o nó novo como o pró
		ximo elemento depois do final.*/
		while(tmp->prox != NULL) tmp = tmp->prox;
		tmp->prox = novo;
	}
	tam++;
}
/*Cria e insere um novo elemento no final
da lista*/

void insereInicio(node *LISTA){
	node *novo=aloca();
	/*novo recebe um novo elemento de lista
	com espaço alocado na memória.*/
	node *oldHead = LISTA->prox;
	/*oldHead irá conter o primeiro
	elemento da lista.*/
	LISTA->prox = novo;
	/*O primeiro elemento da
	lista,agora será novo.*/
	novo->prox = oldHead;
	/*O segundo elemento da
	lista,agora será oldHead.*/
	tam++;
	/*Aumentando o tamanho
	da lista*/
}
/*Cria e insere um novo elemento no início 
da lista (como sua cabeça).*/

void exibe(node *LISTA){
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return;
	}
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	/*tmp é um elemento temporário,
	que percorre toda a lista (do pri
	meiro elemento até NULL) e mostra 
	os dados encontrados em cada nó.*/
	printf("\n");
	int count;
	for(count=0;count<tam;count++)printf(" ^ ");
	printf("\nOrdem:");
	for(count=0;count<tam;count++)printf("%5d", count+1);
	printf("\n\n");
}
/*Se a lista não estiver vazia,mostra cada dado de 
cada nó inserido em ordem sequencial (do primeiro 
ao último).*/

void libera(node *LISTA){
	if(!vazia(LISTA)){
		node *proxNode,*atual;
		atual = LISTA->prox;
		/*atual recebe o pri
		meiro elemento da lista.*/
		while(atual != NULL){
			/*Enquanto não chegarmos
			ao elemento após o último
			da lista (NULL) esse iterador
			repetirá.*/
			proxNode = atual->prox;
			/*proxNode recebe sempre
			o próximo elemento de atual.*/
			free(atual);
			/*Libera o espaço de memória
			ocupado por cada nó da lista.*/
			atual = proxNode;
			/*Faz com que atual receba,após
			ter o nó da lista contido em 
			si,liberado (seu espaço ocupado 
			na memória),um elemento exatamente
			depois deste.*/
		}	
	}
}
/*Se a lista possuir elementos,libera os espaços 
de memória ocupados por eles.*/

void insere(node *LISTA){
	int pos,count;
	printf("Em que posicao, [de 1 ate %d] voce " 
	"deseja inserir: ", tam);
	scanf("%d", &pos);
	if(pos>0 && pos <= tam){
		/*Se a posição escolhida pelo usuário
		estiver fora do intervalo da lista,o else
		será executado.*/
		if(pos==1) insereInicio(LISTA);
		else{
			node *atual = LISTA->prox,*anterior=LISTA;
			/*atual recebe o primeiro nó da lista.
			anterior recebe o próprio ponteiro que
			aponta para a lista.*/
			node *novo=aloca();
			/*Cria-se o novo elemento para
			ser inserido na lista.*/
			for(count=1;count<pos;count++){
				anterior=atual;
				atual=atual->prox;
			}
			/*Esse laço for percorre a lista
			até encontrar a posição especificada
			pelo usuário,desfaz a ligação entre 
			a corrente de nós e o nó encontrado
			naquela posição,liga o novo nó à cor
			rente e,por fim,o outro nó ao novo.
			Ex.: Inserir Z na posição 4
			A->B->C->D->E->F->NULL (Início)
			A->B->C  D->E->F->NULL
			A->B->C->Z  D->E->F->NULL
			A->B->C->Z->D->E->F->NULL (Fim)
			*/
			anterior->prox=novo;
			novo->prox = atual;
			tam++;
		}
	}else printf("Elemento invalido\n\n");
}
/*Cria e insere um novo elemento na lista,
na posição especificada pelo usuário.
Trabalha deslocando cada elemento um nó 
para traz.*/

node *retiraInicio(node *LISTA){
	if(LISTA->prox == NULL){
	/*Se o primeiro elemento da
	lista for NUll significa que
	ela está vazia.*/
		printf("Lista ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = LISTA->prox;
		/*tmp recebe o primeiro
		elemento da lista.*/
		LISTA->prox = tmp->prox;
		/*O primeiro elemento da lista
		recebe exatamente o segundo 
		elemento da lista (próximo 
		depois do primeiro).*/
		tam--;
		/*Pós-decrementando a lista
		de nós.*/
		return tmp;
		/*tmp possui o antigo primeiro
		elemento da lista,que agora é
		retornado para a função opcao()
		para a exibição de uma mensagem
		final de remoção do elemento.*/
	}
}
/*Retira o primeiro elemento da lista 
de nós.*/

node *retiraFim(node *LISTA){
	if(LISTA->prox == NULL){
		/*Se o primeiro elemento da
		lista for NUll significa que
		ela está vazia.*/
		printf("Lista ja vazia\n\n");
		return NULL;
	}else{
		node *ultimo = LISTA->prox,
 		*penultimo = LISTA;
 		/*ultimo recebe o primeiro elemento
		 da lista;penultimo,o próprio ponteiro
		 que aponta para a lista.*/
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		/*Esse laço percorre a lista
		desde seu primeiro elemento
		até encontrar o último.
		Quando isso é feito (ultimo
		->prox==NULL e penultimo->prox
		==ultimo),NULL é atribuído ao
		último elemento (penultimo->prox
		=NULL).*/
		penultimo->prox = NULL;
		tam--;
		/*Pós-decrementando a lista
		de nós.*/
		return ultimo;
		/*O ultimo elemento é retornado
		para a função opcao() para a 
		exibição de uma mensagem final
		de remoção do elemento.*/
	}
}
/*Retira o último elemento da lista
de nós.*/

node *retira(node *LISTA){
	int opt,count;
	printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
	scanf("%d", &opt);
	if(opt>0 && opt <= tam){
		/*Se a posição escolhida pelo usuário
		estiver fora do intervalo da lista,o else
		será executado.*/
		if(opt==1) return retiraInicio(LISTA);
		else{
			node *atual = LISTA->prox,
			*anterior=LISTA;
			/*atual recebe o primeiro elemento
			da lista;anterior,o próprio ponteiro
			que aponta para a lista.*/
			for(count=1;count<opt;count++){
				anterior=atual;
				atual=atual->prox;
			}
			/*O comando for percorre toda a
			lista até encontrar a posição solicitada
			pelo usuário.Quando isso é feito,o elemento
			anterior a essa posição,se desliga dela e 
			se liga ao elemento exatamente depois deste.
			Ex.: Retirando X da posição 3
			A->B->X->C->D->E->F->NULL (Início)
			A->B  X->C->D->E->F->NULL
			A->B->C->D->E->F->NULL	(Fim)
				  X
			*/
			anterior->prox=atual->prox;
			tam--;
			/*Pós-decrementando a lista
			de nós.*/
			return atual;
			/*atual contém o elemento que fora
			desligado da lista de nós.Ele é 
			retornado para a função opcao() 
			para a exibição de uma mensagem 
			final de remoção do elemento.*/
		}
	}else{
		printf("Elemento invalido\n\n");
		return NULL;
	}
}
/*Retira um elemento qualquer dentro do 
intervalo da lista.*/
