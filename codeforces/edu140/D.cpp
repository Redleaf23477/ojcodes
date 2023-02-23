#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    int L = 0, R = 0;
    LL accL = 0, accR = 0;
    for (auto c : str) {
        if (c == '1') L = accL + 1, accL += L;
        else R = accR + 1, accR += R;
    }
    for (LL i = 1 + accL; i <= (1 << n) - accR; i++) cout << i << " ";
    cout << "\n";
}

