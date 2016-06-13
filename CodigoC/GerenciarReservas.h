#ifndef _GerenciarReservas_h
#define _GerenciarReservas_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void GerenciarReservas__INITIALISATION(void);

/* Clause OPERATIONS */

extern void GerenciarReservas__adicionarReserva(int32_t pp, int32_t cc);
extern void GerenciarReservas__removerReserva(int32_t pp);
extern void GerenciarReservas__situacaoReserva(int32_t cc, int32_t *qq);
extern void GerenciarReservas__cardReservas(int32_t *qq);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _GerenciarReservas_h */
