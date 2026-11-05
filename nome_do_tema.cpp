#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATENÇÃO: O cálculo da complexidade deve incluir todo o ccódigo, inclusive a leitura do arquivo.

typedef struct elemento{
	int info;		//variavel que guarda a informacao do no
	elemento *prox; //ponteiro para o proximo elemento (no) do grafo
} elemento;

typedef struct busca{
	int vertice; //variavel que guarda o vertice
	bfs *prox; //pronteiro para o proximo elemento da fila de busca
} bfs;

typedef struct pilha{
	elemento *topo; //ponteiro que aponta para o elemento do topo da pilha
} pilha;

typedef struct fila{
	elemento *inicio; //ponteiro de controle que aponta para o elemento inicial da fila
	elemento *fim; //ponteiro de controle que aponta para o elemento final da fila
} fila;

char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare variáveis globais a partir daqui.

bfs *inicio_busca = 0; // ponteiros para controlar onde comeca e onde termina a fila da busca, inicializados com 0 para = vazio
bfs *fim_busca = 0;
int visitado[MAX]; //variavel de controle para identificar os vertices ja visitados

void enfileirar(int v){ //serve para enfileirar os vertices (v) que serao visitados depois
	bfs *novo = (bfs *) malloc(sizeof(bfs)); //alocacao da memoria
	
	if(novo == NULL){
		printf("\nerro de alocacao.\n");
		return;
	}
	
	novo->vertice = v; //guarda o numero do vertice
	novo->prox = 0; //aponta o prox igual a nulo, pois o anterior é o ultimo
	
	if(fim_bfs == 0){ //se a fila estiver vazia o inicio e o fim passam a ser o mesmo
		inicio_busca = novo;
		fim_busca = novo;
	} else { //senao estiver, conecta o antigo vertice guardado ao novo e atualiza o vertice final
		fim_busca->prox = novo;
		fim_busca = novo;
	}
}

int desenfileirar(){ //serve para retirar os vertices ja visitados da fila da bfs, le o primeiro da fila e libera a memoria em seguida
	if(inicio == 0){ //verifica se a fila esta vazia, se estiver vazia nao ha o que remover
		return -1;
	}
	
	bfs *aux = inicio_busca; //o auxiliar guarda o endereco da primeira posicao
	int v = aux->vertice; //pega o numero do vertice guardado na primeira posicao
	inicio_busca = inicio_busca->prox; //avanca o ponteiro do inicio para a proxima posicao
	
	if(inicio_busca == 0){ //se o novo valor guardado no inicio for zero, a fila acabou e o fim tambem vira 0
		fim_busca = 0;
	}
	
	free(aux); // libera a memoria antiga do aux
	return v; // retorna o numero do vertice
}

void busca_largura(int v_inicial){
	for (int k = 1; k<= n; k++){ //marca todos os vertices como nao visitados
		visitado[k] = 0;
	}
	
	enfileirar(v_inicial); //coloca o vertice de inicio na fila
	visitado[v_inicial] = 1; //marca ele como visitado
	
	printf("\nResultado da busca em largura: ");
	while(inicio_busca != 0){ //enquanto a fila da busca nao estiver vazia sera repetido
		int v_atual = desenfileirar(); //retira o retira o vertice da frente da fila
		
		printf("%d ", v_atual); //exibe o resultado atual da busca
		
		for(int v = 1; v <= n; v++){ //procura o vizinhos do vertice atual olhando a linha dele
			if(matriz_adj[v_atual][v] == 1 && visitado[v] == 0){ //se existir aresta (matriz_adj == 1) e o vizinho nao foi visitado ainda
				visitado[v] = 1; // marca o vizinho como visitado
				enfileirar(v); // e manda o vizinho pra fila de busca
			}
		}
	}
	printf("\n");
	
}

void push(pilha *p, int dado){ //funcao inserir da pilha
	elemento *novo = (elemento *) malloc(sizeof(elemento)); //alocacao da memoria
	
	if(novo == 0){
		printf("\nErro de alocacao!\n");
		return;	
	}
		
	novo->info = dado; //guarda o novo dado
	novo->prox = p->topo; //atualiza o proximo elemento do topo com a informacao do topo antigo
	p->topo = novo; //atualiza o topo com o dado recem inserido
}

int pop(pilha *p){ //funcao de remover da pilha

	if(p->topo == 0) //confere se a pilha nao esta vazia
		return -1;
		
	elemento *aux = p->topo; //guarda o topo no ponteiro auxiliar
	int valor = aux->info; //guarda a informacao do no do topo
	p->topo = p->topo->prox; // substitui o topo com o valor do proximo no
	free(aux); //libera o auxiliar e as informacoes contidas nele
	return valor; //retorna a informacao do no que foi removido
}

void exibir_pilha(){ //funcao para exibir a pilha do grafo

	if(p->topo == 0){ //confere se a pilha esta vazia
		printf("\na pilha esta vazia.");
		return;
	}
	
	printf("\nexibindo pilha: ");
	elemento *atual = p->topo; //guarda o topo como sendo o primeiro elemento a ser impresso (atual)
	while (atual != 0){
		printf("%d ", atual->info); //executa um laco de repeticao para imprimir a informacao do no atual
		atual = atual->prox; //avanca o atual para o elemento seguinte
	}
	
	printf("\n");
	
}

void enqueue(fila *f, int dado){ //funcao de inserir na fila
	elemento *novo = (elemento *) malloc(sizeof(elemento));
	
	if(novo == 0){
		printf("\nerro de alocacao!\n");
		return
	}
	
	novo->info = dado; //guarda o novo dado
	novo->prox = 0; // atualiza o proximo para nulo (fim da fila)
	
	if(f->fim == 0){ //verifica se a fila esta vazia
		f->inicio = novo; //aloca o novo no como o inicio e o fim da fila
		f->fim = novo;
	} else { //senao, atualiza o proximo elemento do fim com o novo no e indica que o fim é ele tambem
		f->fim->prox = novo;
		f->fim = novo;
	}
	
} 

int dequeue(fila *f){
	
}


void executafuncao (){   										// É dentro desta função que o aluno deverá escrever seu código
int x = 0;
if (!x) {
printf ("deu certo");
}



}


int main() {
	opcao = 1;

    while(opcao != 0){
        inicio:
        tamanho = 0;
        m = 0;
        digrafo = 0;
        system("cls"); 
        fflush(stdin); 
        printf("Digite o nome do arquivo (sem o .txt): ");
        gets(nome_arquivo);
        FILE *arquivo; 
        strcat(nome_arquivo,".txt"); 
            
        if((arquivo = fopen(nome_arquivo,"r")) != NULL){
        	while(fgets(aux, MAX, arquivo)) { 
                   char *elemento; 
                   elemento = strtok(aux, " ");
                    while (elemento != NULL){
                        elemento = strtok(NULL, " "); 
                    }
                    tamanho = tamanho + 1; 
                }
                fclose(arquivo);
                
                printf ("\n --------------------------- MATRIZ DE ADJACÊNCIA ---------------------------\n");
                
                if((arquivo = fopen(nome_arquivo,"r")) != NULL){
                    printf("\n");
                    for(int i = 1; i <= tamanho; i++){
                        for(int j = 1; j <= tamanho; j++){
                            fscanf(arquivo, "%d", &matriz_adj[i][j]);
							printf("%3d ", matriz_adj[i][j]); 
                        }
                        printf("\n");
                    }
                }
                fclose(arquivo);
				n = tamanho;
				
                for(int i = 1; i <= tamanho; i++){
                    for(int j = 1; j <= tamanho; j++){
						if (matriz_adj[i][j] != matriz_adj[j][i]) {
							digrafo = 1;   // é dígrafo
						}
					}
				}
				
                for(int i = 1; i <= tamanho; i++){
                    for(int j = 1; j <= tamanho; j++){
						if (digrafo == 1 && matriz_adj[i][j] != 0) {
							m = m + 1;
						} 
						if (digrafo == 0 && matriz_adj[i][j] != 0 && i <= j) {
							m = m + 1;
						}
					}
				}
				
	          printf ("\nN = %d e M = %d \n \n",n,m);     
            } else {
                printf("\nErro ao abrir o arquivo/Erro ao localizar o arquivo\n\n");
                
            }
        	  
		executafuncao ();       
        printf("\nDigite 0 para sair ou qualquer outra coisa para continuar: ");
		scanf("%d", &opcao);
        
    }
    return 0;
}

