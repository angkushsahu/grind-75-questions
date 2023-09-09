#include <string>
#include <iostream>
using namespace std;

void convert_to_valid_string(string& str) {
    int i = 0;
    while (i < str.size()) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '0' && str[i] <= '9') i ++;
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char)(str[i] + 32);
            i ++;
        } else str.erase(i, 1);
    }
}

bool valid_palindrome(string str) {
    convert_to_valid_string(str);
    const int size = str.size();

    for (int i = 0; i < size; i ++)
        if (str[i] != str[size - i - 1])
            return false;

    return true;
}

int main() {
    string str;
    getline(cin, str);
    cout << valid_palindrome(str) << endl;

    return 0;
}
