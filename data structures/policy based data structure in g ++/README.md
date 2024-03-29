# **policy based data structure in g++**(not end yet)

The g++ compiler also supports some data structures that are not part of the C++ standard library. Such structures are called policy-based data structures. These data structures are designed for high-performance, flexibility, semantic safety, and conformance to the corresponding containers in std.

To use these structures, the following lines must be added to the code: 
```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
```
what we will discuss about : 
1. Ordered Set
2. ordered map
# **1. Ordered Set**

# **Motivation** :

Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order. It performs all the operations as performed by the set data structure in STL in $log(n)$ omplexity and performs two additional operations also in $log(n)$ omplexity .
- **order_of_key (k)** :

 Number of items strictly smaller than k : 
 It returns to the number of items that are strictly smaller than our item k in $O(logn)$ time.

 Let us assume we have a set s : {1, 5, 6, 17, 88}, then :

s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.

s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
- **find_by_order(k)** : $k^{th}$ element in a set (counting from zero).

It returns to an iterator to the $k^{th}$ element (counting from zero) in the set in $O(logn)$ time.To find the first element $k$ must be zero.

Let us assume we have a set s : {1, 5, 6, 17, 88}, then :

*(s.find_by_order(2)) : $3^{th}$ element in the set i.e. 6

*(s.find_by_order(4)) : $5^{th}$ element in the set i.e. 88
*note* : Required header files to implement ordered set and their description : 

For implementing ordered_set and GNU C++ library contains other Policy based data structures we need to include :

```cpp
include <ext/pb_ds/assoc_container.hpp> // Common file
include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
```
The first one is used to include the associative containers or group of templates such as set, multimap, map etc.The tree-based data structures which we will be using below is present in this header file.
The second header file is used to include the 

tree_order_statistics_node update which is explained below:
```cpp
using namespace __gnu_pbds;
```
It is a namespace necessary for the GNU based Policy based data structures.

The tree based container has a concrete structure but the necessary structure required for the ordered set implementation is :
```cpp
tree < int ,  null_type ,  less ,  rb_tree_tag ,  tree_order_statistics_node_update >
```
1. **int** : It is the type of the data that we want to insert (KEY).It can be integer, float or pair of int etc.
2.  **null_type** : It is the mapped policy. It is null here to use it as a set.If we want to get map but not the set, as the second argument type must be used mapped type.
3. **less** : It is the basis for comparison of two functions.
4. **rb_tree_tag** : type of tree used. It is generally Red black trees because it takes log(n) time for insertion and deletion while other take linear time such as splay_tree.
5. **tree_order_statistics_node__update** : It is included in tree_policy.hpp and contains various operations for updating the node variants of a tree-based container, so we can keep track of metadata like the number of nodes in a subtree .

## ***Set Vs Ordered Set***
There is not so much difference between the set and ordered set although ordered set can be assumed as an extended version of set capable of performing some more advanced functions(stated above) that are extensively used in competitive programming.

# **2. Ordered map**

## Problems 
soon ......(work in it).

## Resource
[Documentation](https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/)

[geeksforgeeks 1](https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/)

[geeksforgeeks 2](https://www.geeksforgeeks.org/policy-based-data-structures-g/)

[Codeforces Article](https://codeforces.com/blog/entry/11080)