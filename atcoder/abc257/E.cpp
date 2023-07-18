#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<int> cost(10);
    for (int i = 1; i <= 9; i++) cin >> cost[i];

    int mn_cost = cost[9], mn_i = 9;
    for (int i = 9; i > 0; i--) {
        if (cost[i] < mn_cost) {
            mn_cost = cost[i];
            mn_i = i;
        }
    }

    string ans(N / mn_cost, '0' + mn_i);
    int rem = N % mn_cost + mn_cost;
    for (auto &ch : ans) {
        for (int i = 9; i > mn_i; i--) {
            if (cost[i] <= rem) {
                ch = '0' + i;
                rem -= cost[i];
                rem += mn_cost;
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



