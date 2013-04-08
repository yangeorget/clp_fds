/*-------------------------------------------------------------------------*/
/* Title           : quasigroups                                           */
/* Created by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Find the quasigroups satisfying the given algebraic relations           */
/*-------------------------------------------------------------------------*/

:- main.



qg(Num,N) :-
	g_assign(size,N),
	N2 is N*N,
	fd_vector_max(N2),
	length(ML,N),
	ll_length(ML,N),
	lines_to_columns(ML,MC),
	append(ML,L),
	interval_domain(L,1,N),
	g_link(relation,L),
    
	latin_square_cstrs(ML,MC),
	isomorphic_cstrs(MC),
	idempotence_cstrs(1,ML),
	algebraic_cstrs(Num),

	bt_reset,
	bool_labelingff(L),
	matrix_write(ML).
qg(_,_) :-
	write('No (more) solution.'),
	nl,
	bt_get(Backtracks),
	write(Backtracks), write(' backtracks.'),nl.



latin_square_cstrs(ML,MC) :-
	ll_alldifferent(ML),
	ll_alldifferent(MC).

ll_alldifferent([]).
ll_alldifferent([X|L]) :-
	bool_global_alldifferent(X),
	ll_alldifferent(L).



isomorphic_cstrs(MC) :- % to cut the search space
	last(MC,C),
	isc(C,0).

isc([],_).
isc([V|C],Inf) :-
	V in Inf..infinity,
	Inf1 is Inf+1,
	isc(C,Inf1).



idempotence_cstrs(I,ML) :- % the values on the diagonal are known
	nth(I,ML,L),
	nth(I,L,I),        % ie ML_{I,I} = I 
	g_read(size,N),
	(I =\= N
    ->
	I1 is I+1,
	idempotence_cstrs(I1,ML)
    ; 
	true).



% only the non-trivial cases (ie X<>Y)
algebraic_cstrs(0).
algebraic_cstrs(3) :-
	GY = (X =\= Y -> p(X,Y,XY),p(Y,X,YX),p(XY,YX,X) ; true), 
	GX = for_all(Y,GY),
	for_all(X,GX).
algebraic_cstrs(4) :-
	GY = (X =\= Y -> p(Y,X,YX),p(X,Y,XY),p(YX,XY,X) ; true), 
	GX = for_all(Y,GY),
	for_all(X,GX).
algebraic_cstrs(5) :-
	GY = (X =\= Y -> p(Y,X,YX),p(YX,Y,YXY),p(YXY,Y,X) ; true), 
	GX = for_all(Y,GY),
	for_all(X,GX).
algebraic_cstrs(6) :-
	GY = (X =\= Y -> p(X,Y,XY),p(XY,Y,P),p(X,XY,P) ; true), 
	GX = for_all(Y,GY),
	for_all(X,GX).
algebraic_cstrs(7) :-
	GY = (X =\= Y -> p(Y,X,YX),p(YX,Y,P),p(X,YX,P) ; true), 
	GX = for_all(Y,GY),
	for_all(X,GX).

:- public for_all/2.
for_all(X,G) :-
	g_read(size,N),
	cfor(X,1,N,G).

cfor(X,S,E,G) :-
	S =< E,
	(S == E
    ->
	X = S,
	G
    ; 
	copy_term((X,G),(X1,G1)),
	X1 = S,
	G1,
	S1 is S+1,
	cfor(X,S1,E,G)).

p(I,J,IJ) :-
	integer(I),
	integer(J),
	!,
	g_read(relation,R),
	g_read(size,N),
	K is N*(I-1) + J,
	nth(K,R,IJ).
p(I,J,IJ) :-
	g_read(relation,R),
	g_read(size,N),
	'x=y+c'(I,I1,1),
	'x=ny+z'(K,N,I1,J),
	v_element(K,R,IJ).

'x=ny+z'(X,N,Y,Z) :-
	X in add(mul(def(Y),N),def(Z)),
	Y in div(sub(def(X),def(Z)),N),
	Z in sub(def(X),mul(def(Y),N)).

'pac x=ny+z'(X,N,Y,Z) :-
	X #= N*Y + Z.



matrix_write([]).
matrix_write([L|LL]) :-
	write(L),nl,
	matrix_write(LL).









