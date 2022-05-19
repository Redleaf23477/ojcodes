#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool is_palindrome(const string &str) {
    for (int i = 0, j = str.size() - 1; i <= j; i++, j--) {
        if (str[i] != str[j]) return false;
    }
    return true;
}

bool is_mirrored(const string &str) {
    static const vector<char> mirror_alpha {
        'A', 'x', 'x', 'x', '3', 'x', 'x', 'H', 'I', 'L', 'x', 'J', 
        'M', 'x', 'O', 'x', 'x', 'x', '2', 'T', 'U', 'V', 'W', 'X', 
        'Y', '5'
    };
    static const vector<char> mirror_digit {
        '1', 'S', 'E', 'x', 'Z', 'x', 'x', '8', 'x'
    };
    for (int i = 0, j = str.size() - 1; i <= j; i++, j--) {
        char ch;
        if (isdigit(str[i])) {
            ch = mirror_digit[str[i] - '1'];
        } else {
            ch = mirror_alpha[str[i] - 'A'];
        }
        if (str[j] != ch) return false;
    }
    return true;
}

void check(const string &str) {
    bool m = is_mirrored(str);
    bool p = is_palindrome(str);
    if (m && p) {
        cout << "is a mirrored palindrome";
    } else if (m) {
        cout << "is a mirrored string";
    } else if (p) {
        cout << "is a regular palindrome";
    } else {
        cout << "is not a palindrome";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str; 
    while (cin >> str) {
        cout << str << " -- ";
        check(str);
        cout << "." << endl;
        cout << endl;
    }
}