/* WARNING if type checker is not performed, translation could contain errors ! */

#include "GerenciarPessoas.h"

/* Clause SEES */
#include "Pessoas.h"

/* Clause IMPORTS */
#include "Set.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static GerenciarPessoas__SITUACAO GerenciarPessoas__situacaoI[11];
/* Clause INITIALISATION */
void GerenciarPessoas__INITIALISATION(void)
{
    
    unsigned int i = 0;
    Set__INITIALISATION();
    for(i = 0; i <= Pessoas__PEOPLE__max-1;i++)
    {
        GerenciarPessoas__situacaoI[i] = GerenciarPessoas__normal;
    }
}

/* Clause OPERATIONS */

void GerenciarPessoas__cadastrarPessoa(int32_t pp)
{
    Set__add_people(pp);
    GerenciarPessoas__situacaoI[pp] = GerenciarPessoas__normal;
}

void GerenciarPessoas__verSituacao(int32_t pp, GerenciarPessoas__SITUACAO *rr)
{
    (*rr) = GerenciarPessoas__situacaoI[pp];
}

void GerenciarPessoas__alterarSituacao(int32_t pp, GerenciarPessoas__SITUACAO ss)
{
    GerenciarPessoas__situacaoI[pp] = ss;
}

