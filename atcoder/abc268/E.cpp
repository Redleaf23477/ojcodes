#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int get_dist(int x, int i, int N) {
    int d1 = abs(i - x);
    int d2 = abs(N - d1);
    return min(d1, d2);
}

void solve() {
    int N; cin >> N;
    vector<LL> arr(N);
    for (auto &x : arr) cin >> x;

    LL sum = 0;
    vector<LL> tag(N + N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x = arr[i];
        int d1 = (i - x + N) % N, d2 = (x - i + N) % N;
        int len = N / 2, odd = N % 2;
        if (d1 <= d2) {
            sum += d1;
            // going up first
            tag[1] += 1;
            tag[len - d1 + 1] -= 1;
            // going down
            tag[len - d1 + 1 + odd] -= 1;
            tag[len - d1 + 1 + odd + len] += 1;
            // going up
            tag[len - d1 + 1 + odd + len] += 1;
        } else {
            sum += d2;
            // going down first
            tag[1] -= 1;
            tag[d2 + 1] += 1;
            // going up
            tag[d2 + 1] += 1;
            tag[d2 + 1 + len] -= 1;
            // going down
            tag[d2 + 1 + len + odd] -= 1;
        }
    }
    LL ans = sum;
    for (int i = 0, acc = 0; i < N; i++) {
        acc += tag[i];
        sum += acc;
        ans = min(ans, sum);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}