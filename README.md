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
- Silent compilation
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
./push_swap --bench 2 1 3 6 5 4
```
**Simple strategy:**
```bash
./push_swap --simple 2 1 3 6 5 4
```
**Medium strategy:**
```bash
./push_swap --medium 2 1 3 6 5 4
```
**Complex strategy:**
```bash
./push_swap --complex 2 1 3 6 5 4
```

### Expected output
Operations sequence (e.g., pb, pb, ra...) ending with sorted stack a (ascending).

## Resources

- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Radix Sort](https://en.cppreference.com/w/cpp/algorithm/sort)
- [Tutorials](https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/)

### AI Assistance
- Makefile enhancements (progress bar, silencing), debugging, optimization suggestions.

## Algorithms & Strategies

This project implements an **adaptive multi-strategy sorting dispatcher** that selects the most efficient algorithm based on the input size. The strategies leverage two stacks (`a` and `b`) and a restricted instruction set to minimize the total number of operations.

---

### 1. Simple Sort (`size ≤ 20`)

**Type:** *Hardcoded Micro-optimizations + Selection Sort + Insertion Sort*

For very small inputs, the algorithm uses a hybrid approach optimized for minimal stack operations:

- **2–3 elements:** Hardcoded decision trees (`sort_two` / `sort_three`) directly apply `sa` (swap), `ra` (rotate), or `rra` (reverse rotate) based on value comparisons. This avoids any loop overhead.
- **4–20 elements:** A **Selection Sort** variant is used:
  1. Repeatedly find the minimum element in stack `a`.
  2. Rotate it to the top using the shortest path (`ra` or `rra`).
  3. Push it to stack `b` (`pb`).
  4. Continue until only 3 elements remain in `a`, which are sorted with `sort_three`.
  5. Finally, **Insertion Sort** is performed: elements in `b` are pushed back to `a` (`pa`) one by one, inserting each at its correct sorted position by rotating `a`.

> **Reasoning:** For small `n`, the overhead of complex indexing or chunking outweighs the simplicity of direct min-finding and insertion.

---

### 2. Medium Sort (`20 < size ≤ 200`)

**Type:** *Index-Based Chunking / Bucket Sort + Greedy Retrieval*

For medium-sized inputs, the algorithm switches to an **index-based chunking strategy** that reduces the cost of finding individual minima or maxima:

1. **Indexing:** All values are first mapped to their rank (index) in the sorted order, so comparisons rely on integer ranges rather than relative values.
2. **Chunk Size:** The stack is divided into chunks of size `sqrt(size) × 2`. This balances the number of rotation passes needed in `a` versus the number of elements to reorganize in `b`.
3. **Push to B:** The algorithm scans stack `a` and rotates until an element belonging to the current index range `[lower, upper]` is on top. It is then pushed to `b` (`pb`).
   - **Optimization:** If the pushed element's index is in the lower half of the current chunk, an extra `rb` (rotate `b`) is applied to keep smaller values at the bottom of `b`, effectively pre-sorting `b` into two zones.
4. **Bounds Update:** Once a chunk is fully pushed, the bounds are shifted to the next chunk.
5. **Greedy Retrieval:** After all elements are in `b`, the algorithm repeatedly finds the **maximum** element in `b`, rotates it to the top (shortest path via `rb` or `rrb`), and pushes it back to `a` (`pa`). Because `a` is being filled from largest to smallest, it ends up sorted in ascending order.

> **Reasoning:** Chunking groups nearby-ranked elements together, reducing random access costs. The greedy max retrieval exploits the fact that stack `b` acts as a temporary buffer where extracting maxima in reverse order naturally builds the sorted sequence in `a`.

---

### 3. Complex Sort (`size > 200`)

**Type:** *Binary Radix Sort (Least Significant Bit — LSD)*

For large inputs, the algorithm uses a **Binary Radix Sort** on the element indices. This strategy guarantees near-linear operation counts and scales efficiently to 500+ elements:

1. **Indexing:** As with medium sort, values are converted to their sorted rank (index).
2. **Bit-Pass Loop:** For each bit position `i` from `0` up to the maximum number of bits needed to represent the largest index (`max_bits`):
   - Scan through all elements currently in stack `a`.
   - If the `i`-th bit of the element's index is `1`, rotate `a` (`ra`) — keeping it in `a`.
   - If the bit is `0`, push it to `b` (`pb`).
   - After one full pass, all elements with bit `0` are in `b`, and those with bit `1` remain in `a` (in original relative order).
3. **Restore:** All elements from `b` are pushed back to `a` (`pa`), restoring them on top of the `1`-bit group.
4. **Repeat:** The process repeats for the next bit position. Because `a` is processed LSD-first, each pass preserves the ordering stability of previously sorted lower bits.

> **Reasoning:** Radix Sort operates in `O(n × log(max_index))` stack operations, which is predictable and efficient for large `n`. Unlike comparison-based sorts, it does not require finding minima or maxima, eliminating expensive scanning and rotation patterns. The two-stack architecture naturally supports the partition-into-buckets behavior of radix sorting.

---

### 4. Adaptive Dispatcher

**Type:** *Strategy Router*

The `sort_adaptive` function acts as the central dispatcher:

| Input Size | Strategy Selected | Sort Type |
|------------|------------------|-----------|
| `≤ 1` | Already sorted | — |
| `≤ 20` | Simple Sort | Selection + Insertion |
| `≤ 200` | Medium Sort | Chunking / Bucket Sort |
| `> 200` | Complex Sort | Binary Radix Sort (LSD) |

> **Reasoning:** No single algorithm is optimal across all input sizes. Hardcoded logic and selection sort excel for tiny inputs due to low overhead. Chunking provides a middle-ground trade-off between locality and operation count. Radix sort dominates asymptotically for large inputs due to its linearithmic behavior and lack of comparison-based searching.