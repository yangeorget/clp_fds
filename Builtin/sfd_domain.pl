/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Built-In: FD predicates                                                 */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_domain.pl                                                           */
/*-------------------------------------------------------------------------*/


:- public fd_unify/2, fd_var/1, fd_vector_max/1, fd_infinity/1.

fd_unify(X,Y):-
	X in def(Y),
	Y in def(X).


fd_var(_X):-
	pragma_c('Fd_Var_1').


fd_vector_max(_N):-
	pragma_c('Fd_Vector_Max_1').


fd_infinity(_X):-
	pragma_c('get_integer(infinity,0)').




:- public sfd_value_index/3, sfd_value/2, sfd_index/2, 
	  sfd_is_instantiated/1, sfd_min/2, sfd_max/2, sfd_size/2.


sfd_value_index(_,_,_) :- 
	pragma_c('Sfd_Value_Index_3').


sfd_value(X,V) :-
	sfd_value_index(X,V,_).


sfd_index(X,I) :-
	sfd_value_index(X,_,I).


sfd_is_instantiated(_) :- 
	pragma_c('Sfd_Is_Instantiated_1').


sfd_min(_,_) :- 
	pragma_c('Sfd_Min_2').


sfd_max(_,_) :- 
	pragma_c('Sfd_Max_2').


sfd_size(_,_) :- 
	pragma_c('Sfd_Size_2').




:- public sfd_2int/2.

sfd_2int([],[]).
sfd_2int([V|Vs],[I|Is]) :-
	sfd_2int_aux(V,I),
	sfd_2int(Vs,Is).

sfd_2int_aux(V,I) :-
	sfd_is_instantiated(V),
	!,
	sfd_index(V,I).
sfd_2int_aux(V,I) :-
	integer(I),
	V in sing(I).



:- public interval_domain/3, interval_domain/4.

interval_domain([],_,_).
interval_domain([X|L],I,S):-
	X in I..S,
	interval_domain(L,I,S).


interval_domain([],_,_,_).
interval_domain([X|L],I,S,V):-
	X in (I..S)*V,
	interval_domain(L,I,S,V).



:- public sparse_domain/3, sparse_domain/4, sparse_domain/5.

sparse_domain([],_,_,_,_).
sparse_domain([X|L],I,S,A,B):-
	X in ((I..S)+B)*A,
	sparse_domain(L,I,S,A,B).


sparse_domain([],_,_,_).
sparse_domain([X|L],LV,A,B):-
	X in ([LV]+B)*A,
	sparse_domain(L,LV,A,B).


sparse_domain([],_,_).
sparse_domain([X|L],LX,LV) :-
	X in [LX],
	set_domain(LX,LV,X),
	sparse_domain(L,LX,LV).

set_domain([],[],_).
set_domain([FX|LX],[FV|LV],X):-
	X in (comp(FX))+(FV),
	set_domain(LX,LV,X).















