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


Length Increasing Subsequence

At the start the lis_tab look like this :

| LIS   |---|---|---|---|---|
|-------|---|---|---|---|---|
|INDEX | 2 | 1 | 3 | 4 | 5 |
|LIS | 1 | 1 | 1 | 1 | 1 |

LIS of all index is egal to 1 there are all at least a lis of length 1

I starting at size - 1
J starting at i + 1
if (index[i] < index[j] && lis[i] < lis[j] + 1)
	lis[i] = lis[j] + 1


|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 1 | 1 | 2 | 1 |
|I & J 	|   |   |   | I | J |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS 	| 1 | 1 | 3 | 2 | 1 |
|I & J 	|   |   | I | J |   |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS 	| 1 | 1 | 3 | 2 | 1 |
|I & J 	|   |   | I |   | J |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	|   | I | J |   |   |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	|   | I |   | J |   |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	|   | I |   |   | J |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I | J |   |   |   |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I |   | J |   |   |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I |   |   | J |   |

|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I |   |   |   | J |

At the end the lis_tab look like this :
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |

So the best LIS is [0, 2, 3, 4]

## Find The Best Move

---

## Stats

Limit = 700
Number of tests = 100000

Average : 566
Max : 669
Min : 461

Number of tests above the limit : 0 / 100000

Limit = 12
Number of tests = 100000

Average : 8
Max : 12
Min : 0

Number of tests above the limit : 0 / 100000

Limit = 5500
Number of tests = 500

Average : 4684
Max : 5093
Min : 4349

Number of tests above the limit : 0 / 500

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
* **Thanks to Youva Gaudé & Johanne Vigny & ULYSSE LEVALLOIS & ALEX CARDONA & QUANTIN THIERRY & ELIA KHALED for the big help**
