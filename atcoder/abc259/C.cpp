#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string S, T; cin >> S >> T;
    size_t i = 0, j = 0;
    auto get_ch = [](string &str, size_t &idx) {
        if (idx == str.size()) {
            return make_pair('?', 0);
        }
        char ch = str[idx];
        int cnt = 0;
        for (; idx < str.size() && str[idx] == ch; idx++) cnt++;
        return make_pair(ch, cnt);
    };
    while (true) {
        auto s_ch = get_ch(S, i);
        auto t_ch = get_ch(T, j);

        if (s_ch.first == '?' || t_ch.first == '?') {
            if (s_ch.first == t_ch.first) {
                cout << "Yes\n"; break;
            } else {
                cout << "No\n"; break;
            }
        }

        if (s_ch.first != t_ch.first) {
            cout << "No\n"; break;
        } else if (s_ch.second > t_ch.second) {
            cout << "No\n"; break;
        } else if (s_ch.second == 1 && s_ch.second < t_ch.second) {
            cout << "No\n"; break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



