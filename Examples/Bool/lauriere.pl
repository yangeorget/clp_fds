/*-------------------------------------------------------------------------*/
/* Title           : lauriere's product                                    */
/* Original Source : J.L. Lauriere                                         */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Solve the operation:                                                    */
/*         X1  X2  X3                                                      */
/*      *  X4  X5  X6                                                      */
/*      -------------                                                      */
/*         X7  X8  X9                                                      */
/*     X10 X11 X12                                                         */
/* X13 X14 X15                                                             */
/* ------------------                                                      */
/* X16 X17 X18 X19 X20                                                     */
/*                                                                         */
/* using each digit (in 0..9) exactly twice.                               */
/*                                                                         */
/* Unique solution: (resolution by line)                                   */
/* [1,7,9,2,2,2,4,7,1,6,3,5,8,3,5,8,4,0,0,9,6]                             */
/*-------------------------------------------------------------------------*/

:- main.

q:-     statistics(runtime,_),
        lauriere(L), 
	bool_labelingff(L),
	statistics(runtime,[_,Time]), 
        write(L), nl,
        write('time : '), write(Time), nl.


lauriere(LD):-
	fd_vector_max(9),
	LD=[X1,X2,X3,X4,X5,X6,X7,X8,X9,X10,
            X11,X12,X13,X14,X15,X16,X17,X18,X19,X20],

	interval_domain(LD,0,9),

	exactly(2,LD,0),
	exactly(2,LD,1),
	exactly(2,LD,2),
	exactly(2,LD,3),
	exactly(2,LD,4),
	exactly(2,LD,5),
	exactly(2,LD,6),
	exactly(2,LD,7),
	exactly(2,LD,8),
	exactly(2,LD,9),

	Y  #= 100*X1+10*X2+X3,

	Z1 #= 100*X7 +10*X8 +X9,
	Z2 #= 100*X10+10*X11+X12,
	Z3 #= 100*X13+10*X14+X15,

	'pac xy=z'(Y,X6,Z1),
	'pac xy=z'(Y,X5,Z2),
	'pac xy=z'(Y,X4,Z3),

	                   100*X7 +10*X8 +X9 + 
                  1000*X10+100*X11+10*X12    + 
        10000*X13+1000*X14+100*X15          #= 
        10000*X16+1000*X17+100*X18+10*X19+X20.



:- q.
