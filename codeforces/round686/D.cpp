// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

LL sp[100005];
vector<LL> primes;

void init() {
    iota(sp, sp+100005, 0);
    for (LL i = 2; i * i < 100005; i++) {
        if (sp[i] != i) continue;
        for (LL j = i*i; j < 100005; j += i) {
            sp[j] = i;
        }
    }
    for (LL i = 2; i < 100005; i++) {
        if (sp[i] == i) primes.emplace_back(i);
    }
    /*
    cerr << "primes = ";
    for (auto x : primes) cerr << x << " ";
    cerr << endl;
    */
}

void process() {
    LL n; cin >> n;
    map<LL,LL> fac;
    LL len = 0;
    /*
    for (auto p : primes) {
        if (n % p == 0) fac[p] = 0;
        while (n % p == 0) {
            n /= p;
            len = max(len, ++fac[p]);
        }
    }
    */
    for (auto p : primes) {
        if (n % p == 0) {
            LL cnt = 0;
            while (n % p == 0) {
                n /= p; 
                cnt++;
            }
            len = max(len, fac[p] = cnt); 
        }
        if (n < 100005) break;
    }
    while (n != 1 && n < 100005) {
        LL p = sp[n];
        if (fac.count(p) == 0) fac[p] = 0;
        len = max(len, ++fac[p]);
        n /= p;
    }
    if (n != 1) len = max(len, fac[n] = 1);
    vector<LL> ans(len, 1);

    for (auto [p, cnt] : fac) {
        for (LL i = 0; i < cnt; i++) {
            ans[len-1-i] *= p;
        }
    }

    cout << len << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

