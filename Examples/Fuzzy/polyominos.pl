/*-------------------------------------------------------------------------*/
/* Title           : polyominos                                            */
/* Created by      : Yan Georget                                           */
/* Semiring        : fuzzy (small if gap<3)                                */
/*                                                                         */
/* Reconstruction of a convex polyomino from its (horizontal & vertical)   */
/* projections (which are partially unknown) such that the gap is minimal. */
/* A projection is either an integer or a triple (Ref,Inf,Sup), in this    */
/* case: Inf <= Duration <= Sup.                                           */
/* The gap is the max of |Ref-Duration| for all projections.               */
/*                                                                         */
/*-------------------------------------------------------------------------*/

:- main.



t1 :-
        C = [2,2,2],
	L = [1,3,2],
        q(L,C).


t2 :-
        C = [(2,1,3),(2,1,3)], 
	L = [(2,1,3),(2,1,3)],
        q(L,C).

t3 :-
        L = [(3,2,4),(3,2,4),4,4,(3,2,4),(3,2,4),(3,2,4),4,4,3],
        C = [1,2,3,4,4,4,4,(3,2,4),4,(3,2,4)],
        q(L,C).



q(L,C) :-
	length(L,MaxC),
	length(C,MaxL),

	make_duration_vars(L,DL),
        make_duration_vars(C,DC),
	make_start_end_vars(DL,SL,EL,MaxL),
	make_start_end_vars(DC,SC,EC,MaxC),
	make_foot_vars(SC,EC,DC,SLeft,ELeft,_DLeft,SRight,ERight,_DRight),
	make_foot_vars(SL,EL,DL,SUp,EUp,_DUp,SDown,EDown,_DDown),
	make_boolean_vars(Bline,Bcol,MaxL,MaxC),
	append([SL,SC,EL,EC],Vars),

	overlap_cstrs(SL,DL),
	overlap_cstrs(SC,DC),
	communication_cstrs(SL,EL,Bline),
	communication_cstrs(SC,EC,Bcol),
	%redundant_cstrs(DL,DC),

	write('Before labeling:'),nl,

	write(DL),write(SL),write(EL),nl,
	write(DC),write(SC),write(EC),nl,

	write_poly(Bline),nl,
	write('Labeling:'),nl,

	bt_reset,
	max_sol(Vars,
	        polylab(SLeft,ELeft,SL,
		        SRight,ERight,EL,
			SUp,EUp,SC,
			SDown,EDown,EC,
			MaxC,MaxL,Vars),
		polylab(SLeft,ELeft,SL,
		        SRight,ERight,EL,
			SUp,EUp,SC,
			SDown,EDown,EC,
			MaxC,MaxL,Vars)),	

	write(DL),write(SL),write(EL),nl,
	write(DC),write(SC),write(EC),nl,	

	bt_get(Bt),
	blevel(Vars,Value),
	semiring_unity(One),
	Gap is One-Value,      % we have maximized Value 
	
	write_poly(Bline),nl,
	write('Gap: '), write(Gap),nl,
	write('Backtracks: '), write(Bt),nl.



:- public polylab/15.
polylab(SLeft,ELeft,SL,
	   SRight,ERight,EL,
	   SUp,EUp,SC,
	   SDown,EDown,EC,
	   MaxC,MaxL,Vars) :-
	foot(left,SLeft,ELeft,SL,MaxC),
	foot(right,SRight,ERight,EL,MaxC),
	foot(up,SUp,EUp,SC,MaxL),
	foot(down,SDown,EDown,EC,MaxL),
	bool_labelingff(Vars).



make_duration_vars([],[]).
make_duration_vars([(Ref,A,B)|Ds],[V|Vs]) :-
        !,
        make_domain(A,B,Domain),
        make_values(Domain,Ref,Values),
        sparse_domain([V],Domain,Values),
        make_duration_vars(Ds,Vs).
make_duration_vars([D|Ds],[V|Vs]) :-
	!,
        integer(D),
        V in sing(D),
        make_duration_vars(Ds,Vs).



make_domain(A,B,D) :-
        (A > B
    -> 
        D = []
    ; 
        D = [A|D1],
        A1 is A+1,
        make_domain(A1,B,D1)).



make_values([],_,[]).
make_values([H|T],R,[V|L]) :-
        Delta is H-R,
        abs(Delta,Delta1),
        semiring_unity(One),
        V is One-Delta1,
        make_values(T,R,L).



make_start_end_vars([],[],[],_).
make_start_end_vars([Duration|Durations],[Start|Starts],[End|Ends],Max) :-
	End in 0..sub(Max,1),
	Start in 0..sub(Max,1),
	End #= Start+Duration-1,
	make_start_end_vars(Durations,Starts,Ends,Max).



make_foot_vars(StartL,EndL,DurationL,
	       Start1,End1,Duration1,
	       Start2,End2,Duration2):-
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



redundant_cstrs(DL,DC) :-
	sum(DC,Sum),
        sum(DL,Sum).



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
	bool_labeling([Start,End]),
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



