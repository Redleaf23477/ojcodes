#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    int lgn; cin >> lgn;
    int n = (1 << lgn);

    vector<LL> fac(n + 1, 1);
    vector<LL> pw2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = i * fac[i-1] % MOD;
        pw2[i] = 2 * pw2[i-1] % MOD;
    }

    vector<int> seat(n);
    for (int i = 0; i < n; i++) {
        cin >> seat[i];
        if (seat[i] != -1) seat[i]--;
    }
    
    bool has_solution = true;
    LL ans = 1;
    for (int h = lgn - 1; h >= 0 && has_solution; h--) {
        LL one = 0, two = 0;
        for (int i = 0; i < n; i += 2) {
            if (seat[i] == -1 && seat[i+1] == -1) {
                two++;
            } else if (seat[i] != -1 && seat[i+1] != -1) {
                if (((seat[i] >> h) & 1) && ((seat[i+1] >> h) & 1)) {
                    has_solution = false;
                } 
                if (!((seat[i] >> h) & 1) && !((seat[i+1] >> h) & 1)) {
                    has_solution = false;
                } 
            } else {
                int people = (seat[i] != -1? seat[i] : seat[i+1]);
                one += ((people >> h) & 1) == 0;
            }
        }
        if (!has_solution) break;
        ans = ans * fac[one + two] % MOD * pw2[two] % MOD;
        for (int i = 0; i < n / 2; i++) {
            int a = seat[i * 2], b = seat[i * 2 + 1];
            if (a != -1 && ((a >> h) & 1)) seat[i] = b;
            else if (b != -1 && ((b >> h) & 1)) seat[i] = a;
            else seat[i] = (a == -1? b : a);
        }
        n /= 2;
        seat.resize(n);
    }

    cout << (has_solution? ans : 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



