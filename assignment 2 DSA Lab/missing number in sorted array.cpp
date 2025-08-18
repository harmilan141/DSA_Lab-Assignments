#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 5; // size of array
    int expectedSum = (6 * (6 + 1)) / 2; // sum from 1 to max element
    int actualSum = 0;
    for (int x : arr) actualSum += x;
    cout << "Missing number: " << expectedSum - actualSum;
}
