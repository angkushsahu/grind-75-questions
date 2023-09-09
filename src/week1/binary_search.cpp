#include <vector>
#include <iostream>
using namespace std;

int binary_search(const vector<int> arr, const int size, const int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size, 0);
    for (int& i : arr) cin >> i;
    int key; cin >> key;

    cout << binary_search(arr, size, key) << endl;

    return 0;
}
