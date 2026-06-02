#include<stdlib.h>
#include<stdio.h>
typedef struct {
    char nome[25];
    int temp;
    float energia;
    int comunicacao;

} Missao;

Missao nave;

int historicoTemp[100];
int historicoEnergia[100];
int historicoComunicacao[100];

int totalLeituras = 0;

int opcao = 0;

void insere_dados(){
    printf("=======================================");
    printf("\nOla, seja bem-vindo ao centro de monitoramento da nave!\n");
    printf("=======================================");
    
    printf("\n\nDigite o seu primeiro nome:\n");
    scanf("%s", nave.nome);
    printf("\nOla, %s!, prosseguiremos com o monitoramento da nave.\n", nave.nome);
    
    printf("\n\nDigite a temperatura atual da nave:\n");
    scanf("%d", &nave.temp);
    
    
    printf("\nDigite a porcentagem atual de energia da nave:\n");
    scanf("%f", &nave.energia);
    
    printf("\nDigite o Status da comunicacao\n");
    printf("| 0 | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 |\n");
    scanf("%d", &nave.comunicacao);

    historicoTemp[totalLeituras] = nave.temp;
    historicoEnergia[totalLeituras] = nave.energia;
    historicoComunicacao[totalLeituras] = nave.comunicacao;

    totalLeituras++;


    
    
}

void historico() {
    
    
}

void status (){
    printf("=======================================");
    printf("\nStatus da Missao\n");
    printf("=======================================");

    printf("\n\nTemperatura atual da nave: %d", nave.temp);
    printf("\n\nA energia esta em %.2f%%", nave.energia);
    printf("\n\nA qualidade da comunicacao esta em: %d%%\n", nave.comunicacao);

}

void condicoes() {
    
    // verificando condições de temperatura
    
    if (nave.temp > 100){
        printf("\nA nave estrara em estado critico! Risco de falha total dos sistemas!\n");
        
    } else if (nave.temp > 80 && nave.temp <= 100) {
        printf("\nAlerta de superaquecimento!\n");

    } else if (nave.temp >=60 && nave.temp <= 80) {
        printf("\nA temperatura da nave esta dentro dos limites seguros.\n");
        
    } else if (nave.temp >= 20 && nave.temp < 60) {
        printf("\nA temperatura da nave esta em niveis recomendados.\n");
        
    } else if (nave.temp < 20) {
        printf("\nA temperatura da nave esta muito baixa, risco de dano aos sistemas!\n");
        
    } else {
        printf("\n a temperatura da nave esta em um estado desconhecido, verifique os sensores!\n");
    }

    // Verificando condições de energia
    
    if (nave.energia < 20) {
        printf("\nA nave entrara em modo de economia de energia.\n Recarregue a nave!\n");
        
    } else if (nave.energia >= 20 && nave.energia <= 50) {
        printf("\nA nave esta operando abaixo da capacidade recomendada.\n Recomenda-se o abastecimento de energia");
        
    }else if (nave.energia >50 && nave.energia <=75) {
        printf("\nA nave esta operando com niveis seguros de energia");
        
    } else {
        printf("\nA nave esta operando com capacidade maxima\n");
    }
    
    // verificando condições de comunicação
    
    if (nave.comunicacao == 0) {
        printf("Sem condicoes de comunicacao.");
        
    } else if (nave.comunicacao > 0 && nave.comunicacao <= 25) {
        printf("\nAs condicoes de comunicacao foram severamente prejudicadas.\n");
        
    } else if (nave.comunicacao > 25 && nave.comunicacao <= 50) {
        printf("\nAs condicoes de comunicacao estão prejudicadas, porem, funcionando\n");

    } else if (nave.comunicacao > 50 && nave.comunicacao <= 75) {
        printf("\n As condicoes de comunicacao estao em bom estado.\n");

    } else {
        printf("\nAs condicoes de comunicacao estão em otimo estado.\n");
    }
    
}


int main(){

    int dados_inseridos = 0;

    while(opcao != 4){
        
        printf("\n=======================================");

        printf("\nMENU\n");

        printf("=======================================\n");
        
        printf("\n1 - Inserir dados\n");
        printf("2 - Visualizar status\n");
        printf("3 - Executar analise\n");
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
                    break;
                }
                    status();
                    break;
                    
                    

            case 3:
                if(dados_inseridos == 0){
                    printf("Por favor, insira os dados primeiros.");
                    break;
                }
                    condicoes();
                     break;
                    

            case 4:
                printf("Sessao finalizada!");
                break;

            default:
                printf("Opçao invalida, por favor, escolha uma opcao valida.");

        }
    }
}