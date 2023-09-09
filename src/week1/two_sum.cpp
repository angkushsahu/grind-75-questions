#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> two_sum(vector<int> arr, const int sum) {
    const int size = arr.size();
    unordered_map<int, int> map;

    for (int i = 0; i < size; i ++) {
        const int element = sum - arr[i];
        if (map.count(element))
            return { i, map[element] };
        map[arr[i]] = i;
    }

    return {};
}

int main() {
    int size; cin >> size;
    vector<int> arr(size, 0);
    for (int& i : arr) cin >> i;
    int sum; cin >> sum;

    vector<int> result = two_sum(arr, sum);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
