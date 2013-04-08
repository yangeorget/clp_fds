/*-------------------------------------------------------------------------*/
/* Title           : cantatrice                                            */
/* Original Source : Con'Flex distribution                                 */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : fuzzy (big)                                           */
/*                                                                         */
/* Find a menu for the breakfast of a cantatrice.                          */
/*-------------------------------------------------------------------------*/

:- main.


cantatrice([The,Lait,Toast,Oeuf,Xint]) :-

	interval_domain([The,Lait],0,5,10),
	interval_domain([Toast],2,5,10),
	interval_domain([Oeuf],1,5,10),

	% Xint = (X-184)/5,
	sparse_domain([Xint],
	[0,1,2,3,4,5, 6, 7, 8, 9,10,11,12,13,14,15,
	16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31],
	[4,5,6,7,8,9,10,10,10,10,10,10,10,10,10,10,
	10,10,10,10,10,10,10,10,10,10,10, 9, 8, 7, 6, 5]),

	relation(
	[([0,1],6),([0,2],10),([0,3],10),([0,4],10),([0,5],10),
	([1,0],5),([1,1],10),([1,2],10),([1,3],10),([1,4],10),([1,5],10),
	([2,0],10),([2,1],10),([2,2],10),([2,3],10),([2,4],10),([2,5],10),
	([3,0],10),([3,1],10),([3,2],10),([3,3],10),([3,4],10),([3,5],10),
	([4,0],10),([4,1],10),([4,2],10),([4,3],10),([4,4],10),([4,5],10),
	([5,0],10),([5,1],10),([5,2],10),([5,3],10),([5,4],10),([5,5],10)],
	[The,Lait]),

	'x=y+c'(OM1,Oeuf,-1),
	'x=y+c'(TM2,Toast,-2),
	'x=cy'(OF62,62,OM1),
	'x=cy'(TF60,60,TM2),
	'x=cy'(LF20,20,Lait),
	'x=cy'(TF15,15,The),
	'x=y+z'(S1,OF62,TF60),
	'x=y+z'(S2,S1,LF20),
	'x=y+z'(S3,S2,TF15),
	'x=y+c'(Xint,S3,-2),

	Toast #>= 2*Oeuf.


t :-   
	fd_vector_max(35),
	statistics(runtime,_),
	cantatrice(L),
	max_sol(L),
	write(L),nl,
	statistics(runtime,[_,Time]),
	write('time: '), write(Time), nl,
	halt_or_else(0,true).

:- t.


