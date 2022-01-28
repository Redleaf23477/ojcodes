#include <bits/stdc++.h>
using namespace std;

int count(int n, vector<int> &cnt) {
    vector<int> fac(10, 1);
    for (int i = 2; i < 10; i++) fac[i] = fac[i-1] * i;
    int ans = fac[n];
    for (auto x : cnt) {
        if (x > 0) ans /= fac[x];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string str; cin >> str;
    vector<int> cnt(26, 0);
    for (auto c : str) cnt[c-'a'] += 1;
    cout << count(str.size(), cnt) << endl;
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

