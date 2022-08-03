#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int N, K, A; cin >> N >> K >> A;
    K -= 1;
    A += K;
    A -= 1;
    A %= N;
    A += 1;
    cout << A << "\n";
}

