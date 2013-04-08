new_compiler_files([wamcc0,wamcc1,wamcc2,wamcc3,wamcc4,wamcc5,wamcc6,wamcc7,wamcc8,
                wamcc]).
path('../src/').

read_files([],_).
read_files([F|Files],Path):-
	name(F,SF),
	name(Path,SP),
	append(SP,SF,SX),
	name(X,SX),
	consult(X),
	read_files(Files,Path).

make_new_compiler :-	
	path(Path),
	new_compiler_files(Files),
	read_files(Files,Path).
