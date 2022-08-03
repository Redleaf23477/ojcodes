#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    string str; cin >> str;
    int buff = 0;
    for (auto c : str) {
        if (c == '1') buff++;
        else {
            cout << buff;
            buff = 0;
        }
    }
    cout << buff << "\n";
}

