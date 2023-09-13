#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    vector<int> col {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
    string str; cin >> str;
    vector<bool> up (7, false);
    for (int i = 0; i < 10; i++) {
        if (str[i] == '1') up[col[i]] = true;
    }
    if (str[0] == '1') {
        cout << "No\n";
    } else {
        int left_up = -1, right_up = -1;
        for (int i = 0; i < 7; i++) {
            if (left_up == -1 && up[i]) left_up = i;
            if (up[i]) right_up = i;
        }
        bool ans = false;
        for (int i = 0; i < 7; i++) {
            if (!up[i] && left_up < i && i < right_up) {
                ans = true;
            }
        }
        cout << (ans? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}