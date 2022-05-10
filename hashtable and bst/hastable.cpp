#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
    private: 
        static const int hashGroupNumber = 10;
        list<pair <int, string>> table[hashGroupNumber];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insert(int key, string value);
        void remove(int key);
        string getValue(int key);
        void printHashTable(); 
        int getKey(string value);
};

bool HashTable::isEmpty() const {
    int sum{};
    for(int i{}; i < hashGroupNumber; i++) {
        sum += table[i].size();
    }

    if(sum == 0) return true;
    else return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroupNumber;
}

void HashTable::insert(int key, string value) {
    int hashedValue = hashFunction(key);
    auto& indicatedList = table[hashedValue];
    auto it = begin(indicatedList);
    bool keyExists = false;
    for(; it != end(indicatedList); it++) {
        if(it->first == key) {
            keyExists = true;
            it->second = value;
            cout << "Value for a key: " << key 
            << " was replaced\n";
            break;
        }
    }

    if(!keyExists) {
        indicatedList.emplace_back(key, value);
    }

    return;
}

void HashTable::remove(int key) {
    int hashedValue = hashFunction(key);
    auto& indicatedList = table[hashedValue];
    auto it = begin(indicatedList);
    bool keyExists = false;
    for(; it != end(indicatedList); it++) {
        if(it->first == key) {
            keyExists = true;
            it = indicatedList.erase(it);
            cout << "Value for a key: " << key 
            << " was removed\n";
            break;
        }
    }
    if(!keyExists) {
        cout << "Item with a key: " << key
        << " was not found\n";
    }

    return;
}

void HashTable::printHashTable() {
    for (int i{}; i < hashGroupNumber; i++) {
        if(table[i].size() == 0) continue;
        auto it = table[i].begin();
        for(; it != table[i].end(); it++) {
            cout << "Key: " << hashFunction(it->first)
            << " Value: " << it->second << "\n";
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    HashTable hashTable;

    if(hashTable.isEmpty()) cout <<
    "Your hashTable is empty, please fill it\n";
    else cout << "Your hashTable contains some values\n";

    hashTable.insert(123, "Michael");
    hashTable.insert(321, "John");
    hashTable.insert(245, "Balenbay");
    hashTable.insert(213, "Artur");
    hashTable.insert(453, "Helen");
    hashTable.insert(3453, "Rogger");
    hashTable.insert(121323, "Steve");


    hashTable.printHashTable();
    return 0;
}