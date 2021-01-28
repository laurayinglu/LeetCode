Heap review
============

- **Array Representation of BT**: if a node is at index i, left child is at index 2i, right child is at index 2i+1; its' parent is at index $\lfloor i/2 \rfloor$

- **Complete binary tree**: perfectly balanced, except for the bottom level, height = logN

- **Heap**:
  > use siftdown when deletion and siftup when insert

    - insert(x): compare x with parent and swap if it's larger. Complexity is O(1) to O(logn) = height, bottom-up
    - deletion: delete top node, swap top value with the last node value and then delete the last node, then adjust to preserve the max heap property. (up-bottom). Complexity O(logN)

- **Heap sort**: 
  - create heap: 10, 20, 15, 30, 40, insert each element (insert(x) function), nlogn
  - then delete the element until finish all of them. nlogn
  - Total: 2nlogn = O(nlogn)

- **Heapify**: Process of maintaining a heap (direction is different)
  
  - start from right to left, downward, siftdown
  - O(n) faster
  > A heap of size n has at most $\lceil \frac{n}{2^{h+1}} \rceil$ nodes at height h
  
  $$
    T(n) = \sum_{h=0}^{lgn} \lceil \frac{n}{2^{h+1}} \rceil*O(h) 
    = O(n* \sum_{h=0}^{lgn} \frac{h}{2^{h}}) = O(n* \sum_{h=0}^{\infty} \frac{h}{2^{h}})
  $$
    
  $$
\sum_{h=0}^{\infty} x^n = 1/(1-x)
  $$
  take derivative on both sides and multiply by x, get 
    $$
\sum_{h=0}^{\infty} nx^n = x/(1-x)^2
  $$

  Putting in the result back, we get Complexity = O(n)

- **Priority Queue**:
  - build max heap
  - heap: logn for insertion and logn for deletion