# Push_Swap - 42 School Project

## Description
This is an implementation of the **Push Swap** project from 42 School. The goal is to sort a list of integers using two stacks (a and b) with a limited set of operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.

Features:
- Efficient sorting algorithms: simple (≤3), medium (≤100), complex (≤500), adaptive
- Parsing with error handling (duplicates, non-integers, overflow)
- Benchmarking mode (`--bench`)
- Custom ft_printf and libft integrations
- Compliant with 42 norms

## Build & Run
```bash
make
./push_swap 2 1 3
# Expected: ra pb sa pa pa (or equivalent minimal moves)
```

### Testing
```bash
./push_swap $(shuf -n 100 -e {1..100}) | wc -l  # Count moves
./push_swap $(shuf -n 500 -e {1..500}) | wc -l
```

## Operations Implemented
- swap (sa/sb/ss)
- push (pa/pb) 
- rotate (ra/rb/rr)
- reverse rotate (rra/rrb/rrr)

## Strategies
- **Simple**: Insertion sort for ≤3 elements
- **Medium**: Radix-like for ≤100
- **Complex/Adaptive**: Optimized chunking based on disorder metric

## Author
**Alexandro Rakototsiafa** - [GitHub](https://github.com/rakototsiafa-alexandro-tolotra)
