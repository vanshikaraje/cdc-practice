#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    // stack of {price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Pop all prices less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price with its total span
        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << stockSpanner.next(price) << " ";
    }

    return 0;
}
