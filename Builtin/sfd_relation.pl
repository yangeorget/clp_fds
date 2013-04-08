/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Built-In: FD predicates                                                 */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_relation.pl                                                         */
/*-------------------------------------------------------------------------*/


/* relations */

:- public element/3, element/4, relation/2.

element(I,LX,X) :-
	length(LX,N),
	length(LV,N),
	semiring_unity(One),
	list_of(LV,One),
	element(I,LX,LV,X).

element(I,LX,LV,X) :-
	length(LX,N),
	length(LV,N),
	I in 1..N,
	element1(I,X,N,LX,LV).

element1(_,_,_,_,_):-
	pragma_c('Element1_5').


relation(VTuples,Vars):-
	split(VTuples,Tuples,Values),
	lines_to_columns(Tuples,CTuples),
	relationc1(CTuples,Vars,Values,_).

relationc1([],[],_,_).
relationc1([C|CTuples],[X|Vars],Values,I):-
	element(I,C,Values,X),
	relationc1(CTuples,Vars,Values,I).


split([],[],[]).
split([(Tuple,Value)|L],[Tuple|LTuples],[Value|LValues]) :-
	split(L,LTuples,LValues).



	
:- public v_element/3, v_relation/2.

v_element(I,L,X) :-
	length(L,N),
	I in 1..N,
	v_element1(I,X,N,L).

v_element1(_,_,_,_):-
	pragma_c('V_Element1_4').


v_relation(Tuples,Vars):-
	lines_to_columns(Tuples,CTuples),
	v_relationc1(CTuples,Vars,_).

v_relationc1([],[],_).
v_relationc1([C|CTuples],[X|Vars],I):-
	v_element(I,C,X),
	v_relationc1(CTuples,Vars,I).




:- public nogood/2.

nogood(Tuple,Vars) :-
	equiv_eq_csts(Bools,Vars,Tuple),
	and(Bools,ZeroVar),
	ZeroVar in sing(0). % and not: and(Bools,0) (for constraint retraction)











