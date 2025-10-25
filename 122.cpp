#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        // If we've reached the last node, save the path
        if (node == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        // Explore all neighbors
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);         // Choose
            dfs(neighbor, graph, path, result); // Explore
            path.pop_back();                  // Backtrack
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path = {0}; // Start path from node 0
        dfs(0, graph, path, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};

    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);

    cout << "All paths from source to target:\n";
    for (auto& path : paths) {
        cout << "[ ";
        for (int node : path) cout << node << " ";
        cout << "]\n";
    }
    return 0;
}
