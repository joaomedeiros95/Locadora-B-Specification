#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Locadora_i.c"

static char* enumStrings[] = {"alugando", "inadimplente", "normal"};

void cadastrarPessoas() {
    printf("Cadastrando Pessoas...\n");
    int i;
    for(i = 1; i < 6; i++) {
        printf("Cadastrada Pessoa %d\n", i);
        GerenciarPessoas__cadastrarPessoa(i);
    }
}

void verSituacaoPessoas() {
    int i;
    for(i = 1; i < 6; i++) {
        GerenciarPessoas__SITUACAO situacao;
        GerenciarPessoas__verSituacao(i, &situacao);
        printf("Pessoa %d tem situacao: %s\n", i, enumStrings[situacao]);
    }
}

void alugarCarro(int modelo, int pessoa, int dias) {
    printf("Alugando modelo %d pela pessoa %d por %d dias!\n", modelo, pessoa, dias);
    int carro = 0;
    Locadora__alugarCarro(modelo, pessoa, dias, &carro);
    printf("Pessoa %d alugou carro %d!\n", pessoa, carro);
}

void statusDosCarros() {
    int tmp = 0;
    Locadora__carrosLivres(&tmp);
    printf("Quantidade de carros livres: %d\n", tmp);
    Locadora__carrosAlugados(&tmp);
    printf("Quantidade de carros alugados: %d\n", tmp);
    Locadora__carrosReservados(&tmp);
    printf("Quantidade de carros reservados: %d\n", tmp);
}

void adicionarCarros() {
    printf("Cadastrando Pessoas...\n");
    int i;
    for(i = 1; i <= 6; i++) {
        printf("Cadastrado Carro %d\n", i);
        GerenciarVeiculos__adicionarCarro(i, (i % 3) + 1);
    }
}

void devolverCarro(int pessoa) {
    printf("Devolvendo carro da pessoa %d\n", pessoa);
    Locadora__devolverCarro(pessoa);
}

void pagarDevido(int pessoa, int valor) {
    printf("Pessoa %d está pagando %d reais\n", pessoa, valor);
    Locadora__pagarDevido(pessoa, valor);
}

void reservarVeiculo(int pessoa, int carro) {
    printf("Pessoa %d está reservando veículo %d\n", pessoa, carro);
    Locadora__reservarVeiculo(pessoa, carro);
}

void retirarCarroReservado(int pessoa, int carro) {
    printf("Pessoa %d está retirando carro %d reservado\n", pessoa, carro);
    int carroretorno = 0;
    GerenciarVeiculos__retirarCarroReservado(carro, pessoa, &carroretorno);
}

void removerReserva(int pessoa) {
    printf("Removendo reserva da pessoa %d\n", pessoa);
    GerenciarReservas__removerReserva(pessoa);
}

/** Ainda não foi 100% implementado */
void deletarCarro(int carro) {
    printf("Removendo carro %d\n", carro);
    GerenciarVeiculos__removerCarro(carro);
}

int main(int argc, char **argv) {
    printf("Comecando...\n");
    Locadora__INITIALISATION();

    cadastrarPessoas();
    statusDosCarros();
    adicionarCarros();
    statusDosCarros();
    verSituacaoPessoas();
    alugarCarro(1, 1, 10);
    verSituacaoPessoas();
    statusDosCarros();
    devolverCarro(1);
    verSituacaoPessoas();
    statusDosCarros();
    pagarDevido(1, 250);
    verSituacaoPessoas();
    pagarDevido(1, 250);
    verSituacaoPessoas();
    reservarVeiculo(2, 5);
    statusDosCarros();
    retirarCarroReservado(2, 5);
    statusDosCarros();
    verSituacaoPessoas();
    reservarVeiculo(3, 4);
    statusDosCarros();
    removerReserva(3);
    statusDosCarros();
    deletarCarro(6);
    statusDosCarros();

    return 0;
}
