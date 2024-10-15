#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
class HashTable {
private:
    static const int hashSize = 10; 
    vector<list<pair<string, int>>> table; 

    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch; 
        }
        return hash % hashSize; 
    }

public:
    HashTable() : table(hashSize) {}

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; 
                return;
            }
        }
        
        table[index].emplace_back(key, value);
    }

    bool remove(const string& key) {
        int index = hashFunction(key);
        auto& cell = table[index];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                return true; 
            }
        }
        return false; 
    }

    bool search(const string& key, int& value) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;  
                return true; 
            }
        }
        return false;  
    }

    void display() {
        for (int i = 0; i < hashSize; i++) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("arman", 7);
    ht.insert("garik", 2);
    ht.insert("hayk", 3);
    ht.insert("aarmn", 5);
    ht.insert("giak", 9);
    
    ht.display();
    cout << endl;
    int value;
    if (ht.search("garik", value)) {
        cout << "Found garik: " << value << endl;
    } else {
        cout << "Garik not found!" << endl;
    }
    cout << endl;

    ht.remove("garik");
    ht.display();

    return 0;
}
