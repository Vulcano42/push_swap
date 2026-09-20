*This project has been created as part of the 42 curriculum by ibabilonia.*

# Push_swap

## Description

**Push_swap** is a sorting algorithm project from the 42 curriculum.

The objective is to sort a list of integers using two stacks, **A** and
**B**, while using a limited set of operations.

The program receives a sequence of integers as arguments and generates
a sequence of operations that sorts the numbers in ascending order.

## Stacks

The project uses two stacks:

```text
Stack A                 Stack B

[  42  ]               [     ]
[  10  ]               [     ]
[  5   ]               [     ]
[  1   ]               [     ]
```

Initially, all numbers are placed in **Stack A** and **Stack B** is
empty.

The objective is:

```text
A → [ 1 2 3 4 5 ... ]
B → [           ]
```

## Allowed Operations

### Swap

```text
sa    Swap the first two elements of A
sb    Swap the first two elements of B
ss    sa and sb simultaneously
```

### Push

```text
pa    Push the first element of B to A
pb    Push the first element of A to B
```

### Rotate

```text
ra    Rotate A upward
rb    Rotate B upward
rr    ra and rb simultaneously
```

### Reverse Rotate

```text
rra   Rotate A downward
rrb   Rotate B downward
rrr   rra and rrb simultaneously
```

## Algorithm

The project uses **indexing/ranking** to work with the position of each
number in the sorted sequence.

Instead of comparing only the original values, each number receives a
rank.

For example:

```text
Input:

50 10 80 30 20

Ranks:

3 0 4 2 1
```

This makes it easier to determine the position of each element during
the sorting process.

## Chunks

The algorithm divides the elements into **chunks**.

The number of chunks is calculated according to the size of Stack A.

For example:

```text
chunk = ft_isqrt(3 * size / 2) + 2;
```

For `size = 5`:

```text
3 × 5 / 2 + 2
15 / 2 + 2
7 + 2
9
```

The chunks are then used to progressively move elements between the
two stacks while controlling their positions.

## Sorting Small Inputs

For small numbers of elements, the project uses dedicated sorting
logic instead of the complete chunk-based algorithm.

This avoids unnecessary operations and keeps the algorithm efficient
for small inputs.

## Modes

The program supports different sorting strategies through command-line
flags.

### `--simple`

Uses the simple sorting strategy.

```bash
./push_swap --simple 5 2 8 1 3
```

### `--medium`

Uses the medium sorting strategy.

```bash
./push_swap --medium 5 2 8 1 3
```

### `--complex`

Uses the complex sorting strategy.

```bash
./push_swap --complex 5 2 8 1 3
```

### `--adaptive`

Automatically selects the sorting strategy according to the disorder
of the input.

```bash
./push_swap --adaptive 5 2 8 1 3
```

### `--bench`

Displays information about the sorting process and its performance.

```bash
./push_swap --bench 5 2 8 1 3
```

Flags can also be combined according to the project's supported
interface.

## Disorder

The project calculates the degree of disorder of the input.

The disorder value ranges from:

```text
0 → completely sorted
10000 → completely disordered
```

The adaptive mode uses this value to select the sorting strategy.

The current thresholds are:

```text
disorder < 2000  → SIMPLE
disorder < 5000  → MEDIUM
otherwise        → COMPLEX
```

## Input Validation

The program validates the input before sorting.

Invalid inputs include:

* Non-numeric arguments
* Values outside the range of an `int`
* Duplicate numbers
* Invalid formatting

When an invalid input is detected, the program outputs:

```text
Error
```

## Compilation

Compile the project with:

```bash
make
```

The executable generated is:

```text
push_swap
```

Example:

```bash
./push_swap 4 67 3 87 23
```

The program outputs the operations required to sort the stack.

## Example

Input:

```bash
./push_swap 2 1 3
```

Possible output:

```text
sa
```

Result:

```text
Before:

A = [2 1 3]

sa

After:

A = [1 2 3]
```

## Project Structure

```text
push_swap/
├── push_swap.c
├── parse.c
├── ops.c
├── ...
├── Makefile
└── README.md
```

## Concepts

This project focuses on:

* Algorithms
* Sorting
* Stack manipulation
* Linked lists
* Indexing
* Input parsing
* Memory management
* Algorithm complexity
* Operation optimization
* Data structures

## Goal

The main challenge of Push_swap is not only to sort the numbers, but to
find an efficient sequence of operations while respecting the limited
set of instructions provided by the project.

## Author

Thiago mendes/thialima 

https://github.com/Vulcano42/push_swap

Batriz Silva /beatrida

https://github.com/biagwmes/push_swap.git

42 São Paulo

