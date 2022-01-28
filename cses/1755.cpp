#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string str; cin >> str;
    vector<int> cnt(26, 0);
    for (auto c : str) {
        cnt[c-'A'] += 1;
    }

    int odd = 0, even = 0;
    for (auto c : cnt) {
        odd += (c % 2 == 1);
        even += (c % 2 == 0);
    }

    if (odd > 1) {
        cout << "NO SOLUTION\n";
    } else if (odd > 0 && str.size() % 2 == 0) {
        cout << "NO SOLUTION\n";
    } else {
        for (int i = 0, j = 0; i < 26; i++) {
            while (cnt[i] >= 2) {
                str[j] = str[str.size() - 1 - j] = 'A' + i;
                j++;
                cnt[i] -= 2;
            }
            if (cnt[i] == 1) {
                str[str.size() / 2] = 'A' + i;
            }
        }

        cout << str << "\n";
    }
}

