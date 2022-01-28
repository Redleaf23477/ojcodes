#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        if ((str.back() - '0') % 2 == 0) {
            cout << 0 << "\n";
        } else if ((str.front() - '0') % 2 == 0) {
            cout << 1 << "\n"; 
        } else {
            int ans = -1;
            for (auto c : str) {
                if ((c - '0') % 2 == 0) {
                    ans = 2; break;
                }
            }
            cout << ans << "\n";
        }
    }
}

