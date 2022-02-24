#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        vector<bool> arr(26, false);
        string str; cin >> str;
        bool good = true;
        for (auto x : str) {
            if ('a' <= x && x <= 'z') arr[x-'a'] = true;
            else if (arr[x-'A'] == false) good = false;
        }
        cout << (good? "YES\n" : "NO\n");
    }
}

