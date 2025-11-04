//  heap sort
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 5, 3, 8, 2, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--) {
        int parent = i;
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;

            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest != parent) {
                swap(arr[parent], arr[largest]);
                parent = largest;
            } else break;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        int parent = 0;
        int size = i;
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;

            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != parent) {
                swap(arr[parent], arr[largest]);
                parent = largest;
            } else break;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
