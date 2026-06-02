#include<stdlib.h>
#include<stdio.h>
char nome[25];
int temp, opcao, comunicacao;
float energia;


void insere_dados(){
    printf("=======================================");
    printf("Olá, seja bem-vindo ao centro de monitoramento da nave!");
    printf("=======================================");
    
    printf("\n\nDigite o seu primeiro nome:\n");
    scanf("%s", nome);
    printf("\n Olá, %s!, prosseguiremos com o monitoramento da nave.\n", nome);
    
    printf("\n\nDigite a temperatura atual da nave:\n");
    scanf("%d", &temp);
    
    
    printf("\n Digite a porcentagem atual de energia da nave:\n");
    scanf("%f", &energia);
    
    printf("\nDigite o Status da comunicação\n");
    printf("| 0 | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 |\n");
    scanf("%d", &comunicacao);
    
    
}

void analise() {
    condicoes();
    
}

void status (){
    printf("=======================================");
    printf("Status da Missão");
    printf("=======================================");

    printf("\n\n Temperatura atual da nave: %d", temp);
    printf("\n\n A energia está em %.2f%%", energia);
    printf("\n\n A qualidade da comunicação está em: %d%%", comunicacao);

}

void condicoes() {
    
    // verificando condições de temperatura
    
    if (temp > 100){
        printf("\nA nave estrará em estado crítico! Risco de falha total dos sistemas!\n");
        
    } else if (temp > 80 && temp <= 100) {
        printf("\nAlerta de superaquecimento!\n");

    } else if (temp >=60 && temp <= 80) {
        printf("\nA temperatura da nave está dentro dos limites seguros.\n");
        
    } else if (temp >= 20 && temp < 60) {
        printf("\nA temperatura da nave está em níveis recomendados.\n");
        
    } else if (temp < 20) {
        printf("\nA temperatura da nave está muito baixa, risco de dano aos sistemas!\n");
        
    } else {
        printf("\n a temperatura da nave está em um estado desconhecido, verifique os sensores!\n");
    }

    // Verificando condições de energia
    
    if (energia < 20) {
        printf("\nA nave entrará em modo de economia de energia.\n Recarregue a nave!\n");
        
    } else if (energia >= 20 && energia <= 50) {
        printf("\nA nave está operando abaixo da capacidade recomendada.\n Recomenda-se o abastecimento de energia");
        
    }else if (energia >50 && energia <=75) {
        printf("\nA nave está operando com níveis seguros de energia");
        
    } else {
        printf("\nA nave está operando com capacidade máxima\n");
    }
    
    // verificando condições de comunicação
    
    if (comunicacao == 0) {
        printf("Sem condições de comunicação.");
        
    } else if (comunicacao > 0 && comunicacao <= 25) {
        printf("\nAs condições de comunicação foram severamente prejudicadas.\n");
        
    } else if (comunicacao > 25 && comunicacao <= 50) {
        printf("\nAs condições de comunicação estão prejudicadas, porém, funcionando\n");

    } else if (comunicacao > 50 && comunicacao <= 75) {
        printf("\n As condições de comunicação estão em bom estado.\n");

    } else {
        printf("\nAs condições de comunicação estão em ótimo estado.\n");
    }
    
}


int main(){

    int dados_inseridos = 0;

    while(opcao != 4){
        
        printf("=======================================");
        
        printf("MENU");

        printf("=======================================");
        
        printf("1 - Inserir dados\n");
        printf("2 - Visualizar status\n");
        printf("3 - Executar análise\n");
        printf("4 - Encerrar sistema\n");
        
        scanf("%d", &opcao);


        switch(opcao){
            case 1:
                insere_dados();
                dados_inseridos = 1;
                break;
                

            case 2:
            if(dados_inseridos == 0){
                printf("Por favor, insira os dados primeiro.");
            }
                status();
                break;
                

            case 3:
            if(dados_inseridos == 0){
                printf("Por favor, insira os dados primeiros.");
            }
                analise();
                break;
                

            case 4:
                printf("Sessão finalizada!");
                break;

            default:
                printf("Opção inválida, por favor, escolha uma opção válida.");

        }
    }
}