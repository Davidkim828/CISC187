# Adaptive Sorting Strategy

## Objective

The objective of this assignment is to analyze how input order affects sorting algorithm performance and to apply that analysis to make an adaptive algorithmic decision.

---

## Time Complexity Table

| Sorting Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Selection Sort | O(N²) | O(N²) | O(N²) |
| Insertion Sort | O(N) | O(N²) | O(N²) |

---

# Part A: Adaptive Sorting Selection

## Threshold Definition

I used the number of adjacent inversions to classify the array.

An adjacent inversion happens when:

```text
array[i] > array[i + 1]
```

For an array of 50 integers, there are 49 adjacent pairs.

My threshold:

```text
0 to 10 inversions: Best Case / Nearly Sorted
11 to 38 inversions: Average Case
39 to 49 inversions: Worst Case
```

Decision:

```text
Best Case / Nearly Sorted -> Use Insertion Sort
Average Case -> Use Selection Sort
Worst Case -> Use Selection Sort
```

---

## Code

```javascript
function selectionSort(array) {
    let arr = [...array];

    for (let i = 0; i < arr.length - 1; i++) {
        let minIndex = i;

        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        let temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    return arr;
}

function insertionSort(array) {
    let arr = [...array];

    for (let i = 1; i < arr.length; i++) {
        let key = arr[i];
        let j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return arr;
}

function countAdjacentInversions(array) {
    let count = 0;

    for (let i = 0; i < array.length - 1; i++) {
        if (array[i] > array[i + 1]) {
            count++;
        }
    }

    return count;
}

function classifyCase(array) {
    let inversions = countAdjacentInversions(array);

    if (inversions <= 10) {
        return "Best Case";
    } else if (inversions >= 39) {
        return "Worst Case";
    } else {
        return "Average Case";
    }
}

function adaptiveSort(array) {
    let caseType = classifyCase(array);
    let sortedArray;
    let algorithm;

    if (caseType === "Best Case") {
        algorithm = "Insertion Sort";
        sortedArray = insertionSort(array);
    } else {
        algorithm = "Selection Sort";
        sortedArray = selectionSort(array);
    }

    console.log("Original Array:");
    console.log(array);

    console.log("Case:");
    console.log(caseType);

    console.log("Selected Algorithm:");
    console.log(algorithm);

    console.log("Sorted Array:");
    console.log(sortedArray);
}

let numbers = [
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50
];

adaptiveSort(numbers);
```

---

# Part B: Case Classification Without Sorting

## Code

```javascript
function countAdjacentInversions(array) {
    let count = 0;

    for (let i = 0; i < array.length - 1; i++) {
        if (array[i] > array[i + 1]) {
            count++;
        }
    }

    return count;
}

function classifyWithoutSorting(array) {
    let inversions = countAdjacentInversions(array);

    if (inversions >= 39) {
        return "Worst Case";
    } else {
        return "Average Case";
    }
}

let userInput = [
    50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
    40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
    30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
    20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1
];

console.log("Classification:");
console.log(classifyWithoutSorting(userInput));
```

---

# Part C: Documentation

## Threshold

I used adjacent inversions to measure how sorted the array already is.

```text
0 to 10 inversions = Best Case
11 to 38 inversions = Average Case
39 to 49 inversions = Worst Case
```

Since the array has 50 integers, it has 49 adjacent pairs.

---

## Reasoning

If the array has very few adjacent inversions, it is already sorted or nearly sorted.

Insertion Sort is better for this situation because it can run close to `O(N)`.

If the array has many inversions, especially close to descending order, I choose Selection Sort because it always runs consistently in `O(N²)`.

---

## Algorithm Selection

```text
Best Case -> Insertion Sort
Average Case -> Selection Sort
Worst Case -> Selection Sort
```

Insertion Sort is chosen when the array is nearly sorted.

Selection Sort is chosen when the array is not nearly sorted because its time complexity does not change much based on the input order.

---

## Time Complexity Discussion

Selection Sort always looks for the minimum value in the unsorted part of the array.

Because of this, Selection Sort has:

```text
Best Case: O(N²)
Average Case: O(N²)
Worst Case: O(N²)
```

Insertion Sort performs well when the array is already sorted or nearly sorted.

Insertion Sort has:

```text
Best Case: O(N)
Average Case: O(N²)
Worst Case: O(N²)
```

So input order affects Insertion Sort more than Selection Sort.

---

# Final Summary

| Part | Result |
|---|---|
| Sorting algorithms used | Selection Sort and Insertion Sort |
| Threshold method | Adjacent inversions |
| Best case algorithm | Insertion Sort |
| Average case algorithm | Selection Sort |
| Worst case algorithm | Selection Sort |
| Part B sorting performed? | No |
