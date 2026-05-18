# Space Constraints Activity

## Objective
The purpose of this activity is to analyze the space efficiency of algorithms using Big O notation and understand how different implementations affect memory usage.

---

# Task 1 — Word Builder Algorithm

## Code

```javascript
function wordBuilder(array) { 
    let collection = [];

    for(let i = 0; i < array.length; i++) { 
        for(let j = 0; j < array.length; j++) {

            if (i !== j) {
                collection.push(array[i] + array[j]);
            }

        }
    }

    return collection; 
}
```

## Space Complexity Analysis

The algorithm creates a new array called `collection`.

The nested loops generate combinations of words from the input array.  
For an array of size `n`, approximately `n²` strings are added into `collection`.

Therefore, the amount of additional memory grows proportionally to `n²`.

### Space Complexity

$begin:math:display$
O\(n\^2\)
$end:math:display$

---

# Task 2 — Reverse Array Function

## Code

```javascript
function reverse(array) { 
    let newArray = [];

    for (let i = array.length - 1; i >= 0; i--) { 
        newArray.push(array[i]);
    }

    return newArray;
}
```

## Space Complexity Analysis

The function creates a completely new array called `newArray`.

If the original array contains `n` elements, the new array will also contain `n` elements.

Thus, the extra memory usage grows linearly with the input size.

### Space Complexity

$begin:math:display$
O\(n\)
$end:math:display$

---

# Task 3 — Reverse Array Using O(1) Extra Space

## Code

```javascript
function reverseInPlace(array) {

    let left = 0;
    let right = array.length - 1;

    while (left < right) {

        let temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }

    return array;
}
```

## Explanation

This version reverses the array directly inside the original array instead of creating a second array.

Only a few temporary variables are used regardless of input size.

### Space Complexity

$begin:math:display$
O\(1\)
$end:math:display$

### Time Complexity

$begin:math:display$
O\(n\)
$end:math:display$

---

# Task 4 — Double Array Implementations

## Version #1

```javascript
function doubleArray1(array) { 
    let newArray = [];

    for(let i = 0; i < array.length; i++) { 
        newArray.push(array[i] * 2);
    }

    return newArray; 
}
```

### Analysis

- Iterates through the array once → `O(n)` time
- Creates a new array of size `n` → `O(n)` space

---

## Version #2

```javascript
function doubleArray2(array) {

    for(let i = 0; i < array.length; i++) {
        array[i] *= 2;
    }

    return array; 
}
```

### Analysis

- Iterates through the array once → `O(n)` time
- Modifies the existing array directly → `O(1)` extra space

---

## Version #3

```javascript
function doubleArray3(array, index=0) { 

    if (index >= array.length) {
        return;
    }

    array[index] *= 2;

    doubleArray3(array, index + 1);

    return array; 
}
```

### Analysis

- Recursive function visits each element once → `O(n)` time
- Recursive calls use the call stack → `O(n)` space

---

# Efficiency Table

| Version | Time Complexity | Space Complexity |
|---|---|---|
| Version #1 | O(n) | O(n) |
| Version #2 | O(n) | O(1) |
| Version #3 | O(n) | O(n) |

---

# Conclusion

This activity demonstrates how different implementations of the same problem can significantly affect memory usage.  
Algorithms that modify data in place are usually more space-efficient than those that create additional arrays or use recursion.
