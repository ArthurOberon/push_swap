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

# RESTART

|Restart		|Description	|Current Status		|
|---------------|---------------|-----------|
|Index			| get index in the pile a	| <ul><li>- [x] Done</li><li>- [x] Norminette</li></ul>	|
|Part 1			| Find a way to separate pile a in two	| <ul><li>- [ ] Done</li><li>- [ ] Norminette</li></ul>	|
|Part 2			| Find a way to calcul the smaller move with position in the pile and not by doing the move and go back	| <ul><li>- [x] Done</li><li>- [x] Norminette</li></ul>	|
|Optimize		| Find Optimizations	| <ul><li>- [ ] Done</li><li>- [ ] Norminette</li></ul>	|

## Part 1
- [ ] ...
- [ ] Norminette

## Part 2
- [x] Find his position in the pile
- [x] If x > pile_length / 2 => ra/b
- [x] Else => rra/b
- [x] Find a way to also use sa/sb
- [x] Do that for each element and find the smaller
- [x] Do the smaller move
- [x] Do it again till the end
- [x] Norminette

## Optimize
- [ ] ...
- [ ] Norminette

## Malloc Protections :
- [x] get_next_line
- [x] ft_tab_from_list
- [x] ft_lstnew_instruction
- [x] ft_malloc_zero
- [x] ft_lst_add
- [x] ft_get_ascending_sequence
- [x] ft_strdup
- [ ] ft_create_ascending_tab
- [ ] ft_create_descending_tab

# Currents Problems
- [ ] 5 4 3 2 1	-> 14 moves
- [ ] 5 1 4 3 2	-> 14 moves
