#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &arr, int target) {
    int n = arr.size();
	
  	// compare target with each element in array
    for (int i = 0; i < n; ++i) {
      
      	// if equal or larger value found,
      	// return its index
      	if(arr[i] >= target) {
          	return i;
        }
    }
  	
  	// if all elements are smaller, return length
  	return n;
}
int main() {
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int target = 9;
  
    cout << lowerBound(arr, target);
    return 0;
}