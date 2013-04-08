/*-------------------------------------------------------------------------*/
/* Title           : crypt-arithmetic                                      */
/* Original Source : Daniel Diaz - INRIA France                            */
/* Adapted by      : Yan Georget                                           */
/* Semiring used   : bool                                                  */
/*                                                                         */
/* Solve the operation:                                                    */
/*                                                                         */
/*    D O N A L D                                                          */
/*  + G E R A L D                                                          */
/*  --------------                                                         */
/*  = R O B E R T                                                          */
/*                                                                         */
/* (resolution by line)                                                    */
/*                                                                         */
/* Solution:                                                               */
/*  [D,O,N,A,L,G,E,R,B,T]                                                  */
/*  [5,2,6,4,8,1,9,7,3,0]                                                  */
/*-------------------------------------------------------------------------*/

:- main.

q:-	statistics(runtime,_),
	donald(L),
	bool_labelingff(L),
	statistics(runtime,[_,Time]),
	write(L), nl,
	write('time : '), write(Time), nl.



donald(LD):-
	LD=[D,O,N,A,L,G,E,R,B,T],
	bool_alldifferent(LD),
	interval_domain(LD,0,9),
	interval_domain([D,G],1,9),

	   100000*D+10000*O+1000*N+100*A+10*L+D +
	   100000*G+10000*E+1000*R+100*A+10*L+D
	#= 100000*R+10000*O+1000*B+100*E+10*R+T.


:- q.
