/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler                INRIA Rocquencourt - LOCO Project */
/* Buit-In Predicates                                   Yan Georget - 1998 */
/*                                                                         */
/* Bits library                                                            */
/*                                                                         */
/* bits.pl                                                                 */
/*-------------------------------------------------------------------------*/

:- public num_bitnb/2. 
% num_bitnb(+Value,?BitsNb)

num_bitnb(0,0) :- 
	!.
num_bitnb(B,N) :-
	LB is B /\ 1,
	B1 is B>>1,
	num_bitnb(B1,N1),
	(LB == 1 
    -> 
	N is N1+1 
    ; 
	N is N1). 


:- public bitnb_num/3.
% bitnb_num(+BitsNb,+Size,?Value)

bitnb_num(0,_,0) :-
	!.
bitnb_num(N,N,B) :-
	!,
	B is (1<<N)-1.
bitnb_num(N,P,B) :-
	P1 is P-1,
	N1 is N-1,
	bitnb_num(N1,P1,B1),
	B is (B1<<1)+1.
bitnb_num(N,P,B) :-
	P1 is P-1,
	bitnb_num(N,P1,B1),
	B is B1<<1.


:- public skip_null/4.
% skip_null(+OldMask,+OldOffset,?NewMask,?NewOffset)

skip_null(OldMask,OldOffset,NewMask,NewOffset) :-
	Bit is OldMask /\ 1,
	(Bit == 1
    -> 
	NewOffset = OldOffset,
	NewMask  = OldMask
    ;
	OldMask1 is OldMask >>1,
	OldOffset1 is OldOffset+1,
	skip_null(OldMask1,OldOffset1,NewMask,NewOffset)).



