#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T2 = tuple<int,int>;
using T3 = tuple<int,int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<T3> arr(n);
    for (int i = 0; i < n; i++) {
        auto &[l, r, idx] = arr[i];
        cin >> l >> r;
        idx = i;
    }
    sort(arr.begin(), arr.end());
    vector<int> ans(n, 0);
    priority_queue<T2, vector<T2>, greater<T2>> pq;
    for (auto [l, r, idx] : arr) {
        int room = pq.size() + 1;
        if (!pq.empty() && get<0>(pq.top()) < l) {
            room = get<1>(pq.top());
            pq.pop();
        }
        ans[idx] = room;
        pq.emplace(r, room);
    }
    cout << pq.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

