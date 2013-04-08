/*-------------------------------------------------------------------------*/
/* Title           : GSAT                                                  */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : bool                                                  */
/*                                                                         */
/* A CLP implementation of the famous GSAT algorithm.                      */
/*-------------------------------------------------------------------------*/

% this implementation is quite a hack since we use directed constraints...
% note that this is only for efficiency reasons

:- public t/0. 
t :-
	fd_vector_max(2),
	
	write('variables creation...'),
	gsat_vars,
	write('done'),nl,
	write('constraints creation...'),
	gsat_cstrs,
	write('done'),nl,
	
	bt_reset,
	gsat(10000),  % the maximal number of tries
	bt_get(B),
	
	write('backtracks: '), write(B), nl.



% the main predicate
:- public gsat/1, gsat/2.     
gsat(MaxTries) :-
	gsat(0,MaxTries),
	!.
gsat(_,_) :-
	write('(re)starting'),nl,
	vars(N),
	gsat_init(0,N),
	gsat_cont(N).
gsat(Try,MaxTries) :-
	bt_inc,
	Try1 is Try+1,
	Try1 < MaxTries,
	gsat(Try1,MaxTries).



:- public gsat_cont/1.
gsat_cont(_) :-
	compute_cost(Cost),
	write('cost: '), write(Cost), nl,
	Cost = 0,
	!,
	write('satisfiable'),nl.
gsat_cont(N) :-
	gsat_repair(0,N),
	bt_inc,
	gsat_cont(N).



:- public gsat_repair/2.
gsat_repair(I,_) :-
	write('var: '), write(I), 
	compute_local_cost(I,LocalCost),
	write(' local cost: '), write(LocalCost), nl,
	LocalCost =\= 0,
	compute_cost(Cost),
	gsat_flip(I), 
	compute_cost(NewCost),
	NewCost < Cost,
	!.
gsat_repair(I,N) :-
	I1 is I+1,
	I1 < N,
	gsat_repair(I1,N).
	


:- public compute_cost/1.
compute_cost(Cost) :-
	g_read(gsat_cost,CostVar),
	sfd_min(CostVar,Cost).



:- public compute_local_cost/2.
compute_local_cost(I,LocalCost) :-
	g_read(gsat_local_costs(I),LocalCostVar),
	sfd_max(LocalCostVar,LocalCost).



:- public gsat_vars/0, gsat_vars/2.
gsat_vars :-
	vars(N),
	g_assign(gsat_instantiations,g_array(N,g_array(2))),
	g_link(gsat_variables,g_array(N)),
	gsat_vars(0,N).	
gsat_vars(N,N) :-
	!.
gsat_vars(I,N) :-
	V in 0..1,
	g_link(gsat_variables(I),V),
	cstrs_block_start,
	V in sing(0),
	cstrs_block_end(Ref0),
	g_assign(gsat_instantiations(I,0),Ref0),
	cstrs_block_retract(Ref0),
	cstrs_block_start,
	V in sing(1),
	cstrs_block_end(Ref1),
	g_assign(gsat_instantiations(I,1),Ref1),
	cstrs_block_retract(Ref1),
	I1 is I+1,
	gsat_vars(I1,N).



:- public gsat_cstrs/0.
gsat_cstrs :-
	vars(N),
	clauses(M),
	g_link(gsat_clauses,g_array(M)),
	gsat_clauses(0,M),
	g_link(gsat_local_costs,g_array(N)),
	gsat_local_costs(0,N),
	g_read(gsat_local_costs,g_array(LocalCosts)),
	directed_sum(LocalCosts,Cost),
	g_link(gsat_cost,Cost).



:- public  gsat_clauses/2. 
gsat_clauses(M,M) :-
	!.
gsat_clauses(I,M) :-
	clause(I,Motif,NV1,NV2,NV3),
	NV11 is NV1-1,
	NV21 is NV2-1,
	NV31 is NV3-1,
	g_read(gsat_variables(NV11),V1),
	g_read(gsat_variables(NV21),V2),
	g_read(gsat_variables(NV31),V3),
	cnf(Motif,V1,V2,V3,C),
	g_link(gsat_clauses(I),C),
	I1 is I+1,
	gsat_clauses(I1,M).



:- public gsat_local_costs/2.
gsat_local_costs(N,N) :-
	!.
gsat_local_costs(I,N) :-
	I1 is I+1,
	findall(J,clause(J,_,I1,_,_),LocalClausesNum1),
	findall(J,clause(J,_,_,I1,_),LocalClausesNum2),
	findall(J,clause(J,_,_,_,I1),LocalClausesNum3),
	append([LocalClausesNum1,LocalClausesNum2,LocalClausesNum3],LocalClausesNum),
	gsat_local_clauses(LocalClausesNum,LocalClauses),
	directed_sum(LocalClauses,LocalCost),
	g_link(gsat_local_costs(I),LocalCost),
	gsat_local_costs(I1,N).



:- public gsat_local_clauses/2.
gsat_local_clauses([],[]).
gsat_local_clauses([Num|Nums],[Cl|Cls]) :-
	g_read(gsat_clauses(Num),Cl),
	gsat_local_clauses(Nums,Cls).



:- public gsat_flip/1.	
gsat_flip(I) :-
	g_read(gsat_variables(I),V),
	g_read(gsat_instantiations(I,0),Ref0),
	g_read(gsat_instantiations(I,1),Ref1),
	(sfd_min(V,0)
    ->
	cstrs_block_retract(Ref0),
	cstrs_block_tell(Ref1)
    ;
	cstrs_block_retract(Ref1),
	cstrs_block_tell(Ref0)).



:- public gsat_init/2.
gsat_init(N,N) :-
	!.
gsat_init(I,N) :-
	random(B,2),
	g_read(gsat_instantiations(I,B),Ref),
	cstrs_block_tell(Ref),
	I1 is I+1,
	gsat_init(I1,N).



:- public directed_sum/2.
directed_sum([],Sum) :-
	Sum in sing(0).
directed_sum([X],Sum) :- 
	!,
	Sum in min(X)..max(X).
directed_sum([X,Y|L],Sum) :-
	!,
	directed_sum([Y|L],Sum1),
	Sum in add(min(X),min(Sum1))..add(max(X),max(Sum1)).



% B is the ``cost'' of the clause
:- public cnf/5.
cnf(m000,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(sub(1,val(X)),sub(1,val(Y)),sub(1,val(Z)))).
cnf(m100,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(val(X),sub(1,val(Y)),sub(1,val(Z)))).
cnf(m010,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(sub(1,val(X)),val(Y),sub(1,val(Z)))).
cnf(m001,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(sub(1,val(X)),sub(1,val(Y)),val(Z))).
cnf(m011,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(sub(1,val(X)),val(Y),val(Z))).
cnf(m101,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(val(X),sub(1,val(Y)),val(Z))).
cnf(m110,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(val(X),val(Y),sub(1,val(Z)))).
cnf(m111,X,Y,Z,B) :-
	B in 0..1,
	B in sing(or(val(X),val(Y),val(Z))).
	


:- public write_cost/0.
write_cost :-
	g_read(gsat_cost,C),
	write(C),nl.


:- public write_vars/0.
write_vars :-
	g_read(gsat_variables,g_array(V)),
	write(V),nl.


:- public write_costs/0.
write_costs :-
	g_read(gsat_local_costs,g_array(C)),
	write(C),nl.

:- public write_clauses/0.
write_clauses :-
	g_read(gsat_clauses,g_array(C)),
	write(C),nl.








