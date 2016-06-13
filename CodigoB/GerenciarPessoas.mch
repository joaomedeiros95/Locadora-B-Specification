/* GerenciarPessoas
 * Author: Stefano Loss
 * Creation date: 25/05/2016
 */
MACHINE
    GerenciarPessoas
SETS
    SITUACAO = { alugando , inadimplente , normal }
SEES
    Pessoas
ABSTRACT_VARIABLES
    situacao , pessoas
INVARIANT
    situacao : PEOPLE --> SITUACAO & pessoas <: PEOPLE
INITIALISATION
    situacao := PEOPLE * { normal } || pessoas := {}
OPERATIONS
    cadastrarPessoa ( pp ) =
        PRE pp : PEOPLE & pp /: pessoas
        THEN pessoas := pessoas \/ { pp } || situacao ( pp ) := normal
        END ;

    rr <-- verSituacao ( pp ) =
        PRE pp : PEOPLE & pp : pessoas
        THEN rr := situacao ( pp )
        END ;

    alterarSituacao ( pp , ss ) =
        PRE pp : PEOPLE & pp : pessoas & ss : SITUACAO
        THEN situacao ( pp ) := ss
        END


END
