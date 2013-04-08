/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/*                                                 Yan Georget - June 1998 */
/* sfd_enumeration.pl                                                      */
/*-------------------------------------------------------------------------*/


:- public blevel/2.

blevel([],A) :-
	semiring_unity(A).
blevel([H],A) :-
	!,
	sfd_value(H,A).
blevel([H|T],A) :-
	!,
	sfd_value(H,AV),
	blevel(T,AT),
	semiring_mul(AV,AT,A).



:- public deleteff/3.

deleteff([Y],Y,[]) :-
	!.
deleteff([Y|LY],X,R):-
	sfd_size(Y,SY),
	(SY == 1
    ->
	deleteff(LY,X,R)
    ;
	deleteff(LY,Y,SY,X,[],R)).

deleteff([],X,_,X,R,R) :-
	!.
deleteff([Z|LZ],Y,SY,X,RT,R) :-
	sfd_size(Z,SZ),
	(SZ =< SY 
    -> 
	deleteff(LZ,Z,SZ,X,[Y|RT],R)
    ;
	deleteff(LZ,Y,SY,X,[Z|RT],R)).



:- public indomain/1.

indomain(X) :- 
	(sfd_is_instantiated(X)
    ->
	true
    ;
	sfd_index(X,I),
	(X in sing(I)
    ; 
	bt_inc,
	X in comp(I), 
	indomain(X))).



:- public labeling/1, labelingff/1.

labeling([]).
labeling([X|L]) :-
	indomain(X),
	labeling(L).

labelingff(_):-
	pragma_c('Labelingff_1').

labelingff1(L,X):-  % called by Labelingff_1
	indomain(X),
	labelingff(L).











