:- public lessons_by_decreasing_durations/1.

lessons_by_decreasing_durations(
	[14,15,17,24,5,6,8,13,16,18,19,1,2,3,4,7,9,10,11,12,20,21,22,23]
).


:- public lessons_by_increasing_durations/1.

lessons_by_increasing_durations(
	[23,22,21,20,12,11,10,9,7,4,3,2,1,19,18,16,13,8,6,5,24,17,15,14]
).


:- public lessons_by_decreasing_tokens_nb/1.

lessons_by_decreasing_tokens_nb(
	[12,1,18,6,10,16,21,23,24,3,11,20,2,5,13,19,7,8,15,22,4,9,14,17]
).


:- public lessons_by_increasing_tokens_nb/1.

lessons_by_increasing_tokens_nb(
	[17,14,9,4,22,15,8,7,19,13,5,2,20,11,3,24,23,21,16,10,6,18,1,12]
).


:- public duration/1.

duration([1,1,1,1,2,2,1,2,1,1,1,1,2,3,3,2,3,2,2,1,1,1,1,3]). 


:- public size/1.

size(20).


:- public data/1.

data([
[a,a,a,p,a,a,i,i,a,a,p,a,a,a,i,i,i,i,a,a,a,a,a,a,a,a,p,a,a,p,a,a,a,a,p,a,a,a,i,i],
[i,i,a,a,a,a,i,i,a,a,a,a,a,a,i,i,a,a,a,a,a,a,p,a,a,p,a,a,a,a,a,a,a,a,a,a,i,i,i,i],
[a,a,a,a,a,a,a,a,p,a,i,i,p,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,p,a,i,i,a,a,a,a,a,a,a,a],
[a,a,a,a,a,a,a,a,a,a,a,a,a,a,i,i,a,a,i,i,a,a,i,i,a,a,a,a,a,a,a,a,a,a,a,a,a,a,i,i],
[a,a,a,i,a,a,a,i,a,a,a,i,a,a,a,i,a,a,i,i,p,a,a,i,a,p,i,i,a,a,i,i,a,a,a,i,a,a,i,i],
[a,a,a,i,i,i,i,i,i,i,i,i,a,p,i,i,a,p,a,i,a,a,a,i,i,i,a,i,a,a,a,i,p,p,a,i,i,i,a,i],
[i,i,i,i,a,a,a,a,i,i,i,i,i,i,i,i,i,i,a,a,a,a,i,i,a,a,i,i,a,a,p,a,i,i,a,a,a,a,a,a],
[i,i,a,i,a,a,i,i,p,a,a,i,a,a,a,i,a,a,a,i,a,a,a,i,i,i,a,i,a,a,a,i,i,i,a,i,i,i,a,i],
[a,a,i,i,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,i,i,a,a],
[a,a,a,a,a,a,a,a,a,a,i,i,a,a,a,a,a,a,a,p,i,i,a,p,a,a,a,p,p,a,a,a,i,i,a,a,a,a,a,a],
[i,i,i,i,a,a,a,a,a,p,a,a,a,a,a,a,p,p,a,a,i,i,i,i,i,i,a,a,a,a,a,a,a,a,i,i,a,a,a,a],
[p,a,a,a,p,a,a,a,a,a,a,p,a,p,a,a,a,a,a,a,a,a,a,a,i,i,a,a,a,a,a,a,p,a,a,a,p,a,a,a],
[i,i,i,i,a,a,a,i,a,a,a,i,a,p,a,i,a,a,a,i,i,i,i,i,a,a,a,i,a,a,a,i,a,p,i,i,i,i,a,i],
[a,a,i,i,a,a,i,i,a,a,i,i,i,i,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,i,i,i,i,a,a,i,i],
[a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,p,i,i,a,a,i,i],
[a,a,a,i,a,p,i,i,a,p,p,i,a,a,a,i,a,a,a,i,a,a,a,i,a,a,a,i,a,a,a,i,i,i,p,i,a,a,a,i],
[a,a,i,i,i,i,i,i,i,i,i,i,a,a,i,i,a,a,i,i,a,a,i,i,i,i,i,i,a,a,i,i,a,a,i,i,a,a,i,i],
[a,a,a,i,a,a,a,i,a,a,a,i,a,a,i,i,a,a,a,i,a,p,a,i,a,p,a,i,p,a,a,i,p,a,a,i,i,i,p,i],
[a,a,a,i,p,a,a,i,a,a,a,i,a,a,a,i,p,a,i,i,i,i,a,i,i,i,a,i,a,a,a,i,a,a,a,i,i,i,a,i],
[i,i,a,a,a,a,a,a,a,a,a,a,a,a,a,a,i,i,a,a,a,a,a,a,p,a,a,a,a,p,a,a,a,a,a,a,p,a,a,a],
[a,a,a,a,a,a,a,a,p,a,a,a,p,a,a,a,a,a,a,a,a,a,a,a,a,a,i,i,a,a,i,i,a,a,a,p,a,a,a,p],
[a,a,i,i,i,i,i,i,a,a,a,a,a,a,a,a,a,a,a,a,i,i,a,a,a,a,a,a,p,a,i,i,a,a,a,a,i,i,i,i],
[i,i,a,a,a,p,a,a,a,a,p,a,p,a,i,i,a,a,a,a,a,p,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,i,i],
[i,i,i,i,p,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,a,a,i,i,p,a,i,i,a,a,i,i,p,a,i,i,p,a,i,i]
]).
