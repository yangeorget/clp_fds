/*-------------------------------------------------------------------------*/
/* Title           : five houses problem                                   */
/* Original source : Pascal Van Hentenryck's book                          */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Solution:                                                               */
/*  [N1,N2,N3,N4,N5,     [3,4,5,2,1,                                       */
/*   C1,C2,C3,C4,C5,      5,3,1,2,4,                                       */
/*   P1,P2,P3,P4,P5,      5,1,4,2,3,                                       */
/*   A1,A2,A3,A4,A5,      4,5,1,3,2,                                       */
/*   D1,D2,D3,D4,D5]      4,1,2,5,3]                                       */
/*-------------------------------------------------------------------------*/

:- main.


t :-
	fd_vector_max(5),
	statistics(runtime,_),
	five_houses(L),
	bool_labeling(L),
	statistics(runtime,[_,Time]),
	write('time : '), write(Time), nl,
	write(L),nl.


five_houses(L):-
	L=[N1,N2,N3,N4,N5,
	C1,C2,C3,C4,C5,
	P1,P2,P3,P4,P5,
	A1,A2,A3,A4,A5,
	D1,D2,D3,D4,D5],

	interval_domain(L,1,5),

	N5 = 1,
	D5 = 3,

	bool_alldifferent([C1,C2,C3,C4,C5]),
	bool_alldifferent([P1,P2,P3,P4,P5]),
	bool_alldifferent([N1,N2,N3,N4,N5]),
	bool_alldifferent([A1,A2,A3,A4,A5]),
	bool_alldifferent([D1,D2,D3,D4,D5]),

	'x=y'(N1,C2),
	'x=y'(N2,A1),
	'x=y'(N3,P1),
	'x=y'(N4,D3),
    	'x=y'(N3,P1),
	'x=y'(P3,D1),
	'x=y'(C1,D4),
	'x=y'(P5,A4),
	'x=y'(P2,C3),
	'x=y+c'(C1,C5,1),

	plus_or_minus(A3,P4,1),
	plus_or_minus(A5,P2,1),
	plus_or_minus(N5,C4,1).


plus_or_minus(X,Y,C):-      % constructive disjunction
	X in (add(def(Y),C))+(sub(def(Y),C)),
	Y in (add(def(X),C))+(sub(def(X),C)).


:- t.



