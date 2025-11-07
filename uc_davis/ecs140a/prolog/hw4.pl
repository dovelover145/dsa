shuffle([], [], []).
shuffle([H1 | T1], [H2 | T2], [H1, H2 | T3]) :- shuffle(T1, T2, T3).


double([], []).
double([H1 | T1], [H1, H1 | T2]) :- double(T1, T2).


no_duplicates([], []).
no_duplicates([H1 | T1], [H1 | T2]) :- \+element(H1, T1), no_duplicates(T1, T2).
no_duplicates([H1 | T1], [H2 | T2]) :- element(H1, T1), no_duplicates(T1, [H2 |T2]).

element(Val, [Val | _]).
element(Val, [_ | T1]) :- element(Val, T1).


same_elements([], []).
same_elements(L1, L2) :- is_permutation(L1, L1, L2).

is_permutation([], _, _).
is_permutation([H1 | T1], L1, L2) :- count(H1, L1, C), count(H1, L2, C), is_permutation(T1, L1, L2).

count(_, [], 0).
count(Val, [H1 | T1], C) :- Val = H1, count(Val, T1, CP), C is CP + 1; Val \= H1, count(Val, T1, CP), C is CP.