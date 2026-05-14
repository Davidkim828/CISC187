# C-LinkedList

# Stack using Linked List

## 1. Why is a linked list efficient for stack implementation?

A linked list is efficient because insertion and deletion at the head take O(1) time. Since a stack only operates on the top element, a linked list is a natural fit

---

## 2. Time complexity of push and pop

- push(): O(1)
- pop(): O(1)

---

## 3. What happens if memory is not deallocated?

If memory is not deallocated, it causes a memory leaks. Over time, this can consume all available memory and crash the program.

---

## 4. Array vs Linked List stack

Array:
- Fast access
- Fixed size

Linked List:
- Dynamic size
- No overflow if memory is not full
