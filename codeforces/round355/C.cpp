#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9 + 7;

int to_int(char ch) {
    if ('0' <= ch && ch <= '9') return ch - '0';
    else if ('A' <= ch && ch <= 'Z') return ch - 'A' + 10;
    else if ('a' <= ch && ch <= 'z') return ch - 'a' + 36;
    else if (ch == '-') return 62;
    else return 63;
}

void solve() {
    string str; cin >> str;
    vector<int> arr;
    for (auto ch : str) arr.emplace_back(to_int(ch));
    LL ans = 1;
    for (size_t i = 0; i < arr.size(); i++) {
        for (int b = 0; b < 6; b++) {
            if (((arr[i] >> b) & 1) == 0) {
                ans = ans * 3 % MOD;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



