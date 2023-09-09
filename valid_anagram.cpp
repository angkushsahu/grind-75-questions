#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

bool is_anagram(string s, string t) {
    unordered_map<char, int> map;

    for (char ch : s) map[ch] ++;
    for (char ch : t) map[ch] --;

    for (pair<char, int> element : map)
        if (element.second)
            return false;

    return true;
}

int main() {
    string s; cin >> s;
    string t; cin >> t;

    cout << is_anagram(s, t) << endl;

    return 0;
}
