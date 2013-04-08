/*-------------------------------------------------------------------------*/
/* Title           : N adder diagnostic                                    */
/* Original Source : A. Colmerauer                                         */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : sets (32)                                             */
/*                                                                         */
/* The problem consists in finding the maximal number of non-broken        */
/* components in a N bit adder that thinks 0+2^N-1=0                       */
/* Each adder consists of 5 gates (2 'and', 2 'xor' and 1 'or').           */
/*-------------------------------------------------------------------------*/

:- main.


t(N) :-
	fd_vector_max(1),
	N<6,

	statistics(runtime,_),
	bt_reset,	
	diag_cstrs(N,0,1,0,Vars),
	sets_max_sol(Vars),
	blevel(Vars,Value),
	num_bitnb(Value,Nb),
	statistics(runtime,[_,Time]),
	bt_get(Backtracks),
	
	write('Backtracks: '),
	write(Backtracks),nl,
	write('Time: '),
	write(Time),nl,
	write('Solution: '),
	write(Nb),nl,
	halt_or_else(0,true).


diag_cstrs(N,X,Y,Z,Vars) :-
	all(All,N),
	length(Xs,N),
	interval_domain(Xs,X,X,All),
	length(Ys,N),
	interval_domain(Ys,Y,Y,All),
	length(Zs,N),
	interval_domain(Zs,Z,Z,All),
	N1 is N+1,
	length(Cs,N1),
	interval_domain(Cs,0,1,All),
	Cs = [C1|_],
	last(Cs,C),
	interval_domain([C,C1],0,0,All),
	adder(Xs,Ys,Zs,N,0,Cs,Us),
	append([Us,Cs,Xs,Ys,Zs],Vars).
	

all(All,N) :-
	All is 1<<(N*5)-1.


adder([],[],[],_,_,_,[]).
adder([X|Xs],[Y|Ys],[Z|Zs],N,P,[Ci,C|Cs],Ul):-
	fullAdder(N,P,X,Y,Ci,Z,C,U),
	P1 is P+1,
	adder(Xs,Ys,Zs,N,P1,[C|Cs],Us),
	append(U,Us,Ul).


value(DontWork,N,P,Q) :-
	all(All,N),
	DontWork is All /\ \(1<<(5*P+Q)).


fullAdder(N,P,X,Y,C1,Z,C,[U1,U2,U3]):-
	all(All,N),
	value(V0,N,P,0),
	'x=y and z:(a;b)'(U1,X,Y,All,V0),
	value(V1,N,P,1),
	'x=y and z:(a;b)'(U2,U3,C1,All,V1),
	value(V2,N,P,2),
	'x=y or z:(a;b)'(C,U1,U2,All,V2),
	value(V3,N,P,3),
	'x=y xor z:(a;b)'(U3,X,Y,All,V3),
	value(V4,N,P,4),
	'x=y xor z:(a;b)'(Z,U3,C1,All,V4).







