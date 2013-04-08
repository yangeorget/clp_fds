/*-------------------------------------------------------------------------*/
/* Title           : menu                                                  */
/* Original Source : Thomas Schiex, ICUAI92                                */
/* Adapted by      : Yan Georget                                           */
/* Semiring        : fuzzy (big)                                           */
/*                                                                         */
/* Find a menu.                                                            */
/*                                                                         */ 
/* DATA:                                                                   */
/*    dish     [fish,wildboar,sauerkraut]                                  */
/*    drink    [whitewine,redwine,beer,water]                              */
/*    entrance [salmon,caviar,foiegras,oysters,nothing]                    */
/*    dessert  [applepie,ice,fruit,nothing]                                */
/*-------------------------------------------------------------------------*/

:- main.


menu([Entrance,Dish,Dessert,Drink]) :-
	interval_domain([Dish],1,3,10),
	interval_domain([Drink,Dessert],1,4,10),
	interval_domain([Entrance],1,5,10),

	% no entrance or no dessert is not appreciated: 0.4
	'x<>c:(a;b)'(Entrance,5,10,6),
	'x<>c:(a;b)'(Dessert,4,10,6),
						
	% having water is no good: 0.5
	'x<>c:(a;b)'(Drink,4,10,5),

	% i don't want oysters
	'x<>c'(Entrance,4),
	
	% i would like to taste the sauerkraut
	sparse_domain([Dish],3,3,10,8),

	c1(Dish,Drink),
	c2(Entrance,Dish),
	c3(Entrance,Dish,Drink),
	c4(Dish,Dessert),
	c5(Entrance,Dessert).

	
c1(Dish,Drink) :-
	% sauerkraut should be accompanied with a beer: 0.8 
	% or white wine: 0.3 or water: 0.2.
	% meat should certainly be eaten with a red wine: 0.9
	relation(
	[([1,1],10),([1,2],10),([1,3],10),([1,4],10),
	([2,1],1),([2,2],10),([2,3],1),([2,4],1),
	([3,1],2),([3,2],2),([3,3],7),([3,4],2)],
	[Dish,Drink]).

c2(Entrance,Dish) :-	
	% fish may not be eaten twice: 0.7
	% i would like some fish: 0.8
	relation(
	[([1,1],3),([1,2],10),([1,3],10),
	([2,1],3),([2,2],10),([2,3],10),
	([3,1],10),([3,2],2),([3,3],2),
	([4,1],3),([4,2],10),([4,3],10),
	([5,1],10),([5,2],2),([5,3],2)],
	[Entrance,Dish]).

c3(Entrance,Dish,Drink) :-
	% fish should be accompanied with white wine: 0.9 or water: 0.2
	relation(
	[([1,1,1],8),([1,1,2],1),([1,1,3],1),([1,1,4],1),
	([1,2,1],8),([1,2,2],1),([1,2,3],1),([1,2,4],1),
	([1,3,1],8),([1,3,2],1),([1,3,3],1),([1,3,4],1),
	([2,1,1],8),([2,1,2],1),([2,1,3],1),([2,1,4],1),
	([2,2,1],8),([2,2,2],1),([2,2,3],1),([2,2,4],1),
	([2,3,1],8),([2,3,2],1),([2,3,3],1),([2,3,4],1),
	([3,1,1],8),([3,1,2],1),([3,1,3],1),([3,1,4],1),
	([3,2,1],10),([3,2,2],10),([3,2,3],10),([3,2,4],10),
	([3,3,1],10),([3,3,2],10),([3,3,3],10),([3,3,4],10),
	([4,1,1],8),([4,1,2],1),([4,1,3],1),([4,1,4],1),
	([4,2,1],8),([4,2,2],1),([4,2,3],1),([4,2,4],1),
	([4,3,1],8),([4,3,2],1),([4,3,3],1),([4,3,4],1),
	([5,1,1],8),([5,1,2],1),([5,1,3],1),([5,1,4],1),
	([5,2,1],10),([5,2,2],10),([5,2,3],10),([5,2,4],10),
	([5,3,1],10),([5,3,2],10),([5,3,3],10),([5,3,4],10)],
	[Entrance,Dish,Drink]).

c3(Entrance,Drink) :-
	% foie gras should certainly be eaten with a red wine: 0.9
	relation(
	[([1,1],10),([1,2],10),([1,3],10),([1,4],10),
	([2,1],10),([2,2],10),([2,3],10),([2,4],10),
	([3,1],10),([3,2],1),([3,3],1),([3,4],1),
	([4,1],10),([4,2],10),([4,3],10),([4,4],10),
	([5,1],10),([5,2],10),([5,3],10),([5,4],10)],
	[Entrance,Drink]).

c4(Dish,Dessert) :-
	% after the wild boar, ice is good: 0.5
	relation(
	[([1,1],10),([1,2],10),([1,3],10),([1,4],10),
	([2,1],5),([2,2],10),([2,3],5),([2,4],5),
	([3,1],10),([3,2],10),([3,3],10),([3,4],10)],
	[Dish,Dessert]).

c5(Entrance,Dessert) :-
	% no entrance and no dessert is not appreciated: 0.6
	relation(
	[([1,1],10),([1,2],10),([1,3],10),([1,4],10),([2,1],10),([2,2],10),
	([2,3],10),([2,4],10),([3,1],10),([3,2],10),([3,3],10),([3,4],10),
	([4,1],10),([4,2],10),([4,3],10),([4,4],10),([5,1],10),([5,2],10),
	([5,3],10),([5,4],4)],
	[Entrance,Dessert]).
		
t :-
	fd_vector_max(60),
	statistics(runtime,_),
	menu(L),
	max_sol(L),
	write(L),nl,
	statistics(runtime,[_,Time]),
	write('time: '), 
	write(Time), nl,
	halt_or_else(0,true).

:- t.


