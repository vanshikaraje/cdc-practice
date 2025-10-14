#include <bits/stdc++.h>
using namespace std;

// Recursive function to print numbers from 1 to n
void printTillN(int n) {
    if (n == 0) return;         // base case
    printTillN(n - 1);          // recursive call
    cout << n << " ";           // print after recursion
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Numbers from 1 to " << n << ": ";
    printTillN(n);
    cout << endl;

    return 0;
}
