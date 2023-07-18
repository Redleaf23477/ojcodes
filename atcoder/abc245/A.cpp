#include <bits/stdc++.h>
using namespace std;
using LL = long long int;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int A, B, C, D; cin >> A >> B >> C >> D;
    if (A * 60 + B <= C * 60 + D) cout << "Takahashi\n";
    else cout << "Aoki\n";
}



