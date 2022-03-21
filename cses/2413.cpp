#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;
constexpr int N = 1e6;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    vector<LL> dp1(N+1, 1);
    partial_sum(dp1.begin(), dp1.end(), dp1.begin());
}

