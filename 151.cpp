class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            // Odd length palindromes
            count += expandAroundCenter(s, i, i);
            
            // Even length palindromes
            count += expandAroundCenter(s, i, i + 1);
        }
        
        return count;
    }
    
    int expandAroundCenter(string &s, int left, int right) {
        int cnt = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
};
