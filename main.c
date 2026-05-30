#include<stdlib.h>
#include<stdio.h>
char nome[25], status[10];
int temp, opcao;
float combustivel;

int main(){
    printf("="*10);
    printf("MENU");
    printf("="*10);

    printf("1 - Inserir dados\n");
    printf("2 - Visualizar status\n");
    printf("3 - Executar análise\n");
    printf("4 - Encerrar sistema\n");

    scanf("%d", &opcao);

    // Confere se o usuário já inseriu dados anteriormente.

    while opcao != 1 {

        printf("Por favor, insira os dados antes de acessar as outras opções.\n");
        printf("Digite 1 para inserir os dados:\n");

        scanf("%d", &opcao);
    }


    switch(opcao){
        case 1:
            insere_dados():
            continue;

        case 2:
            status();
            continue;

        case 3:
            executa_analise();
            continue;

        case 4:
            printf("Sessão finalizada!")
            break;

    }

}

void insere_dados(){
    
    
}

void analise() {
    
}

void status (){
    
}