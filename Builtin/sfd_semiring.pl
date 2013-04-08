/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/* Buit-In Predicates                                   Daniel Diaz - 1994 */
/*                                                                         */
/* Built-In: FD predicates                                                 */
/*                                                                         */
/* Modified by Yan Georget - June 1998                                     */
/* sfd_semiring.pl                                                         */
/*-------------------------------------------------------------------------*/


:- public semiring_mul/3, semiring_add/3, semiring_unity/1, semiring_null/1,
	  semiring_greater/2, semiring_greatereq/2, 
	  semiring_less/2, semiring_lesseq/2,
	  semiring_size/1,
	  semiring_value_write/1.


semiring_mul(_,_,_) :-
	pragma_c('Semiring_Mul_3').


semiring_add(_,_,_) :-
	pragma_c('Semiring_Add_3').


semiring_unity(_) :-


	pragma_c('Semiring_Unity_1').
semiring_null(_) :-
	pragma_c('Semiring_Null_1').



semiring_greater(_,_) :-
	pragma_c('Semiring_Greater_2').


semiring_greatereq(_,_) :-
	pragma_c('Semiring_GreaterEq_2').


semiring_less(_,_) :-
	pragma_c('Semiring_Less_2').


semiring_lesseq(_,_) :-
	pragma_c('Semiring_LessEq_2').


semiring_size(_) :-
	pragma_c('Semiring_Size_1').


semiring_value_write(_) :-
	pragma_c('Semiring_Value_Write_1').











