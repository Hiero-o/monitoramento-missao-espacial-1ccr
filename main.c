#include<stdlib.h>
#include<stdio.h>
char nome[25];
int temp, opcao;
float energia, status;

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
    printf("=" * 60);
    printf("Olá, seja bem-vindo ao centro de monitoramento da nave!");
    printf("=" * 60);
    
    printf("\n\nDigite o seu primeiro nome:\n");
    scanf("%s", &nome);
    printf("\n Olá, %s!, prosseguiremos com o monitoramento da nave.\n", nome);
    
    printf("\n\nDigite a temperatura atual da nave:\n");
    scanf("%d", &temp);
    
    
    printf("\n Digite a porcentagem atual de energia da nave:\n");
    scanf("%f", &energia);
    
    printf("\nDigite o Status da comunicação\n");
    printf("| BOM | REGULAR | RUIM |\n");
    scanf("%d", &status);
    
    
}

void analise() {
    
}

void status (){

}

void condicoes() {

    // verificando condições de temperatura

    if temp > 100{
        printf("\nA nave estrará em estado crítico! Risco de falha total dos sistemas!\n");

    } if else temp > 80 and temp <= 100 {
        printf("\nAlerta de superaquecimento!\n");

    } if else temp >=60 and temp <= 80 {
        printf("\nA temperatura da nave está dentro dos limites seguros.\n");

    } if else temp >= 20 and temp < 60 {
        printf("\nA temperatura da nave está em níveis recomendados.\n");

    } if else temp < 20 {
        printf("\nA temperatura da nave está muito baixa, risco de dano aos sistemas!\n");
        
    } else {
        printf("\n a temperatura da nave está em um estado desconhecido, verifique os sensores!\n");
    }

    // Verificando condições de energia

    if energia < 20 {
        printf("\nA nave entrará em modo de economia de energia.\n Recarregue a nave!\n");

    } if else energia >= 20 and energia <= 50 {
        printf("\nA nave está operando abaixo da capacidade recomendada.\n Recomenda-se o abastecimento de energia");

    }if else energia >50 and energia <=75 {
        printf("\nA nave está operando com níveis seguros de energia");

    } else {
        printf("\nA nave está operando com capacidade máxima\n");
    }

    // verificando condições de comunicação

    if status == 0 {
        printf("Sem condições de comunicação.");

    } if else status > 0 and status <= 25 {
        printf("\nAs condições de comunicação foram severamente prejudicadas.\n");

    } if else status > 25 and status <= 50 {
        printf("\nAs condições de comunicação estão prejudicadas, porém, funcionando\n");

    } if else status > 50 and status <= 75 {
        printf("\n As condições de comunicação estão em bom estado.\n");

    } else {
        printf("\nAs condições de comunicação estão em ótimo estado.\n")
    }

}