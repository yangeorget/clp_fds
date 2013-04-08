/*-------------------------------------------------------------------------*/
/* Title           : conference                                            */
/* Original Source : Implementing Constraint Relaxation over FD using ATMS */
/*                   Jussien & Boizumault                                  */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : fuzzy (small)                                         */
/*-------------------------------------------------------------------------*/

:- main.


conference([Ma,Mj,Am,Jm]) :-
	interval_domain([Ma,Mj,Am,Jm],0,3,3),
	
	'x>y:(a;b)'(Ma,Am,3,0),
	'x>y:(a;b)'(Ma,Jm,3,0),
	'x>y:(a;b)'(Mj,Am,3,0),
	'x>y:(a;b)'(Mj,Jm,3,0),
	
	'x<>c:(a;b)'(Ma,3,3,2),
	'x<>c:(a;b)'(Mj,3,3,2),
	'x<>c:(a;b)'(Am,3,3,2),
	'x<>c:(a;b)'(Jm,3,3,2),

	'x<>y:(a;b)'(Ma,Mj,3,1),
	
	'x<>y'(Ma,Am),
	'x<>y'(Ma,Jm),
	'x<>y'(Mj,Am),
	'x<>y'(Mj,Jm),
	'x<>y'(Am,Jm).


t :-
	fd_vector_max(3),
	statistics(runtime,_),
	conference(L),
	max_sol(L),
	write(L),nl,
	statistics(runtime,[_,Time]),
	write('time: '), write(Time), nl,
	halt_or_else(0,true).


:- t.

