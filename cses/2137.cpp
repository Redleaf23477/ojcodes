#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<bitset<3000>> arr;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        arr.emplace_back(bitset<3000>(str));
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        LL tmp = (arr[i] & arr[j]).count();
        ans += tmp * (tmp - 1) / 2;
    }
    cout << ans << "\n";
}

