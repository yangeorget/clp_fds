/*-------------------------------------------------------------------------*/
/* Title           : time tabling                                          */
/* Original Source : Y. Caseau & F. Laburthe                               */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : sets (big for 1,2,4 ; small for 3,5)                  */
/*                                                                         */
/* http://www.ens.fr/~laburthe/matching.html for a complete description    */
/*                                                                         */
/*-------------------------------------------------------------------------*/


:- public tt/1.

tt(Start) :-
	make_vars(V,S,Size),
	statistics(runtime,_),
	no_overlap(V),
	bt_reset,
	tt_max_sol(S,Start,Size),
	bt_get(Backtracks),
	statistics(runtime,[_,Time]),
	write('backtracks: '), write(Backtracks),nl,
	write('time: '), write(Time), nl.


tt_max_sol(Vars,M,Size) :-
	g_assign('$cur_max',M),
	repeat,
	g_read('$cur_max',N),
	(N1 is N+1,
	write('Search with '), write(N1), write(' tokens'), nl,
	write('Try with '), nl,
	bitnb_num(N1,Size,B), 
	semiring_value_write(B),
	keep(ge,Vars,B),
	sets_labelingff(Vars)
    -> 
	blevel(Vars,C),
	num_bitnb(C,P),   
	nl, 
	write('A '), write(P), write('-token(s) solution has been found'), nl,
	g_assign('$cur_max',P),
	fail
    ;
	!,
	nl,
	write('Final search with '), write(N), write(' tokens'), nl,
	write('Try with '), nl,
	bitnb_num(N,Size,B),
	semiring_value_write(B),
	keep(ge,Vars,B),
	sets_labelingff(Vars),
	nl).


make_vars(V,S,Size) :-
	lessons_by_decreasing_durations(L),
	size(Size),
	make_vars(L,V,S,Size).
make_vars([],[],[],_).
make_vars([H|T],[[H,D,X]|R],[X|S],Size) :-
	duration(DL),
	nth(H,DL,D),
	allowed(H,A),
	prefered(H,P),
	value(H,V,Size),
	value(all,VA,Size),
	X in (([A])*V)+(([P])*VA),
	make_vars(T,R,S,Size).


no_overlap([_]).
no_overlap([[_,D,X]|T]) :-
	no_overlap(D,X,T),
	no_overlap(T).
no_overlap(_,_,[]).
no_overlap(D1,X1,[[_,D2,X2]|T]) :-
	X1 in ge(add(def(X2),D2))+le(sub(def(X2),D1)),
	X2 in le(sub(def(X1),D2))+ge(add(def(X1),D1)),
	no_overlap(D1,X1,T).


allowed(I,A) :-
	data(D),
	nth(I,D,L),
	allowed(1,L,A).
allowed(_,[],[]).
allowed(N,[a|LD],[N|LA]) :-
	N1 is N+1,
	allowed(N1,LD,LA).
allowed(N,[p|LD],[N|LA]) :-
	N1 is N+1,
	allowed(N1,LD,LA).
allowed(N,[i|LD],LA) :-
	N1 is N+1,
	allowed(N1,LD,LA).


prefered(I,A) :-
	data(D),
	nth(I,D,L),
	prefered(1,L,A).
prefered(_,[],[]).
prefered(N,[p|LD],[N|LA]) :-
	N1 is N+1,
	prefered(N1,LD,LA).
prefered(N,[a|LD],LA) :-
	N1 is N+1,
	prefered(N1,LD,LA).
prefered(N,[i|LD],LA) :-
	N1 is N+1,
	prefered(N1,LD,LA).


value(all,V,T) :- 
	!,
	V is (1<<T)-1.
value(L,V,T) :-
	lessons_by_decreasing_tokens_nb(LL),
	nth(I,LL,L),
	V is ((1<<T)-1) /\ \(1<<(I-1)).












