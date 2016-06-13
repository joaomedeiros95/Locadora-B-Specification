#ifndef _Locadora_h
#define _Locadora_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "Pessoas.h"
#include "Carros.h"
#include "Modelos.h"

/* Clause INCLUDES */
#include "GerenciarPessoas.h"
#include "GerenciarVeiculos.h"
#include "GerenciarPagamento.h"

/* Clause IMPORTS */
#include "GerenciarPessoas.h"
#include "GerenciarVeiculos.h"
#include "GerenciarPagamento.h"
#define Locadora__cadastrarPessoa GerenciarPessoas__cadastrarPessoa
#define Locadora__adicionarCarro GerenciarVeiculos__adicionarCarro
#define Locadora__removerReserva GerenciarVeiculos__removerReserva
#define Locadora__verSituacao GerenciarPessoas__verSituacao
#define Locadora__retirarCarroReservado GerenciarVeiculos__retirarCarroReservado

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */
typedef enum
{
    Locadora__alugando,
    Locadora__inadimplente,
    Locadora__normal
    
} Locadora__SITUACAO;
typedef enum
{
    Locadora__naopagou,
    Locadora__pagoumetade,
    Locadora__pagoutudo
    
} Locadora__SITUACAOPAG;

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void Locadora__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Locadora__alugarCarro(int32_t mm, int32_t pp, int32_t dd, int32_t *c1);
extern void Locadora__deletarCarro(int32_t cc);
extern void Locadora__devolverCarro(int32_t pp);
extern void Locadora__pagarDevido(int32_t pp, int32_t vv);
extern void Locadora__reservarVeiculo(int32_t pp, int32_t cc);
extern void Locadora__carrosLivres(int32_t *pp);
extern void Locadora__carrosAlugados(int32_t *pp);
extern void Locadora__carrosReservados(int32_t *pp);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Locadora_h */
