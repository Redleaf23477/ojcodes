#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL f(LL n) {
    vector<int> small_ans {0, 0, 6, 28, 96, 252};
    if (n < small_ans.size()) return small_ans[n];
    LL sq = n * n;
    return ((n-4) * (n-4) * (sq-1-8) + 
        (n-4) * 4 * (sq-1-6) + 
        (n-4) * 4 * (sq-1-4) + 
        4 * (sq-1-4) +
        8 * (sq-1-3) + 
        4 * (sq-1-2)) / 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << f(i) << "\n";
    }
}

