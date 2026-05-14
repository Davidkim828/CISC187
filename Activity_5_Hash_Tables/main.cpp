

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <iomanip>
#include <random>
#include <algorithm>

using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const {
        const int prime = 31;
        long long hash = 0;

        for (char c : key) {
            hash = hash * prime + c;
        }

        return static_cast<int>(hash % capacity);
    }

    void rehash() {
        vector<list<pair<string, int>>> oldTable = table;
        capacity *= 2;
        table.clear();
        table.resize(capacity);
        currentSize = 0;
        collisionCount = 0;

        for (const auto& bucket : oldTable) {
            for (const auto& item : bucket) {
                insert(item.first, item.second);
            }
        }
    }

public:
    HashTable(int size = 11)
        : table(size), currentSize(0), capacity(size), collisionCount(0) {}

    void insert(const string& key, int value) {
        int index = hashFunction(key);

        // Update existing key if found
        for (auto& item : table[index]) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }

        // Count collision if bucket is not empty
        if (!table[index].empty()) {
            collisionCount++;
        }

        table[index].push_back({key, value});
        currentSize++;

        if (loadFactor() > 0.75) {
            rehash();
        }
    }

    bool remove(const string& key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                currentSize--;
                return true;
            }
        }

        return false;
    }

    int search(const string& key) const {
        int index = hashFunction(key);

        for (const auto& item : table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }

        return -1; // key not found
    }

    double loadFactor() const {
        return static_cast<double>(currentSize) / capacity;
    }

    int size() const {
        return currentSize;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    void printTable() const {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            for (const auto& item : table[i]) {
                cout << "(" << item.first << ", " << item.second << ") ";
            }
            cout << endl;
        }
    }

    int getCapacity() const {
        return capacity;
    }

    int getCollisionCount() const {
        return collisionCount;
    }

    int getMaxBucketSize() const {
        int maxSize = 0;
        for (const auto& bucket : table) {
            if (static_cast<int>(bucket.size()) > maxSize) {
                maxSize = static_cast<int>(bucket.size());
            }
        }
        return maxSize;
    }

    double getAverageBucketLength() const {
        int nonEmptyBuckets = 0;
        int totalElements = 0;

        for (const auto& bucket : table) {
            if (!bucket.empty()) {
                nonEmptyBuckets++;
                totalElements += static_cast<int>(bucket.size());
            }
        }

        if (nonEmptyBuckets == 0) {
            return 0.0;
        }

        return static_cast<double>(totalElements) / nonEmptyBuckets;
    }
};

// Generate random lowercase string
string randomString(int length) {
    static const string chars = "abcdefghijklmnopqrstuvwxyz";
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, static_cast<int>(chars.size()) - 1);

    string result;
    for (int i = 0; i < length; i++) {
        result += chars[dist(gen)];
    }
    return result;
}

void runExperiment(const string& testName, const vector<string>& keys) {
    HashTable ht;

    for (int i = 0; i < static_cast<int>(keys.size()); i++) {
        ht.insert(keys[i], i + 1);
    }

    cout << "\n=== " << testName << " ===" << endl;
    cout << "Capacity: " << ht.getCapacity() << endl;
    cout << "Number of elements: " << ht.size() << endl;
    cout << fixed << setprecision(2);
    cout << "Load factor: " << ht.loadFactor() << endl;
    cout << "Total collisions: " << ht.getCollisionCount() << endl;
    cout << "Maximum bucket size: " << ht.getMaxBucketSize() << endl;
    cout << "Average bucket length: " << ht.getAverageBucketLength() << endl;
}

int main() {
    HashTable ht;

    // Insert at least 100 words
    vector<string> words;
    for (int i = 1; i <= 100; i++) {
        words.push_back("student" + to_string(i));
    }

    for (int i = 0; i < static_cast<int>(words.size()); i++) {
        ht.insert(words[i], i + 100);
    }

    cout << "=== Basic Hash Table Test ===" << endl;
    cout << "Table capacity: " << ht.getCapacity() << endl;
    cout << "Number of elements: " << ht.size() << endl;
    cout << fixed << setprecision(2);
    cout << "Load factor: " << ht.loadFactor() << endl;
    cout << "Total collisions: " << ht.getCollisionCount() << endl;

    // Search tests
    cout << "\nSearch existing key 'student25': ";
    int value1 = ht.search("student25");
    if (value1 != -1) {
        cout << "Found value = " << value1 << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Search non-existing key 'student999': ";
    int value2 = ht.search("student999");
    if (value2 != -1) {
        cout << "Found value = " << value2 << endl;
    } else {
        cout << "Not found" << endl;
    }

    // Remove tests
    cout << "\nRemoving 'student10': ";
    cout << (ht.remove("student10") ? "Removed successfully" : "Remove failed") << endl;

    cout << "Searching 'student10' after remove: ";
    cout << (ht.search("student10") == -1 ? "Not found" : "Still exists") << endl;

    cout << "Removing 'student50': ";
    cout << (ht.remove("student50") ? "Removed successfully" : "Remove failed") << endl;

    cout << "Searching 'student50' after remove: ";
    cout << (ht.search("student50") == -1 ? "Not found" : "Still exists") << endl;

    // Experiments
    vector<string> randomKeys;
    for (int i = 0; i < 100; i++) {
        randomKeys.push_back(randomString(8));
    }

    vector<string> sequentialKeys;
    for (int i = 1; i <= 100; i++) {
        sequentialKeys.push_back("student" + to_string(i));
    }

    vector<string> samePrefixKeys;
    for (int i = 1; i <= 100; i++) {
        string num = to_string(i);
        while (num.length() < 4) {
            num = "0" + num;
        }
        samePrefixKeys.push_back("data_" + num);
    }

    runExperiment("Random Strings", randomKeys);
    runExperiment("Sequential Keys", sequentialKeys);
    runExperiment("Same Prefix Keys", samePrefixKeys);

    return 0;
}