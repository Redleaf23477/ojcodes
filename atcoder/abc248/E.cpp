#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Vec {
    LL x, y;
    Vec(LL _x, LL _y) : x(_x), y(_y) {}
    Vec() : x(0), y(0) {}
    LL len2() const { return x * x + y * y; }
    tuple<LL,LL> dir() const {
        LL g = gcd(x, y);
        LL dx = x / g, dy = y / g;
        if (dy == 0) dx = abs(dx);
        if (dy < 0) dx *= -1, dy *= -1;
        return make_tuple(dx, dy); 
    }
    Vec operator-(Vec that) {
        return Vec(that.x - this->x, that.y - this->y);
    }
    bool operator<(Vec that) {
        if (this->x != that.x) return this->x < that.x;
        else return this->y < that.y;
    }
};

void solve() {
    int N, K; cin >> N >> K;
    vector<Vec> arr(N);
    for (auto &[x, y] : arr) cin >> x >> y;

    if (K == 1) {
        cout << "Infinity\n"; return;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        map<tuple<LL,LL>, vector<int>> dir;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            Vec v = arr[j] - arr[i];
            dir[v.dir()].emplace_back(j);
        }
        for (auto &[line, vec_list] : dir) {
            if (vec_list.size() + 1 < K) continue;
            bool count = true;
            for (auto j : vec_list) {
                if (arr[j] < arr[i]) {
                    count = false; break;
                }
            }
            if (count) ans ++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



