#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to simulate collisions
        
        for (int asteroid : asteroids) {
            bool destroyed = false;

            // Collision condition: stack top is moving right (+ve), current is moving left (-ve)
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(asteroid) > abs(st.top())) {
                    // Current asteroid destroys the top one
                    st.pop();
                } else if (abs(asteroid) == abs(st.top())) {
                    // Both destroy each other
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid destroyed
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroid);
            }
        }

        // Convert stack to vector (reverse order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
