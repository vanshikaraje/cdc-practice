#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // The number of blocked cells is <= 200, so the maximum area they can enclose is small (~200*200/2)
    const int BOUND = 1e6;
    const int LIMIT = 200 * 200 / 2; // approx max enclosed area

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (auto& b : blocked)
            blockedSet.insert(hashKey(b[0], b[1]));

        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }

    bool bfs(vector<int>& start, vector<int>& finish, unordered_set<long long>& blocked) {
        queue<pair<int,int>> q;
        unordered_set<long long> visited;
        q.push({start[0], start[1]});
        visited.insert(hashKey(start[0], start[1]));

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && visited.size() <= LIMIT) {
            auto [x, y] = q.front(); q.pop();
            if (x == finish[0] && y == finish[1]) return true;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= BOUND || ny >= BOUND) continue;

                long long key = hashKey(nx, ny);
                if (blocked.count(key) || visited.count(key)) continue;

                visited.insert(key);
                q.push({nx, ny});
            }
        }

        // If we explored more than LIMIT cells, we are not enclosed
        return visited.size() > LIMIT;
    }

    long long hashKey(int x, int y) {
        return (static_cast<long long>(x) << 20) + y; // unique 1e6-based hash
    }
};
