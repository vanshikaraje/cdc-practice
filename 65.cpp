#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Finding upper bound for value 30 in vector v
    cout << *upper_bound(v.begin(), v.end(), 30);

    return 0;
}