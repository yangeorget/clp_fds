/*-------------------------------------------------------------------------*/
/* Title           : alphacipher                                           */
/* Original source : newsgroup rec.puzzle                                  */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Solution:                                                               */
/*  [A, B,C, D, E,F, G, H, I, J, K,L,M, N, O, P,Q, R, S,T,U, V,W, X, Y, Z] */
/*  [5,13,9,16,20,4,24,21,25,17,23,2,8,12,10,19,7,11,15,3,1,26,6,22,14,18] */
/*-------------------------------------------------------------------------*/

:- main.

q:- 
	statistics(runtime,_),
	alpha(L),
	bool_labelingff(L),
	statistics(runtime,[_,Time]),
	write('time : '), write(Time), nl,
	write(L), nl.



alpha(LD):-
	LD=[A,B,C,_D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z],
	interval_domain(LD,1,26),
	bool_alldifferent(LD),
	
	B+A+L+L+E+T       #= 45,
	C+E+L+L+O         #= 43,
	C+O+N+C+E+R+T     #= 74,
	F+L+U+T+E         #= 30,
	F+U+G+U+E         #= 50,
	G+L+E+E           #= 66,
	J+A+Z+Z           #= 58,
	L+Y+R+E           #= 47,
	O+B+O+E           #= 53,
	O+P+E+R+A         #= 65,
	P+O+L+K+A         #= 59,
	Q+U+A+R+T+E+T     #= 50,
	S+A+X+O+P+H+O+N+E #= 134,
	S+C+A+L+E         #= 51,
	S+O+L+O           #= 37,
	S+O+N+G           #= 61,
	S+O+P+R+A+N+O     #= 82,
	T+H+E+M+E         #= 72,
	V+I+O+L+I+N       #= 100,
	W+A+L+T+Z         #= 34.

:- q.


