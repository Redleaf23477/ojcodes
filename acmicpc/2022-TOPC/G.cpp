#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

int solve(int n, int m, vector<int> const &A, vector<int> const &B, int delta, int start) {
    int mx_ans = 0;
    for (int use = 1; use <= n; use++) {
        int ans = 0;
        priority_queue<T, vector<T>, less<T>> pq;
        for (int i = 0, j = start; i < use; i++, j = (j + delta + n) % n) {
            pq.emplace(A[j], B[j]);
        }
        for (int i = 0; i < m - use + 1; i++) {
            if (!pq.empty()) {
                auto [a, b] = pq.top(); pq.pop();
                ans += a;
                if (a - b > 0) pq.emplace(a - b, b);
            }
        }
        mx_ans = max(mx_ans, ans);
    }
    return mx_ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n, 0), B(n, 0);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    int mx_ans = 0;
    for (int start = 0; start < n; start++) {
        int step = min(start, n - start);
        mx_ans = max(mx_ans, solve(n, m - step, A, B, 1, start));
        mx_ans = max(mx_ans, solve(n, m - step, A, B, -1, start));
    }
    cout << mx_ans << "\n";
}

