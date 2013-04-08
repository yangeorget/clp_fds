/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Built-In: FD predicates                                                 */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_arithmetic_complex.pl                                               */
/*-------------------------------------------------------------------------*/


:- public alldifferent/1, out_of/2.

alldifferent([]).
alldifferent([X|L]):-
	out_of(L,X),
	alldifferent(L).

out_of([],_).
out_of([Y|L],X):-
	'x<>y'(X,Y),
	out_of(L,X).



:- public decreasing/1, increasing/1, 
	  strictly_decreasing/1, strictly_increasing/1,
	  sum/2, choose/2, min/2, max/2.

increasing([]).
increasing([_]) :-
	!.
increasing([X,Y|L]) :-
	Y #>= X,
	increasing([Y|L]).


decreasing([]).
decreasing([_]) :-
	!.
decreasing([X,Y|L]) :-
	X #>= Y,
	decreasing([Y|L]).

 
strictly_increasing([]).
strictly_increasing([_]) :-
	!.
strictly_increasing([X,Y|L]) :-
	Y #> X,
	strictly_increasing([Y|L]).


strictly_decreasing([]).
strictly_decreasing([_]) :-
	!.
strictly_decreasing([X,Y|L]) :-
	X #> Y,
	strictly_decreasing([Y|L]).
 

sum([],Sum) :-
	Sum in sing(0).
sum([X],Sum) :- 
	!,
	'pac x=y'(X,Sum). 
sum([X,Y|L],Sum) :-
	!,
	sum([Y|L],Sum1),
	'pac x+y=z'(X,Sum1,Sum). 


choose([Y],X) :-
	!,
	'x=y'(X,Y).
choose([Y|Ys],X) :-
	choose(Ys,Z),
	'x=choose(y,z)'(X,Y,Z).


min([Y],X) :-
	!,
	'x=y'(X,Y).
min([Y|Ys],X) :-
	min(Ys,Z),
	'x=min(y,z)'(X,Y,Z).


max([Y],X) :-
	!,
	'x=y'(X,Y).
max([Y|Ys],X) :-
	max(Ys,Z),
	'x=max(y,z)'(X,Y,Z).

