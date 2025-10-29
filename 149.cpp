class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome (centered at i)
            expandAroundCenter(s, i, i, start, maxLen);

            // Even length palindrome (centered between i and i+1)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }
};
