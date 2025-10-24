// User function Template for C++
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> ans;
        vector<int> visited(V, 0);
        
        // Call recursive helper for vertex 0
        dfsHelper(0, adj, visited, ans);
        
        return ans;
    }

  private:
    // Recursive helper function
    void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans) {
        visited[node] = 1;
        ans.push_back(node);
        
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfsHelper(neigh, adj, visited, ans);
            }
        }
    }
};
