#ifndef _Set_h
#define _Set_h

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
extern void Set__INITIALISATION(void);

/* Clause OPERATIONS */

extern void Set__add_people(int32_t ee);
extern void Set__OUT_people(int32_t *oo);
extern void Set__add_car(int32_t ee);
extern void Set__OUT_car(int32_t *oo);
extern void Set__remove_car(int32_t cc);
extern void Set__cardCarros(int32_t *qq);
extern void Set__cardPessoas(int32_t *qq);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _Set_h */
