#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    // dijkstra
    using T3 = tuple<int,int,int>;  // (coin, acc, rec)
    using T2 = tuple<int,int>;  // (acc, rec)
    
    map<T2, int> dist;
    priority_queue<T3, vector<T3>, greater<T3>> pq;
    for (int first = 1; first <= n; first++) {
        dist[T2(first, 0)] = first;
        pq.emplace(first, first, 0);
    }

    int ans = n;
    while (!pq.empty()) {
        auto [coin, acc, rec] = pq.top(); pq.pop();
        // cerr << "(" << coin << ", " << acc << ", " << rec << ")" << endl;
        if (acc == n) {
            ans = min(ans, coin); continue;
        }
        if (coin > dist[T2(acc, rec)]) continue;


        if (rec != acc && n - acc >= acc) {
            // four coins
            T2 t2(acc, acc);
            auto it = dist.find(t2);
            if (it == dist.end() || it->second > coin + 4) {
                dist[t2] = coin + 4;
                pq.emplace(coin + 4, acc, acc);
            }
        }
        if (rec > 0 && n - acc >= rec) {
            // two coins
            T2 t2(acc + rec, rec);
            auto it = dist.find(t2);
            if (it == dist.end() || it->second > coin + 2) {
                dist[t2] = coin + 2;
                pq.emplace(coin + 2, acc + rec, rec);
            }
        }
        {
            // one coin
            T2 t2(acc + 1, rec);
            auto it = dist.find(t2);
            if (it == dist.end() || it->second > coin + 1) {
                dist[t2] = coin + 1;
                pq.emplace(coin + 1, acc + 1, rec);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve(); 
    }
}

