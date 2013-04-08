/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/*                                                 Yan Georget - June 1998 */
/* sfd_srg_bool.pl                                                         */
/*-------------------------------------------------------------------------*/


:- public bool_v_element/3.

bool_v_element(I,L,X) :-
	length(L,N),
	I in 1..N,
	bool_v_element1(I,X,N,L).

bool_v_element1(_,_,_,_):-
	pragma_c('Bool_V_Element1_4').


:- public bool_indomain/1.

bool_indomain(X) :-
	sfd_min(X,Min),
	(X in sing(Min)
    ;
	bt_inc,
	X in add(Min,1)..infinity,
	bool_indomain(X)).



:- public bool_labeling/1.

bool_labeling([]).
bool_labeling([X|L]) :-
	bool_indomain(X),
	bool_labeling(L).



:- public bool_labelingff/1.

bool_labelingff(_L):-
	pragma_c('Bool_Labelingff_1').

bool_labelingff1(L,X):-  % called by Bool_Labelingff_1
	bool_indomain(X),
	bool_labelingff(L).



:- public bool_alldifferent/1, bool_out_of/2, bool_diff/2.

bool_alldifferent([]).
bool_alldifferent([X|L]):-
	bool_out_of(L,X),
	bool_alldifferent(L).

bool_out_of([],_).
bool_out_of([Y|L],X):-
	bool_diff(X,Y),
	bool_out_of(L,X).

bool_diff(X,Y) :-
	X in comp(val(Y)),
	Y in comp(val(X)).



:- public bool_global_alldifferent/1.

bool_global_alldifferent(L) :-
	length(L,N),
	bool_global_alldifferent_aux(N,L).

bool_global_alldifferent_aux(_,_) :-
	pragma_c('Bool_Global_Alldifferent_Aux_2').



:- public bool_global_alldifferent2/1.

bool_global_alldifferent2(L) :-
	length(L,N),
	bool_global_alldifferent2_aux(N,L).

bool_global_alldifferent2_aux(_,_) :-
	pragma_c('Bool_Global_Alldifferent2_Aux_2').



:- public bool_minof/2, bool_maxof/2.

bool_minof(Goal,Var):-
	fd_infinity(Max),
	g_assign('$cur_min',Max),
	repeat,
	g_read('$cur_min',B),
	(Var #< B,
	call(Goal)
    -> 
	sfd_min(Var,C), 
	g_assign('$cur_min',C),
	fail
    ;
	!,
	Var=B,
	call(Goal)).


bool_maxof(Goal,Var):-
	g_assign('$cur_max',0),
	repeat,
	g_read('$cur_max',B),
	(Var #> B,
	call(Goal)
    -> 
	sfd_max(Var,C), 
	g_assign('$cur_max',C),
	fail
    ;
	!,
	Var=B,
	call(Goal)).




