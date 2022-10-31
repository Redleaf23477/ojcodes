#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Pos { int x, y; };
bool operator < (Pos const &lhs, Pos const &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    else return lhs.y < rhs.y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    Pos home, office;
    cin >> home.x >> home.y;
    cin >> office.x >> office.y;
    vector<Pos> arr(n);
    for (auto &p : arr) cin >> p.x >> p.y;
    // normalize
    office.x -= home.x, office.y -= home.y;
    for (auto &p : arr) p.x -= home.x, p.y -= home.y;
    home.x = home.y = 0;
    if (office.x < 0) {
        for (auto &p : arr) p.x *= -1;
        office.x *= -1;
    }
    if (office.y < 0) {
        for (auto &p : arr) p.y *= -1;
        office.y *= -1;
    }
    sort(arr.begin(), arr.end());
    /*
    cerr << "home(" << home.x << ", " << home.y << ")" << endl;
    cerr << "office(" << office.x << ", " << office.y << ")" << endl;
    for (auto p : arr) {
        cerr << "point(" << p.x << ", " << p.y << ")" << endl;
    }
    */
    // LIS
    vector<int> tmp {0};
    for (auto &p : arr) {
        if (p.x < 0) continue;
        if (p.y < 0) continue;
        if (p.x > office.x) break;
        if (p.y > office.y) continue;
        auto it = upper_bound(tmp.begin(), tmp.end(), p.y);
        if (it == tmp.end()) tmp.emplace_back(p.y);
        else *it = min(*it, p.y);
    }
    cout << tmp.size() - 1 << "\n";
}

