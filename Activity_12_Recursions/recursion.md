## 1. 



```ruby
def print_every_other(low, high) 
    return if low > high
    puts low
    print_every_other(low + 2, high)
end
```

The base case is:

```ruby
return if low > high
```

This stops the recursion when `low` becomes greater than `high`.

---

## 2. 

Given function:

```ruby
def factorial(n)
    return 1 if n == 1
    return n * factorial(n - 2)
end
```


## 3

Original function:

```ruby
def sum(low, high)
    return high + sum(low, high - 1)
end
```

The correct base case is when `high == low`.

Fixed version:

```ruby
def sum(low, high)
    return low if high == low
    return high + sum(low, high - 1)
end
```

C++ version:

```cpp
#include <iostream>
using namespace std;

int sum(int low, int high) {
    if (high == low) {
        return low;
    }

    return high + sum(low, high - 1);
}

int main() {
    cout << sum(1, 10) << endl;
    return 0;
}
```

Output:

```text
55
```

---

## 4

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Element {
    bool isNumber;
    int number;
    vector<Element> list;

    Element(int value) {
        isNumber = true;
        number = value;
    }

    Element(vector<Element> nestedList) {
        isNumber = false;
        number = 0;
        list = nestedList;
    }
};

void printNumbers(const vector<Element>& arr) {
    for (const Element& item : arr) {
        if (item.isNumber) {
            cout << item.number << endl;
        } else {
            printNumbers(item.list);
        }
    }
}

int main() {
    vector<Element> array = {
        Element(1),
        Element(2),
        Element(3),
        Element(vector<Element>{Element(4), Element(5), Element(6)}),
        Element(7),
        Element(vector<Element>{
            Element(8),
            Element(vector<Element>{
                Element(9), Element(10), Element(11),
                Element(vector<Element>{Element(12), Element(13), Element(14)})
            })
        }),
        Element(vector<Element>{
            Element(15), Element(16), Element(17), Element(18), Element(19),
            Element(vector<Element>{
                Element(20), Element(21), Element(22),
                Element(vector<Element>{
                    Element(23), Element(24), Element(25),
                    Element(vector<Element>{Element(26), Element(27), Element(29)})
                }),
                Element(30), Element(31)
            }),
            Element(32)
        }),
        Element(33)
    };

    printNumbers(array);

    return 0;
}
```

