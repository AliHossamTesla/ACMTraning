# Sparse Table

Sparse Table is a data structure, that allows answering range queries.It can answer most range queries in $O(\log n)$,but its true power is answering range minimum queries (or equivalent range maximum queries). For those queries it can compute the answer in $O(1)$ time. 

The only drawback of this data structure is, that it can only be used on immutable arrays. This means, that the array cannot be changed between two queries. If any element in the array changes, the complete data structure has to be recomputed.

## Intuition

Any non-negative number can be uniquely represented as a sum of decreasing powers of two.
This is just a variant of the binary representation of a number.
E.g. $13 = (1101)_2 = 8 + 4 + 1$.
For a number $x$ there can be at most $\lceil \log_2 x \rceil$ summands.