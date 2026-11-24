# Push_swap

*This project has been created as part of the 42 curriculum by moelgham.*

## Description

Push_swap is a sorting project from the 42 curriculum. The goal is simple to explain but challenging to do well: we have two stacks (`a` and `b`) and a limited set of instructions (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). Starting with a random list of unique integers in stack `a` and an empty stack `b`, the program must print the shortest possible sequence of instructions that sorts stack `a` in ascending order (smallest number on top).

The real difficulty is not sorting — it is sorting with as few operations as possible. My implementation uses a chunk-based approach inspired by quicksort: I push numbers from `a` to `b` around the median, rotate `b` to keep useful elements near the top, sort the remaining three elements in `a`, then push everything back to `a` while choosing the cheapest insertion point for each element (cost = rotations in `a` + rotations in `b` − combined rotations).

The project handles:
- Any number of arguments, including arguments containing multiple numbers separated by spaces.
- Error cases: non-integer arguments, integers outside `int` range, and duplicates.
- Small stacks with dedicated strategies (`sort_three` for 3 elements, and a special case for 2).

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable. The Makefile supports `all`, `clean`, `fclean`, and `re`.

### Execution

```bash
./push_swap 2 1 3 6 5 8
```

The program prints one instruction per line. To check the result:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l          # number of operations
./push_swap $ARG | ./checker_OS $ARG   # should print OK
```

If there are no arguments, the program prints nothing and exits. On invalid input it prints `Error` to standard error.

### Example

```bash
$> ./push_swap 3 2 1
sa
rra
$> ./push_swap 0 one 2 3
Error
```

## Technical choices

- **Parsing**: every argument is split on spaces with a custom `ft_split_mult`, then all tokens are appended into one array. Validation (digits only, optional leading `-`, `int` range via a sentinel value from `ft_atoi`, duplicates) happens after parsing.
- **Data structure**: a single `t_elem` array per stack, where each element stores `num`, `uses` (whether the slot is occupied) and `index` (its position, `-1` marks the end). This avoids linked lists and keeps rotations cheap.
- **Sorting strategy**:
  - 2 elements → one `sa` if needed.
  - 3 elements → `sort_three`.
  - More → push elements to `b` around the median (`get_median`), sort the rest with `sort_three`, then reinsert using `best_index` which minimizes the total rotation cost, including shared rotations handled by `count_coherences`.
- **Memory**: all allocations are freed at the end via `ft_free` / `ft_free_split`; error paths free before returning.

## Resources

- 42 push_swap subject (version 10.2).
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — used to observe the instruction flow on small stacks.
- [Big-O notation and sorting complexity](https://www.bigocheatsheet.com/) — refresher on algorithm complexity.
- Peer discussions at 42 about the "cheapest insertion" approach and chunk-based sorting.

### How AI was used

I used AI as a learning and debugging assistant, not as a code generator:
- **Understanding the algorithm**: I asked for explanations of the chunk/median approach and the cost calculation (rotations in `a` + rotations in `b` minus common rotations) before writing `resolve_stack` and `best_index`.
- **Debugging**: when the output was not sorted or the operation count was too high, I described the behavior and asked for possible causes; I then verified each suggestion by testing with the visualizer and the checker.
- **Documentation**: I used AI to help structure this README and to improve the clarity of my explanations.

All code in this repository was written, reviewed, and tested by me. I can explain every function and every design decision during the evaluation.
