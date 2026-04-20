*This project has been created as part of the 42 school program by arakotot.*

## Descriptions

**Push_swap** is a project that challenges you to create an algorithm to sort a list of integers using a limited set of operations on two stacks (a and b). The goal is to develop efficient sorting strategies that minimize the number of operations while handling various input sizes and edge cases.

### Objectives

- Parse command-line arguments into stack 'a' with error handling (duplicates, invalid ints, overflow).
- Implement core operations: sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr.
- Develop adaptive sorting algorithms for different stack sizes:
  * ≤3 elements: direct swaps/rotates
  * ≤100: medium chunking
  * ≤500: complex radix/target optimization
- Benchmarking and disorder metrics.
- Strict 42 Norm compliance (no leaks, efficient code).
- Custom libft and ft_printf integration.

## Instructions

### Compilation

```bash
make
```

Builds `push_swap` executable with enhanced Makefile featuring:
- Silent compilation (no gcc spam)
- Colored progress bar and status echoes
- Dependencies (libft, ft_printf) auto-built

**Clean targets:**
```bash
make clean      # remove .o files
make fclean     # full clean (executable + libs)
make re         # fclean + make
```

### Usage

**Sort numbers:**
```bash
./push_swap 2 1 3 6 5 4
```

**Benchmark mode:**
```bash
./push_swap --bench 100 500  # 100 random lists of size 500
```

### Expected output
Operations sequence (e.g., pb, pb, ra...) ending with sorted stack a (ascending).

## Installation

**Local use:**
```bash
make
cp push_swap /path/to/project/
```

## Testing

1. **Official 42 tester:** Check intra 42 cluster.
2. **Marius Toulch tester:** Clone https://github.com/marius-toulch/push_swap_tester
3. **Green tester:** https://github.com/LazyNinja62/push_swap_visualizer
4. **Benchmark locally:**
```bash
./push_swap --bench 500 100  # test large inputs
```

## Resources

- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Radix Sort](https://en.cppreference.com/w/cpp/algorithm/sort)

### AI Assistance
- Makefile enhancements (progress bar, silencing), debugging, optimization suggestions.
