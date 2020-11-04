#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using LL = long long int;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        LL n, m;
        cin >> n >> m;
        LL sum =0 ;
        for(int i = 0; i < n; i++) {
            LL x; cin >> x; sum += x;
        }
        cout << (sum==m? "YES" : "NO") << endl;
    }
    cout.flush();
    return 0;
}

