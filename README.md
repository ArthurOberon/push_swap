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

---

# How My Push_Swap Work ?

|STEP		|Description	|
|---------------|---------------|
|LIS			| Length Increase Subsequence	|
|Find The Best Move| Calcul the number of move for each element of pile_b and do the best	|

## LIS

## Find The Best Move

# Result
Complexite moyenne: 566
Complexite max : 649
Complexite min : 488

NB d'elem dont la complexite est sup a la lim : 0 / 1000

Complexite moyenne: 9
Complexite max : 13
Complexite min : 0

NB d'elem dont la complexite est sup a la lim : 0 / 1000

Complexite moyenne: 4699
Complexite max : 5016
Complexite min : 4444

NB d'elem dont la complexite est sup a la lim : 0 / 100

## Malloc Protections :
- [x] get_next_line
- [x] ft_tab_from_list
- [x] ft_lstnew_instruction
- [x] ft_malloc_zero
- [x] ft_lst_add
- [x] ft_strdup
- [x] ft_tab_from_list (index)
- [x] ft_tab_from_list (lis_utils)
- [x] ft_init_lis_tab
- [x] ft_create_lis

## Author
* **[Arthur Obéron](https://github.com/ArthurOberon)**
* **Thanks to Johanne Vigny & ULYSSE LEVALLOIS & ALEX CARDONA & QUANTIN THIERRY & ELIA KHALED for the big help**
