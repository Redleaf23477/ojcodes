#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    if (n == 1) {
        if (arr[0] == 0) cout << "ap!\n";
        else if (arr[0] > 0) cout << "*fizzle*\n";
        else cout << "*bunny*\n";
        return;
    }

    if (*min_element(arr.begin(), arr.end()) == 0 && *max_element(arr.begin(), arr.end()) == 0) {
        cout << "ap!\n";
        return;
    }


    for (size_t i = 1; i < arr.size(); i++) {
        int zero_cnt = 0;
        vector<LL> bk(arr);
        for (size_t j = i; j < arr.size(); j++) {
            arr[j] -= bk[j-1];
            if (arr[j] == 0) zero_cnt += 1;
        }
        // if all zero
        if (zero_cnt + i == arr.size()) {
            cout << string(i, 'z') << "ap!\n";
            return;
        }
        
        /*
        // debug
        for (size_t j = i; j < arr.size(); j++) {
            cerr << arr[j] << " \n"[j+1==arr.size()];
        }
        */
    }
    if (arr.back() > 0) cout << "*fizzle*\n";
    else cout << "*bunny*\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

