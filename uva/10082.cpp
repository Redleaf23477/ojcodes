#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str;

    vector<char> keyboard {
        '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\', 
        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 
        'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'
    };

    assert(keyboard.size() == 13 + 13 + 11 + 10);
    
    while (getline(cin, str)) {
        for (auto c : str) {
            if (c == ' ') cout << ' ';
            else {
                auto it = find(keyboard.begin(), keyboard.end(), c);
                it--;
                cout << *it;
            }
        }
        cout << endl;
    }
}