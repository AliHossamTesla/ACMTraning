# **Sparse Table**

Sparse Table is a data structure, that allows answering range queries.It can answer most range queries in $O(\log n)$,but its true power is answering range minimum queries (or equivalent range maximum queries). For those queries it can compute the answer in $O(1)$ time. 

The only drawback of this data structure is, that it can only be used on immutable arrays. This means, that the array cannot be changed between two queries. If any element in the array changes, the complete data structure has to be recomputed.

## **Motivation**

I can represent any nonnegative number in summution of power of two, in other words, $13 = 2^3 + 2^2 + 2^0$. which called binary representation we can simple write it $13 = (1101)_2 = 8 + 4 + 1$.

we can go to good point how number of ones in it ?

For a number $x$ there can be at most $\lceil \log_2 x \rceil$ Ones.

In another hand if I have intervail $[2, 14]$ can represent as $[2, 14] = [2, 9] \cup [10, 13] \cup [14, 14]$

what's the maximum number of distribution i can make for intervail ?

also there the union consists of at most $\lceil \log_2(\text{length of interval}) \rceil$ many intervals.

note : $\lceil  x \rceil$ refere to x rounded up .

The main idea behind Sparse Tables is to precompute all answers for range queries with power of two length. Afterwards a different range query can be answered by splitting the range into ranges with power of two lengths, looking up the precomputed answers, and combining them to receive a complete answer.

## **Precomputation**


