/* WARNING if type checker is not performed, translation could contain errors ! */

#include "GerenciarPagamento.h"

/* Clause SEES */
#include "Pessoas.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

#define GerenciarPagamento__precoDiaBase 10
/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

int32_t GerenciarPagamento__faltapagar[11];
GerenciarPagamento__SITUACAOPAG GerenciarPagamento__situacaopag[11];
/* Clause INITIALISATION */
void GerenciarPagamento__INITIALISATION(void)
{
    
    unsigned int i = 0;
    for(i = 0; i <= Pessoas__PEOPLE__max-1;i++)
    {
        GerenciarPagamento__faltapagar[i] = 0;
    }
    for(i = 0; i <= Pessoas__PEOPLE__max-1;i++)
    {
        GerenciarPagamento__situacaopag[i] = GerenciarPagamento__pagoutudo;
    }
}

/* Clause OPERATIONS */

void GerenciarPagamento__gerarConta(int32_t pm, int32_t pp, int32_t dd)
{
    GerenciarPagamento__faltapagar[pp] = GerenciarPagamento__faltapagar[pp]+(GerenciarPagamento__precoDiaBase * dd * pm);
    GerenciarPagamento__situacaopag[pp] = GerenciarPagamento__naopagou;
}

void GerenciarPagamento__pagarConta(int32_t pp, int32_t vv)
{
    GerenciarPagamento__faltapagar[pp] = (GerenciarPagamento__faltapagar[pp]-vv);
    {
        int32_t xx;
        
        xx = GerenciarPagamento__faltapagar[pp];
        if(xx == 0)
        {
            GerenciarPagamento__situacaopag[pp] = GerenciarPagamento__pagoutudo;
        }
        else
        {
            GerenciarPagamento__situacaopag[pp] = GerenciarPagamento__pagoumetade;
        }
    }
}

void GerenciarPagamento__verSituacaoPessoa(int32_t pp, GerenciarPagamento__SITUACAOPAG *ss)
{
    (*ss) = GerenciarPagamento__situacaopag[pp];
}

