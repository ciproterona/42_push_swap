<p align="center">
  <i>This project has been created as part of the 42 curriculum by eroque-d, jobezerr</i>
</p>
<h1 align="center">Push_swap</h1>
<p align="center">
  <strong>Because Swap_push doesn’t feel as natural</strong>
</p>

## Description

Push_swap sorts a stack of unique integers using only the operations allowed by the
project: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` and `rrr`.

The program contains the four strategies required by the subject and can select one
at runtime. By default, it measures the initial disorder and chooses a strategy
automatically.

## Build and usage

```sh
make
./push_swap 4 67 3 87 23
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive --bench 4 67 3 87 23
```

> Operations are written to standard output. Benchmark information is written to
> standard error, so the operation stream can still be piped to a checker.

## Codebase Structure

The program follows this sequence:

1. `src/main.c` reads flags and arguments.
2. `src/parsing/` validates integers, rejects duplicates and assigns indexes.
3. `compute_disorder` measures how far the original stack is from sorted.
4. `sort_selected` chooses one of the four sorting strategies.
5. Functions in `src/operations/` update the stacks and print each operation.
6. `src/benchmark/` prints optional statistics to standard error.
7. `src/program.c` owns program initialization, cleanup and fatal errors.

The main data types are intentionally distinct:

- `t_node` is one integer stored in a linked-list node.
- `t_stack` is a stack, with its head, size and output statistics.
- `t_program` contains stacks A and B plus command-line configuration.

## Source layout

```text
src/
├── main.c                 command-line flow
├── program.c              initialization, cleanup and errors
├── parsing/               integer validation and indexing
├── stack/                 linked-list primitives
├── operations/            Push_swap operations and output
├── algorithms/            the four sorting strategies
└── benchmark/             optional operation statistics
```

## Algorithms

### Simple — O(n²)

The simple strategy repeatedly finds the smallest value, rotates it to the top and
pushes it to stack B. Values are then pushed back to stack A in sorted order.

### Medium — O(n√n)

The medium strategy divides indexed values into ranges. It pushes values to stack B
chunk by chunk, then repeatedly moves the largest remaining value back to stack A.

### Complex — O(n log n)

The complex strategy is a binary LSD radix sort. For each index bit, values with a
zero bit move to stack B while values with a one bit rotate in stack A. Stack B is
then pushed back before processing the next bit.

### Adaptive

The adaptive strategy counts inverted pairs before performing any move:

- disorder below `0.2`: simple strategy;
- disorder from `0.2` up to `0.5`: medium strategy;
- disorder of `0.5` or more: complex strategy.

These thresholds and complexity classes follow the current subject. Complexity is
measured in generated Push_swap operations.

## Resources

- The Push_swap subject supplied with the project
- Donald Knuth, *The Art of Computer Programming, Volume 3: Sorting and Searching*
- Oceano, [push_swap: a performant sorting algorithm using 2 stacks](https://www.youtube.com/watch?v=OaG81sDEpVk)

### AI

AI was used to assist with code review, refactoring suggestions and test
generation.

## License

This repository follows the [42 Unlicense](./LICENSE).

Feel free to open issues, suggest improvements or send pull requests! ദ്ദി˙ ᴗ ˙ )
