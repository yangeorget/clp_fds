/*-------------------------------------------------------------------------*/
/* Title          : N-queens problem                                       */
/* Original Source: P. Van Hentenryck's book                               */
/* Adapted by     : Yan Georget                                            */
/* Semiring       : sets (32)                                              */
/*                                                                         */
/* Put N queens on an NxN chessboard so that there is no couple of queens  */
/* threatening each other.                                                 */
/*-------------------------------------------------------------------------*/

:- main.


q(N) :-
	N < 28, 
	queens(L,N),
	mk_values(Values,N), % generate starting values
	write('Starting values: '), write(Values),nl,
	
	bt_reset,
	wcs(L,Values), % uses the Weak-Commitment Search (Makoto Yokoo) 
	bt_get(B),

	write('Solution: '),write(L),nl,
	write('Backtracks: '), write(B),nl.



mk_values(Values,N) :-
	length(Values,N),
	O is N-2,  % choose an offset
	mk_values(Values,0,O,N).
mk_values([],_,_,_).
mk_values([V|Vs],S,O,N) :-
	V is S+1,
	S1 is (S+O) mod N,
	mk_values(Vs,S1,O,N).



% problem description	
queens(L,N) :-
	fd_vector_max(N),
	length(L,N),
	interval_domain(L,1,N),
	safe(L).

safe([]).
safe([X|L]):-
	noattack(L,X,1),
	safe(L).

noattack([],_,_).
noattack([Y|L],X,I):-
	X in dpmc(def(Y),I),
	Y in dpmc(def(X),I),
	I1 is I+1,
	noattack(L,X,I1).




