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
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
vector<LL> d;

void init() {
    cin >> n;
    d.resize(2*n); for (auto &x : d) cin >> x;
}

/*
 * e.g. sorted array = (-z -y -x x y z)
 *
 * The following relation can be easily proven if plotted on OX axis
 * D[0] = sum(dist to x) = 2*(x+y+z)
 * D[1] = sum(dist to y) > D[0]
 * D[2] = sum(dist to z) > D[1]
 *
 */

void process() {
    sort(d.begin(), d.end());
    vector<LL> d2(n);
    bool good = true;
    for (int i = 0; i < n; i++) {
        if (d[2*i] != d[2*i+1]) good = false;
        if (d[2*i] == 0) good = false;
        if (i>0 && d[2*i] == d[2*i-1]) good = false;
        d2[i] = d[2*i];
    }
    LL acc = 0; // dist(positive elements to smallest element)
    LL cur = 0; // dist(a positive element to smallest element)
    for (int i = 1; i < n; i++) {
        LL d = d2[i] - d2[i-1];
        if (d % (2*i) != 0) good = false;
        d /= (2*i);
        cur += d;
        acc += cur;
    }
    if (d2[0] % 2 != 0) good = false;
    /*
    cerr << var(cur) << var(acc) << endl;
    cerr << var(d2[0]) << endl;
    */
    d2[0] /= 2; // now D[0] = sum(all positive elems) = n*(smallest elem) + acc
    d2[0] -= acc;
    if (d2[0] <= 0 || d2[0] % n != 0) good = false;
    cout << (good? "YES" : "NO") << endl;
}

