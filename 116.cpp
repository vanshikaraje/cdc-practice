class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int maxVal = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]);
            // When the max value so far equals the current index,
            // we can safely make a new chunk.
            if (maxVal == i) {
                chunks++;
            }
        }
        return chunks;
    }
};
