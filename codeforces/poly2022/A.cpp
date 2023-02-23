#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string str; cin >> str;
        int cnt = str[0] - '0';
        for (int i = 1; i < n; i++) {
            if (str[i] == '0') cout << '+';
            else if (cnt == 1) { cout << '-'; cnt -= 1; }
            else { cout << '+'; cnt += 1; }
        }
        cout << '\n';
    }
}

