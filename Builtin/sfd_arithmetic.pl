/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Built-In: FD predicates                                                 */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_arithmetic.pl                                                       */
/*-------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------*/
/* Full Arc-Consistency                                                    */
/*-------------------------------------------------------------------------*/


:- public 'x=choose(y,z)'/3, 'x=choose(y,z):(a;b)'/5.
'x=choose(y,z)'(X,Y,Z):-
	X in def(Y)+def(Z),
	'b <=> x=y'(B1,X,Y),
	'b <=> x=y'(B2,X,Z),
	'x=y or z'(1,B1,B2).

'x=choose(y,z):(a;b)'(X,Y,Z,A,B):-
	X in (0..infinity)*A,
	X in (def(Y)+def(Z))+(sigma(Y)*sigma(Z)*B),
	'b <=> x=y'(B1,X,Y),
	'b <=> x=y'(B2,X,Z),
	'x=y or z:(a;b)'(1,B1,B2,A,B).



:- public 'x=min(y,z)'/3, 'x=min(y,z):(a;b)'/5.
'x=min(y,z)'(X,Y,Z):-
	'x>=y'(Y,X),
	'x>=y'(Z,X),
	'x=choose(y,z)'(X,Y,Z).

'x=min(y,z):(a;b)'(X,Y,Z,A,B):-
	'x>=y:(a;b)'(Y,X,A,B),
	'x>=y:(a;b)'(Z,X,A,B),
	'x=choose(y,z):(a;b)'(X,Y,Z,A,B).



:- public 'x=max(y,z)'/3, 'x=max(y,z):(a;b)'/5.
'x=max(y,z)'(X,Y,Z):-
	'x>=y'(X,Y),
	'x>=y'(X,Z),
	'x=choose(y,z)'(X,Y,Z).

'x=max(y,z):(a;b)'(X,Y,Z,A,B):-
	'x>=y:(a;b)'(X,Y,A,B),
	'x>=y:(a;b)'(X,Z,A,B),
	'x=choose(y,z):(a;b)'(X,Y,Z,A,B).



:- public 'x=c:(a;b)'/4, 'x=c'/2.
'x=c:(a;b)'(X,C,A,B) :-
	X in (sing(C)+B)*A.
'x=c'(X,C) :-
	X in sing(C).



:- public 'x<>c:(a;b)'/4, 'x<>c'/2.
'x<>c:(a;b)'(X,C,A,B) :-
	X in (comp(C)+B)*A.
'x<>c'(X,C) :-
	X in comp(C).



:- public 'x<>y:(a;b)'/4, 'x<>y'/2.
'x<>y:(a;b)'(X,Y,A,B) :- 
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in d(def(Y))+(sigma(Y)*B),
	Y in d(def(X))+(sigma(X)*B).
'x<>y'(X,Y) :- 
	X in d(def(Y)),
	Y in d(def(X)).



:- public 'x=y:(a;b)'/4, 'x=y'/2.
'x=y:(a;b)'(X,Y,A,B) :- 
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in def(Y)+(sigma(Y)*B),
	Y in def(X)+(sigma(X)*B).
'x=y'(X,Y) :- 
	X in def(Y),
	Y in def(X).



:- public 'x>y:(a;b)'/4, 'x>y'/2.
'x>y:(a;b)'(X,Y,A,B) :- 
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in g(def(Y))+(sigma(Y)*B),
	Y in l(def(X))+(sigma(X)*B).
'x>y'(X,Y) :- 
	X in g(def(Y)),
	Y in l(def(X)).	



:- public 'x>=y:(a;b)'/4, 'x>=y'/2.
'x>=y:(a;b)'(X,Y,A,B) :- 
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in ge(def(Y))+(sigma(Y)*B),
	Y in le(def(X))+(sigma(X)*B).
'x>=y'(X,Y) :- 
	X in ge(def(Y)),
	Y in le(def(X)).
	


:- public 'x=y+c:(a;b)'/5, 'x=y+c'/3.
'x=y+c:(a;b)'(X,Y,C,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in add(def(Y),C)+(sigma(Y)*B),
	Y in sub(def(X),C)+(sigma(X)*B).
'x=y+c'(X,Y,C) :-
	X in add(def(Y),C),
	Y in sub(def(X),C).

	
	
:- public 'x>y+c:(a;b)'/5, 'x>y+c'/3.
'x>y+c:(a;b)'(X,Y,C,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in g(add(def(Y),C))+(sigma(Y)*B),
	Y in l(sub(def(X),C))+(sigma(X)*B).
'x>y+c'(X,Y,C) :-
	X in g(add(def(Y),C)),
	Y in l(sub(def(X),C)).



:- public 'x>=y+c:(a;b)'/5, 'x>=y+c'/3.
'x>=y+c:(a;b)'(X,Y,C,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in ge(add(def(Y),C))+(sigma(Y)*B),
	Y in le(sub(def(X),C))+(sigma(X)*B).
'x>=y+c'(X,Y,C) :-
	X in ge(add(def(Y),C)),
	Y in le(sub(def(X),C)).
	


:- public 'x=y+z:(a;b)'/5, 'x=y+z'/3.
'x=y+z:(a;b)'(X,Y,Z,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Z in (0..infinity)*A,
	X in add(def(Y),def(Z))+(sigma(Y)*sigma(Z)*B),
	Y in sub(def(X),def(Z))+(sigma(X)*sigma(Z)*B),
	Z in sub(def(X),def(Y))+(sigma(X)*sigma(Y)*B).
'x=y+z'(X,Y,Z) :-
	X in add(def(Y),def(Z)),
	Y in sub(def(X),def(Z)),
	Z in sub(def(X),def(Y)).



:- public 'x>y+z:(a;b)'/5, 'x>y+z'/3.
'x>y+z:(a;b)'(X,Y,Z,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Z in (0..infinity)*A,
	X in g(add(def(Y),def(Z)))+(sigma(Y)*sigma(Z)*B),
	Y in l(sub(def(X),def(Z)))+(sigma(X)*sigma(Z)*B),
	Z in l(sub(def(X),def(Y)))+(sigma(X)*sigma(Y)*B).
'x>y+z'(X,Y,Z) :-
	X in g(add(def(Y),def(Z))),
	Y in l(sub(def(X),def(Z))),
	Z in l(sub(def(X),def(Y))).
			


:- public 'x>=y+z:(a;b)'/5, 'x>=y+z'/3.
'x>=y+z:(a;b)'(X,Y,Z,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Z in (0..infinity)*A,
	X in ge(add(def(Y),def(Z)))+(sigma(Y)*sigma(Z)*B),
	Y in le(sub(def(X),def(Z)))+(sigma(X)*sigma(Z)*B),
	Z in le(sub(def(X),def(Y)))+(sigma(X)*sigma(Y)*B).
'x>=y+z'(X,Y,Z) :-
	X in ge(add(def(Y),def(Z))),
	Y in le(sub(def(X),def(Z))),
	Z in le(sub(def(X),def(Y))).



:- public 'x=cy:(a;b)'/5, 'x=cy'/3.
'x=cy:(a;b)'(X,C,Y,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in mul(def(Y),C)+(sigma(Y)*B),
	Y in div(def(X),C)+(sigma(X)*B).
'x=cy'(X,C,Y) :-
	X in mul(def(Y),C),
	Y in div(def(X),C).



:- public 'x>cy:(a;b)'/5, 'x>cy'/3.
'x>cy:(a;b)'(X,C,Y,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in g(mul(def(Y),C))+(sigma(Y)*B),
	Y in l(div(def(X),C))+(sigma(X)*B).
'x>cy'(X,C,Y) :-
	X in g(mul(def(Y),C)),
	Y in l(div(def(X),C)).



:- public 'x>=cy:(a;b)'/5, 'x>=cy'/3.
'x>=cy:(a;b)'(X,C,Y,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	X in ge(mul(def(Y),C))+(sigma(Y)*B),
	Y in le(div(def(X),C))+(sigma(X)*B).
'x>=cy'(X,C,Y) :-
	X in ge(mul(def(Y),C)),
	Y in le(div(def(X),C)).



:- public 'x=yz:(a;b)'/5, 'x=yz'/3.
'x=yz:(a;b)'(X,Y,Z,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Z in (0..infinity)*A,
	X in mul(def(Y),def(Z))+(sigma(Y)*sigma(Z)*B),
	Y in div(def(X),def(Z))+(sigma(X)*sigma(Z)*B),
	Z in div(def(X),def(Y))+(sigma(X)*sigma(Y)*B).
'x=yz'(X,Y,Z) :-
	X in mul(def(Y),def(Z)),
	Y in div(def(X),def(Z)),
	Z in div(def(X),def(Y)).



:- public 'x>yz:(a;b)'/5, 'x>yz'/3.
'x>yz:(a;b)'(X,Y,Z,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Z in (0..infinity)*A,
	X in g(mul(def(Y),def(Z)))+(sigma(Y)*sigma(Z)*B),
	Y in l(div(def(X),def(Z)))+(sigma(X)*sigma(Z)*B),
	Z in l(div(def(X),def(Y)))+(sigma(X)*sigma(Y)*B).
'x>yz'(X,Y,Z) :-
	X in g(mul(def(Y),def(Z))),
	Y in l(div(def(X),def(Z))),
	Z in l(div(def(X),def(Y))).



:- public 'x>=yz:(a;b)'/5, 'x>=yz'/3.
'x>=yz:(a;b)'(X,Y,Z,A,B) :-
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Z in (0..infinity)*A,
	X in ge(mul(def(Y),def(Z)))+(sigma(Y)*sigma(Z)*B),
	Y in le(div(def(X),def(Z)))+(sigma(X)*sigma(Z)*B),
	Z in le(div(def(X),def(Y)))+(sigma(X)*sigma(Y)*B).
'x>=yz'(X,Y,Z) :-
	X in ge(mul(def(Y),def(Z))),
	Y in le(div(def(X),def(Z))),
	Z in le(div(def(X),def(Y))).



/*-------------------------------------------------------------------------*/
/* Partial Arc-Consistency                                                 */
/*-------------------------------------------------------------------------*/


:- public 'pac xy=z'/3.
'pac xy=z'(X,Y,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
        X in ceil_div0(min(Z),max(Y))..floor_div0(max(Z),min(Y)),
        Y in ceil_div0(min(Z),max(X))..floor_div0(max(Z),min(X)),
        Z in mul(min(X),min(Y))..mul(max(X),max(Y)).



/* the following constraints are used in #-expressions: */


% 2 vars
:- public 'pac x=y'/2.
'pac x=y'(X,Y) :-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in min(Y) .. max(Y),
	Y in min(X) .. max(X).



:- public 'pac x<>y'/2.
'pac x<>y'(X,Y) :-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in comp(val(Y)),
	Y in comp(val(X)).



:- public 'pac x>=y'/2.
'pac x>=y'(X,Y):-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in min(Y) .. infinity,
	Y in 0 .. max(X).



:- public 'pac x>y'/2.
'pac x>y'(X,Y):-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in add(min(Y),1) .. infinity,
	Y in 0 .. sub(max(X),1).



:- public 'pac x+c=y'/3.
'pac x+c=y'(X,C,Y):-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in sub(min(Y),C) .. sub(max(Y),C),
	Y in add(min(X),C) .. add(max(X),C).



:- public 'pac ax=y'/3.
'pac ax=y'(A,X,Y):-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in ceil_div(min(Y),A) .. floor_div(max(Y),A),
	Y in mul(min(X),A) .. mul(max(X),A).



:- public 'pac ax+c=y'/4.
'pac ax+c=y'(A,X,C,Y):-
	X in (0..infinity)*sigma(Y),
	Y in (0..infinity)*sigma(X),
	X in ceil_div(sub(min(Y),C),A) .. floor_div(sub(max(Y),C),A),
	Y in add(mul(min(X),A),C) .. add(mul(max(X),A),C).




% 3 vars
:- public 'pac ax+y+c=z'/5.
'pac ax+y+c=z'(A,X,Y,C,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
	X in ceil_div(sub(sub(min(Z),max(Y)),C),A)
             .. floor_div(sub(sub(max(Z),min(Y)),C),A),
	Y in sub(sub(min(Z),mul(A,max(X))),C)
             .. sub(sub(max(Z),mul(A,min(X))),C),
	Z in add(add(mul(A,min(X)),min(Y)),C)
             .. add(add(mul(A,max(X)),max(Y)),C).



:- public 'pac ax+by+c=z'/6.
'pac ax+by+c=z'(A,X,B,Y,C,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
	X in ceil_div(sub(sub(min(Z),mul(max(Y),B)),C),A)
             .. floor_div(sub(sub(max(Z),mul(B,min(Y))),C),A),
	Y in ceil_div(sub(sub(min(Z),mul(A,max(X))),C),B)
             .. floor_div(sub(sub(max(Z),mul(A,min(X))),C),B),
	Z in add(add(mul(A,min(X)),mul(B,min(Y))),C)
             .. add(add(mul(A,max(X)),mul(B,max(Y))),C).



:- public 'pac x+y=z'/3.
'pac x+y=z'(X,Y,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
	X in sub(min(Z),max(Y))..sub(max(Z),min(Y)),
	Y in sub(min(Z),max(X))..sub(max(Z),min(X)),
	Z in add(min(X),min(Y))..add(max(X),max(Y)).



:- public 'pac ax+y=z'/4.
'pac ax+y=z'(A,X,Y,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
	X in ceil_div(sub(min(Z),max(Y)),A)..floor_div(sub(max(Z),min(Y)),A),
	Y in sub(min(Z),mul(A,max(X)))..sub(max(Z),mul(A,min(X))),
	Z in add(mul(A,min(X)),min(Y))..add(mul(A,max(X)),max(Y)).



:- public 'pac x+y+c=z'/4.
'pac x+y+c=z'(X,Y,C,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
	X in sub(sub(min(Z),max(Y)),C)..sub(sub(max(Z),min(Y)),C),
	Y in sub(sub(min(Z),max(X)),C)..sub(sub(max(Z),min(X)),C),
	Z in add(add(min(X),min(Y)),C)..add(add(max(X),max(Y)),C).



:- public 'pac ax+by=z'/5.
'pac ax+by=z'(A,X,B,Y,Z):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)),
	X in ceil_div(sub(min(Z),mul(B,max(Y))),A)
             .. floor_div(sub(max(Z),mul(B,min(Y))),A),
	Y in ceil_div(sub(min(Z),mul(A,max(X))),B)
             .. floor_div(sub(max(Z),mul(A,min(X))),B),
	Z in add(mul(A,min(X)),mul(B,min(Y)))
             .. add(mul(A,max(X)),mul(B,max(Y))).




% 4 vars
:- public 'pac x+y+z=t'/4.
'pac x+y+z=t'(X,Y,Z,T):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)*sigma(T)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)*sigma(T)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)*sigma(T)),
	T in (0..infinity)*(sigma(X)*sigma(Y)*sigma(Z)),
	X in sub(sub(min(T),max(Y)),max(Z))..sub(sub(max(T),min(Y)),min(Z)),
	Y in sub(sub(min(T),max(X)),max(Z))..sub(sub(max(T),min(X)),min(Z)),
	Z in sub(sub(min(T),max(X)),max(Y))..sub(sub(max(T),min(X)),min(Y)),
	T in add(add(min(X),min(Y)),min(Z))..add(add(max(X),max(Y)),max(Z)).



:- public 'pac ax+y+z=t'/5.
'pac ax+y+z=t'(A,X,Y,Z,T):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)*sigma(T)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)*sigma(T)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)*sigma(T)),
	T in (0..infinity)*(sigma(X)*sigma(Y)*sigma(Z)),
	X in ceil_div(sub(sub(min(T),max(Y)),max(Z)),A)
             .. floor_div(sub(sub(max(T),min(Y)),min(Z)),A),
	Y in sub(sub(min(T),mul(A,max(X))),max(Z))
             .. sub(sub(max(T),mul(A,min(X))),min(Z)),
	Z in sub(sub(min(T),mul(A,max(X))),max(Y))
             .. sub(sub(max(T),mul(A,min(X))),min(Y)),
	T in add(add(mul(A,min(X)),min(Y)),min(Z))
             .. add(add(mul(A,max(X)),max(Y)),max(Z)).



:- public 'pac ax+by+z=t'/6.
'pac ax+by+z=t'(A,X,B,Y,Z,T):-
	X in (0..infinity)*(sigma(Y)*sigma(Z)*sigma(T)),
	Y in (0..infinity)*(sigma(X)*sigma(Z)*sigma(T)),
	Z in (0..infinity)*(sigma(X)*sigma(Y)*sigma(T)),
	T in (0..infinity)*(sigma(X)*sigma(Y)*sigma(Z)),
	X in ceil_div(sub(sub(min(T),mul(B,max(Y))),max(Z)),A)
             .. floor_div(sub(sub(max(T),mul(B,min(Y))),min(Z)),A),
	Y in ceil_div(sub(sub(min(T),mul(A,max(X))),max(Z)),B)
             .. floor_div(sub(sub(max(T),mul(A,min(X))),min(Z)),B),
	Z in sub(sub(min(T),mul(A,max(X))),mul(B,max(Y)))
             .. sub(sub(max(T),mul(A,min(X))),mul(B,min(Y))),
	T in add(add(mul(A,min(X)),mul(B,min(Y))),min(Z))
             .. add(add(mul(A,max(X)),mul(B,max(Y))),max(Z)).






