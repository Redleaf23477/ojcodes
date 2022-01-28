#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool search(vector<tuple<LL,int>> &arr, LL sum) {
    for (size_t i = 0; i+1 < arr.size(); i++) {
        LL s = sum - get<0>(arr[i]);
        auto it = lower_bound(arr.begin() + i + 1, arr.end(), make_tuple(s, 0));
        if (it != arr.end() && get<0>(*it) == s) {
            cout << get<1>(arr[i]) << " " << get<1>(*it) << endl;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL sum; cin >> sum;
    vector<tuple<LL,int>> arr(n);
    for (int i = 0; i < n; i++) {
        auto &[val, idx] = arr[i];
        cin >> val;
        idx = i + 1;
    }
    sort(arr.begin(), arr.end());

    if (!search(arr, sum)) cout << "IMPOSSIBLE" << endl;
}

