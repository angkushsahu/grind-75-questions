#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int max_profit(vector<int> arr, const int size) {
    int min_so_far = INT_MAX;
    int max_so_far = INT_MIN;

    for (int i : arr) {
        min_so_far = min(i, min_so_far);
        max_so_far = max(max_so_far, i - min_so_far);
    }

    return max_so_far;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size, 0);
    for (int& i : arr) cin >> i;

    cout << max_profit(arr, size) << endl;

    return 0;
}
