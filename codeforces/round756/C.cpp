#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        list<int> arr(n);
        for (auto &x : arr) cin >> x;
        if (arr.front() == n || arr.back() == n) {
            list<int> ans;
            if (arr.front() == n) {
                ans.emplace_back(arr.front());
                arr.pop_front();
            } else {
                ans.emplace_back(arr.back());
                arr.pop_back();
            }

            while (!arr.empty()) {
                if (arr.front() < arr.back()) {
                    ans.emplace_front(arr.front());
                    arr.pop_front();
                } else {
                    ans.emplace_back(arr.back());
                    arr.pop_back();
                }
            }

            for (auto x : ans) cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

