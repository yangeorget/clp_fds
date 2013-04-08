/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_srg_sets.pl                                                         */
/*-------------------------------------------------------------------------*/



:- public sets_value_index/3, sets_value/2, sets_index/2.

sets_value_index(_,_,_) :- 
	pragma_c('Sets_Value_Index_3').

sets_value(X,V) :-
	sets_value_index(X,V,_).

sets_index(X,I) :-
	sets_value_index(X,_,I).



:- public sets_indomain/1.

sets_indomain(X) :- 
	(sfd_is_instantiated(X)
    ->
	true
    ;
	sets_index(X,I),
	(X in sing(I)
    ; 
	bt_inc,
	X in comp(I),
	sets_indomain(X))).



:- public sets_labeling/1, sets_labelingff/1.

sets_labeling([]).
sets_labeling([X|L]) :-
	sets_indomain(X),
	sets_labeling(L).


sets_labelingff(_):-
	pragma_c('Sets_Labelingff_1').

sets_labelingff1(L,X):-           
	sets_indomain(X),
	sets_labelingff(L).



:- public sets_card_ge/2.

sets_card_ge([],_).
sets_card_ge([X|L],N) :-
	X in keep_card_ge(def(X),N),
	sets_card_ge(L,N).



:- public sets_card_g/2.

sets_card_g([],_).
sets_card_g([X|L],N) :-
	X in keep_card_g(def(X),N),
	sets_card_g(L,N).



:- public sets_max_sol/1, sets_max_sol/3, sets_max_sol/4.

sets_max_sol(Vars) :-
	sets_max_sol(Vars,sets_labeling(Vars),sets_labeling(Vars)).

sets_max_sol(Vars,Goal1,Goal2) :-
	sets_max_sol(Vars,Goal1,Goal2,0).

sets_max_sol(Vars,Goal1,Goal2,A) :-
	g_assign('$cur_max',A),
	repeat,
	g_read('$cur_max',B),
	(sets_card_g(Vars,B),
	Goal1,
	blevel(Vars,Blevel),
	num_bitnb(Blevel,C),
	C > B
    -> 
	g_assign('$cur_max',C),
	fail
    ;
	!,
	g_read('$cur_max',D),
	sets_card_ge(Vars,D),
	Goal2).




/*-------------------------------------------------------------------------*/
/* The following code is an implementation of Makoto Yokoo's               */
/* "Weak Commitment Search"                                                */
/*                                                                         */
/* It founds, if it exists, a solution of the problem. It does not         */
/* backtrack. It should not be included in a constraint block (since it    */
/* uses constraint retraction).                                            */
/*-------------------------------------------------------------------------*/


:- public wcs/2.

wcs(Vars,Values) :-
	length(Values,N),
	N < 28,
	g_assign(wcs_values,g_array(Values)),
	N1 is N+1, % such that it does not fail even if all the variables are incorrect
	All is (1<<N1)-1,
	g_assign(wcs_all,All),
	wcs_start(Vars).


% starts or restarts
wcs_start(Vars) :-
	wcs_vars(Vars,1),
	wcs_extend(Vars,1),
	!.
wcs_start(Vars) :-
	g_read(wcs_nogood_size,NogoodSize),
	NogoodSize =\= 0,
	g_read(wcs_values,g_array(Values)),
	length(NogoodVars,NogoodSize),
	length(NogoodValues,NogoodSize),
	prefix(NogoodVars,Vars),
	prefix(NogoodValues,Values),
	nogood(NogoodValues,NogoodVars),
	!,
	wcs_start(Vars).


% builds the valued domains (thus the constraints remain unchanged)
wcs_vars([],_).
wcs_vars([Var|Vars],I) :-
	Ia is I-1,
	I1 is I+1,
	g_read(wcs_values(Ia),Value),
	g_read(wcs_all,All),
	Mask is All^(1<<Ia),
	cstrs_block_start,
	'x=c:(a;b)'(Var,Value,All,Mask),
	cstrs_block_end(CB),
	fdv_cstrs_block_put(Var,CB),
	wcs_vars(Vars,I1).


% extends a partial solution 
wcs_extend([],_).
wcs_extend([Var|Vars],I) :-
	I1 is I+1,
	Mask is (1<<I)-1,
	(keep(ge,[Var],Mask)
    ->
	wcs_extend(Vars,I1)
    ; 	
	bt_inc,
	wcs_extend_aux(Var,Vars,I,I1,Mask)).

wcs_extend_aux(Var,Vars,I,I1,Mask) :-
	Ia is I-1,
	(fdv_cstrs_block_retract(Var),
	keep(ge,[Var],Mask),
	sets_max_sol([Var]),
	sfd_min(Var,Index),
	g_assign(wcs_values(Ia),Index)
    ->	
	wcs_extend(Vars,I1)
    ;
	bt_inc,
	g_assign(wcs_nogood_size,Ia),
	fail).
	




