#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    vector<int> pos_in_B(n+1);
    for (int i = 0; i < n; i++) {
        pos_in_B[B[i]] = i;
    }

    vector<vector<int>> match_B(n);
    for (int i = 0; i < n; i++) {
        for (int j = A[i]; j <= n; j += A[i]) {
            match_B[pos_in_B[j]].emplace_back(i);
        }
    }

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        /*
        cerr << "i = " << i << ": ";
        for (auto p : match_B[i]) cerr << p << " ";
        cerr << endl;
        */
        for (int j = match_B[i].size() - 1; j >= 0; j--) {
            int p = match_B[i][j];
            auto it = lower_bound(lis.begin(), lis.end(), p);
            if (it == lis.end()) {
                lis.emplace_back(p);
            } else {
                *it = p;
            }
        }
    }
    cout << lis.size() << "\n";
}

