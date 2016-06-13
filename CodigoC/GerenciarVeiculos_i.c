/* WARNING if type checker is not performed, translation could contain errors ! */

#include "GerenciarVeiculos.h"

/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"
#include "Modelos.h"

/* Clause IMPORTS */
#include "Set.h"
#include "GerenciarReservas.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t GerenciarVeiculos__alugueis_i[11];
static int32_t GerenciarVeiculos__tipocarro_i[11];
/* Clause INITIALISATION */
void GerenciarVeiculos__INITIALISATION(void)
{
    
    unsigned int i = 0;
    GerenciarReservas__INITIALISATION();
    Set__INITIALISATION();
    for(i = 0; i <= Pessoas__PEOPLE__max-1;i++)
    {
        GerenciarVeiculos__alugueis_i[i] = 0;
    }
    {
        int32_t ii;
        int32_t tmp;
        
        ii = 10;
        while((ii) > (0))
        {
            tmp = ii % 3;
            if(tmp == 0)
            {
                GerenciarVeiculos__tipocarro_i[ii] = 1;
            }
            else if(tmp == 1)
            {
                GerenciarVeiculos__tipocarro_i[ii] = 2;
            }
            else
            {
                GerenciarVeiculos__tipocarro_i[ii] = 3;
            }
            ii = ii-1;
        }
    }
}

/* Clause OPERATIONS */

void GerenciarVeiculos__retirarCarro(int32_t mm, int32_t pp, int32_t *cc)
{
    {
        int32_t ii;
        int32_t tmp;
        int32_t situacao;
        
        ii = 10;
        while((ii) > (0))
        {
            tmp = GerenciarVeiculos__tipocarro_i[ii];
            {
                int32_t aa;
                int32_t tmp2;
                int32_t tmp3;
                int32_t sair;
                int32_t sReserva;
                
                aa = 10;
                sair = 0;
                tmp2 = 0;
                while(((aa) >= (0)) &&
                (sair == 0))
                {
                    tmp3 = GerenciarVeiculos__alugueis_i[aa];
                    if(tmp3 == ii)
                    {
                        tmp2 = 1;
                        sair = 1;
                    }
                    aa = aa-1;
                }
                GerenciarReservas__situacaoReserva(ii, &sReserva);
                if((tmp2) != (0))
                {
                    situacao = 1;
                }
                else if(sReserva == 1)
                {
                    situacao = 2;
                }
                else
                {
                    situacao = 3;
                }
            }
            if((tmp == mm) &&
            (situacao == 3))
            {
                GerenciarVeiculos__alugueis_i[pp] = ii;
                (*cc) = ii;
            }
            ii = ii-1;
        }
    }
}

void GerenciarVeiculos__retirarCarroReservado(int32_t cc, int32_t pp, int32_t *qq)
{
    GerenciarVeiculos__alugueis_i[pp] = cc;
    (*qq) = cc;
    GerenciarReservas__removerReserva(pp);
}

void GerenciarVeiculos__situacaoCarro(int32_t cc, int32_t *qq)
{
    {
        int32_t ii;
        int32_t tmp;
        int32_t tmp2;
        int32_t sair;
        int32_t sReserva;
        
        ii = 10;
        sair = 0;
        tmp = 0;
        while(((ii) >= (0)) &&
        (sair == 0))
        {
            tmp2 = GerenciarVeiculos__alugueis_i[ii];
            if(tmp2 == cc)
            {
                tmp = 1;
                sair = 1;
            }
            ii = ii-1;
        }
        GerenciarReservas__situacaoReserva(cc, &sReserva);
        if((tmp) != (0))
        {
            (*qq) = 1;
        }
        else if(sReserva == 1)
        {
            (*qq) = 2;
        }
        else
        {
            (*qq) = 3;
        }
    }
}

void GerenciarVeiculos__deixarCarro(int32_t pp)
{
    GerenciarVeiculos__alugueis_i[pp] = 0;
}

void GerenciarVeiculos__adicionarCarro(int32_t cc, int32_t tt)
{
    Set__add_car(cc);
    GerenciarVeiculos__tipocarro_i[cc] = tt;
}

void GerenciarVeiculos__removerCarro(int32_t cc)
{
    GerenciarVeiculos__tipocarro_i[cc] = 0;
    Set__remove_car(cc);
}

void GerenciarVeiculos__tamanhoCarros(int32_t *qq)
{
    Set__cardCarros(qq);
}

void GerenciarVeiculos__cardAlugueis(int32_t *qq)
{
    {
        int32_t ii;
        int32_t tmp;
        
        ii = 10;
        (*qq) = 0;
        while((ii) >= (0))
        {
            tmp = GerenciarVeiculos__alugueis_i[ii];
            if((tmp) > (0))
            {
                (*qq) = (*qq)+1;
            }
            ii = ii-1;
        }
    }
}

