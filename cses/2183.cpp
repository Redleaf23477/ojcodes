#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    LL num = 1;
    for (auto x : arr) {
        if (num < x) {
            break;
        } else {
            num += x;
        }
    }

    cout << num << "\n";
}

