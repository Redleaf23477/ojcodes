#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int k;
    while (cin >> k) {
        using Node = tuple<int,vector<int>>;
        vector<vector<int>> arr(k, vector<int>(k));
        for (auto &x: arr) {
            for (auto &y : x) {
                cin >> y;
            }
            sort(x.begin(), x.end());
        }

        // dijkstra
        int sum = 0;
        for (auto &x : arr) sum += x.front();
        set<Node> pq;  // use set as priority queue
        pq.insert(Node(sum, vector<int>(k, 0)));
        for (int i = 0; i < k; i++) {
            auto [sum, idx] = *pq.begin(); pq.erase(pq.begin());
            cout << sum << " \n"[i==k-1];
            if (i == k-1) break;
            LL mx = k*1000000;
            if (!pq.empty()) {
                auto it = pq.end();
                it--;
                mx = get<0>(*it);
            }
            for (int j = 0; j < k; j++) {
                sum += arr[j][idx[j]+1] - arr[j][idx[j]];
                idx[j] += 1;
                if (pq.size() < k-i || sum < mx) pq.insert(Node(sum, idx));
                idx[j] -= 1;
                sum -= arr[j][idx[j]+1] - arr[j][idx[j]];
            }
            while (pq.size() > k-i) {
                auto it = pq.end(); it--;
                pq.erase(it);
            }
        }
    }
}
