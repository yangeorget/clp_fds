/*-------------------------------------------------------------------------*/
/* Title          : N-queens problem                                       */
/* Original Source: P. Van Hentenryck's book                               */
/* Adapted by     : Yan Georget                                            */
/* Semiring       : bool                                                   */
/*                                                                         */
/* Put N queens on an NxN chessboard so that there is no couple of queens  */
/* threatening each other.                                                 */
/*-------------------------------------------------------------------------*/


% available options:                                              
%     std   = first variable, first value
%     ff    = first fail    , first value
% these options are available both for single model and multi models


:- main.


/* multi-models */
mmq(N,O) :-
	queens(N,L),
	queens(N,C),
	communicate(L,C),
	append(L,C,V),
	bt_reset,
	labeling(V,O),
	bt_get(B),
	statistics(runtime,[_,T]),
	infos(L,O,B,T).


/* single model */
q(N,O):-	
	queens(N,L),
	statistics(runtime,_),
	bt_reset,
	labeling(L,O),
	bt_get(B),
	statistics(runtime,[_,T]),
	infos(L,O,B,T).


infos(L,O,B,T) :-
	write(L),nl,
	write('Option: '), write(O),nl,
	write('Backtracks: '), write(B),nl,
	write('Time: '), write(T), nl.


/* constraints */
queens(N,L) :-
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
	X in comp(val(Y)),
	X in comp(add(val(Y),I)),
	X in comp(sub(val(Y),I)),
	Y in comp(val(X)),
	Y in comp(add(val(X),I)),
	Y in comp(sub(val(X),I)),
	I1 is I+1,
	noattack(L,X,I1).


communicate(L,C) :-
	communicate(L,C,1).
communicate([],_,_).
communicate([L|Ls],C,I) :-
	communicate(C,L,1,I),
	I1 is I+1,
	communicate(Ls,C,I1).
communicate([],_,_,_).
communicate([C|Cs],L,J,I) :-
	'b <=> x=c'(B,L,J),
	'b <=> x=c'(B,C,I),
	J1 is J+1,
	communicate(Cs,L,J1,I).


/* labelings */
labeling(L,std) :-
	bool_labeling(L).
labeling(L,ff) :-
	bool_labelingff(L).

	

