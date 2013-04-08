/*-------------------------------------------------------------------------*/
/* Title           : menu                                                  */
/* Original Source : ConFlex distribution                                  */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : fuzzy (8)                                             */
/*                                                                         */
/* LP example                                                              */
/*-------------------------------------------------------------------------*/
:- main.


q :-
	fd_vector_max(115),

	interval_domain([X1], 10,40),
	interval_domain([X2], 0, 50),
	sparse_domain([Z],
[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115],
[115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0]),
	
	6*X1 + 5*X2 #>= 300,
	3*X1 + 4*X2 #>= 200,
	2*X1 + X2 #>= 70,
	5*X1 +  2*X2 #<= 200,
	20*Z #= 25*X1 + 26*X2,

	statistics(runtime,_),
	max_sol([Z,X1,X2]),
	write([Z,X1,X2]),nl,
	statistics(runtime,[_,Time]),
	write('time: '), 
	write(Time), nl,
	halt_or_else(0,true).

:- q.


