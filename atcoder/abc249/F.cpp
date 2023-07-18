#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, K; cin >> N >> K;
    vector<pair<int,LL>> arr(N + 1);
    arr[0] = make_pair(1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    LL ans = -1e18;
    priority_queue<LL> pq;
    LL op_add = 0;
    LL ignore = 0;
    int set_op = 0;
    for (int i = N; i >= 0; i--) {
        auto [op, y] = arr[i];
        if (op == 1) {
            ans = max(ans, y + op_add - ignore); 
            set_op++;
            if (set_op > K) break;
            if (pq.size() + set_op > K) {
                ignore -= pq.top();
                pq.pop();
            }
        } else {
            op_add += y;
            if (y < 0) {
                ignore += y;
                pq.emplace(y);
                if (pq.size() + set_op > K) {
                    ignore -= pq.top();
                    pq.pop();
                }
            }
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



