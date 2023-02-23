#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) pq.emplace(arr[i]);
    cout << pq.top() << "\n";
    for (int i = k; i < n; i++) {
        pq.emplace(arr[i]);
        pq.pop();
        cout << pq.top() << "\n";
    }
}

