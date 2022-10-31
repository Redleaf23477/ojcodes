#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int,int,string>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<T> arr(n);
    for (auto &[g, s, b, name] : arr) {
        cin >> g >> s >> b >> ws;
        getline(cin, name);
    }
    sort(arr.begin(), arr.end());
    cout << get<3>(arr.back()) << "\n";
}

