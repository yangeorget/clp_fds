:- public lessons_by_decreasing_durations/1.

lessons_by_decreasing_durations(
	[8,3,13,14,25,4,6,7,1,2,5,9,10,11,12,15,16,17,18,19,20,21,22,23,24,26]
).


:- public lessons_by_increasing_durations/1.

lessons_by_increasing_durations(
	[26,24,23,22,21,20,19,18,17,16,15,12,11,10,9,5,2,1,7,6,4,25,14,13,3,8]
).


:- public lessons_by_decreasing_tokens_nb/1.

lessons_by_decreasing_tokens_nb(
	[19,15,12,20,21,23,1,10,16,17,18,22,24,3,5,9,4,13,14,26,2,11,6,7,8,25]
).


:- public lessons_by_increasing_tokens_nb/1.

lessons_by_increasing_tokens_nb(
	[25,8,7,6,11,2,26,14,13,4,9,5,3,24,22,18,17,16,10,1,23,21,20,12,15,19]
).


:- public duration/1.

duration([1,1,3,2,1,2,2,4,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,3,1]).  


:- public size/1.

size(26).


:- public data/1.

data([
[i,i,a,a,a,p,i,i,a,a,i,i,a,p,i,i,i,i,i,i,i,i,i,i,p,p,p,a,p,a,a,a,a,p,a,a,p,a,i,i],
[a,a,a,a,p,a,a,a,a,a,i,i,i,i,a,a,i,i,a,a,i,i,p,a,i,i,i,i,a,a,a,a,p,a,i,i,a,a,i,i],
[a,p,i,i,a,a,i,i,p,p,i,i,p,p,i,i,i,i,i,i,i,i,i,i,a,a,i,i,i,i,i,i,a,a,i,i,a,p,i,i],
[i,i,p,i,p,a,i,i,a,a,i,i,i,i,p,i,a,p,a,i,a,p,a,i,a,a,i,i,a,a,a,i,i,i,a,i,i,i,i,i],
[a,p,p,p,p,a,a,a,i,i,i,i,i,i,a,a,i,i,i,i,a,a,i,i,p,a,i,i,a,a,p,a,i,i,a,a,i,i,a,a],
[i,i,a,i,i,i,a,i,a,a,p,i,a,a,i,i,a,a,a,i,i,i,a,i,a,a,a,i,p,a,a,i,i,i,a,i,a,a,a,i],
[p,a,i,i,a,a,a,i,i,i,i,i,a,a,a,i,p,a,i,i,a,a,a,i,i,i,i,i,i,i,i,i,i,i,i,i,a,a,i,i],
[a,i,i,i,a,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,a,i,i,i,a,i,i,i,i,i,i,i,i,i,i,i,p,i,i,i],
[p,a,i,i,a,a,i,i,i,i,p,a,p,a,a,a,i,i,a,a,a,a,a,p,a,a,p,a,i,i,i,i,a,a,a,a,p,a,a,a],
[i,i,i,i,p,a,i,i,a,a,a,a,a,a,p,a,i,i,p,a,p,p,i,i,a,a,i,i,i,i,p,a,a,a,i,i,a,a,p,a],
[i,i,a,a,a,a,i,i,i,i,i,i,p,a,i,i,i,i,a,a,i,i,i,i,a,a,p,a,p,a,i,i,i,i,a,a,i,i,i,i],
[p,a,p,a,a,a,i,i,i,i,a,a,a,a,a,a,i,i,i,i,a,p,p,p,a,p,a,a,i,i,a,p,p,a,a,p,a,a,p,a],
[i,i,i,i,i,i,i,i,a,p,i,i,a,p,i,i,a,a,i,i,p,p,i,i,i,i,i,i,i,i,i,i,a,a,i,i,a,p,i,i],
[p,p,i,i,a,a,i,i,i,i,i,i,a,p,i,i,p,a,i,i,a,p,i,i,i,i,i,i,a,a,i,i,i,i,i,i,a,a,i,i],
[a,a,i,i,a,a,a,a,p,a,i,i,a,a,i,i,i,i,a,a,p,p,p,p,p,p,p,p,i,i,p,a,i,i,a,a,a,a,p,a],
[p,a,a,a,i,i,i,i,a,a,i,i,a,a,a,a,a,p,i,i,i,i,a,p,i,i,a,p,a,p,a,p,i,i,a,a,a,p,a,a],
[i,i,i,i,a,a,i,i,i,i,a,p,a,a,i,i,a,a,p,a,a,a,a,a,i,i,p,p,a,a,a,p,i,i,i,i,i,i,p,p],
[a,a,i,i,a,a,a,a,a,a,a,a,a,p,a,a,i,i,i,i,i,i,i,i,p,a,p,a,p,p,i,i,a,p,i,i,i,i,a,p],
[a,p,i,i,a,a,a,p,p,a,p,a,i,i,p,a,p,p,i,i,i,i,i,i,p,p,a,p,i,i,p,a,a,p,i,i,a,a,i,i],
[p,p,i,i,i,i,i,i,p,a,a,a,p,a,a,a,p,p,a,p,a,p,i,i,i,i,i,i,a,a,i,i,a,a,p,a,i,i,i,i],
[p,p,a,p,a,p,i,i,i,i,a,a,p,p,a,a,i,i,i,i,p,a,i,i,i,i,a,a,a,p,a,a,a,a,a,p,a,a,i,i],
[a,a,i,i,p,a,a,a,a,p,i,i,i,i,i,i,p,a,i,i,a,a,i,i,p,a,p,a,i,i,a,p,a,p,a,a,i,i,i,i],
[i,i,a,p,p,p,i,i,i,i,i,i,i,i,a,a,a,a,i,i,a,a,p,p,a,p,i,i,i,i,a,p,a,a,p,a,a,a,p,a],
[i,i,i,i,a,a,i,i,p,a,i,i,a,a,a,p,a,a,i,i,a,p,i,i,a,a,p,p,a,a,i,i,a,p,i,i,a,p,i,i],
[a,a,i,i,i,i,i,i,i,i,i,i,i,i,i,i,a,a,i,i,i,i,i,i,i,i,i,i,a,a,i,i,p,a,i,i,i,i,i,i],
[a,a,i,i,i,i,i,i,a,a,i,i,i,i,a,a,i,i,i,i,i,i,a,a,a,a,a,p,p,a,i,i,p,p,a,a,a,a,i,i]
]).

