/*-------------------------------------------------------------------------*/
/* Prolog to Wam Compiler               INRIA Rocquencourt - ChLoE Project */
/*                                                 Yan Georget - June 1998 */
/* sfd_misc.pl                                                             */
/*-------------------------------------------------------------------------*/


:- public bt_reset/0, bt_inc/0, bt_get/1, bt_save/0, bt_restore/0.

bt_inc :-
	g_read('$btnumber',BT),
	BT1 is BT+1,
	g_assign('$btnumber',BT1).

bt_reset :-
	g_assign('$btnumber',0).

bt_get(N) :-
	g_read('$btnumber',N).

bt_save :-
	g_read('$btnumber',BT),
	g_assign('$btnumbersave',BT).

bt_restore :-
	g_read('$btnumbersave',BT),
	g_assign('$btnumber',BT).













