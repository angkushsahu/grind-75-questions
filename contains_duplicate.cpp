#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool contains_duplicate(const vector<int> arr, const int size) {
    unordered_map<int, int> map;
    for (int i : arr) {
        map[i] ++;
        if (map[i] > 1) return true;
    }
    return false;
}

int main() {
    int size; cin >> size;
    vector<int> arr(size, 0);
    for (int& i : arr) cin >> i;

    cout << contains_duplicate(arr, size) << endl;

    return 0;
}
