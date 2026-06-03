#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[25];
    int temp;
    float energia;
    int comunicacao;

} Missao;

Missao nave;

int historicoTemp[100];
float historicoEnergia[100];
int historicoComunicacao[100];
char historicoNome[100][25];

int totalLeituras = 0;

int opcao = 0;

void insere_dados(){
    printf("===============================================================");
    printf("\nOla, seja bem-vindo ao centro de monitoramento da nave!\n");
    printf("===============================================================");
    
    printf("\n\nDigite o seu primeiro nome:\n");
    scanf("%s", nave.nome);
    printf("\nOla, %s!, prosseguiremos com o monitoramento da nave.\n", nave.nome);
    


    do{
        printf("\n\nDigite a temperatura atual da nave:\n");
        scanf("%d", &nave.temp);

        if(nave.temp < 0 || nave.temp > 100){

            printf("Dado irreal, por favor, verifique novamente ou os sensores.");

        }

    } while (nave.temp < 0 || nave.temp > 100);


    do{
        printf("\nDigite a porcentagem atual de energia da nave:\n");
        scanf("%f", &nave.energia);

        if(nave.energia < 0 || nave.energia > 100){

            printf("Dado impossivel, insira novamente.");

        }

    } while(nave.energia < 0 || nave.energia > 100);

    do {
        printf("\nDigite o Status da comunicacao\n");
        printf("| 0 | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 |\n");
        scanf("%d", &nave.comunicacao);

        if(nave.comunicacao < 0 || nave.comunicacao > 100){

            printf("Dado invalido, por favor, insira novamente.");

        }

    } while(nave.comunicacao < 0 || nave.comunicacao > 100);


    historicoTemp[totalLeituras] = nave.temp;
    historicoEnergia[totalLeituras] = nave.energia;
    historicoComunicacao[totalLeituras] = nave.comunicacao;
    strcpy(historicoNome[totalLeituras], nave.nome);

    totalLeituras++;

}

void historico() {
    if(totalLeituras == 0){
        printf("\nInsira mais dados para consultar o histórico");
        return;
    }

    printf("\n=======================================\n");
    printf("Historico de leituras");
    printf("\n=======================================\n");

    for(int i = 0; i < totalLeituras; i++){
        printf("\nLeitura %d\n", i + 1);

        printf("\nTripulante: %s\n", historicoNome[i]);

        printf("\nTemperatura - %d Graus celsius\n", historicoTemp[i]);


        printf("\nEnergia - %.2f%%\n", historicoEnergia[i]);

        printf("\nComunicacao - %d%%\n",historicoComunicacao[i]);

        printf("\n----------------------------------\n");

    }
    
}

void status (){
    printf("=======================================");
    printf("\nStatus da Ultima Leitura da Missao\n");
    printf("=======================================");

    printf("\nTripulante: %s.\n", nave.nome);

    printf("\nTemperatura atual da nave: %d", nave.temp);

    printf("\n\nA energia esta em %.2f%%", nave.energia);

    printf("\n\nA qualidade da comunicacao esta em: %d%%\n", nave.comunicacao);

}

void condicoes() {

    printf("\n=======================================");

    printf("\nRelatorio da Missao Espacial.\n");

    printf("=======================================\n"); 
    
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
        printf("\nA temperatura da nave esta em um estado desconhecido, verifique os sensores!\n");
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
        printf("\nSem condicoes de comunicacao.\n");
        
    } else if (nave.comunicacao > 0 && nave.comunicacao <= 25) {
        printf("\nAs condicoes de comunicacao foram severamente prejudicadas.\n");
        
    } else if (nave.comunicacao > 25 && nave.comunicacao <= 50) {
        printf("\nAs condicoes de comunicacao estao prejudicadas, porem, funcionando\n");

    } else if (nave.comunicacao > 50 && nave.comunicacao <= 75) {
        printf("\nAs condicoes de comunicacao estao em bom estado.\n");

    } else {
        printf("\nAs condicoes de comunicacao estão em otimo estado.\n");
    }
    
}

void estatistica() {
    if(totalLeituras == 0){
        printf("Por favor, insira primeiro mais de um dado.");
        return;
    }

    int maior_temp = historicoTemp[0];
    float menor_energia = historicoEnergia[0];
    int menor_temp = historicoTemp[0];
    float maior_energia = historicoEnergia[0];
    float somaTemp = 0;
    float mediaTemp = 0;
    float somaEnergia = 0;
    float mediaEnergia = 0;
    
    // Define a maior temperatura

    for(int i = 0; i < totalLeituras; i++){
        if(historicoTemp[i] > maior_temp){
            maior_temp = historicoTemp[i];
        }
    }

    // Define a menor temperatura

    for(int i = 0 ; i < totalLeituras; i++){
        if(historicoTemp[i] < menor_temp){
            menor_temp = historicoTemp[i];
        }
    }

    //Define a menor energia

    for(int i = 0; i < totalLeituras; i++){
        if(historicoEnergia[i] < menor_energia){
            menor_energia = historicoEnergia[i];
        }
    }

    // Define a maior energia

    for(int i = 0; i < totalLeituras; i++){
        if(historicoEnergia[i] > maior_energia){
            maior_energia = historicoEnergia[i];
        }
    }

    // Soma as energias

    for(int i = 0; i < totalLeituras; i++){
        somaEnergia += historicoEnergia[i];
    }

    // Faz a média das energias

    mediaEnergia = somaEnergia / totalLeituras;

    // Soma as temperaturas

    for(int i = 0; i < totalLeituras; i++){
        somaTemp += historicoTemp[i];
    }

    // faz a média das temperaturas

    mediaTemp = somaTemp / totalLeituras;
    
    // Imprime registros na tela

    printf("\n=======================================");

    printf("\nEstatistica da Missao Espacial\n");

    printf("=======================================\n"); 

   printf("\n\nA maior temperatura foi de %d Graus.\n", maior_temp);
   
   printf("\nA menor temperatura foi de %d Graus.\n", menor_temp);
   
   printf("\nA media das temperaturas foi de %.2f Graus.\n", mediaTemp);

   printf("\nA maior carga de energia foi de %.2f%%.\n", maior_energia);
   
   printf("\nA menor carga de energia foi de %.2f%%.\n", menor_energia);
   
   printf("\nA media das energias foi de %.2f%%.\n", mediaEnergia);


}


void relatorio(){

    
    printf("\nOla, aqui esta o relatorio da missao:\n");

    condicoes();

    estatistica();

    printf("\n\nEste foi o relatorio da missao espacial, obrigado!");
    
}

int main(){

    int dados_inseridos = 0;

    while(opcao != 5){
        
        printf("\n=======================================");

        printf("\nMENU\n");

        printf("=======================================\n");
        
        printf("\n1 - Inserir dados\n");
        printf("2 - Visualizar status da ultima leitura\n");
        printf("3 - Executar analise\n");
        printf("4 - Historico\n");
        printf("5 - Encerrar sistema\n");
        
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
                    relatorio();
                     break;
            
            case 4:
                if(dados_inseridos == 0){
                    printf("Por favor, insira mais dados para acessar o historico");
                    break;
                }
                historico();
                break;

            case 5:
                printf("Sessao finalizada!");
                break;

            default:
                printf("Opçao invalida, por favor, escolha uma opcao valida.");

        }
    }
}