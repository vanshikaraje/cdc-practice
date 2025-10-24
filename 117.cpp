// User function Template for C++
class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>> &edges) {
        vector<vector<int>> adj(V);
        
        // Loop through all edges
        for (auto &edge : edges) {
            int u = edge.first;
            int v = edge.second;
            
            // Since it's an undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return adj;
    }
};
