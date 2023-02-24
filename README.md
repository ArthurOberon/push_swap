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
ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG
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
|Find The Best Move| Calcul the number of move for each element of Stack B and do the best	|

## LIS

Length Increasing Subsequence is used to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

### For example :

At the start it will look like this :

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX	| 2 | 1 | 3 | 4 | 5 |
|LIS	| 1 | 1 | 1 | 1 | 1 |

LIS of all index is egal to 1 because there are all at least a lis of length 1

Initialization of variable :
```
I = size - 1;
J = I - 1;
```
Condition to change LIS[I]
```
if (index[i] < index[j] && lis[i] < lis[j] + 1)
	lis[i] = lis[j] + 1;
```

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 1 | 1 | 2 | 1 |
|I & J 	|   |   |   | I | J |


`I--`
`J = I - 1`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS 	| 1 | 1 | 3 | 2 | 1 |
|I & J 	|   |   | I | J |   |

`J++`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS 	| 1 | 1 | 3 | 2 | 1 |
|I & J 	|   |   | I |   | J |

`I--`
`J = I - 1`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	|   | I | J |   |   |

`J++`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	|   | I |   | J |   |

`J++`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	|   | I |   |   | J |

`I--`
`J = I - 1`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I | J |   |   |   |

`J++`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I |   | J |   |   |

`J++`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I |   |   | J |   |

`J++`

| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |
|I & J	| I |   |   |   | J |

At the end the lis_tab look like this :
| POS   | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
|INDEX 	| 1 | 0 | 2 | 3 | 4 |
|LIS	| 1 | 4 | 3 | 2 | 1 |

So the length of LIS is : `4`
And the LIS is : `[0, 2, 3, 4]`
## Find The Best Move

To find the best move, I create a structure :
```
typedef struct s_best_move
{
	int		sa;			// Number of sa
	int		sb;			// Number of sb
	int		rota_dir_a;		// Number of rotation on a (negatif is for rra)
	int		rota_dir_b;		// Number of rotation on b (negatif is for rrb)
	int		size;			// Sum of all previous variables + 1 (+ 1 is for pa)
}	t_best_move;
```

* For each element of the stack B, it found the best movement with respect to its position in the stack. And saved the t_best_move with the smallest size
* When he has finished calculating the movements for each of the elements, it makes the movements that have been saved (by using each variable of the struct to know if we do a sa, rra, rb, rr, etc...)
* Repeat, until the Stack is empty

* And TADA, it sorted !
---

## Stats
For 1 to 5 :
```
Limit = 12
Number of tests = 100000

Average : 8
Max : 12
Min : 0

Number of tests above the limit : 0 / 100000
```

For 1 to 100 :
```
Limit = 700
Number of tests = 100000

Average : 566
Max : 669
Min : 461

Number of tests above the limit : 0 / 100000
```

For 1 to 500 :
```
Limit = 5500
Number of tests = 500

Average : 4684
Max : 5093
Min : 4349

Number of tests above the limit : 0 / 500
```

# VISUALIZER

## Usage

To check if the set of instructions sort correctly :
```
./checker_visu/checker 1 2 3
```
To check if the set of instructions sort correctly with the visualizer add `-v` :
```
./checker_visu/checker -v 1 2 3
```

### Example with visualizer:
```
ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker_visu/checker -v $ARG
```
On fish :
```
set ARG (ruby -e "puts (-50..50).to_a.shuffle.join(' ')") ; ./push_swap $ARG | ./checker_visu/checker -v $ARG
```

### Compiling

```
make -C checker_visu/
```

## Author
* **[Arthur Obéron](https://github.com/ArthurOberon)**
* **Thanks to :**
* **[Youva Gaudé](https://github.com/Eviber)**
* **Alex Cardona**
* **Johanne Vigny**
* **Elia Khaled**
* **Ulysse Levallois**
* **[Quentin Thierry](https://github.com/QuentinThierry/)**
