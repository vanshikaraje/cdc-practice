#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> s_count; // for secret non-bulls
        unordered_map<char, int> g_count; // for guess non-bulls

        // First pass: find bulls and build count maps for non-bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                s_count[secret[i]]++;
                g_count[guess[i]]++;
            }
        }

        // Second pass: count cows using min of counts
        for (auto &[ch, count] : g_count) {
            if (s_count.count(ch)) {
                cows += min(count, s_count[ch]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
int main() {
    Solution sol;
    string secret = "1123", guess = "0111";
    cout << sol.getHint(secret, guess) << endl; // Output: 1A1B
    return 0;
}
