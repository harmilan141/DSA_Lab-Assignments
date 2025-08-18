#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key;
    cout << "Enter element to search: ";
    cin >> key;
    int result = binarySearch(arr, n, key);
    if (result != -1) cout << "Element found at index " << result << endl;
    else cout << "Element not found\n";
}
