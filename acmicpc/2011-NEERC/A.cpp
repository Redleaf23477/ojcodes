#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n >> ws;
    string str; 
    while (n--) {
        getline(cin, str);
        int g = 0, b = 0;
        for (auto c : str) {
            c = tolower(c);
            g += (c == 'g');
            b += (c == 'b');
        }
        if (g > b) {
            cout << str << " is GOOD" << endl;
        } else if (b > g) {
            cout << str << " is A BADDY" << endl;
        } else {
            cout << str << " is NEUTRAL" << endl;
        }
    }
}

