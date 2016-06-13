/* GerenciarVeiculos
 * Author: João Eduardo Medeiros
 * Creation date: 24/05/16
 */
MACHINE
    GerenciarVeiculos
SEES 
    Pessoas, Carros, Modelos
INCLUDES 
    GerenciarReservas
PROMOTES 
    removerReserva, adicionarReserva, cardReservas
VARIABLES 
    carros, alugueis, tipocarro
INVARIANT 
    carros <: CARS & alugueis : PEOPLE >+> CARS & tipocarro : CARS +-> MODELO
INITIALISATION 
    carros := {} || alugueis := {} || tipocarro := {}
OPERATIONS
    cc <-- retirarCarro(mm,pp) = 
        PRE mm : MODELO & pp : PEOPLE & pp /: dom(alugueis) & pp /: dom(reservas)
        THEN ANY carx 
             WHERE carx : CARS & carx : carros & carx : dom(tipocarro |> {mm}) & carx /: ran(alugueis) & carx /: ran(reservas) 
             THEN alugueis := alugueis \/ {pp |-> carx} || cc := carx
             END
        END;

    qq <-- retirarCarroReservado(cc,pp) = 
        PRE cc : CARS & cc : carros & pp : PEOPLE & pp : dom(reservas) & pp /: dom(alugueis) & cc : ran(reservas) & cc /: ran(alugueis)
        THEN alugueis := alugueis \/ {pp |-> cc} || qq := cc || removerReserva(pp)
        END;

    qq <-- situacaoCarro(cc) = 
        PRE cc : CARS & cc : carros
        THEN IF cc : ran(alugueis) THEN qq := 1
             ELSIF cc : ran(reservas) THEN qq := 2 
             ELSE qq := 3 END
        END;
    
    deixarCarro(pp) =
        PRE pp : PEOPLE & pp : dom(alugueis)
        THEN alugueis := {pp} <<| alugueis
        END;
    
    adicionarCarro(cc, tt) =
        PRE cc : CARS & tt : MODELO & cc /: carros 
        THEN carros := carros \/ {cc} || tipocarro := tipocarro \/ {cc |-> tt}
        END;
        
    removerCarro(cc) = 
        PRE cc : CARS & cc : carros 
        THEN carros := carros - {cc} || tipocarro := {cc} <<| tipocarro
        END;

    qq <-- tamanhoCarros = 
       BEGIN qq := card(carros)
       END;

    qq <-- cardAlugueis = 
       BEGIN qq := card(alugueis)
       END
END
