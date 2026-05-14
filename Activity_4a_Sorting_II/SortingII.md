# Insertion Sort Assignment

## Objective

Understand the working of insertion sort algorithm and evaluate the algorithm's efficiency.

---

## Task 1: Average Case of Insertion Sort

Insertion sort has an average-case time complexity of:

```text
O(N²)
```

For insertion sort, each element is inserted into the sorted part of the array.

In the average case, each new element is compared with about half of the previous elements.

```text
1/2 + 2/2 + 3/2 + ... + (N-1)/2
```

This becomes:

```text
N(N-1) / 4
```

After removing constants and lower terms:

```text
O(N²)
```

### Figure

```text
Original array:

[5, 4, 3, 2, 1]

Pass 1:
[4, 5, 3, 2, 1]

Pass 2:
[3, 4, 5, 2, 1]

Pass 3:
[2, 3, 4, 5, 1]

Pass 4:
[1, 2, 3, 4, 5]
```

---

## Task 2: Operation Count

Let:

```text
N = 5
Array = [5, 4, 3, 2, 1]
```

Count:

```text
comparison: A[j] > key
shift: A[j+1] = A[j]
```

---

## Part A: Start at i = 1

```text
i = 1: 1 comparison + 1 shift = 2
i = 2: 2 comparisons + 2 shifts = 4
i = 3: 3 comparisons + 3 shifts = 6
i = 4: 4 comparisons + 4 shifts = 8
```

Total:

```text
2 + 4 + 6 + 8 = 20
```

Answer:

```text
20 operations
```

---

## Part B: Start at i = 2

```text
i = 2: 2 comparisons + 2 shifts = 4
i = 3: 3 comparisons + 3 shifts = 6
i = 4: 4 comparisons + 4 shifts = 8
```

Total:

```text
4 + 6 + 8 = 18
```

Answer:

```text
18 operations
```

---

## Part B: Start at i = 3

```text
i = 3: 3 comparisons + 3 shifts = 6
i = 4: 4 comparisons + 4 shifts = 8
```

Total:

```text
6 + 8 = 14
```

Answer:

```text
14 operations
```

---

## Part C

If the algorithm starts at `i = 2` or `i = 3`, it does not correctly sort the entire array.

Insertion sort assumes the first part of the array is already sorted.

Starting at `i = 1` makes the sorted part begin correctly from the first element.

If we skip `i = 1`, some earlier elements may not be placed in the correct order.

---

## Task 3: containsX Function

### Original Code

```javascript
function containsX(string) {
    foundX = false;

    for (let i = 0; i < string.length; i++) { 
        if (string[i] === "X") {
            foundX = true; 
        }
    }

    return foundX; 
}
```

---

## Part A

The time complexity is:

```text
O(N)
```

The function checks every character in the string.

---

## Part B: Improved Code

```javascript
function containsX(string) {
    for (let i = 0; i < string.length; i++) { 
        if (string[i] === "X") {
            return true;
        }
    }

    return false;
}
```

### Time Complexity

Best case:

```text
O(1)
```

Average case:

```text
O(N)
```

Worst case:

```text
O(N)
```

The improved version stops as soon as it finds `"X"`.

---

## Final Answers

| Task | Answer |
|---|---|
| Insertion sort average case | O(N²) |
| Start at i = 1 | 20 operations |
| Start at i = 2 | 18 operations |
| Start at i = 3 | 14 operations |
| Does it still sort fully? | No |
| containsX original | O(N) |
| containsX improved best case | O(1) |
| containsX improved average case | O(N) |
| containsX improved worst case | O(N) |
