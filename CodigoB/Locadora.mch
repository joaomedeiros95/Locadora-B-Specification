/* Locadora
 * Author: João Eduardo Medeiros
 * Creation date: 29/05/16
 */
MACHINE
    Locadora
INCLUDES 
    GerenciarPessoas, GerenciarVeiculos, GerenciarPagamento
SEES 
    Pessoas, Carros, Modelos
PROMOTES
    cadastrarPessoa, adicionarCarro, removerReserva, verSituacao, retirarCarroReservado

VARIABLES precoModelo
    
INVARIANT 
    precoModelo : MODELO --> NAT1

INITIALISATION 
    precoModelo := {1 |-> 5} \/ {2 |-> 7} \/ {3 |-> 10}
    
OPERATIONS
        
    c1 <-- alugarCarro(mm, pp, dd) =     
        PRE mm : MODELO & pp : PEOPLE & pp : pessoas & pp /: (dom(reservas) \/ dom(alugueis)) & dd : NAT1 & situacao(pp) = normal
        THEN c1 <-- retirarCarro(mm,pp) || gerarConta((precoModelo(mm)),pp,dd) || alterarSituacao(pp, alugando)
        END;

    deletarCarro(cc) = 
        PRE cc : CARS & cc : carros & cc /: ran(alugueis) & cc /: ran(reservas) 
        THEN removerCarro(cc)
        END;

    devolverCarro(pp) = 
        PRE pp : PEOPLE & pp : pessoas & pp : dom(alugueis) 
        THEN deixarCarro(pp) || alterarSituacao(pp, inadimplente) 
        END;

    pagarDevido(pp, vv) = 
        PRE pp : PEOPLE & pp : pessoas & vv : NAT1 & vv >= (faltapagar(pp) / 2) & faltapagar(pp) > 0 & pp /: dom(alugueis)
        THEN pagarConta(pp,vv) || IF (faltapagar(pp) - vv) = 0 & pp /: dom(alugueis) THEN alterarSituacao(pp, normal) END
        END;

    reservarVeiculo(pp, cc) = 
        PRE pp : PEOPLE & pp : pessoas & cc : CARS & cc : carros & pp /: (dom(reservas) \/ dom(alugueis)) & cc /: (ran(reservas) \/ ran(alugueis)) & situacao(pp) = normal
        THEN adicionarReserva(pp, cc)
        END;

    pp <-- carrosLivres = pp := card(carros) - card(alugueis) - card(reservas);

    pp <-- carrosAlugados = pp := card(alugueis);

    pp <-- carrosReservados = pp := card(reservas)
END
