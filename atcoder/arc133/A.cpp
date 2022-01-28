#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n), tmp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (tmp.empty() || arr[i] != tmp.back()) tmp.emplace_back(arr[i]);
    }
    int bye = tmp.back();
    for (size_t i = 0; i + 1 < tmp.size(); i++) {
        if (tmp[i] > tmp[i+1]) {
            bye = tmp[i]; break;
        }
    }
    for (auto x : arr) {
        if (x != bye) cout << x << " ";
    }
    cout << "\n";
}

