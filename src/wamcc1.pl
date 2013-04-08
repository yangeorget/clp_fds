/* Modified by Yan Georget - June 1998 */

/*-------------------------------------------------------------------------*/
/* Passe 1: Elimination de certaines structures syntaxiques.               */
/*                                                                         */
/* ..., !,...: devient '$get_bc_reg'(VarCut)...'$cut'(VarCut), ...         */
/*                                                                         */
/* (P -> Q)  : devient '$get_bc_reg'(VarCut),P,'$cut'(VarCut),Q ; fail)    */
/*                                                                         */
/* (P -> Q;R): devient '$get_bc_reg'(VarCut),P,'$cut'(VarCut),Q ; R)       */
/*                                                                         */
/* (\+P)     : devient '$get_bc_reg'(VarCut),P,'$cut'(VarCut),fail ; true) */
/*                                                                         */
/* X         : devient call(X)                                             */
/*                                                                         */
/* P;Q;...;R : devient '$aux_k'(var1,var2,...,varp)          k=1,2,...,n   */
/*                  et '$aux_k'(var1,var2,...,varp):- P                    */
/*                     '$aux_k'(var1,var2,...,varp):- Q                    */
/*                        :                                                */
/*                     '$aux_k'(var1,var2,...,varp):- R                    */
/*                                                                         */
/*                                                                         */
/*                                                                         */
/* predicat d'appel: sucre_syntaxique(ClSrc,LSrc,ClSrc1,LFdC,LSrc1)        */
/*                                                                         */
/* entree                                                                  */
/* ClSrc  : clause source a verifier/modifier                              */
/* LSrc   : liste des autres clauses sources                               */
/*                                                                         */
/* sortie                                                                  */
/* ClSrc1 : clause modifiee                                                */
/*                                                                         */
/* LSrc1  : liste a laquelle on a ajoute les clause '$aux_k'(var1,...,varp)*/
/*                                                                         */
/* En mode debug: P:- Q1, ... , Qn. devient P:- Q1, ..., Qn, '$dbg_true'.  */
/* si Qn n'est pas defini dans le module courant. $dbg_true est un inline  */
/* qui ne s'expanse en rien mais entraine la generation d'un proceed pour  */
/* cette clause. Sinon on ne peut tracer sous debug la sortie de l'appel de*/
/* P si celui-ci est fait depuis un module non debugge.                    */
/*                                                                         */
/* Prise en compte des FD :                                                */
/*                                                                         */
/* Si une clause contient au moins une contrainte FD, avant la premiere de */
/* celles-ci on ajoute les predicats definissant la 'argument frame' (AFrm)*/
/* de pointeur AF. Une variable Prolog appariassant dans une contrainte est*/
/* un argument pour la contrainte. Un argument est soit un parametre, soit */
/* une variable FD. Chaque argument sera charge dans la A frame et y sera  */
/* reference par un numero NoArg qui est soit un FP (frame parameter) soit */
/* un FV (frame variable).                                                 */
/*                                                                         */
/* Exemple: dans X in min(Y)+C..100                                        */
/*          la 'argument frame' contiendra X, Y comme variables (fv)       */
/*                                      et C    comme parametre (fp)       */
/*                                                                         */
/* De plus dans le corps toutes les contraintes X in R deviennent :        */
/* '$cstr'(NoFdC,VarAFrm) et LFdC = [cstr(NoFdC,Opt2,X',R'), ...]          */
/* dans X' et R' les variables  etant remplacees par fp(i,TypeParam) si ce */
/* sont des parametres ou par fv(i) si ce sont des var FD.                 */
/* (i=numero de l'argument dans la frame, a partir de 0).                  */
/* TypeParam = 'r' ou 't' suivant que c'est un range ou un terme           */
/*                                                                         */
/* Exemple :                                                               */
/* p(X,Y,C):- r(X), X in min(Y)+C..max(Y)+C, s(Y), Y in min(X)-C..max(X)-C.*/
/*                                                                         */
/* p(X,Y,Z):- r(X),                                                        */
/*            '$fd_set_AF'(3,VarAFrm),                                     */
/*            '$fd_fv'(X), '$fd_fv'(Y), '$fd_fp'(C,t),                     */
/*            '$fd_cstr'(1,VarAFrm), s(Y), '$fd_cstr'(2,VarAFrm).          */
/*                                                                         */
/* LFdC =[ cstr(1,1,fv(0),min(fv(1))+fp(2,t)..max(fv(1))+fp(2,t)),         */
/*         cstr(2,1,fv(1),min(fv(0))-fp(2,t)..max(fv(0))-fp(2,t)) ]        */
/*                                                                         */
/* Pour X in R no_opt2 : l'optimisation 2 ne doit pas etre appliquee, le   */
/* champ Opt2 = 0 sinon = 1.                                               */
/*-------------------------------------------------------------------------*/

:- public sucre_syntaxique/5.

sucre_syntaxique(ClSrc,LSrc,ClSrc3,LFdC,LSrc1):-
	(ClSrc=(T:-_) ; ClSrc=T),
        functor(T,F,N),
	(test_pred_info(dyn,F,N) 
              -> make_special_clause(nb_clause_dyn,'$dyn_',
                                     assertz(ClSrc),ClSrc2),
                 LSrc1=LSrc
              ;
	         normalise_cuts(ClSrc,ClSrc1),
		 normalise_alts(ClSrc1,LSrc,ClSrc2,LSrc1)),
		 (g_read(no_inline,f) -> normalise_fdc(ClSrc2,ClSrc3,LFdC)
                                     ;
                                         ClSrc3=ClSrc2,
                                         LFdC=[]),
	!.




normalise_cuts((T:-C),ClSrc):-                                  % clause
        normalise_cuts1(C,VarCut,C1,HasCut),
        (HasCut==t -> ClSrc=(T:-'$get_bc_reg'(VarCut),C1)
                   ;  ClSrc=(T:-C1)).

normalise_cuts(T,T).                                            % fait




normalise_cuts1(X,_,call(X),_):-
	var(X).

normalise_cuts1((P->Q;R),VarCut,ClSrc,HasCut):-
	ClSrc=('$get_bc_reg'(VarCut1),P,'$cut'(VarCut1),Q1;R1),
	normalise_cuts1(Q,VarCut,Q1,HasCut),
	normalise_cuts1(R,VarCut,R1,HasCut).

normalise_cuts1((P->Q),VarCut,ClSrc,HasCut):-
	ClSrc=('$get_bc_reg'(VarCut1),P,'$cut'(VarCut1),Q1;fail),
	normalise_cuts1(Q,VarCut,Q1,HasCut).

normalise_cuts1(\+P,VarCut,ClSrc,HasCut):-
	normalise_cuts1((P->fail;true),VarCut,ClSrc,HasCut).

normalise_cuts1((P,Q),VarCut,(P1,Q1),HasCut):-
	normalise_cuts1(P,VarCut,P1,HasCut),
	normalise_cuts1(Q,VarCut,Q1,HasCut).

normalise_cuts1((P;Q),VarCut,(P1;Q1),HasCut):-
	normalise_cuts1(P,VarCut,P1,HasCut),
	normalise_cuts1(Q,VarCut,Q1,HasCut).

normalise_cuts1((!),VarCut,'$cut'(VarCut),t).

normalise_cuts1(P,_,P1,_):-
	functor(P,F,N),
	(test_pred_info(dyn,F,N) -> P1=call(P)
                                 ;  P1=P).




normalise_alts((T:-C),LSrc,(T:-C2),LSrc1):-                          % clause
	functor(T,F,_),
	normalise_alts1(C,LSrc,F,T,C1,LSrc1,LastPred),
	g_read(debug,Debug),
	(Debug=:=0 -> C2=C1
                   ;  
                      functor(LastPred,FLastPred,NLastPred),
	              (test_pred_info(def,FLastPred,NLastPred)
	                     -> C2=C1
                             ;  C2=(C1,'$dbg_true'))).

normalise_alts(T,LSrc,T,LSrc).                                       % fait


normalise_alts1(X,LSrc,_,_,call(X),LSrc,call(_)):-
	var(X).

normalise_alts1((P,Q),LSrc,F,RestC,(P1,Q1),LSrc2,LastPred):-
	normalise_alts1(P,LSrc,F,(RestC,Q),P1,LSrc1,_),
	normalise_alts1(Q,LSrc1,F,(RestC,P),Q1,LSrc2,LastPred).

normalise_alts1((P;Q),LSrc,F,RestC,PredAux,LSrc1,PredAux):-
	g_read(aux,Aux),
	Aux1 is Aux+1,
	g_assign(aux,Aux1),
	(sub_atom(F,Pos,5,'_$aux') -> L is Pos-1,
                	              sub_atom(F,1,L,F1)
			           ; 
				      F1=F),
	number_atom(Aux,ANo),
	atom_concat('$aux',ANo,AAux),
	atom_concat(F1,'_',F2),
	atom_concat(F2,AAux,Nom),
	lst_var(RestC,[],VarRestC),
	lst_var((P;Q),[],VarOu),
	ens_inter(VarRestC,VarOu,V),
	PredAux=..[Nom|V],
	functor(PredAux,FPredAux,NPredAux),                % add a new clause
	set_pred_info(def,FPredAux,NPredAux),
	linearise((P;Q),PredAux,LSrc,LSrc1).

normalise_alts1(P,LSrc,_,_,P,LSrc,P).




linearise(Body,PredAux,LSrc,LSrc2):-
	(Body=(P;Q) -> linearise(Q,PredAux,LSrc,LSrc1),
	               linearise1(P,PredAux,LSrc1,LSrc2)
                    ;
                       linearise1(Body,PredAux,LSrc,LSrc2)).


linearise1(P,PredAux,LSrc,LSrc1):-
	(P==fail -> LSrc1=LSrc
                 ;  
		    copy_term((PredAux:-P),AltP),
		    LSrc1=[AltP|LSrc]).




/* on utilise linearise plutot que :

   normalise_alts1((P;Q),...) recursivement sur P et Q

   pour generer un code plus optimal (code plat) x:-P;Q;R donne :
   
   x:-	'$aux_1'     au lieu de  x:- '$aux_1'

   '$aux_1':- P.                 '$aux_1':- P.
   '$aux_1':- Q.                 '$aux_1':- '$aux_2'.
   '$aux_1':- R.
                                 '$aux_2':- Q.
                                 '$aux_2':- R.
*/




lst_var(X,V,V1):-
	var(X),
	!,
	ens_ajout(V,X,V1).

lst_var(T,V,V1):-
	functor(T,_,A),
	lst_var_args(1,A,T,V,V1).



lst_var_args(I,A,T,V,V2):-
	(I=<A -> arg(I,T,ArgT),
                 lst_var(ArgT,V,V1),
		 I1 is I+1,
		 lst_var_args(I1,A,T,V1,V2)
              ;
                 V2=V).




	/* FD transformations */

normalise_fdc((T:-C),(T:-C1),LFdC):-                            % clause
	normalise_fdc1(C,[],VarAF,VarAFrm,C1,LFdC,LArg),
	(LArg\==[] -> cree_fd_A_frame(LArg,NbArg,AFrm),
	              VarAFrm=('$fd_set_AF'(NbArg,VarAF),AFrm)
	           ;  
	              true).

normalise_fdc(T,T,_).                                          % fait


normalise_fdc1((P,Q),LArg,VarAF,VarAFrm,(P1,Q1),LFdC,LArg2):-
	normalise_fdc1(P,LArg,VarAF,VarAFrm,P1,LFdC1,LArg1),
	normalise_fdc1(Q,LArg1,VarAF,VarAFrm,Q1,LFdC2,LArg2),
	append(LFdC1,LFdC2,LFdC).

normalise_fdc1(X in RO,LArg,VarAF,VarAFrm,FdCSrc,LFdC,LArg2):-
	(nonvar(RO), RO = (R no_opt2) -> Opt2=0
	                              ;  R=RO, Opt2=1),
	g_read(no_fdc,NoFdC),
	NoFdC1 is NoFdC+1,
	g_assign(no_fdc,NoFdC1),
	no_fd_arg(LArg,fv,X,-1,LArg1,FV),
	traite_fd_arg([R],LArg1,[R1],LArg2),
	LFdC=[cstr(NoFdC,Opt2,fv(FV),R1)],
	(LArg==[] -> FdCSrc=(VarAFrm,'$fd_cstr'(NoFdC,VarAF))
	          ;  FdCSrc='$fd_cstr'(NoFdC,VarAF)).

normalise_fdc1(E1 #= E2,LArg,_,_,P,[],LArg):-
	transf_eq(E1,E2,P),
	(g_read(verbose,t) -> write(P), nl, nl
                           ;  true).

normalise_fdc1(E1 #\= E2,LArg,_,_,P,[],LArg):-
	transf_ne(E1,E2,P),
	(g_read(verbose,t) -> write(P), nl, nl
                           ;  true).


normalise_fdc1(E1 #>= E2,LArg,_,_,P,[],LArg):-
	transf_ge(E1,E2,P),
	(g_read(verbose,t) -> write(P), nl, nl
                           ;  true).

normalise_fdc1(E1 #> E2,LArg,_,_,P,[],LArg):-
	transf_g(E1,E2,P),
	(g_read(verbose,t) -> write(P), nl, nl
                           ;  true).


normalise_fdc1(E1 #<= E2,LArg,_,_,P,[],LArg):-
	transf_ge(E2,E1,P),
	(g_read(verbose,t) -> write(P), nl, nl
                           ;  true).


normalise_fdc1(E1 #< E2,LArg,_,_,P,[],LArg):-
	transf_g(E2,E1,P),
	(g_read(verbose,t) -> write(P), nl, nl
                           ;  true).


normalise_fdc1(P,LArg,_,_,P,[],LArg).



traite_fd_arg([],LArg,[],LArg).

traite_fd_arg([P|L],LArg,[R|L1],LArg2):-
	(var(P), X=P, FpType=t, R=fp(FP,t)
                    ;
	 P=[X|_],FpType=r, R=[fp(FP,r)]), %SFD
	!,
	no_fd_arg(LArg,fp(FpType),X,-1,LArg1,FP),
	traite_fd_arg(L,LArg1,L1,LArg2).

% SFD
traite_fd_arg([P|L],LArg,[P1|L1],LArg2):-
	P=..[F|LstArg],
	 ( (F=sigma ; F=def ; F=min ; F= max ; F=val), LstArg=[X], var(X)
	    -> no_fd_arg(LArg,fv,X,-1,LArg1,FV),
	       LstArg1=[fv(FV)]
	    ;
	       traite_fd_arg(LstArg,LArg,LstArg1,LArg1)),
	P1=..[F|LstArg1],
	traite_fd_arg(L,LArg1,L1,LArg2).




no_fd_arg([],ArgType,X,NoArg,[arg(ArgType,X,NoArg1)],NoArg1):-
	NoArg1 is NoArg+1.

no_fd_arg(LArg,ArgType,X,_,LArg,NoArg):-
	LArg=[arg(ArgType,X1,NoArg)|_],
	X==X1.

no_fd_arg([Arg|LArg],ArgType,X,_,[Arg|LArg1],NoArg1):-
	Arg=arg(_,_,NoArg),
	no_fd_arg(LArg,ArgType,X,NoArg,LArg1,NoArg1).




cree_fd_A_frame([arg(ArgType,X,_)|LArg],NbArg,AFrm):-
	(ArgType=fp(FpType) -> Pred='$fd_fp'(X,FpType)
                            ;  Pred='$fd_fv'(X)),
	(LArg==[] -> AFrm=Pred,
	             NbArg=1
	          ;
	             cree_fd_A_frame(LArg,NbArg1,AFrm1),
	             NbArg is NbArg1+1,
	             AFrm=(Pred,AFrm1)).



% par 3

/*
transf_eq(LE,RE,(P,LP,RP)):-
	normalize(LE,RE,LEL,LC,REL,RC,P),
	(REL=[], RC>0, LEL=[AX|LEL1], eq_var(LEL1,LC,Z1,P1),
	 eq_var([AX],0,Z2,P2), LP=(P1,P2), RP='pac x+y=c'(Z2,Z1,RC)
	   ;
	 eq_var(LEL,LC,Z,LP),
 	 eq_var(REL,RC,Z,RP)),
	!.
*/

transf_eq(LE,RE,(P,LP,RP)):-
	normalize(LE,RE,LEL,LC,REL,RC,P),
	eq_var(LEL,LC,Z,LP),
	eq_var(REL,RC,Z,RP).


transf_ne(LE,RE,(P,LP,RP,'pac x<>y'(LZ,RZ))):-
	normalize(LE,RE,LEL,LC,REL,RC,P),
	eq_var(LEL,LC,LZ,LP),
	eq_var(REL,RC,RZ,RP).



transf_ge(LE,RE,(P,LP,RP,'pac x>=y'(LZ,RZ))):-
	normalize(LE,RE,LEL,LC,REL,RC,P),
	eq_var(LEL,LC,LZ,LP),
	eq_var(REL,RC,RZ,RP).



transf_g(LE,RE,(P,LP,RP,'pac x>y'(LZ,RZ))):-
	normalize(LE,RE,LEL,LC,REL,RC,P),
	eq_var(LEL,LC,LZ,LP),
	eq_var(REL,RC,RZ,RP).



eq_var([],Z,Z,true).

eq_var([A*X],C,Y,P):-
	(C=0 -> (A=1 -> X=Y, P=true
	             ;  P='pac ax=y'(A,X,Y))
	     ;
	        (A=1 -> P='pac x+c=y'(X,C,Y)
	             ;  P='pac ax+c=y'(A,X,C,Y))).

eq_var([A*X,B*Y],C,Z,P):-
	(C=0 -> (A=1 -> (B=1 -> P='pac x+y=z'(X,Y,Z)
	                     ;  P='pac ax+y=z'(B,Y,X,Z))
	             ;
	                (B=1 -> P='pac ax+y=z'(A,X,Y,Z)
	                     ;  P='pac ax+by=z'(A,X,B,Y,Z)))
	     ;
	        (A=1 -> (B=1 -> P='pac x+y+c=z'(X,Y,C,Z)
	                     ;  P='pac ax+y+c=z'(B,Y,X,C,Z))
	             ;
	                (B=1 -> P='pac ax+y+c=z'(A,X,Y,C,Z)
	                     ;  P='pac ax+by+c=z'(A,X,B,Y,C,Z)))).


eq_var([A*X,B*Y|EL],C,T,(P,P1)):-
	eq_var(EL,C,Z,P1),
	(A=1 -> (B=1 -> P='pac x+y+z=t'(X,Y,Z,T)
	             ;  P='pac ax+y+z=t'(B,Y,X,Z,T))
	     ;
	        (B=1 -> P='pac ax+y+z=t'(A,X,Y,Z,T)
	             ;  P='pac ax+by+z=t'(A,X,B,Y,Z,T))).








 /* nf = [a1*X1,...] + C   ai>=1  C >=0 */

/* without sorting by coef

normalize(E1,E2,LEL,LC,REL,RC,P):-
	normalize1(E1-E2,1,EL,C,P),
	(C>=0 -> LC=C, RC=0
	      ;  LC=0, RC is -C),
	split(EL,LEL,REL),
	!.
*/

normalize(E1,E2,LEL2,LC,REL2,RC,P):-
	normalize1(E1-E2,1,EL,C,P),
	(C>=0 -> LC=C, RC=0
	      ;  LC=0, RC is -C),
	split(EL,LEL,REL),
	sort(LEL,LEL1),
	reverse(LEL1,[],LEL2),
	sort(REL,REL1),
	reverse(REL1,[],REL2),
	!.


normalize1(E,Sign,EL,C,(P1,P2)):-
	 nonvar(E),
	 E=E1+E2,
	 !,
	 normalize1(E1,Sign,EL1,C1,P1),
	 normalize1(E2,Sign,EL2,C2,P2),
	 append_with_add(EL1,EL2,EL),
	 C is C1+C2.

normalize1(E,Sign,EL,C,(P1,P2)):-
	 nonvar(E),
	 E=E1-E2,
	 !,
	 Sign1 is -Sign,
	 normalize1(E1,Sign, EL1,C1,P1),
	 normalize1(E2,Sign1,EL2,C2,P2),
	 append_with_add(EL1,EL2,EL),
	 C is C1+C2.

normalize1(CX,Sign,[C1*Y],0,P):-
	 nonvar(CX),
	 CX=C*X,
	 !,
	 (integer(C) -> C1 is Sign*C,
                        Y=X,
			P=true
                     ;
                        C1=Sign,
                        P='pac ax=y'(C,X,Y)).
			

normalize1(C,Sign,[],C1,true):-
	integer(C),
	!,
	C1 is Sign*C.

normalize1(X,Sign,[Sign*X],0,true).




append_with_add([],EL,EL).

append_with_add([C*X|EL1],EL2,EL3):-
	sum_in_list(EL2,C,X,EL21),
	append_with_add(EL1,EL21,EL3).




sum_in_list([],C,X,[C*X]).

sum_in_list([C1*X|EL],C2,Y,[C*X|EL]):-
	X==Y,
	C is C1+C2.

sum_in_list([CX|EL],C,X,[CX|EL1]):-
	sum_in_list(EL,C,X,EL1).




split([],[],[]).

split([C*X|EL],[C*X|LEL],REL):-
	C > 0,
	split(EL,LEL,REL).

split([C*X|EL],LEL,[C1*X|REL]):-
	C < 0,
	C1 is -C,
	split(EL,LEL,REL).

split([_|EL],LEL,REL):-
	split(EL,LEL,REL).




reverse([],L,L).

reverse([X|L],L1,L2):-
	reverse(L,[X|L1],L2).
















/*
cree_terme_arith_d([],C,C).

cree_terme_arith_d([A*X],C,T):-
	(C=0 -> (A=1 -> T=X
	             ;  T=A*X)
	     ;
	        (A=1 -> T=X+C
	             ;  T=A*X+C)).

cree_terme_arith_d([A*X|EL],C,T1+T2):-
	cree_terme_arith_d(EL,C,T2),
	(A=1 -> T1=X
	     ;  T1=A*X).






cree_terme_arith_g([],T,T).

cree_terme_arith_g([A*X|EL],T,T1):-
	(T=0 -> (A=1 -> cree_terme_arith_g(EL,X,T1)
	             ;  cree_terme_arith_g(EL,A*X,T1))
	     ;
	        (A=1 -> cree_terme_arith_g(EL,T+X,T1)
	             ;  cree_terme_arith_g(EL,T+A*X,T1))).

*/



