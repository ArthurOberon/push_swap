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

---

*!!!! IF THERE, CHECK THE BOLD FIRST !!!!*

Do summary of all malloc variable to do a function to exit and free all in case of error ?

#### Problematics/Reference Numbers :
```
5 7 14 10 9 13 15 12 4 0 6 11 3 8 1 2
```
```
6 8 11 4 12 10 14 3
```
```
1 2 6 4 0 5 7 3
```
```
4 1 2 0 5 6 7 3
```
```
3 2 5 7 0 6 4 1
```
```
3 4 5 7 0 1 6 2
```
```
4 0 5 2 7 6 1 3
```
```
4 2 0 7 6 5 3 1
```
```
6 5 2 1 4 3 0 7
```
```
4 7 6 3 5 1 2 0
```
```
1 2 3 -1 4 5 0 7 8 9 -10
```
#### Current test
```
1 2 3 -1 4 5 0 7 8 9 10
```

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
- [ ] If index bigger than last => pa ra
- [x] Else find if rra or ra to rotate the list
- [ ] Norminette

## Ideas :
- [ ] Create ft_check -> check if 3 or less element, or others checkable things
- [ ] Create ft_check_evidence -> at the start, check for evident mouv (ex : 2 1 => sa : 1 2)
- [ ] Create ft_found_place -> to get where is a precise number in the list and found if is better to do rra or ra to go to this one

# Currents Problems
-  If index bigger than last => pa ra seem to missing some condition to be good
