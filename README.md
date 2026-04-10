*This project has been created as part of the 42 curriculum by herasoan, arakotot*.

## Descriptions
This is an implementation of the **Push Swap** project from 42 School. The goal is to sort a list of integers using two stacks (a and b) with a limited set of operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.

### Features:
- Efficient sorting algorithms: simple (≤3), medium (≤100), complex (≤500), adaptive
- Parsing with error handling (duplicates, non-integers, overflow)
- Benchmarking mode (`--bench`)
- Custom ft_printf and libft integrations
- Compliant with 42 norms

### Operations Implemented:
- swap (sa/sb/ss)
- push (pa/pb) 
- rotate (ra/rb/rr)
- reverse rotate (rra/rrb/rrr)

### Strategies:
- **Simple**: Insertion sort for ≤3 elements
- **Medium**: Radix-like for ≤100
- **Complex/Adaptive**: Optimized chunking based on disorder metric

## Instructions

### Installation

```bash
make
./push_swap 2 1 3
```
