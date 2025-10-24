class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size(); // number of vertices
        vector<int> ans;
        vector<int> visited(V, 0);
        
        queue<int> q;
        q.push(0);        // start BFS from node 0
        visited[0] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Visit all adjacent nodes
            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        
        return ans;
    }
};
