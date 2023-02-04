![Norminette](https://github.com/ArthurOberon/Push_swap/actions/workflows/norminette.yml/badge.svg) ![Makefile](https://github.com/ArthurOberon/Push_swap/actions/workflows/makefile.yml/badge.svg)

---

# Push\_swap

This project is about sorting numbers with 2 stacks and only the following operations :
* `sa`	: Swap A -> Swap the 2 first element at the top of stack A. Do nothing if there is only one or no elements.
* `sb`	: Swap B -> Swap the 2 first element at the top of stack B. Do nothing if there is only one or no elements.
* `ss`	: Swap A and B at the same time.
* `pa`	: Push A -> Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* `pb`	: Push B -> Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* `ra`	: Rotate A -> Shift up all elements of stack A by 1. The first element becomes the last one.
* `rb`	: Rotate B -> Shift up all elements of stack B by 1. The first element becomes the last one.
* `rr`	: Rotate A and B at the same time.
* `rra` : Reverse Rotate A -> Shift down all elements of stack A by 1. The last element becomes the first one
* `rrb` : Reverse Rotate B -> Shift down all elements of stack B by 1. The last element becomes the first one
* `rrr` : Reverse Rotate A and B at the same time.

## Usage

To generate a set of instructions for a set of number :
```
./push_swap 1 2 3
```
or
```
./push_swap "1 2 3"
```

To check if the set of instructions sort correctly :
```
./push_swap 1 2 3 | ./checker 1 2 3
```

To create a set of random numbers :
```
ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
```
### Example :
```
ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker -v $ARG
```
On fish :
```
set ARG (ruby -e "puts (-50..50).to_a.shuffle.join(' ')") ; ./push_swap $ARG | ./checker $ARG
```

### Compiling
To compile push_swap :
```
make all
```

To compile the checker :
```
make bonus
```


## Author
* **[Arthur Obéron](https://github.com/ArthurOberon)**
* **Thanks to Johanne Vigny for the big help**
---

*!!!! IF THERE, CHECK THE BOLD FIRST !!!!*

Do summary of all malloc variable to do a function to exit and free all in case of error ?

#### Problematics/Reference Numbers :
```
5 7 14 10 9 13 15 12 4 0 6 11 3 8 1 2
```
- [x]
```
6 8 11 4 12 10 14 3
```
- [x]
```
1 2 6 4 0 5 7 3
```
- [x]
```
4 1 2 0 5 6 7 3
```
- [x]
```
3 2 5 7 0 6 4 1
```
- [x]
```
3 4 5 7 0 1 6 2
```
- [x]
```
4 0 5 2 7 6 1 3
```
- [x]
```
4 2 0 7 6 5 3 1
```
- [x]
```
6 5 2 1 4 3 0 7
```
- [x]
```
4 7 6 3 5 1 2 0
```
- [x]
```
1 2 3 -1 4 5 0 7 8 9 -10
```
- [x]
#### Current test
```
1 2 3 -1 4 5 0 7 8 9 10
```
- [x]
```
1 15 0 3 10 6 13 4 8 9 5 12 2 7 11 14
```
- [x]
#### Test Error, Get all sort in A but with error
INFINITY LOOP :
```
5 4 14 12 10 15 3 6 2 11 0 8 1 13 9 7
```
- [x]
```
11 6 2 13 8 12 15 10 5 7 4 14 1 9 0 3
```

- [x]

NOT SORTED :
```
8 10 2 9 14 15 12 1 5 4 3 13 0 11 7 6
```

- [x]

```
5 4 14 12 10 15 3 6 2 11 0 8 1 13 9 7
```
- [x]
```
8 12 13 3 15 4 7 2 1 6 9 11 10 5 14 0
```
- [x]

# RESTART !
|Restart		|Description	|Current Status		|
|---------------|---------------|-----------|
|Index			| Using a tab and sort_int_tab	| <ul><li>- [x] Done</li></ul>	|
|Find ascending	| Find biggest sequence, push all the top expect min of start, push all bottom expect max of end	| <ul><li>- [ ] Done</li></ul>	|
|Calcul move	| For the X first, and apply the smaller, till the end	| <ul><li>- [ ] Done</li></ul>	|
|Others Ideas	| See Ideas	| <ul><li>- [ ] Done</li></ul>	|

## Find Ascending
- [x] Check the list to find the biggest ascendant sequence's coordonate
- [x] Push all the top part but keep the min
- [x] Move to the bottom part
- [x] Push all the bottom part but keep the max
- [ ] Norminette
 
 ## Find Ascending Not Effecient Enough
 Try to :
 - Calcul the biggest ascending sequence's with numbers in between, using the index : if < push else keep

## Calcul Move
- [x] Create a variable in list_instruction which the opposite of his operation
- [x] Create ft_no_lo_se -> calcul number of mouv to place on X first number
- [x] Calcul mouv and write in tmp list_instruction
- [x] Reverse the list to get back at the start
- [x] If smaller write in tmp_smaller list_instruction
- [x] Else delete list
- [x] Restart while i != X
- [ ] Norminette

## FT_NO_LO_SE
- [x] If index between first and second => pa sa
- [x] If index bigger than last => pa
- [x] Else find if rra or ra to rotate the list
- [ ] Norminette

## Ideas :
- [ ] Create ft_check -> check if 3 or less element, or others checkable things
- [ ] Create ft_check_evidence -> at the start, check for evident mouv (ex : 2 1 => sa : 1 2)
- [x] Create ft_optimize_rotation -> find if it is better to do ra/b or rra/b

## Have to :
- [ ] Find the good X for test for X first number of b the best mouvement
- [ ] Get the right parsing with all the subtleties
- [ ] Manage malloc and their protections
- [ ] Free all without leaks (maybe with a function to free and exit)
- [ ] Check instruction list to find mouvements that can be combinated (ex : ra, rb => rr)

# Currents Problems
- [ ] Do not use sb at all -> bad ?
