#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = pair<LL,LL>;
using Vec = pair<LL,LL>;

Vec operator - (P lhs, P rhs) { return Vec(lhs.first - rhs.first, lhs.second - rhs.second); }
LL cross(Vec lhs, Vec rhs) { return lhs.first * rhs.second - lhs.second * rhs.first; }


vector<P> monotone_chain(vector<P> &arr, int n) {
    sort(arr.begin(), arr.end(), [](P const &lhs, P const &rhs) {
        if (lhs.first != rhs.first) return lhs.first < rhs.first;
        else return lhs.second < rhs.second; 
    });
    auto add_to_hull = [&] (vector<P> &convex_hull, P pt) {
        while (convex_hull.size() > 1) {
            Vec prev = convex_hull.end()[-1] - convex_hull.end()[-2];
            Vec me = pt - convex_hull.back();
            if (cross(prev, me) <= 0) convex_hull.pop_back();
            else break;
        }
        convex_hull.emplace_back(pt);
    };
    // lower hull
    vector<P> lower_hull {arr[0], arr[1]};
    for (int i = 2; i < n; i++) add_to_hull(lower_hull, arr[i]);
    // upper hull
    vector<P> upper_hull {arr.end()[-1], arr.end()[-2]};
    for (int i = n-3; i >= 0; i--) add_to_hull(upper_hull, arr[i]);

    lower_hull.pop_back();
    upper_hull.pop_back();
    lower_hull.insert(lower_hull.end(), upper_hull.begin(), upper_hull.end());

    /*
    cerr << "convex hull: ";
    for (auto [x, y] : lower_hull) cerr << "(" << x << "," << y << ")" << endl;
    */

    return lower_hull;
}

tuple<P,P,P> largest_triangle(vector<P> const &convex_hull) {
    int n = convex_hull.size();
    tuple<int,int,int> best(-1, -1, -1);
    LL best_area = 0;
    for (int i = 0; i + 2 < n; i++) for (int j = i + 1, k = j + 1; j < n; j++) {
        Vec base = convex_hull[j] - convex_hull[i];
        while (k + 1 < n) {
            Vec prev = convex_hull[k] - convex_hull[i];
            Vec me = convex_hull[k+1] - convex_hull[i];
            /*
            cerr << "base(" << base.first << ", " << base.second << ")" << endl;
            cerr << "prev(" << prev.first << ", " << prev.second << ")" << endl;
            cerr << "me(" << me.first << ", " << me.second << ")" << endl;
            cerr << "(" << i << "," << j << "," << k << ") => ";
            cerr << cross(base, prev) << ", " << cross(base, me) << endl;
            */
            if (cross(base, prev) <= cross(base, me)) k++;
            else break;
        }
        LL area = cross(base, convex_hull[k] - convex_hull[i]);
        if (area > best_area) {
            best_area = area;
            best = make_tuple(i, j, k); 
        }
    }
    auto [i, j, k] = best;

    /*
    cerr << "best triangle: " << i << ", " << j << ", " << k << endl;
    cerr << "(" << convex_hull[i].first << "," << convex_hull[i].second << ")";
    cerr << "(" << convex_hull[j].first << "," << convex_hull[j].second << ")";
    cerr << "(" << convex_hull[k].first << "," << convex_hull[k].second << ")";
    cerr << endl;
    */

    return make_tuple(convex_hull[i], convex_hull[j], convex_hull[k]);
}

void solve() {
    int n; cin >> n;
    LL s; cin >> s;
    vector<P> arr(n);
    for (auto &[x, y] : arr) cin >> x >> y;
    vector<P> convex_hull = monotone_chain(arr, n);
    auto [a, b, c] = largest_triangle(convex_hull);

    cout << a.first + (b.first - c.first) << " " << a.second + (b.second - c.second) << "\n";
    cout << b.first + (c.first - a.first) << " " << b.second + (c.second - a.second) << "\n";
    cout << c.first + (a.first - b.first) << " " << c.second + (a.second - b.second) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



