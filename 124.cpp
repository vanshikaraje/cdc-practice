#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]); // Path compression
        return parent[x];
    }

    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0); // initialize parent[i] = i

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1)
                    unite(parent, rank, i, j);
            }
        }

        unordered_set<int> provinces;
        for (int i = 0; i < n; i++)
            provinces.insert(find(parent, i));

        return provinces.size();
    }
};
