/* GerenciarReservas
 * Author: João Eduardo Medeiros
 * Creation date: 29/05/16
 */
MACHINE
    GerenciarReservas
SEES
    Pessoas, Carros
VARIABLES 
    reservas
INVARIANT 
    reservas : PEOPLE >+> CARS
INITIALISATION 
    reservas := {}
OPERATIONS
    adicionarReserva(pp,cc) =
        PRE pp : PEOPLE & cc : CARS & pp /: dom(reservas) & cc /: ran(reservas) 
        THEN reservas := reservas \/ {pp |-> cc}
        END;

    removerReserva(pp) =
        PRE pp : PEOPLE & pp : dom(reservas)
        THEN reservas := {pp} <<| reservas
        END;

    qq <-- situacaoReserva(cc) = 
        PRE cc : CARS 
        THEN IF cc : ran(reservas) THEN qq := 1 ELSE qq := 0 END
        END;

    qq <-- cardReservas = 
        BEGIN qq := card(reservas)
        END
END
