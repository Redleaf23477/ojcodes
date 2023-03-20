#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int ans_min = 0, ans_max = 0;
    int R, C; cin >> R >> C;
    auto calc_min = [&](string s, char want = '0', char unwant = '1') {
        int two_room = C / 4, one_room = C / 2;
        int ans = 0;
        for (int i = 0; two_room > 0 && i + 1 < C; i++) {
            if (s[i] == unwant && s[i+1] == unwant) {
                s[i] = s[i+1] = 'x';
                two_room--;
                if (unwant == '1') ans++;
            }
        }
        for (int i = 0; two_room > 0 && i + 1 < C; i++) {
            int zero = (s[i] == '0') + (s[i+1] == '0');
            int one = (s[i] == '1') + (s[i+1] == '1');
            if (zero == 1 && one == 1) {
                s[i] = s[i+1] = 'x';
                two_room--, ans++;
            }
        }
        for (int i = 0; two_room > 0 && i + 1 < C; i++) {
            if (s[i] == want && s[i+1] == want) {
                s[i] = s[i+1] = 'x';
                two_room--;
                if (want == '1') ans++;
            }
        }
        assert(two_room == 0);
        for (int i = 0; i < C; i++) {
            if (s[i] == '1') ans++;
        }
        return ans;
    };
    auto calc_max = [&](string s) {
        int two_room = C / 4, one_room = C / 2;
        int ans = 0;
        for (int i = 0; two_room > 0 && i+1 < C; i++) {
            if (s[i] == '0' && s[i+1] == '1') {
                s[i] = s[i+1] = 'x';
                ans++, two_room--;
            }
            if (s[i] == '1' && s[i+1] == '0') {
                s[i] = s[i+1] = 'x';
                ans++, two_room--;
            }
            if (s[i] == '0' && s[i+1] == '0') {
                s[i] = s[i+1] = 'x';
                two_room--;
            }
        }
        for (int i = 0; two_room > 0 && i+1 < C; i++) {
            if (s[i] == '1' && s[i+1] == '1') {
                s[i] = s[i+1] = 'x';
                ans++, two_room--;
            }
        }
        for (int i = 0; i < C; i++) {
            if (s[i] == '1') ans++;
        }

        return ans;
    };

    for (int r = 0; r < R; r++) {
        string str; cin >> str;
        ans_min += calc_min(str);
        ans_max += calc_max(str);
        // cerr << "r = " << r << ", min = " << calc(str, '0', '1');
        // cerr << ", max = " << calc(str, '1', '0') << endl;
    }
    cout << ans_min << " " << ans_max << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



