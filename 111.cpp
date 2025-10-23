class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays — smallest greed & cookie first
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // pointer for children
        int j = 0; // pointer for cookies
        
        // Try to satisfy each child
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Cookie big enough for child i
                i++;
            }
            // Move to next cookie (used or too small)
            j++;
        }
        
        return i; // number of content children
    }
};
