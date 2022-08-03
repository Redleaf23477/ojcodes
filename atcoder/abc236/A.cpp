#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string s; cin >> s;
    int a, b; cin >> a >> b;
    swap(s[a-1], s[b-1]);
    cout << s << "\n";
}

