#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // because graph is undirected
        }

        // BFS traversal
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) return true; // path found

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false; // no path found
    }
};


int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};
    int source = 0, destination = 2;

    cout << (sol.validPath(n, edges, source, destination) ? "true" : "false") << endl;
    return 0;
}
