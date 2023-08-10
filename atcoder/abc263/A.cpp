#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool fullhouse(vector<int> &arr) {
    if (arr[0] != arr[1]) return false;
    if (arr[3] != arr[4]) return false;
    return (arr[2] == arr[1]) || (arr[2] == arr[3]);
}

void solve() {
    vector<int> arr(5);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    cout << (fullhouse(arr)? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



