/*-------------------------------------------------------------------------*/
/* Title           : robot                                                 */
/* Original Source : Ruttkay, Fuzzy Constraint Satisfaction                */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : fuzzy (big)                                           */
/*                                                                         */
/* Find clothes for a robot                                                */
/*-------------------------------------------------------------------------*/

:- main.


robot([F,T,S]) :-
	interval_domain([F,S],0,1,10),
	interval_domain([T],0,2,10),
	
	relation([([0,0],10),([0,1],4),([0,2],2),([1,2],8),([1,1],5)],[F,T]),
	relation([([0,1],10),([0,0],7),([1,0],10),([1,1],1)],[F,S]),
	relation([([0,0],10),([0,1],7),([1,0],10),([1,1],4),
                  ([2,1],10),([2,0],6)],[T,S]).


t :-
	fd_vector_max(5),
	statistics(runtime,_),
	robot(L),
	max_sol(L),
	write(L),nl,
	statistics(runtime,[_,Time]),
	write('time: '), write(Time), nl,
	halt_or_else(0,true).


:- t.
