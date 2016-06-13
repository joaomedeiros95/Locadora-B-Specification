/* WARNING if type checker is not performed, translation could contain errors ! */

#include "GerenciarReservas.h"

/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t GerenciarReservas__reservas_i[11];
/* Clause INITIALISATION */
void GerenciarReservas__INITIALISATION(void)
{

    unsigned int i = 0;
    for(i = 0; i <= Pessoas__PEOPLE__max-1;i++)
    {
        GerenciarReservas__reservas_i[i] = 0;
    }
}

/* Clause OPERATIONS */

void GerenciarReservas__adicionarReserva(int32_t pp, int32_t cc)
{
    GerenciarReservas__reservas_i[pp] = cc;
}

void GerenciarReservas__removerReserva(int32_t pp)
{
    GerenciarReservas__reservas_i[pp] = 0;
}

void GerenciarReservas__situacaoReserva(int32_t cc, int32_t *qq)
{
    {
        int32_t ii;
        int32_t tmp;
        int32_t sair;

        ii = 10;
        sair = 0;
        (*qq) = 0;
        while(((ii) >= (0)) &&
        (sair == 0))
        {
            tmp = GerenciarReservas__reservas_i[ii];
            if(tmp == cc)
            {
                (*qq) = 1;
                sair = 1;
            }
            ii = ii-1;
        }
    }
}

void GerenciarReservas__cardReservas(int32_t *qq)
{
    {
        int32_t ii;
        int32_t tmp;

        ii = 10;
        (*qq) = 0;
        while((ii) >= (0))
        {
            tmp = GerenciarReservas__reservas_i[ii];
            if((tmp) > (0))
            {
                (*qq) = (*qq)+1;
            }
            ii = ii-1;
        }
    }
}
