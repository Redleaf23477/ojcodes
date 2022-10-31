#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    LL K; cin >> K;
    vector<LL> A(n), F(n); 
    for (auto &a : A) cin >> a;
    for (auto &f : F) cin >> f;
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<LL>());
    auto ok = [&](LL tim) {
        LL acc = 0;
        for (int i = 0; i < n; i++) {
            LL mx = tim / F[i];
            if (A[i] > mx) acc += A[i] - mx;
        }
        return acc <= K;
    };
    LL low = 0, high = 1e13, mid, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ok(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }
    cout << ans << "\n";
}

