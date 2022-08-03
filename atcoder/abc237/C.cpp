#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string str; cin >> str;
    int a = 0;
    while (!str.empty() && str.back() == 'a') {
        str.pop_back(); a++;
    }

    bool ans = true;
    for (int i = 0, j = str.size() - 1; i <= j && ans;) {
        if (str[i] == str[j]) {
            i++, j--;
        } else if (str[i] == 'a') {
            if (a > 0) i++, a--;
            else ans = false;
        } else {
            ans = false;
        }
    }
    cout << (ans? "Yes\n" : "No\n");
}

