#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

using Pt = tuple<LL,LL>;
using Tri = tuple<vector<Pt>,int>;

istream &operator >> (istream &in, Pt &p) {
    auto &[x, y] = p;
    in >> x >> y;
    return in;
}

istream &operator >> (istream &in, Tri &t) {
    auto &[pts, idx] = t;
    pts.resize(3);
    for (auto &p : pts) in >> p;
    return in;
}

int get_side(const Pt &p, const Pt &p1, const Pt &p2) {
    auto [x, y] = p;
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    int res = (y1 - y2) * x - (x1 - x2) * y + (x1 - x2) * y1 - (y1 - y2) * x1;
    int h = (y1 - y2) * (x1 - x2) > 0;
    if (res == 0) return 0;
    else if (res > 0) return h * 1;
    else return h * -1;
}

int get_side(const Tri &t, const Pt &p1, const Pt &p2) {
    const auto &[pts, idx] = t;
    for (const auto &p : pts) {
        int side = get_side(p, p1, p2);
        if (side != 0) return side;
    }
    return 0;  // unreachable
}

bool same_side(const Tri &t, const Pt &p1, const Pt &p2) {
    const auto &[pts, idx] = t;
    int zero = 0, same = 1;
    for (const auto &p : pts) {
        int side = get_side(p, p1, p2);
        if (side != 0) same *= side;
        else zero += 1;
    }
    return (zero >= 2 || same == 1);
}

bool cmp (const Tri &lhs, const Tri &rhs) {
    const auto &[lpts, lidx] = lhs;
    const auto &[rpts, ridx] = rhs;
    for (const auto &lp : lpts) for (const auto &rp : rpts) {
        if (lp == rp) continue;
        // sep line by lhs[l] and rhs[r]
        if (!same_side(lhs, lp, rp)) continue;
        if (!same_side(rhs, lp, rp)) continue;
        int L = get_side(lhs, lp, rp);
        int R = get_side(rhs, lp, rp);
        if (L == R) continue;
        return L < R;
    }
    return 0;  // unreachable
}


int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<Tri> arr(n);
        for (int i = 0; i < n; i++) {
            auto &t = arr[i];
            cin >> t;
            get<1>(t) = i+1;
        }
        sort(arr.begin(), arr.end(), cmp);
        for (const auto &[pts, idx] : arr) {
            cout << idx << " ";
        }
        cout << "\n";
    }
}

