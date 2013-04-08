/*-------------------------------------------------------------------------*/
/* Title           : crypt-arithmetic                                      */
/* Original Source : P. Van Hentenryck's book                              */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Solve the operation:                                                    */
/*                                                                         */
/*      S E N D                                                            */
/*  +   M O R E                                                            */
/*  -----------                                                            */
/*  = M O N E Y                                                            */
/*                                                                         */
/* Solution: (resolution by column)                                        */
/*  [S,E,N,D,M,O,R,Y]                                                      */
/*  [9,5,6,7,1,0,8,2]                                                      */
/*-------------------------------------------------------------------------*/
 
:- main.
 
t:-	
	fd_vector_max(31),
	
	statistics(runtime,_),
	send(L),
	bool_labelingff(L),
	statistics(runtime,[_,Time]),
	
	write(L),nl,
	write('Time: '),write(Time),nl.


send(LD):-
	LD=[S,E,N,D,M,O,R,Y],
	LR=[R1,R2,R3,R4],
		
	interval_domain(LD,0,9),
	interval_domain(LR,0,1),
	interval_domain([S,M],1,9),

	bool_alldifferent(LD),

	R1     #= M,
	R2+S+M #= O+10*R1,
	R3+E+O #= N+10*R2,
	R4+N+R #= E+10*R3,
	D+E    #= Y+10*R4.


:- t.
