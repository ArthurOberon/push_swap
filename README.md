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

### Problematics/Reference Numbers :
```
19 94 65 0 93 71 18 64 33 50 10 85 30 26 97 55 52 42 35 72 96 70 78 36 86 88 21 5 59 67 84 68 20 57 43 34 54 73 29 99 48 95 40 51 9 98 81 25 22 56 80 100 66 12 63 4 60 92 91 15 13 3 44 69 89 16 77 58 17 14 87 46 83 6 75 74 32 49 7 1 38 37 28 90 62 31 76 79 8 82 27 24 39 45 47 23 41 61 11 53 2
```
- [x] Working with 2292 moves (way to much) ! New record ! -> 601

```
20 3 13 42 34 49 19 28 1 4 47 40 16 22 15 33 14 21 37 17 5 27 48 44 39 38 23 46 29 24 12 9 7 45 6 2 25 11 32 43 30 8 26 41 18 10 36 0 31 50 35
```
- [x] Working with 635 moves (way to much) ! New record ! -> 282

```
23 16 25 24 19 14 20 9 0 8 17 12 1 15 3 4 22 6 18 11 21 10 5 7 13 2
```
- [x] Working with 186 moves (way to much) ! New record ! -> 97

```
10 8 5 3 4 7 6 0 2 1 9
```
- [x] Working with 40 moves (to much) ! New record ! ->28

```
5 7 14 10 9 13 15 12 4 0 6 11 3 8 1 2
```
- [x] Working
```
6 8 11 4 12 10 14 3
```
- [x] Working
```
1 2 6 4 0 5 7 3
```
- [x] Working
```
4 1 2 0 5 6 7 3
```
- [x] Working
```
3 2 5 7 0 6 4 1
```
- [x] Working
```
3 4 5 7 0 1 6 2
```
- [x] Working
```
4 0 5 2 7 6 1 3
```
- [x] Working
```
4 2 0 7 6 5 3 1
```
- [x] Working
```
6 5 2 1 4 3 0 7
```
- [x] Working
```
4 7 6 3 5 1 2 0
```
- [x] Working
```
1 2 3 -1 4 5 0 7 8 9 -10
```
- [x] Working
### Current test
```
1 2 3 -1 4 5 0 7 8 9 10
```
- [x] Working
```
1 15 0 3 10 6 13 4 8 9 5 12 2 7 11 14
```
- [x] Working
```
20 8 11 19 18 9 17 4 10 5 7 16 15 1 6 3 2 14 12 13
```
- [x] Working
```
8 2 12 19 17 16 18 13 14 9 15 20 7 3 11 5 6 10 4 1
```
- [x] Working
```
17 12 16 5 7 4 20 1 19 10 14 8 3 11 18 6 15 9 13 2
```
- [x] Working
### Test Error, Get all sort in A but with error
#### INFINITY LOOP :
```
5 4 14 12 10 15 3 6 2 11 0 8 1 13 9 7
```
- [x] Working
```
11 6 2 13 8 12 15 10 5 7 4 14 1 9 0 3
```
- [x] Working
#### NOT SORTED :
```
8 10 2 9 14 15 12 1 5 4 3 13 0 11 7 6
```
- [x] Working
```
5 4 14 12 10 15 3 6 2 11 0 8 1 13 9 7
```
- [x] Working
```
8 12 13 3 15 4 7 2 1 6 9 11 10 5 14 0
```
- [x] Working
# RESTART !
|Restart		|Description	|Current Status		|
|---------------|---------------|-----------|
|Index			| Using a tab and sort_int_tab	| <ul><li>- [x] Done</li><li>- [x] Norminette</li></ul>	|
|Find ascending	| Find biggest sequence, push all the top expect min of start, push all bottom expect max of end	| <ul><li>- [x] Done</li><li>- [ ] Norminette</li></ul>	|
|Calcul move	| For the X first, and apply the smaller, till the end	| <ul><li>- [x] Done</li><li>- [ ] Norminette</li></ul>	|
|Others Ideas	| See Ideas	| <ul><li>- [x] Done</li><li>- [ ] Norminette</li></ul>	|

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
- [x] Create ft_check -> check if 3 or less element, or others checkable things
- [x] Create ft_check_evidence -> at the start, check for evident mouv (ex : 2 1 => sa : 1 2)
- [x] Create ft_optimize_rotation -> find if it is better to do ra/b or rra/b

## Have to :
- [x] Find the best X for "Test mouvement for the X first element of B and take the fastest one"
- [x] Get the right parsing with all the subtleties
- [ ] Manage malloc and their protections
- [x] Free all without leaks (maybe with a function to free and exit)
- [x] Check instruction list to find mouvements that can be combinated (ex : ra, rb => rr)
- [ ] Find optimizations

# Currents Problems
- [ ] Do not use sb at all -> bad ?
