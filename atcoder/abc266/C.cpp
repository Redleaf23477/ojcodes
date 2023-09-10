#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool convex(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    pair<int,int> u(b.first - a.first, b.second - a.second);
    pair<int,int> v(c.first - b.first, c.second - b.second);
    int cross = u.first * v.second - u.second * v.first;
    return cross >= 0;
}

void solve() {
    vector<pair<int,int>> pt(4);
    for (auto &[x, y] : pt) cin >> x >> y;
    for (int i = 0; i < 4; i++) {
        if (!convex(pt[i], pt[(i + 1) % 4], pt[(i + 2) % 4])) {
            cout << "No\n"; return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}