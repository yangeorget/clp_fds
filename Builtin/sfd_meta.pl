/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler                INRIA Rocquencourt - LOCO Project */
/* Built-In Predicates                              Yan Georget -June 1998 */
/*                                                                         */
/* sfd_meta.pl                                                             */
/*-------------------------------------------------------------------------*/


:- public 'b <=> x=c'/3, 'b <=> x=c:(a;b)'/5.

'b <=> x=c'(B,X,C) :-
	B in 0..1,
	B in (0..1)*sigma(X),
	X in (0..infinity)*sigma(B),
	B in equiv_eqc_r(min(X),max(X),C),
	X in equiv_eqc_a(val(B),C).

'b <=> x=c:(a;b)'(Bool,X,C,A,B) :-
	Bool in (0..1)*A,
	X in (0..infinity)*A,
	Bool in (0..1)*sigma(X),
	X in (0..infinity)*sigma(Bool),
	Bool in equiv_eqc_r(min(X),max(X),C)+B,
	X in equiv_eqc_a(val(Bool),C)+B.


:- public 'b <=> x>c'/3, 'b <=> x>c:(a;b)'/5.

'b <=> x>c'(B,X,C) :-
	B in 0..1,
	B in (0..1)*sigma(X),
	X in (0..infinity)*sigma(B),
	B in equiv_gc_r(min(X),max(X),C),
	X in equiv_gc_a(val(B),C).

'b <=> x>c:(a;b)'(Bool,X,C,A,B) :-
	Bool in (0..1)*A,
	X in (0..infinity)*A,
	Bool in (0..1)*sigma(X),
	X in (0..infinity)*sigma(Bool),
	Bool in equiv_gc_r(min(X),max(X),C)+B,
	X in equiv_gc_a(val(Bool),C)+B.


:- public 'b <=> x>c'/3, 'b <=> x>c:(a;b)'/5.

'b <=> x>c'(B,X,C) :-
	B in 0..1,
	B in (0..1)*sigma(X),
	X in (0..infinity)*sigma(B),
	B in equiv_gec_r(min(X),max(X),C),
	X in equiv_gec_a(val(B),C).

'b <=> x>c:(a;b)'(Bool,X,C,A,B) :-
	Bool in (0..1)*A,
	X in (0..infinity)*A,
	Bool in (0..1)*sigma(X),
	X in (0..infinity)*sigma(Bool),
	Bool in equiv_gec_r(min(X),max(X),C)+B,
	X in equiv_gec_a(val(Bool),C)+B.


:- public 'b <=> x=y'/3, 'b <=> x=y:(a;b)'/5.

'b <=> x=y'(B,X,Y) :-
	B in 0..1,
	B in (0..1)*(sigma(X)*sigma(Y)),
	X in (0..infinity)*(sigma(B)*sigma(Y)),
	Y in (0..infinity)*(sigma(B)*sigma(X)),
	B in equiv_eq_r(def(X),def(Y)),
	X in equiv_eq_a(def(Y),val(B)),
	Y in equiv_eq_a(def(X),val(B)).

'b <=> x=y:(a;b)'(Bool,X,Y,A,B) :-
	Bool in (0..1)*A,
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Bool in (0..1)*(sigma(X)*sigma(Y)),
	X in (0..infinity)*(sigma(Bool)*sigma(Y)),
	Y in (0..infinity)*(sigma(Bool)*sigma(X)),
	Bool in equiv_eq_r(def(X),def(Y))+B,
	X in equiv_eq_a(def(Y),val(Bool))+B,
	Y in equiv_eq_a(def(X),val(Bool))+B.


:- public 'b <=> x>y'/3, 'b <=> x>y:(a;b)'/5.

'b <=> x>y'(B,X,Y) :-
	B in 0..1,
	B in (0..1)*(sigma(X)*sigma(Y)),
	X in (0..infinity)*(sigma(B)*sigma(Y)),
	Y in (0..infinity)*(sigma(B)*sigma(X)),
	B in equiv_g_r(min(X),max(X),min(Y),max(Y)),
	X in equiv_g_a1(def(Y),val(B)),
	Y in equiv_g_a2(def(X),val(B)).

'b <=> x>y:(a;b)'(Bool,X,Y,A,B) :-
	Bool in (0..1)*A,
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Bool in (0..1)*(sigma(X)*sigma(Y)),
	X in (0..infinity)*(sigma(Bool)*sigma(Y)),
	Y in (0..infinity)*(sigma(Bool)*sigma(X)),
	Bool in equiv_g_r(min(X),max(X),min(Y),max(Y))+B,
	X in equiv_g_a1(def(Y),val(Bool))+B,
	Y in equiv_g_a2(def(X),val(Bool))+B.


:- public 'b <=> x>=y'/3, 'b <=> x>=y:(a;b)'/5.

'b <=> x>=y'(B,X,Y) :-
	B in 0..1,
	B in (0..1)*(sigma(X)*sigma(Y)),
	X in (0..infinity)*(sigma(B)*sigma(Y)),
	Y in (0..infinity)*(sigma(B)*sigma(X)),
	B in equiv_ge_r(min(X),max(X),min(Y),max(Y)),
	X in equiv_ge_a1(def(Y),val(B)),
	Y in equiv_ge_a2(def(X),val(B)).

'b <=> x>=y:(a;b)'(Bool,X,Y,A,B) :-
	Bool in (0..1)*A,
	X in (0..infinity)*A,
	Y in (0..infinity)*A,
	Bool in (0..1)*(sigma(X)*sigma(Y)),
	X in (0..infinity)*(sigma(Bool)*sigma(Y)),
	Y in (0..infinity)*(sigma(Bool)*sigma(X)),
	Bool in equiv_ge_r(min(X),max(X),min(Y),max(Y))+B,
	X in equiv_ge_a1(def(Y),val(Bool))+B,
	Y in equiv_ge_a2(def(X),val(Bool))+B.




:- public atmost/3, atleast/3, exactly/3.

atmost(N,L,C) :-
	equiv_eq_cst(B,L,C),
	sum(B,P),
	P in 0..N.

atleast(N,L,C) :-
	equiv_eq_cst(B,L,C),
	sum(B,P),
	P in N..infinity.

exactly(N,L,C) :-
	equiv_eq_cst(B,L,C),
	sum(B,P),
	P in sing(N). % and not: sum(B,N) (for constraint retraction)



:- public equiv_eq_cst/3.
equiv_eq_cst([],[],_).
equiv_eq_cst([B|Bs],[X|Xs],C) :-
	'b <=> x=c'(B,X,C),
	equiv_eq_cst(Bs,Xs,C).



:- public equiv_eq_csts/3.
equiv_eq_csts([],[],[]).
equiv_eq_csts([B|Bs],[X|Xs],[C|Cs]) :-
	'b <=> x=c'(B,X,C),
	equiv_eq_csts(Bs,Xs,Cs).

