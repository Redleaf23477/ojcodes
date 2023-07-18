#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Vec {
    LL x, y;
    Vec(): x(0), y(0) {}
    Vec(int _x, int _y) : x(_x), y(_y) {}
    LL operator* (Vec that) {
        return x * that.y - y * that.x; 
    }
};

struct Point {
    LL x, y;
    Point(): x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Vec operator- (Point that) {
        return Vec(x - that.x, y - that.y);
    }
};

LL triangle_double_area(Point a, Point b, Point c) {
    return (b - a) * (c - a);
}

LL calc_double_area(vector<Point> &arr, int N) {
    LL ans = 0;
    for (int i = 2; i < N; i++) {
        // triangle 0, i-1, i
        ans += triangle_double_area(arr[0], arr[i-1], arr[i]);
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    vector<Point> arr(N);
    for (auto &[x, y] : arr) cin >> x >> y;

    LL area = calc_double_area(arr, N);

    LL ans = 4 * area, sum = 0;
    for (int i = 0, j = 2; i < N; i++) {
        // add triangle i, j-1, j, and advance j
        // if too big, advance i, do not advance j
        while (4 * sum < area) {
            sum += triangle_double_area(arr[i], arr[(j-1+N)%N], arr[j]);
            ans = min(ans, abs(4 * sum - area));
            j = (j + 1) % N;
        }
        // substract triangle i, i+1, j
        sum -= triangle_double_area(arr[i], arr[(i+1)%N], arr[(j-1+N)%N]);
        ans = min(ans, abs(4 * sum - area));
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



