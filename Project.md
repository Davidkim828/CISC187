# Project Activity: Optimized Algorithms in C++

In this project, I solved six different algorithm problems using C++. For each task, I tried to avoid the slower nested-loop solution and used a faster approach instead. I also included the time complexity for each solution.

---

## Task 1: Players Who Play Both Sports

### Explanation

For this task, I need to find players who are in both the basketball list and the football list.

The slow way would be to compare every basketball player with every football player. That would work, but it would take `O(N * M)` time.

A better way is to put all basketball players' full names into an `unordered_set`. Then I can go through the football players and check if their names are already in the set. Since searching in an `unordered_set` is usually very fast, this makes the total runtime `O(N + M)`.

### Time Complexity

`O(N + M)`

### Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct Player {
    string first_name;
    string last_name;
    string team;
};

vector<string> findPlayersInBothSports(const vector<Player>& basketballPlayers,
                                       const vector<Player>& footballPlayers) {
    unordered_set<string> basketballNames;
    vector<string> result;

    for (const Player& player : basketballPlayers) {
        string fullName = player.first_name + " " + player.last_name;
        basketballNames.insert(fullName);
    }

    for (const Player& player : footballPlayers) {
        string fullName = player.first_name + " " + player.last_name;

        if (basketballNames.find(fullName) != basketballNames.end()) {
            result.push_back(fullName);
        }
    }

    return result;
}

int main() {
    vector<Player> basketballPlayers = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    vector<Player> footballPlayers = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    vector<string> result = findPlayersInBothSports(basketballPlayers, footballPlayers);

    cout << "Players who play both sports:" << endl;
    for (const string& name : result) {
        cout << name << endl;
    }

    return 0;
}
```

---

## Task 2: Missing Integer

### Explanation

In this task, the array has numbers from `0` to `N`, but one number is missing.

Instead of checking every possible number with nested loops, I used the sum formula. First, I find what the sum should be if no number was missing. Then I subtract the actual sum of the array. The difference is the missing number.

For example, if the full numbers should be `0` through `6`, I calculate the expected sum of those numbers. Then I subtract the sum of the given array.

### Time Complexity

`O(N)`

### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int findMissingInteger(const vector<int>& numbers) {
    int n = numbers.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int number : numbers) {
        actualSum += number;
    }

    return expectedSum - actualSum;
}

int main() {
    vector<int> numbers1 = {2, 3, 0, 6, 1, 5};
    vector<int> numbers2 = {8, 2, 3, 9, 4, 7, 5, 0, 6};

    cout << "Missing integer in first array: " << findMissingInteger(numbers1) << endl;
    cout << "Missing integer in second array: " << findMissingInteger(numbers2) << endl;

    return 0;
}
```

---

## Task 3: Greatest Stock Profit

### Explanation

For this problem, I need to find the best profit from buying one stock and selling it later.

The important part is that buying must happen before selling. So while I go through the prices, I keep track of the lowest price I have seen so far. At each day, I check how much profit I would make if I sold on that day.

If that profit is bigger than the current best profit, I update the answer.

### Time Complexity

`O(N)`

### Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int greatestStockProfit(const vector<int>& prices) {
    if (prices.size() < 2) {
        return 0;
    }

    int lowestPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        int currentProfit = prices[i] - lowestPrice;

        maxProfit = max(maxProfit, currentProfit);
        lowestPrice = min(lowestPrice, prices[i]);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {10, 7, 5, 8, 11, 2, 6};

    cout << "Greatest stock profit: " << greatestStockProfit(prices) << endl;

    return 0;
}
```

---

## Task 4: Highest Product of Two Numbers

### Explanation

At first, I thought I could just find the two biggest numbers and multiply them. But that does not always work because there can be negative numbers.

For example, `-10 * -6` becomes positive `60`, which can be bigger than multiplying two positive numbers.

So I kept track of four values:

- the largest number
- the second largest number
- the smallest number
- the second smallest number

At the end, I compare these two products:

- largest times second largest
- smallest times second smallest

The bigger one is the answer.

### Time Complexity

`O(N)`

### Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>
using namespace std;

int highestProductOfTwo(const vector<int>& numbers) {
    if (numbers.size() < 2) {
        throw invalid_argument("Array must contain at least two numbers.");
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int number : numbers) {
        if (number > largest) {
            secondLargest = largest;
            largest = number;
        } else if (number > secondLargest) {
            secondLargest = number;
        }

        if (number < smallest) {
            secondSmallest = smallest;
            smallest = number;
        } else if (number < secondSmallest) {
            secondSmallest = number;
        }
    }

    int product1 = largest * secondLargest;
    int product2 = smallest * secondSmallest;

    return max(product1, product2);
}

int main() {
    vector<int> numbers = {5, -10, -6, 9, 4};

    cout << "Highest product of two numbers: " << highestProductOfTwo(numbers) << endl;

    return 0;
}
```

---

## Task 5: Sort Temperature Readings

### Explanation

For this task, the temperature readings only go from `97.0` to `99.0`, and they only use one decimal place.

That means there are not many possible values. Because of that, I can use counting sort instead of a normal sorting algorithm.

I multiply each temperature by 10 so I can use it like an integer. For example:

- `98.6` becomes `986`
- `97.1` becomes `971`

Then I count how many times each temperature appears. After that, I rebuild the sorted list from lowest to highest.

### Time Complexity

`O(N)` because the temperature range is fixed.

### Code

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> sortTemperatures(const vector<double>& temperatures) {
    const int minTemp = 970;
    const int maxTemp = 990;
    const int range = maxTemp - minTemp + 1;

    vector<int> counts(range, 0);
    vector<double> sortedTemperatures;

    for (double temperature : temperatures) {
        int index = static_cast<int>(round(temperature * 10)) - minTemp;
        counts[index]++;
    }

    for (int i = 0; i < range; i++) {
        while (counts[i] > 0) {
            double temperature = (minTemp + i) / 10.0;
            sortedTemperatures.push_back(temperature);
            counts[i]--;
        }
    }

    return sortedTemperatures;
}

int main() {
    vector<double> temperatures = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};

    vector<double> sortedTemperatures = sortTemperatures(temperatures);

    cout << "Sorted temperatures:" << endl;
    for (double temperature : sortedTemperatures) {
        cout << temperature << " ";
    }
    cout << endl;

    return 0;
}
```

---

## Task 6: Longest Consecutive Sequence

### Explanation

For this task, I need to find the longest sequence of numbers that go up by 1.

Sorting the array would make this easier, but sorting would take `O(N log N)`. To keep it `O(N)`, I used an `unordered_set`.

First, I put all numbers into the set. Then, for each number, I only start counting if it is the beginning of a sequence. A number is the beginning if `number - 1` is not in the set.

Then I keep checking `number + 1`, `number + 2`, and so on until the sequence stops.

### Time Complexity

`O(N)` average time.

### Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutiveSequence(const vector<int>& numbers) {
    unordered_set<int> numberSet(numbers.begin(), numbers.end());
    int longestLength = 0;

    for (int number : numbers) {
        if (numberSet.find(number - 1) == numberSet.end()) {
            int currentNumber = number;
            int currentLength = 1;

            while (numberSet.find(currentNumber + 1) != numberSet.end()) {
                currentNumber++;
                currentLength++;
            }

            longestLength = max(longestLength, currentLength);
        }
    }

    return longestLength;
}

int main() {
    vector<int> numbers1 = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    vector<int> numbers2 = {19, 13, 15, 12, 18, 14, 17, 11};

    cout << "Longest consecutive sequence in first array: " << longestConsecutiveSequence(numbers1) << endl;
    cout << "Longest consecutive sequence in second array: " << longestConsecutiveSequence(numbers2) << endl;

    return 0;
}
```

---

# Combined C++ Program

This is one full program that includes all six tasks together, so I can test everything in one file.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stdexcept>
using namespace std;

struct Player {
    string first_name;
    string last_name;
    string team;
};

vector<string> findPlayersInBothSports(const vector<Player>& basketballPlayers,
                                       const vector<Player>& footballPlayers) {
    unordered_set<string> basketballNames;
    vector<string> result;

    for (const Player& player : basketballPlayers) {
        string fullName = player.first_name + " " + player.last_name;
        basketballNames.insert(fullName);
    }

    for (const Player& player : footballPlayers) {
        string fullName = player.first_name + " " + player.last_name;
        if (basketballNames.find(fullName) != basketballNames.end()) {
            result.push_back(fullName);
        }
    }

    return result;
}

int findMissingInteger(const vector<int>& numbers) {
    int n = numbers.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int number : numbers) {
        actualSum += number;
    }

    return expectedSum - actualSum;
}

int greatestStockProfit(const vector<int>& prices) {
    if (prices.size() < 2) {
        return 0;
    }

    int lowestPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        int currentProfit = prices[i] - lowestPrice;
        maxProfit = max(maxProfit, currentProfit);
        lowestPrice = min(lowestPrice, prices[i]);
    }

    return maxProfit;
}

int highestProductOfTwo(const vector<int>& numbers) {
    if (numbers.size() < 2) {
        throw invalid_argument("Array must contain at least two numbers.");
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int number : numbers) {
        if (number > largest) {
            secondLargest = largest;
            largest = number;
        } else if (number > secondLargest) {
            secondLargest = number;
        }

        if (number < smallest) {
            secondSmallest = smallest;
            smallest = number;
        } else if (number < secondSmallest) {
            secondSmallest = number;
        }
    }

    return max(largest * secondLargest, smallest * secondSmallest);
}

vector<double> sortTemperatures(const vector<double>& temperatures) {
    const int minTemp = 970;
    const int maxTemp = 990;
    const int range = maxTemp - minTemp + 1;

    vector<int> counts(range, 0);
    vector<double> sortedTemperatures;

    for (double temperature : temperatures) {
        int index = static_cast<int>(round(temperature * 10)) - minTemp;
        counts[index]++;
    }

    for (int i = 0; i < range; i++) {
        while (counts[i] > 0) {
            sortedTemperatures.push_back((minTemp + i) / 10.0);
            counts[i]--;
        }
    }

    return sortedTemperatures;
}

int longestConsecutiveSequence(const vector<int>& numbers) {
    unordered_set<int> numberSet(numbers.begin(), numbers.end());
    int longestLength = 0;

    for (int number : numbers) {
        if (numberSet.find(number - 1) == numberSet.end()) {
            int currentNumber = number;
            int currentLength = 1;

            while (numberSet.find(currentNumber + 1) != numberSet.end()) {
                currentNumber++;
                currentLength++;
            }

            longestLength = max(longestLength, currentLength);
        }
    }

    return longestLength;
}

int main() {
    cout << "Task 1: Players in both sports" << endl;

    vector<Player> basketballPlayers = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    vector<Player> footballPlayers = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    vector<string> bothSports = findPlayersInBothSports(basketballPlayers, footballPlayers);
    for (const string& name : bothSports) {
        cout << name << endl;
    }

    cout << "\nTask 2: Missing integer" << endl;
    vector<int> missingExample = {2, 3, 0, 6, 1, 5};
    cout << findMissingInteger(missingExample) << endl;

    cout << "\nTask 3: Greatest stock profit" << endl;
    vector<int> prices = {10, 7, 5, 8, 11, 2, 6};
    cout << greatestStockProfit(prices) << endl;

    cout << "\nTask 4: Highest product of two numbers" << endl;
    vector<int> productNumbers = {5, -10, -6, 9, 4};
    cout << highestProductOfTwo(productNumbers) << endl;

    cout << "\nTask 5: Sorted temperatures" << endl;
    vector<double> temperatures = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    vector<double> sortedTemperatures = sortTemperatures(temperatures);

    for (double temperature : sortedTemperatures) {
        cout << temperature << " ";
    }
    cout << endl;

    cout << "\nTask 6: Longest consecutive sequence" << endl;
    vector<int> sequenceNumbers = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    cout << longestConsecutiveSequence(sequenceNumbers) << endl;

    return 0;
}
```
