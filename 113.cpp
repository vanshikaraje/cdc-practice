class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            // Check if current plot is empty
            if (flowerbed[i] == 0) {
                // Check left and right plots (treat out-of-bound as empty)
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Plant flower
                    count++;
                    if (count >= n) return true; // Early stop
                }
            }
        }
        
        return count >= n;
    }
};
