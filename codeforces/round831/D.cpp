#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool solve() {
    int R, C, k; cin >> R >> C >> k;
    vector<int> arr(k); 
    for (auto &x : arr) cin >> x;
    reverse(arr.begin(), arr.end());
    int buff_rem = R * C - 4;
    vector<bool> buff(k+1, false);
    for (int t = k; t > 0; t--) {
        if (buff[t]) {
            buff[t] = false;
            buff_rem += 1;
        } else {
            while (!arr.empty() && arr.back() != t) {
                if (buff_rem == 0) return false;
                buff[arr.back()] = true;
                buff_rem -= 1;
                arr.pop_back();
            }
            arr.pop_back();
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cout << (solve()? "YA\n" : "TIDAK\n");
    }
}

