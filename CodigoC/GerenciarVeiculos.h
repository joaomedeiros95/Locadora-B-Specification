#ifndef _GerenciarVeiculos_h
#define _GerenciarVeiculos_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"
#include "Modelos.h"

/* Clause INCLUDES */
#include "GerenciarReservas.h"

/* Clause IMPORTS */
#include "Set.h"
#include "GerenciarReservas.h"
#define GerenciarVeiculos__removerReserva GerenciarReservas__removerReserva
#define GerenciarVeiculos__adicionarReserva GerenciarReservas__adicionarReserva
#define GerenciarVeiculos__cardReservas GerenciarReservas__cardReservas

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void GerenciarVeiculos__INITIALISATION(void);

/* Clause OPERATIONS */

extern void GerenciarVeiculos__retirarCarro(int32_t mm, int32_t pp, int32_t *cc);
extern void GerenciarVeiculos__retirarCarroReservado(int32_t cc, int32_t pp, int32_t *qq);
extern void GerenciarVeiculos__situacaoCarro(int32_t cc, int32_t *qq);
extern void GerenciarVeiculos__deixarCarro(int32_t pp);
extern void GerenciarVeiculos__adicionarCarro(int32_t cc, int32_t tt);
extern void GerenciarVeiculos__removerCarro(int32_t cc);
extern void GerenciarVeiculos__tamanhoCarros(int32_t *qq);
extern void GerenciarVeiculos__cardAlugueis(int32_t *qq);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _GerenciarVeiculos_h */
