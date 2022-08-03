#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    string str; cin >> str;

    vector<int> cnt(26, 0);
    for (auto c : str) {
        cnt[c - 'a'] += 1;
    }

    int i = 0, j = n-1;
    char target = 'a';
    while (i < j && target < 'z') {
        if (cnt[target - 'a'] == 0) {
            target++;
        } else if (str[i] == target) {
            cnt[target - 'a']--;
            i++;
        } else if (str[j] == target) {
            swap(str[i], str[j]);
            cnt[target - 'a']--;
            cnt[str[j] - 'a']--;
            i++, j--;
        } else {
            cnt[str[j] - 'a']--;
            j--;
        }
    }

    cout << str << "\n";
}

