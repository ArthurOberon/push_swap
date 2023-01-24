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

*!!!! CHECK THE BOLD FIRST !!!!*

Start algo -> first find own way to do a algo -> then try maybe quicksort -> etc...

functions to :
* read list ?
* compare element value and next (if > or <)
* push if element > next
* to push b->a in ascending order in a, ascending part to ascending part
* to move lst to push in the right place

Do summary of all malloc variable to do a function to exit and free all in case of error ?

5 7 14 10 9 13 15 12 4 0 6 11 3 8 1 2


6 8 11 4 12 10 14 3

Ascending :
* if next = max => push
* if tmp < next => push
* if tmp = min => go next

Descending :
* if next = min => push
* if tmp > next => push
* if tmp = max => go next

=> Problems -> pushing tmp and not tmp next...
? change next = X to prev = X ? :
	Ascending :
* if tmp = max => go next
* if tmp = min => go next
* if prev = max => go next ---> without that it seems to work...
* if tmp = max and prev = min => push
* if prev > tmp => push
	Descending :
* if tmp = max => go next
* if tmp = min => go next
* if prev = min => go next
* if tmp = min and prev = max => push
* if prev < tmp => push

For now => Not working with some cases
IDEAS for patch :
* after the sort -> if not in order -> sorting with sa/ra
* do one more verification after check all the piles
* **create function to find if prev is < and next > => push if not**
**=> can try to do all the mouvement with this system**
**push this number and then check the one which take the place pushed one**

Problematics Numbers :
`1 2 6 4 0 5 7 3`
`4 1 2 0 5 6 7 3`
`3 2 5 7 0 6 4 1`
`3 4 5 7 0 1 6 2`
