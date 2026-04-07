#include<stdio.h>
#include<stdlib.h>     // necessario para malloc e free
#include<string.h>
#include<time.h>
// definindo uma Struct do tipo Territorio é um novo TIPO (tipo int, ou float) um dado que possui varios dados dentro
typedef struct{
    char nome [30];
    char cor [10];
    int tropas;
} Territorio;

void cadastrar(Territorio *mapa, int quantidade){     // modularização criando a função cadastrar
    int i;
    for (i = 0; i < quantidade; i++){   // laço for para fazer a iteração dos dados pedidos ao usuário

        printf("\nNome do territorio: ");
        while(getchar() != '\n');                      // para limpar o enter
        fgets(mapa[i].nome, 30, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
 
        printf("Cor do exercito: ");
        fgets(mapa[i].cor, 10, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';
        
        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);   // Para ler o número de tropas, usamos & para passar o endereço da variável
    }
}
void atacar(Territorio *atacante, Territorio *defensor){
	if (atacante->tropas <= 1){
		printf("Não ha tropas suficientes para o ataque!\n");
		return;
	}
	int dadoAtacante = rand()%6 + 1;
	int dadoDefensor = rand()%6 + 1;
	printf("O atacante %s rolou o dado e tirou: %d\n", atacante->nome, dadoAtacante);
	printf("O defensor %s rolou o dado e tirou: %d\n", defensor->nome, dadoDefensor);
	if(dadoAtacante >= dadoDefensor){             // Com essa condição o empate favorece o atacante
		printf("O atacante venceu essa batalha\n");
		defensor->tropas -= 1;
	}
	else{
		printf("O defensor ganhou essa batalha\n");
		if (atacante->tropas > 1)
    atacante->tropas--;
	}
	if (defensor -> tropas <=0){
		printf("Territorio conquistado pelo exercito %s \n", atacante->cor);
		strcpy(defensor->cor, atacante->cor);
		if(atacante->tropas > 1)
			atacante->tropas --;
		defensor->tropas = 1;		
		}
	
	}
	void mapaAtualizado(Territorio *mapa, int quantidade){
	int i;
    for (i=0; i<quantidade ; i++){     // criando um laço de repetição for para exibição de todos os territorios cadastrados
    	printf("\n==========================\n");
		printf("\n\tTerritorio %d \n", i+1);
    	printf("Nome: %s \n", mapa[i].nome);
    	printf("Cor: %s \n", mapa[i].cor);
    	printf("Numero de tropas: %d \n", mapa[i].tropas);
	}
	}
int main(){
	srand(time(NULL)); // para gerar numeros aleatorio que serão usados nos dados do ataque
	int quantidade;
	printf("Quantos territorios deseja cadastar? ");
	scanf("%d", &quantidade);
	
    Territorio *nomeDosTerritorios;  // criando um ponteiro para a STRUCT nomeDosTerritorios
    
    nomeDosTerritorios = calloc (quantidade, sizeof(Territorio));  // alocando memoria dinamicamente com ponteiro
    
    if (nomeDosTerritorios == NULL){    // verificando se a alocação na memoria deu certo
    	printf("Erro na alocação de memoria!\n");
    	return 1;
	}
 	cadastrar(nomeDosTerritorios, quantidade);
 	printf("\nTerritorios cadastrados com sucesso!\n");
 	
 	mapaAtualizado(nomeDosTerritorios, quantidade);
	
	int atac, defensor;
	
	while (1) {
		printf("\n======= FASE DE ATAQUE =======\n");
		printf("Escolha o territorio atacante (1 a %d ou 0 para sair): ", quantidade);
		scanf("%d", &atac);
		
		if (atac == 0){
			printf("Encerrando o jogo...\n");
			break;
		}
		printf("Digite o numero do defensor: ");
		scanf("%d", &defensor);
		
		if (atac < 1 || atac > quantidade || defensor < 1 || defensor > quantidade || atac == defensor){
			printf("Escolha invalida!\n");
			continue;
		}
		atacar(&nomeDosTerritorios[atac-1], &nomeDosTerritorios[defensor-1]);
		printf("\nPressione enter para continuar...");
		getchar();
		getchar();
		
		mapaAtualizado(nomeDosTerritorios, quantidade);
		
	}
	
	
	
    free(nomeDosTerritorios);     // Liberando memória

    return 0;
};