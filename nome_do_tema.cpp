#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATENÇÃO: O cálculo da complexidade deve incluir todo o ccódigo, inclusive a leitura do arquivo.


char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare variáveis globais a partir daqui.

typedef struct Elemento{
	int num;
	struct elemento *prox; //ponteiro para o proximo elemento
} elemento;

typedef struct Pilha{
	struct elemento *topo; // ponteiro para o elemento do topo da pilha
} pilha;

typedef struct Fila{
	int inicio;
	int fim;
} fila;

typedef struct Bfs{
	int vertice;
	struct bfs *prox;
} bfs;

struct bfs *inicio = 0; // ponteiros para controlar onde comeca e onde termina a fila, inicializados com 0 para = vazio
struct bfs *fim = 0;

void enfileirar(int v){ //serve para enfileirar os vertices (v) que serao visitados depois
	struct bfs *novo = (struct bfs*) malloc(sizeof(struct bfs)); //alocacao da memoria
	novo->vertice = v; //guarda o numero do vertice
	novo->prox = 0; //aponta o prox igual a nulo, pois o anterior é o ultimo
	
	if(fim_bfs == 0){ //se a fila estiver vazia o inicio e o fim passam a ser o mesmo
		inicio = novo;
		fim = novo;
	} else { //senao estiver, conecta o antigo vertice guardado ao novo e atualiza o vertice final
		fim->prox = novo;
		fim = novo;
	}
}

int desenfileirar(){ //serve para retirar os vertices ja visitados da fila da bfs, le o primeiro da fila e libera a memoria em seguida
	if(inicio == 0){ //verifica se a fila esta vazia, se estiver vazia nao ha o que remover
		return -1;
	}
	
	struct bfs *aux = inicio; //o auxiliar guarda o endereco da primeira posicao
	int v = aux->vertice; //pega o numero do vertice guardado na primeira posicao
	inicio = inicio->prox; //avanca o ponteiro do inicio para a proxima posicao
	
	if(inicio == 0){ //se o novo valor guardado no inicio for zero, a fila acabou e o fim tambem vira 0
		fim = 0;
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
	while(inicio != 0){ //enquanto a fila da busca nao estiver vazia sera repetido
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

