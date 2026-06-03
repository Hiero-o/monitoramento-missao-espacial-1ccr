# monitoramento-missao-espacial-1ccr
Sistema em C para monitorar informações básicas de uma missão espacial.

Integrantes:

Gustavo Araujo Ramos da Silva - RM 574156
Victor Henrique Nogueira Bezerra Azevedo de Souza - RM 570021
Carlos Henrique - RM 573334

# Explicação da lógica

O sistema utiliza uma struct para armazenar os dados da missão, vetores para registrar o histórico das leituras e funções para separar as responsabilidades do código. As análises são realizadas através de estruturas condicionais e as estatísticas são calculadas utilizando laços de repetição. O usuário pode escolher as opções de 1 a 5 pelo menu, digitando o respectivo valor. O sistema identifica caso for a primeira vez do usuário relatando as informações e obriga que ele insira os primeiros dados para iniciar o monitoramento.