#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 1000; // number of buckets
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl; // 1
    cout << myHashMap.get(3) << endl; // -1
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl; // 1
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl; // -1
    return 0;
}
