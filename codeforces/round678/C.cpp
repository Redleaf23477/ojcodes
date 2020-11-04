#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using LL = long long int;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x, pos; cin >> n >> x >> pos;
    int l = 0, r = n;
    int eq = 1, leq = 0, gt = 0, whatever;
    // simulate
    while(l < r) {
        int mid = (l+r)/2;
        if(mid <= pos) {
            leq ++;
            l = mid+1;
        } else {
            gt ++;
            r = mid;
        }
    }
    leq --;
    whatever = n - eq - leq - gt;

    const LL MOD = (LL)1e9+7;

    LL C[1010][1010]; memset(C, 0, sizeof(C));
    LL fac[1010] = {1};
    for(LL i = 1; i <= 1000; i++) fac[i] = fac[i-1] * i % MOD;
    C[0][0] = 1;
    for(int i = 1; i <= 1000; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            // C[i][j] = C[i-1][j-1] + C[i-1][j]
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if(C[i][j] >= MOD) C[i][j] -= MOD;
        }
    }

    // count
    LL ans = 1;
    /*
    cerr << var(whatever) << var(leq) << var(gt) << endl;
    cerr << var(C[x-1][leq]) << var(C[n-x][gt]) << endl;
    */
    ans = ans * fac[whatever] % MOD;
    ans = ans * C[x-1][leq]*fac[leq] % MOD;
    ans = ans * C[n-x][gt]*fac[gt] % MOD;
    cout << ans << endl;
    cout.flush();
    return 0;
}

