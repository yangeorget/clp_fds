/*-------------------------------------------------------------------------*/
/* Title           : progressive party problem                             */
/* Original source : B.M. Smith                                            */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* Full problem description in:                                            */
/* http://www.ps.uni-sb.de/~walser/ppp/ppp-spec.html                       */
/*-------------------------------------------------------------------------*/
:- main.

q :-
	HostsNb = 13,
	GuestsNb = 29,	
	fd_vector_max(HostsNb),

	D = [D1,D2,D3,D4,D5,D6],
	length(D1,GuestsNb),
	length(D2,GuestsNb),
	length(D3,GuestsNb),
	length(D4,GuestsNb),
	length(D5,GuestsNb),
	length(D6,GuestsNb),
	lines_to_columns(D,G),
	append(D,DD),
	interval_domain(DD,1,HostsNb),

	mk_visit_cstrs(G),     % guests can no visit twice the same host
	mk_capacity_cstrs(D),  % do not exceed boat capacity
	mk_encounter_cstrs(G), % staffs can not encounter more than once
	mk_symmetry_cstrs(G),

	!,
	bt_reset,
	bool_labeling(DD),
	bt_get(BN),
	crews_write(G),
	write(BN), write(' backtracks.'), nl.

crews_write([]).
crews_write([[B1,B2,B3,B4,B5,B6]|Bs]) :-
	write(B1), write(' '),
	write(B2), write(' '),
	write(B3), write(' '),
	write(B4), write(' '),
	write(B5), write(' '),
	write(B6), write(' '),
	nl,
	crews_write(Bs).

mk_visit_cstrs([]).
mk_visit_cstrs([G|L]) :-
	bool_alldifferent(G),
	mk_visit_cstrs(L).

mk_capacity_cstrs([]).
mk_capacity_cstrs([D|L]) :-
	hosts_spare_capacities(HSCs),
	mk_capacity_cstrs(HSCs,1,D),
	mk_capacity_cstrs(L).

mk_capacity_cstrs([],_,_).
mk_capacity_cstrs([HSC|HSCs],HN,D) :-
	guests_crew_sizes(GCSs),
	consumed_capacities(D,GCSs,HN,ConsumedCapacities),
	sum(ConsumedCapacities,ConsumedCapacity),
	ConsumedCapacity #<= HSC, 
	HN1 is HN+1,
	mk_capacity_cstrs(HSCs,HN1,D).
	
consumed_capacities([],[],_,[]).
consumed_capacities([D|Ds],[GCS|GCSs],Host,[CC|CCs]) :-
	'b <=> x=c'(On,D,Host),
	CC #= GCS*On,
	consumed_capacities(Ds,GCSs,Host,CCs).

mk_encounter_cstrs([]).
mk_encounter_cstrs([G|Gs]) :-
	mk_encounter_cstrs(Gs,G),
	mk_encounter_cstrs(Gs).

mk_encounter_cstrs([],_).
mk_encounter_cstrs([[G1,G2,G3,G4,G5,G6]|Gs],GG) :-
	GG = [GG1,GG2,GG3,GG4,GG5,GG6],
	'b <=> x=y'(T1,G1,GG1),
	'b <=> x=y'(T2,G2,GG2),
	'b <=> x=y'(T3,G3,GG3),
	'b <=> x=y'(T4,G4,GG4),
	'b <=> x=y'(T5,G5,GG5),
	'b <=> x=y'(T6,G6,GG6),
	T1 + T2 + T3 + T4 + T5 + T6 #<=1,
	mk_encounter_cstrs(Gs,GG).

mk_symmetry_cstrs(G) :-
	G = [G1|_],              % the guest with the biggest crew visits hosts in order
	G1 = [G_1_1, G_1_2, G_1_3, G_1_4, G_1_5, G_1_6],
	G_1_1 #< G_1_2,
	G_1_2 #< G_1_3,
	G_1_3 #< G_1_4,
	G_1_4 #< G_1_5,
	G_1_5 #< G_1_6,
	
        % to distinguish between guests with same crew size
	lines_to_columns(G,[D1,D2|_]),
	length(D_1_2,14),
	length(D_1_3,2),
	length(D_1_4,8),
	length(D_1_5,3),
	DD1 = [[_],[_],D_1_5,D_1_4,D_1_3,D_1_2],
	append(DD1,D1),
	length(D_2_2,14),
	length(D_2_3,2),
	length(D_2_4,8),
	length(D_2_5,3),
	DD2 = [[_],[_],D_2_5,D_2_4,D_2_3,D_2_2],
	append(DD2,D2),
	gwscs(D_1_2,D_2_2),
	gwscs(D_1_3,D_2_3),
	gwscs(D_1_4,D_2_4),
	gwscs(D_1_5,D_2_5),
	
	% to distinguish between hosts with same crew size
	hwscs([1,2],G1),
	hwscs([4,5,6,7,8,9],G1),
	hwscs([12,13],G1).

gwscs([],[]).
gwscs([Gi1|Gi1s],[Gi2|Gi2s]) :-
	gwscs(Gi1s,Gi2s,Gi1,Gi2),
	gwscs(Gi1s,Gi2s).
gwscs([],[],_,_).
gwscs([Gj1|Gj1s],[Gj2|Gj2s],Gi1,Gi2) :-
	Gi1 #<= Gj1,
	'b <=> x=y'(Bool,Gi1,Gj1),
	'b <=> x>y'(Bool,Gj2,Gi2),
	gwscs(Gj1s,Gj2s,Gi1,Gi2).

hwscs([],_).
hwscs([H|Hs],G) :-
	hwscs(Hs,H,G),
	hwscs(Hs,G).
hwscs([],_,_).
hwscs([Hk|Hs],Hj,[G1,G2,G3,G4,G5,G6]) :-
	'b <=> x=c'(Tk1,G1,Hk),
	'b <=> x=c'(Tk2,G2,Hk),
	'b <=> x=c'(Tk3,G3,Hk),
	'b <=> x=c'(Tk4,G4,Hk),
	'b <=> x=c'(Tk5,G5,Hk),
	'b <=> x=c'(Tk6,G6,Hk),
	'b <=> x=c'(Tj1,G1,Hj),
	'b <=> x=c'(Tj2,G2,Hj),
	'b <=> x=c'(Tj3,G3,Hj),
	'b <=> x=c'(Tj4,G4,Hj),
	'b <=> x=c'(Tj5,G5,Hj),
	'b <=> x=c'(Tj6,G6,Hj),
	Tk1 + Tk2 + Tk3 + Tk4 + Tk5 + Tk6 #<= Tj1 + Tj2 + Tj3 + Tj4 + Tj5 + Tj6,
	hwscs(Hs,Hj,[G1,G2,G3,G4,G5,G6]).

hosts_spare_capacities([10,10,9,8,8,8,8,8,8,7,6,4,4]).
guests_crew_sizes([ 7, 6, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 
	            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]).






