#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int stat1(vector<int> len, int odd, int j, int k) {
    for (int i = 0; i < k && odd > 0; i++) {
        len[j] += 1;
        odd--;
        j = (j + 1) % k;
    }
    return *min_element(len.begin(), len.end());
}

int stat2(vector<int> len, int odd, int j, int k) {
    for (int i = 0; i < j; i++) {
        len[i] -= 1;
        odd ++;
    }
    for (int i = j; i < k && odd > 0; i++) {
        len[i] += 1;
        odd --;
    }
    return *min_element(len.begin(), len.end());
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        vector<int> cnt(26, 0);
        for (auto c : str) cnt[c-'a'] += 1;

        int odd = 0, j = 0;
        vector<int> len(k, 0);
        for (int i = 0; i < 26; i++) {
            while (cnt[i] >= 2) {
                len[j] += 2;
                cnt[i] -= 2;
                j = (j + 1) % k;
            }
            if (cnt[i] % 2 == 1) odd++;
        }

        /*
        cerr << "len = ";
        for (auto x : len) cerr << x << " ";
        cerr << endl;

        cerr << "s1 = " << stat1(len, odd, j, k) << endl;
        cerr << "s2 = " << stat2(len, odd, j, k) << endl;
        */

        cout << max(stat1(len, odd, j, k), stat2(len, odd, j, k)) << endl;
    }
}

