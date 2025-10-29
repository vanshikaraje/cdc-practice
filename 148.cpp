class Solution {
public:
    // Recursive function to calculate LCS
    int lcs(string &text1, string &text2, int i, int j) {
        // Base Case: if either string is empty
        if (i == 0 || j == 0)
            return 0;

        // If last characters match, include it and move both pointers
        if (text1[i - 1] == text2[j - 1])
            return 1 + lcs(text1, text2, i - 1, j - 1);

        // If not matching, check both possibilities and return max
        return max(lcs(text1, text2, i - 1, j), lcs(text1, text2, i, j - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        return lcs(text1, text2, m, n);
    }
};
