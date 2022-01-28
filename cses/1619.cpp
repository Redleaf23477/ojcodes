#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> tim;
    vector<tuple<int,int>> arr(n);
    for (auto &[l, r] : arr) {
        cin >> l >> r;
        tim.emplace_back(l);
        tim.emplace_back(r);
    }
    sort(tim.begin(), tim.end());
    vector<int> pre(2*n, 0);
    for (auto &[l, r] : arr) {
        l = lower_bound(tim.begin(), tim.end(), l) - tim.begin();
        r = lower_bound(tim.begin(), tim.end(), r) - tim.begin();
        pre[l]++, pre[r]--;
    }
    partial_sum(pre.begin(), pre.end(), pre.begin());
    cout << *max_element(pre.begin(), pre.end()) << "\n";
}

