#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using V = tuple<double,double>;  // x, y
using T4 = tuple<LL,LL,V,V>;  // x, y, rotated(ai+ri), rotated(ai-ri) 

const double PI = acos(-1);
const double eps = 1e-9;

void rot(V &lhs, double theta) {
    auto [x, y] = lhs;
    double x2 = x * cos(theta) - y * sin(theta);
    double y2 = x * sin(theta) + y * cos(theta);
    lhs = make_tuple(x2, y2);
}

double cross(V lhs, V rhs) {
    auto [x1, y1] = lhs;
    auto [x2, y2] = rhs;
    return x1 * y2 - x2 * y1;
}

double dot(V lhs, V rhs) {
    auto [x1, y1] = lhs;
    auto [x2, y2] = rhs;
    return x1 * x2 + y1 * y2;
}

double deg2rad(LL deg) {
    deg = (deg % 360 + 360) % 360;
    return deg / 180.0 * PI;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<T4> arr(n);
    for (auto &[x, y, vl, vr] : arr) {
        double a, r;
        cin >> x >> y >> a >> r;
        a = deg2rad(a);
        r = deg2rad(r);

        vl = vr = V(1, 0);
        rot(vl, a - r);
        rot(vr, a + r);
    }

    auto sees = [&](int i, int j) {
        auto [x1, y1, vl, vr] = arr[i];
        auto [x2, y2, __, ___] = arr[j];

        double dx = x2 - x1;
        double dy = y2 - y1;
        double len = sqrt(dx * dx + dy * dy);
        V v(dx / len, dy / len);

        bool intersect_vl = (abs(cross(v, vl)) < eps) && (dot(v, vl) > 0);
        bool intersect_vr = (abs(cross(v, vr)) < eps) && (dot(v, vr) > 0);
        bool between = (cross(vl, v) > 0) && (cross(v, vr) > 0);

        return intersect_vl || intersect_vr || between;
    };

    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (sees(i, j)) {
                // cerr << ".. " << i + 1 << " sees " << j + 1 << endl;
                graph[i].emplace_back(j);
                indeg[j] += 1;
            }
        }
    }

    auto topo_sort = [&]() {
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.emplace(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.emplace_back(u + 1);
            for (auto v : graph[u]) {
                if (--indeg[v] == 0) q.emplace(v);
            }
        }
        if (topo.size() != n) {
            topo.clear();
            topo.emplace_back(-1);
        }
        return topo;
    };

    vector<int> topo = topo_sort();
    for (auto &x : topo) {
        cout << x << " ";
    }
    cout << "\n";
}

