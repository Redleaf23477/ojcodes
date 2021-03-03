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

const int M = 1000006;
int sp[M];
vector<int> p;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    init();
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

void init() {
    iota(sp, sp+M, 0);
    for (LL i = 2; i < M; i++) {
        if (sp[i] != i) continue;
        p.emplace_back(i);
        for (LL j = i*i; j < M; j += i) sp[j] = i;
    }
    /*
    cerr << "p = ";
    for (auto x : p) cerr << x << " ";
    cerr << endl;
    */
}

void process() {
    int d; cin >> d;
    LL p1 = *lower_bound(p.begin(), p.end(), 1+d);
    LL p2 = *lower_bound(p.begin(), p.end(), p1+d);
    LL ans = min(p1*p2, p1*p1*p1);
    cout << ans << endl;
}

