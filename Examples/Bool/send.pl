/*-------------------------------------------------------------------------*/
/* Title           : crypt-arithmetic                                      */
/* Original Source : P. Van Hentenryck's book                              */
/* Adapted by      : Yan Georget                                           */
/* Semiring used   : bool                                                  */
/*                                                                         */
/* Solve the operation:                                                    */
/*                                                                         */
/*      S E N D                                                            */
/*  +   M O R E                                                            */
/*  -----------                                                            */
/*  = M O N E Y                                                            */
/*                                                                         */
/* (resolution by line)                                                    */
/*                                                                         */
/* Solution:                                                               */
/*  [S,E,N,D,M,O,R,Y]                                                      */
/*  [9,5,6,7,1,0,8,2]                                                      */
/*-------------------------------------------------------------------------*/

:- main.

q:-	statistics(runtime,_),
	send(L), 
	bool_labelingff(L),
	statistics(runtime,[_,Time]),
	write(L), nl,
	write('time : '), write(Time), nl.



send(LD):-
	LD=[S,E,N,D,M,O,R,Y],
	bool_alldifferent(LD),
	interval_domain(LD,0,9),
	interval_domain([S,M],1,9),

	   1000*S+100*E+10*N+D + 1000*M+100*O+10*R+E 
	#= 10000*M+1000*O+100*N+10*E+Y.


:- q.