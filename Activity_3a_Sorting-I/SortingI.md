# Sorting Algorithms Assignment

## Objective

Understand the working of sorting algorithms and evaluate the efficiency of algorithms using Big O Notation.

---

## Task 1

Use Big O Notation to describe the time complexity of an algorithm that takes:

```text
4N + 16 steps
```

## Answer

```text
O(N)
```

---

## Task 2

Use Big O Notation to describe the time complexity of an algorithm that takes:

```text
2N² steps
```

## Answer

```text
O(N²)
```

---

## Task 3

Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled.

```ruby
def double_then_sum(array) 
    doubled_array = []

    array.each do |number| 
        doubled_array << number *= 2
    end

    sum = 0

    doubled_array.each do |number| 
        sum += number
    end

    return sum 
end
```

## Answer

```text
O(N)
```

---

## Task 4

Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases.

```ruby
def multiple_cases(array) 
    array.each do |string|
        puts string.upcase 
        puts string.downcase 
        puts string.capitalize
    end 
end
```

## Answer

```text
O(N)
```

---

## Task 5

The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array.

```ruby
def every_other(array) 
    array.each_with_index do |number, index|
        if index.even?
            array.each do |other_number|
                puts number + other_number
            end 
        end
    end 
end
```

## Answer

```text
O(N²)
```

---

## Final Answers

| Task | Big O Notation |
|---|---|
| 4N + 16 steps | O(N) |
| 2N² steps | O(N²) |
| double_then_sum | O(N) |
| multiple_cases | O(N) |
| every_other | O(N²) |
