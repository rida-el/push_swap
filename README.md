### Steps:

- [X] parse input
   - [X] split args
   - [X] read individual numbers
- [X] check for invalid input
- [X] store in stack
- [ ] create moves funtions
  - [X] sa - swap a: swap the first 2 elements at the top of stack a. (do nothing if there is only one or no elements).
  - [X] sb - swap b: swap the first 2 elements at the top of stack b. (do nothing if there is only one or no elements).
  - [X] ss - ss: swap a and swap b at the same time.
  - [X] pa - push a: take the first element at the top of b and put it at top of a. (do nothing if b is empty).
  - [X] pb - push b: take the first element at the top of a an dput it at top of b. (do nothing if a is empty).
  - [X] ra - rotate a: shift up all elements of stack a by 1. the first element becomes the last one.
  - [X] rb - rotate b: shift up all elements of stack b by 1. the first element becomes the last one.
  - [X] rr - rr: rotate a and rotate b at the same time.
  - [X] rra - reverse rotate a: shift down all elements of stack a by 1. the last element becomes the first one.
  - [X] rrb - reverse rotate b: shift down all elements of stack b by 1. the last element beoomes the first one.
  - [X] rrr - rrr: reverse rotate a and reverse rotate b at the same time.
- [ ] Implement sorting algorithm

Algo:
- [X] copy stack into array
- [X] sort array
- [X] calculate P1 and P2 ( P1 = SIZE / {3 or 5 or 6} ---- P2 = P1 / 2)
- [X] S1 - Get value of Vp1 and Vp2
- [X] S2 - loop over stack, if (elm <= P1) {pb; if(elm <= P2) rb} else {ra}; || loop condition: only do P1 + 1 iteration (P1 is the index)
- [X] Repeat S1 AND S2 until stack A has only 1 element
- [X] S3 - ==> Now stack B has ALL elements except one
- [X] S4 - find index(MAX(stack B)); if(index <= size(stack B) / 2){ rb until TOP_STACK_B == MAX(stack B); then pa}; else {rrb until TOP_STACK_B == MAX(stack B); then pa}
- [X] S5 - Repeat S4 until STACK_B is empty.

Extra chekcs:
- [] Check if stack is alreay sorted
- [] handle stack size <= 3
- [X] handle stack size <= 5
- [X] handle stack size >= 100
- [X] handle stack size >= 500
- [ ] handle case like "./push_swap 1 - 6 3" or "./push_swap 1 "-" 6 97 2"
- [ ] handle case like "./push_swap 1 "" 87 656556"
