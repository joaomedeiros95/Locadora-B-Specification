/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Locadora.h"

/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"
#include "Modelos.h"

/* Clause IMPORTS */
#include "GerenciarPessoas.h"
#include "GerenciarVeiculos.h"
#include "GerenciarPagamento.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t Locadora__precoModelo_i[4];
/* Clause INITIALISATION */
void Locadora__INITIALISATION(void)
{
    
    GerenciarPagamento__INITIALISATION();
    GerenciarPessoas__INITIALISATION();
    GerenciarVeiculos__INITIALISATION();
    {
        int32_t ii;
        
        ii = 3;
        while((ii) > (0))
        {
            if(ii == 3)
            {
                Locadora__precoModelo_i[1] = 5;
            }
            else if(ii == 2)
            {
                Locadora__precoModelo_i[2] = 7;
            }
            else
            {
                Locadora__precoModelo_i[3] = 10;
            }
            ii = ii-1;
        }
    }
}

/* Clause OPERATIONS */

void Locadora__alugarCarro(int32_t mm, int32_t pp, int32_t dd, int32_t *c1)
{
    GerenciarVeiculos__retirarCarro(mm, pp, c1);
    GerenciarPagamento__gerarConta((Locadora__precoModelo_i[mm]), pp, dd);
    GerenciarPessoas__alterarSituacao(pp, GerenciarPessoas__alugando);
}

void Locadora__deletarCarro(int32_t cc)
{
    GerenciarVeiculos__removerCarro(cc);
}

void Locadora__devolverCarro(int32_t pp)
{
    GerenciarVeiculos__deixarCarro(pp);
    GerenciarPessoas__alterarSituacao(pp, GerenciarPessoas__inadimplente);
}

void Locadora__pagarDevido(int32_t pp, int32_t vv)
{
    {
        GerenciarPessoas__SITUACAO situacao;
        int32_t tmp;
        
        GerenciarPessoas__verSituacao(pp, &situacao);
        GerenciarPagamento__pagarConta(pp, vv);
        tmp = GerenciarPagamento__faltapagar[pp];
        if((tmp == 0) &&
        ((situacao) != (GerenciarPessoas__alugando)))
        {
            GerenciarPessoas__alterarSituacao(pp, GerenciarPessoas__normal);
        }
    }
}

void Locadora__reservarVeiculo(int32_t pp, int32_t cc)
{
    GerenciarReservas__adicionarReserva(pp, cc);
}

void Locadora__carrosLivres(int32_t *pp)
{
    {
        int32_t tc;
        int32_t ta;
        int32_t tr;
        
        GerenciarVeiculos__tamanhoCarros(&tc);
        GerenciarVeiculos__cardAlugueis(&ta);
        GerenciarReservas__cardReservas(&tr);
        (*pp) = tc-ta-tr;
    }
}

void Locadora__carrosAlugados(int32_t *pp)
{
    GerenciarVeiculos__cardAlugueis(pp);
}

void Locadora__carrosReservados(int32_t *pp)
{
    GerenciarReservas__cardReservas(pp);
}

