# push_swap

This C project is about sorting data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed this program manipulates various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.
A seperate `checker` executable validates if the instructions which are outputed by
the `push_swap` algortihm are indeed correct.

## Overview

- There are 2 stacks. Stack A and Stack B.
- At the beginning:
  - Stack A contains a random amount of negative and/or positive numbers which cannot be duplicated
  - Stack B is empty
- The goal is to sort in ascending order numbers into stack a.


## Stack Instructions

- To sort the stack it is only allowed to use these following instructions:

`sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

`sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

`ss` : sa and sb at the same time.

`pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

`pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

`ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

`rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

`rr` : ra and rb at the same time. rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

`rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one

`rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

`rrr` : rra and rrb at the same time.

## Installation + Compilation

```bash
$ git clone https://github.com/Dustin42Codam/push_swap.git
$ cd push_swap

# Compile both checker and push_swap
$ make

# Compile only the checker executable
$ make checker

# Compile only the push_swap executable
$ make push_swap
```

## Running the program

```bash
$ ./push_swap <set_of_integers>

e.g:
$ ./push_swap 42 8 12 451 23528 -12 2 0

# For running push_swap with larger sets of integers you can install
# ruby to generate a random set of integers for you and pass it
# to push_swap as an argument
$ ./push_swap `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
```

## Visualizing the algorithm

The output of this project is not really interesting.
To spice it up there is a neat open source python script made by Emmanuel Ruaud.
You can find the script also in my repository and directly run it.
Just make sure that you have python3 installed.

```bash
$ python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
```
