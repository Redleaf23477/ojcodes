#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    vector<LL> arr({1});
    while (arr.back() * 3 <= 1000000000ll) {
        arr.emplace_back(arr.back() * 3);
    }
    while (T--) {
        int n; cin >> n;
        if (n > arr.size()) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
}

