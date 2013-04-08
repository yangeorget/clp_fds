/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/*                                                 Yan Georget - June 1998 */
/* sfd_optimization.pl                                                     */
/*-------------------------------------------------------------------------*/


:- public cut/3, keep/3.

cut(_,[],_).
cut(le,[X|L],A) :-
	X in cut_le(def(X),A),
	cut(le,L,A).
cut(l,[X|L],A) :-
	X in cut_l(def(X),A),
	cut(l,L,A).
cut(ge,[X|L],A) :-
	X in cut_ge(def(X),A),
	cut(ge,L,A).
cut(g,[X|L],A) :-
	X in cut_g(def(X),A),
	cut(g,L,A).
cut(d,[X|L],A) :-
	X in cut_d(def(X),A),
	cut(d,L,A).
cut(np,[X|L],A) :-
	X in cut_np(def(X),A),
	cut(np,L,A).
cut(nnp,[X|L],A) :-
	X in cut_nnp(def(X),A),
	cut(nnp,L,A).

keep(_,[],_).
keep(le,[X|L],A) :-
	X in keep_le(def(X),A),
	keep(le,L,A).
keep(l,[X|L],A) :-
	X in keep_l(def(X),A),
	keep(l,L,A).
keep(ge,[X|L],A) :-
	X in keep_ge(def(X),A),
	keep(ge,L,A).
keep(g,[X|L],A) :-
	X in keep_g(def(X),A),
	keep(g,L,A).
keep(d,[X|L],A) :-
	X in keep_d(def(X),A),
	keep(d,L,A).
keep(np,[X|L],A) :-
	X in keep_np(def(X),A),
	keep(np,L,A).
keep(nnp,[X|L],A) :-
	X in keep_nnp(def(X),A),
	keep(nnp,L,A).



:- public max_sol/1, max_sol/3, max_sol/4.

max_sol(Vars) :-
	max_sol(Vars,labeling(Vars),labeling(Vars)).

max_sol(Vars,Goal1,Goal2) :-
	semiring_null(Zero),
	max_sol(Vars,Goal1,Goal2,Zero).

max_sol(Vars,Goal1,Goal2,Alpha) :-
	g_assign('$cur_max',Alpha),
	repeat,
	g_read('$cur_max',B),
	(keep(g,Vars,B),
	Goal1
    -> 
	blevel(Vars,C),
	g_assign('$cur_max',C),
	fail
    ;
	!,
	g_read('$cur_max',D),
	keep(ge,Vars,D),
	Goal2).













