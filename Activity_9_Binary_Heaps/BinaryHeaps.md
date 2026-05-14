# Binary Heaps Assignment

## 1) Heap after inserting 11

The given heap is a **max heap**, so after inserting `11`, it is first placed in the next open position to keep the tree complete. Then it is compared with its parent and swapped upward until the max-heap property is restored.

### Original heap
```text
          10
        /    \
       9      8
     /  \    / \
    6    5  7   4
   / \   /
  2   1 3
After inserting 11

11 is inserted as the right child of 5, then it moves up above 5, above 9, and above 10.

          11
        /    \
      10      8
     /  \    / \
    6    9  7   4
   / \   / \
  2   1 3   5

## 2) Heap after deleting the root node

Now delete the root from the previous heap.
	1.	Remove the root 11
	2.	Move the last element 5 to the root
	3.	Bubble it down until the max-heap property is restored

### Result

          10
        /    \
       9      8
     /  \    / \
    6    5  7   4
   / \   /
  2   1 3

After deleting the root, the heap returns to the same structure as the original heap.

## 3) Order after popping all values from a new heap

Insert these values into a new max heap in this order:

55, 22, 34, 10, 2, 99, 68

Since this is a max heap, each pop removes the largest value remaining.

### Pop order

99, 68, 55, 34, 22, 10, 2


##Final Answers
1.	After inserting 11:

          11
        /    \
      10      8
     /  \    / \
    6    9  7   4
   / \   / \
  2   1 3   5

2.	After deleting the root from that heap:

          10
        /    \
       9      8
     /  \    / \
    6    5  7   4
   / \   /
  2   1 3

3.	Pop order from the new heap:

99, 68, 55, 34, 22, 10, 2


