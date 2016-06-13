/* GerenciarPagamento
 * Author: Stefano Loss
 * Creation date: 25/05/2016
 */
MACHINE GerenciarPagamento
    
SETS              SITUACAOPAG = {naopagou, pagoumetade, pagoutudo}
   
CONCRETE_CONSTANTS       precoDiaBase

PROPERTIES precoDiaBase = 10    
        
SEES              Pessoas

CONCRETE_VARIABLES faltapagar, situacaopag

INVARIANT         faltapagar : PEOPLE --> NAT & situacaopag : PEOPLE --> SITUACAOPAG & !aa.( aa: PEOPLE => ((faltapagar(aa) = 0) <=> (situacaopag(aa) = pagoutudo)))

INITIALISATION    faltapagar := PEOPLE * {0} || situacaopag :=  PEOPLE * {pagoutudo}

OPERATIONS 
    
    /*mm preço pelo modelo, pp pessoa, dd quant dias, qq quant quilometragem*/
    gerarConta(pm, pp, dd)=
        PRE pp : PEOPLE & pm : NAT1 & dd: NAT1      
        THEN faltapagar(pp) := faltapagar(pp) + (precoDiaBase * dd * pm)
            || situacaopag(pp) := naopagou
        END;
        
    pagarConta(pp, vv)=
        PRE pp : PEOPLE & vv : NAT1 & vv >= (faltapagar(pp) / 2) & faltapagar(pp) > 0
        THEN faltapagar(pp) := (faltapagar(pp) - vv)||
            IF ((faltapagar(pp) - vv) = 0) THEN situacaopag(pp) := pagoutudo
            ELSE situacaopag(pp) := pagoumetade
            END
        END;
    
    ss <-- verSituacaoPessoa(pp)=
        PRE pp : PEOPLE 
        THEN ss := situacaopag(pp)
        END

END
