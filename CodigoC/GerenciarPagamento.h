#ifndef _GerenciarPagamento_h
#define _GerenciarPagamento_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Pessoas.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */
typedef enum
{
    GerenciarPagamento__naopagou,
    GerenciarPagamento__pagoumetade,
    GerenciarPagamento__pagoutudo
    
} GerenciarPagamento__SITUACAOPAG;

/* Clause CONCRETE_VARIABLES */

extern int32_t GerenciarPagamento__faltapagar[11];
extern GerenciarPagamento__SITUACAOPAG GerenciarPagamento__situacaopag[11];

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
#define GerenciarPagamento__precoDiaBase 10
/* Array and record constants */

extern void GerenciarPagamento__INITIALISATION(void);

/* Clause OPERATIONS */

extern void GerenciarPagamento__gerarConta(int32_t pm, int32_t pp, int32_t dd);
extern void GerenciarPagamento__pagarConta(int32_t pp, int32_t vv);
extern void GerenciarPagamento__verSituacaoPessoa(int32_t pp, GerenciarPagamento__SITUACAOPAG *ss);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _GerenciarPagamento_h */
