// User function Template for C++
class Solution {
public:
    // Function to detect cycle in a directed graph
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // directed edge u -> v
        }
        
        // Step 2: Initialize visited and recursion stack arrays
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
        
        // Step 3: Check for cycle using DFS
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfs(i, adj, visited, recStack))
                return true;
        }
        
        return false; // no cycle found
    }

private:
    // DFS helper to detect cycle
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &recStack) {
        visited[node] = 1;
        recStack[node] = 1;
        
        for (int neigh : adj[node]) {
            if (!visited[neigh] && dfs(neigh, adj, visited, recStack))
                return true;
            else if (recStack[neigh])
                return true; // cycle detected
        }
        
        recStack[node] = 0; // backtrack
        return false;
    }
};

