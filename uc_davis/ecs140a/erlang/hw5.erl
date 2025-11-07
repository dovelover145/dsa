-module(hw5).
-export([myelem/2, myremoveduplicates/1, myintersection/2, mylast/1, myreverse/1, myreverse_h/2, myreplaceall/3, loop/0, send/2]).


% From lecture slides
myelem(_, []) -> false;
myelem(Item, [Y | Ys]) -> (Item == Y) or (myelem(Item, Ys)).


myremoveduplicates([]) -> [];
myremoveduplicates([H | T]) -> 
    case myelem(H, T) of
        true -> myremoveduplicates(T);
        false -> [H | myremoveduplicates(T)]
    end.


myintersection([], _) -> [];
myintersection([H1 | T1], L2) ->
    case myelem(H1, L2) of
        true -> [H1 | myintersection(T1, L2)];
        false -> myintersection(T1, L2)
    end.


mylast([]) -> [];
mylast([H | []]) -> [H];
mylast([_ | T]) -> mylast(T).


myreverse(L) -> myreverse_h(L, []).

myreverse_h([], Result) -> Result; 
myreverse_h([H | T], Result) -> myreverse_h(T, [H | Result]).


myreplaceall(_, _, []) -> [];
myreplaceall(NewVal, OldVal, [H | T]) ->
    case OldVal == H of
        true -> [NewVal | myreplaceall(NewVal, OldVal, T)];
        false -> [H | myreplaceall(NewVal, OldVal, T)]
    end.