/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - LOCO  Project */
/* Buit-In Predicates                                    Yan Georget  1998 */
/*                                                                         */
/* sfd_retraction.pl                                                       */
/*-------------------------------------------------------------------------*/


:- public cstrs_block_start/0,
	  cstrs_block_start/1,
	  cstrs_block_end/1, 
	  cstrs_block_retract/1, 
	  cstrs_block_tell/1,
	  cstrs_block_size/2.

cstrs_block_start :-
        pragma_c('Cstrs_Block_Start_0').

cstrs_block_start(_Cstrs) :-
        pragma_c('Cstrs_Block_Start_1').

cstrs_block_end(_Cstrs) :-
        pragma_c('Cstrs_Block_End_1').

cstrs_block_retract(_Cstrs):-
        pragma_c('Cstrs_Block_Retract_1').

cstrs_block_tell(_Cstrs):-
        pragma_c('Cstrs_Block_Tell_1').

cstrs_block_size(_Cstrs,_Size):-
        pragma_c('Cstrs_Block_Size_2').



:- public fdv_cstrs_block_put/2,
	  fdv_cstrs_block_get/2,
	  fdv_cstrs_block_clear/1,
	  fdv_cstrs_block_retract/1,
	  fdv_cstrs_block_tell/1.

fdv_cstrs_block_put(_Var,_CB) :-
	pragma_c('Fdv_Cstrs_Block_Put_2').

fdv_cstrs_block_get(_Var,_CB) :-
	pragma_c('Fdv_Cstrs_Block_Get_2').

fdv_cstrs_block_clear(Var) :-
	fdv_cstrs_block_put(Var,0).

fdv_cstrs_block_retract(Var) :-
	fdv_cstrs_block_get(Var,CB),
	cstrs_block_retract(CB).

fdv_cstrs_block_tell(Var) :-
	fdv_cstrs_block_get(Var,CB),
	cstrs_block_tell(CB).

