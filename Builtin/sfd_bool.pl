/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler                INRIA Rocquencourt - LOCO Project */
/* Built-In Predicates                                  Yan Georget - 1998 */
/*                                                                         */
/* sfd_bool.pl                                                             */
/*-------------------------------------------------------------------------*/


:- public 'x=not y:(a;b)'/4, 'x=not y'/2.

'x=not y:(a;b)'(X,Y,A,B) :-
	X in (0..1)*A,
	Y in (0..1)*A,
	X in not(def(Y))+(sigma(Y)*B),
	Y in not(def(X))+(sigma(X)*B).

'x=not y'(X,Y) :-
	X in 0..1,
	Y in 0..1,
	X in not(def(Y)),
	Y in not(def(X)).


:- public 'x=y and z:(a;b)'/5, 'x=y and z'/3.

'x=y and z:(a;b)'(X,Y,Z,A,B) :-
	X in (0..1)*A,
	Y in (0..1)*A,
	Z in (0..1)*A,
	X in and_r(def(Y),def(Z))+(sigma(Y)*sigma(Z)*B),
	Y in and_a(def(X),def(Z))+(sigma(X)*sigma(Z)*B),
	Z in and_a(def(X),def(Y))+(sigma(X)*sigma(Y)*B).

'x=y and z'(X,Y,Z) :-
	X in 0..1,
	Y in 0..1,
	Z in 0..1,
	X in and_r(def(Y),def(Z)),
	Y in and_a(def(X),def(Z)),
	Z in and_a(def(X),def(Y)).


:- public 'x=y or z:(a;b)'/5, 'x=y or z'/3.

'x=y or z:(a;b)'(X,Y,Z,A,B) :-
	X in (0..1)*A,
	Y in (0..1)*A,
	Z in (0..1)*A,
	X in or_r(def(Y),def(Z))+(sigma(Y)*sigma(Z)*B),
	Y in or_a(def(X),def(Z))+(sigma(X)*sigma(Z)*B),
	Z in or_a(def(X),def(Y))+(sigma(X)*sigma(Y)*B).

'x=y or z'(X,Y,Z) :-
	X in 0..1,
	Y in 0..1,
	Z in 0..1,
	X in or_r(def(Y),def(Z)),
	Y in or_a(def(X),def(Z)),
	Z in or_a(def(X),def(Y)).


:- public 'x=y xor z:(a;b)'/5, 'x=y xor z'/3.

'x=y xor z:(a;b)'(X,Y,Z,A,B) :-
	X in (0..1)*A,
	Y in (0..1)*A,
	Z in (0..1)*A,
	X in xor_r(def(Y),def(Z))+(sigma(Y)*sigma(Z)*B),
	Y in xor_a(def(X),def(Z))+(sigma(X)*sigma(Z)*B),
	Z in xor_a(def(X),def(Y))+(sigma(X)*sigma(Y)*B).

'x=y xor z'(X,Y,Z) :-
	X in 0..1,
	Y in 0..1,
	Z in 0..1,
	X in xor_r(def(Y),def(Z)),
	Y in xor_a(def(X),def(Z)),
	Z in xor_a(def(X),def(Y)).




:- public and/2, or/2.

and([],And) :-
	And in sing(1).
and([D],And) :- 
	!,
	'x=y'(D,And). 
and([D|Ds],And1) :-
	and(Ds,And),
	'x=y and z'(And1,D,And).
	
or([],Or) :-
	Or in sing(0).
or([D],Or) :- 
	!,
	'x=y'(D,Or).
or([D|Ds],Or1) :-
	or(Ds,Or),
	'x=y or z'(Or1,D,Or).
	





