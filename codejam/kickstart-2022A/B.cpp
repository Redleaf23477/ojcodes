#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

char int2char(int x) { return '0' + x; }

void solve() {
    string num; cin >> num;

    int rem = 0;
    for (auto c : num) rem += c - '0';
    rem %= 9;

    string ans = num + int2char((9 - rem) % 9);

    // case 0:
    if (rem == 0) {
        string tmp = num.substr(0, 1) + "0" + num.substr(1);
        ans = min(tmp, ans);
    }
    // case 1-9:
    for (int i = 1; i < 10; i++) if ((rem + i) % 9 == 0) {
        int pos_to_ins = num.size();
        char ch = int2char(i);
        for (size_t p = 0; p < num.size(); p++) {
            if (num[p] > ch) {
                pos_to_ins = p; break;
            }
        }
        // cerr << "i = " << i << ", pos_to_ins = " << pos_to_ins << endl;
        string tmp = num.substr(0, pos_to_ins) + ch + num.substr(pos_to_ins);
        ans = min(tmp, ans);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

