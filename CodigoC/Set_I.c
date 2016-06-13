/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Set.h"

/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t Set__fimpeople;
static int32_t Set__arraypeople[11];
static int32_t Set__fimcar;
static int32_t Set__arraycar[11];
/* Clause INITIALISATION */
void Set__INITIALISATION(void)
{
    
    unsigned int i = 0;
    Set__fimpeople = 0;
    Set__fimcar = 0;
    for(i = 0; i <= 10;i++)
    {
        Set__arraycar[i] = 0;
    }
    for(i = 0; i <= 10;i++)
    {
        Set__arraypeople[i] = 0;
    }
}

/* Clause OPERATIONS */

void Set__add_people(int32_t ee)
{
    if((Set__fimpeople) < (10))
    {
        Set__arraypeople[Set__fimpeople] = ee;
        Set__fimpeople = Set__fimpeople+1;
    }
    else
    {
        ;
    }
}

void Set__OUT_people(int32_t *oo)
{
    if((Set__fimpeople) > (0))
    {
        Set__arraypeople[Set__fimpeople] = 0;
        Set__fimpeople = Set__fimpeople-1;
        (*oo) = Set__arraypeople[Set__fimpeople];
    }
}

void Set__add_car(int32_t ee)
{
    if((Set__fimcar) < (10))
    {
        Set__arraycar[Set__fimcar] = ee;
        Set__fimcar = Set__fimcar+1;
    }
    else
    {
        ;
    }
}

void Set__remove_car(int32_t cc)
{
    {
        int32_t ii;
        int32_t tmp;
        int32_t tmp2;
        int32_t sair;
        
        ii = 0;
        tmp = 0;
        tmp2 = 100;
        sair = 0;
        while(((ii) <= (Set__fimcar)) &&
        (sair == 0))
        {
            tmp = Set__arraycar[ii];
            if(tmp == cc)
            {
                tmp2 = ii;
                sair = 1;
            }
            ii = ii+1;
        }
        if((tmp2) < (100))
        {
            ii = tmp2;
            while((ii) < (Set__fimcar))
            {
                Set__arraycar[ii] = Set__arraycar[ii+1];
                ii = ii+1;
            }
            Set__arraycar[Set__fimcar] = 0;
            Set__fimcar = Set__fimcar-1;
        }
    }
}

void Set__OUT_car(int32_t *oo)
{
    if((Set__fimcar) > (0))
    {
        Set__arraycar[Set__fimcar] = 0;
        Set__fimcar = Set__fimcar-1;
        (*oo) = Set__arraycar[Set__fimcar];
    }
}

void Set__cardCarros(int32_t *qq)
{
    (*qq) = Set__fimcar;
}

void Set__cardPessoas(int32_t *qq)
{
    (*qq) = Set__fimpeople;
}

