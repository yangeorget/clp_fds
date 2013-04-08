/*-------------------------------------------------------------------------*/
/* Title           : polyominos                                            */
/* Created by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Reconstruction of a convex polyomino from its (horizontal & vertical)   */
/* projections                                                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/

:- main.



t1 :-
	DL = [2,2,2],
	DC = [1,3,2],
	q(DL,DC).

t2 :-
	DL = [3,5,6,8,9,10,10,10,7,5],
	DC = [3,6,7,8,9,10,9,9,7,5],
	q(DL,DC).

t3 :-
	DL = [4,4,4,4,4,4,4,4,4,4,5,5,5,4,4,4,4,4,4,4,4,4,4,4,3,2,1],
	DC = [1,2,3,4,4,4,4,4,4,4,4,4,4,4,5,5,5,4,4,4,4,4,4,4,4,4,4],
	q(DL,DC).



q(DL,DC) :-
	length(DL,MaxC),
	length(DC,MaxL),

	make_start_end_vars(DL,SL,EL,MaxL),
	make_start_end_vars(DC,SC,EC,MaxC),
	make_foot_vars(SC,EC,DC,SLeft,ELeft,_DLeft,SRight,ERight,_DRight),
	make_foot_vars(SL,EL,DL,SUp,EUp,_DUp,SDown,EDown,_DDown),
	make_boolean_vars(Bline,Bcol,MaxL,MaxC),
	overlap_cstrs(SL,DL),
	overlap_cstrs(SC,DC),
	communication_cstrs(SL,EL,Bline),
	communication_cstrs(SC,EC,Bcol),
	write('Before labeling:'),nl,
	write_poly(Bline),nl,
	!,
	write('Labeling:'),nl,

        bt_reset,
	foot(left,SLeft,ELeft,SL,MaxC),
	foot(right,SRight,ERight,EL,MaxC),
	foot(up,SUp,EUp,SC,MaxL),
	foot(down,SDown,EDown,EC,MaxL),
	append(SL,SC,S),
	bool_labelingff(S),
	bt_get(Bt),

	write('Backtracks: '),write(Bt),nl,
	write_poly(Bline),nl.


make_start_end_vars([],[],[],_).
make_start_end_vars([Duration|Durations],[Start|Starts],[End|Ends],Max) :-
	End in 0..sub(Max,1),
	Start in 0..sub(Max,1),
	End #= Start+Duration-1,
	make_start_end_vars(Durations,Starts,Ends,Max).


make_foot_vars(StartL,EndL,DurationL,Start1,End1,Duration1,Start2,End2,Duration2):-
	StartL = [Start1|_],
	EndL = [End1|_],
	DurationL = [Duration1|_],
	last(StartL,Start2),
	last(EndL,End2),
	last(DurationL,Duration2).


make_boolean_vars(Bline,Bcol,MaxL,MaxC) :-
	N is MaxL * MaxC,
	length(Bs,N),
	interval_domain(Bs,0,1),
	length(Bline,MaxC),
	ll_length(Bline,MaxL),
	append(Bline,Bs),
	lines_to_columns(Bline,Bcol).


communication_cstrs([],[],[]).
communication_cstrs([Start|Starts],[End|Ends],[B|BL]) :-
	communicate(B,Start,End,0),
	communication_cstrs(Starts,Ends,BL).

communicate([],_,_,_).
communicate([B|Bs],S,E,I) :-
	'b <=> x>=y'(B1,I,S),
	'b <=> x>=y'(B2,E,I),
	'x=y and z'(B,B1,B2),
	I1 is I+1,
	communicate(Bs,S,E,I1).


overlap_cstrs([],[]).
overlap_cstrs([_],[_]).
overlap_cstrs([X,Y|L],[DX,DY|LD]) :-
	Y #< X+DX,
	X #< Y+DY,
	overlap_cstrs([Y|L],[DY|LD]).


write_poly([]):- nl.
write_poly([B|BL]):-
	write_booleans(B),
	write_poly(BL).

write_booleans([]) :- nl.
write_booleans([B|L]) :-
	(sfd_is_instantiated(B)
    ->
	(B = 0
    -> 
	write(' ')
    ;
	write('*'))
    ;
	write('?')),
	write_booleans(L).


foot(Way,Start,End,Vars,Max) :-
	bool_indomain(Start),
	sfd_min(Start,NbBefore),
	sfd_min(End,EndVal),
	NbAfter is Max-1-EndVal,
	length(BeforeList,NbBefore),
	prefix(BeforeList,Vars),
	length(AfterList,NbAfter),
	suffix(AfterList,Vars),
	ordering(Way,BeforeList,AfterList).


ordering(left,B,A) :-
	decreasing(B),
	increasing(A).
ordering(right,B,A) :-
	increasing(B),
	decreasing(A).
ordering(up,B,A) :-
	decreasing(B),
	increasing(A).
ordering(down,B,A) :-
	increasing(B),
	decreasing(A).



