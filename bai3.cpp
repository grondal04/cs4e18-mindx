#include <iostream>
#include <string>
#include <stack>
using namespace std;

string encodeString(const string& s) {
    stack<pair<char, int>> stk;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        char currentChar = s[i];
        if (!stk.empty() && stk.top().first == currentChar) {
            stk.top().second++;
        } else {
            stk.push(make_pair(currentChar, 1));
        }
    }

    string encoded = "";
    while (!stk.empty()) {
        encoded = stk.top().first + to_string(stk.top().second) + encoded;
        stk.pop();
    }

    return encoded;
}

int main() {
    string input;
    cout << "Nhap chuoi: ";
    cin >> input;

    string encoded = encodeString(input);
    cout << "Chuoi da ma hoa: " << encoded << endl;

    return 0;
}
