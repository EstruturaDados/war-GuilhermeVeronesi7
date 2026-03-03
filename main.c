#include<stdio.h>
#include<string.h>
// definindo uma Struct do tipo Territorio é um novo TIPO (tipo int, ou float) um dado que possui varios dados dentro
typedef struct{
    char nome [30];
    char cor [10];
    int tropas;
} Territorio;

int main(){
    Territorio nomeDosTerritorios[5];  // criando um vetor chamado nomeDosTerritorios de 5 posições com o tipo de dado Territorio que é a Struct
    printf("===== Cadastre os 5 Territorios: =====\n");
    int i;
    for ( i = 0; i<5 ; i++ ){      // laço for para fazer a iteração dos dados pedidos ao usuário
        printf("\nDigite o nome do Territorio: ");
        scanf("%s", nomeDosTerritorios[i].nome);
        printf("Digite o nome da Cor: ");
        scanf("%s", nomeDosTerritorios[i].cor);
        printf("Digite o numero de tropas: ");
        scanf("%d", &nomeDosTerritorios[i].tropas);  // Para ler o número de tropas, usamos & para passar o endereço da variável
    }
    for (i=0; i<5 ; i++){     // criando um laço de repetição for para exibição de todos os territorios cadastrados
    	printf("============================\n\n");
    	printf("        Territorio %d \n", i+1);
    	printf("Nome: %s \n", nomeDosTerritorios[i].nome);
    	printf("Cor: %s \n", nomeDosTerritorios[i].cor);
    	printf("Numero de tropas: %d \n", nomeDosTerritorios[i].tropas);
	}
	 
    return 0;
};