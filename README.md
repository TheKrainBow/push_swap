# push_swap
## This is my implementation of project Push_swap at 42 school.
## DO NOT USE THIS CODE AS A REFERENCE

### Goal of the project:
In this project, you must sort a series of number, using simple operations on two stacks.

### Parts implemented:
- ✅ push_swap
- ✅ Bonus
  - ✅ random option
  - ✅ color option
  - ✅ visualise option
  - ✅ checker

### Validated by school:
- ❌ push_swap
- ❌ Bonus
  - ❌ random option
  - ❌ color option
  - ❌ visualise option
  - ❌ checker
  
### How to use:
1. Clone the project
  ```git clone https://github.com/TheKrainBow/push_swap```
2. Make the project
  ```make```
3. Execute push_swap
  ```./push_swap <number1> <number2> <number3> <...>```
  Numbers have to be ints, and must not be equal to any other number in the stack.
  The first argument is at the top of the stack, the last at the bottom.
4. Enjoy :)

### Bonus
You can add the flags r c and v in the execution, to have differents behaviors:
- with r (for random), instead of giving a list of number as argument, you must give two numbers.
  - ```./push_swap -r <size_of_stack_to_generate> <seed_for_random>```
  - For exemple, ```./push_swap -r 10 5``` will generate a random array of 10 numbers, and sort it using my push_swap algorithme.
- with c (for color), all output will be colored in:
    - red if the oeration affects stack A.
    - green if the operation affects stack B.
    - blue if the operation affects both.
- with v (for visualize), output is fully changed. It will no more print operations, but show the progress directly on the stacks.

The second bonus is to do a checker executable, that check if the output actually sort the stack. <br \n>
If it's sorted, it output OK, if it's not, it output KO.
It will output "Error." followed by a newline in any wrong usage.
```$ARG="2 4 1 3 6 5"; ./push_swap $ARG | ./checker $ARG``` should output OK
```$ARG="2 4 1 3 6 5"; ./push_swap $ARG | ./checker 98 65 42 1``` should output KO
Checker should work with -r and -c.

Exemples of use:
```
./push_swap -rvc 30 5
./push_swap -c 5 4 1 0 3 2 6
./push_swap -r 500 5 | ./checker -r 500 5
./push_swap
./push_swap NOPE
./push_swap 0 0 1 1 2 2 3 3
```

### Operations:
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.
