#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;

    // Move (n-1) disks from source to auxiliary
    towerOfHanoi(n - 1, from, aux, to);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;

    // Move (n-1) disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to calculate minimum number of moves
long long tohMoves(int n) {
    if (n == 0) return 0;
    // Formula: 2^n - 1
    return pow(2, n) - 1;
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSteps to solve Tower of Hanoi:\n";
    towerOfHanoi(n, '1', '3', '2');

    cout << "\nTotal moves required: " << tohMoves(n) << endl;

    return 0;
}
