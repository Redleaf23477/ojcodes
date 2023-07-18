#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0, dir = 0;
    vector<int> dx {1, 0, -1, 0};
    vector<int> dy {0, -1, 0, 1};
    for (auto op : s) {
        if (op == 'S') {
            x += dx[dir], y += dy[dir];
        } else {
            dir = (dir + 1) % 4;
        }
    }
    cout << x << " " << y << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



