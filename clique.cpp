#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATENÇÃO: O cálculo da complexidade deve incluir todo o ccódigo, inclusive a leitura do arquivo.


char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare variáveis globais a partir daqui.




void executafuncao (){   										// É dentro desta função que o aluno deverá escrever seu código
    int maior_clique = 1;
    int clique;
    int qtd;

    for(int mascara = 1; mascara < (1 << n); mascara++){
        clique = 1;
        qtd = 0;

        for(int i = 0; i < n; i++){
            if(mascara & (1 << i)){
                qtd++;
            }
        }

        for(int i = 0; i < n && clique; i++){
            if(mascara & (1 << i)){
                for(int j = i + 1; j < n; j++){
                    if(mascara & (1 << j)){
                        if(matriz_adj[i+1][j+1] == 0){
                            clique = 0;
                            break;
                        }
                    }
                }
            }
        }

        if(clique && qtd > maior_clique){
            maior_clique = qtd;
        }
    }

    printf("Clique do grafo: K%d\n", maior_clique);
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

