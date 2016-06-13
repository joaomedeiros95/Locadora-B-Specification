#ifndef _GerenciarPessoas_h
#define _GerenciarPessoas_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Pessoas.h"

/* Clause IMPORTS */
#include "Set.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */
typedef enum
{
    GerenciarPessoas__alugando,
    GerenciarPessoas__inadimplente,
    GerenciarPessoas__normal
    
} GerenciarPessoas__SITUACAO;

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void GerenciarPessoas__INITIALISATION(void);

/* Clause OPERATIONS */

extern void GerenciarPessoas__cadastrarPessoa(int32_t pp);
extern void GerenciarPessoas__verSituacao(int32_t pp, GerenciarPessoas__SITUACAO *rr);
extern void GerenciarPessoas__alterarSituacao(int32_t pp, GerenciarPessoas__SITUACAO ss);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _GerenciarPessoas_h */
