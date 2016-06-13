/* Set
 * Author: Stefano Loss
 * Creation date: 08/06/2016
 */
MACHINE Set
ABSTRACT_VARIABLES peopleset, carset
SEES Pessoas, Carros
INVARIANT peopleset <: PEOPLE & carset <: CARS
INITIALISATION peopleset := {} || carset := {}

OPERATIONS
    add_people ( ee ) =
        PRE ee : PEOPLE & ee /= 0 & ee /: peopleset
        THEN peopleset := peopleset \/ { ee }
        END ;

    oo <-- OUT_people =
        PRE peopleset /= {} & oo : PEOPLE
        THEN ANY ee WHERE ee : peopleset
            THEN oo := ee || peopleset := peopleset - { ee }
            END
        END;

    add_car ( ee ) =
        PRE ee : CARS & ee /= 0 & ee /: carset
        THEN carset := carset \/ { ee }
        END ;

    oo <-- OUT_car =
        PRE carset /= {} & oo : CARS
        THEN ANY ee WHERE ee : carset
            THEN oo := ee || carset := carset - { ee }
            END
        END;
        
    remove_car(cc) =
        PRE carset /= {} & cc: CARS
        THEN  carset := carset - { cc }
        END;

    qq <-- cardCarros = 
        BEGIN qq := card(carset)
        END;

    qq <-- cardPessoas = 
        BEGIN qq := card(peopleset)
        END

END
