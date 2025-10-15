#include <bits/stdc++.h>
using namespace std;

// Function to find the greatest smaller element on the left
vector<int> Smallestonleft(int arr[], int n) {
    vector<int> ans;
    set<int> s; // ordered set to store elements on the left

    for (int i = 0; i < n; i++) {
        // Find the first element >= arr[i]
        auto it = s.lower_bound(arr[i]);

        // If iterator points to the beginning, no smaller element exists
        if (it == s.begin()) {
            ans.push_back(-1);
        } else {
            // Move iterator one step back to get the smaller element
            it--;
            ans.push_back(*it);
        }

        // Insert current element into the set
        s.insert(arr[i]);
    }

    return ans;
}

// Driver code (for VS Code testing)
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> result = Smallestonleft(arr, n);

    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
