#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    int L = 0, R = 0;
    int b = 0;
    for (auto ch : str) {
        if (ch == '(') {
            b++;
        } else {
            if (b == 0) L++;
            else b--;
        }
    }
    R += b;
    cout << string(L, '(') << str << string(R, ')') << "\n";
}

