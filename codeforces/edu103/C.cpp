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
vector<LL> c, a, b;

void init() {
    cin >> n;
    c.resize(n), a.resize(n), b.resize(n);
    for (auto &x : c) cin >> x;
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 1; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
}

void process() {
    vector<LL> left(n, 0), right(n, 0); {
        left[1] = 2 + b[1] - a[1];
        for (int i = 2; i < n; i++) {
            left[i] = 2 + b[i] - a[i];
            if (a[i] < b[i]) 
                left[i] = max(left[i], 2+left[i-1]+a[i]-1+c[i-1]-b[i]);
        }
        right[n-2] = 2 + c[n-1] - 1;
        for (int i = n-3; i >= 0; i--) {
            right[i] = 2 + c[i+1] - 1;
            if (a[i+2] < b[i+2]) 
                right[i] = max(right[i], 2+a[i+2]-1+c[i+1]-b[i+2]+right[i+1]);
        }
        /*
        cerr << "left = " << endl;
        for (auto x : left) cerr << x << " ";
        cerr << endl;
        cerr << "right = " << endl;
        for (auto x : right) cerr << x << " ";
        cerr << endl;
        */
    }
    LL ans = 0; {
        // i = 0
        ans = right[0]+b[1]-a[1];
        // i = [1,n-1)
        for (int i = 1; i < n-1; i++) {
            ans = max({ans, left[i]+c[i]-1, right[i]+b[i+1]-a[i+1]});
            if (a[i+1] != b[i+1]) {
                ans = max(ans, left[i]+right[i]+a[i+1]-1+c[i]-b[i+1]);
            }
        }
        // i=n-1
        ans = max(ans, left[n-1]+c[n-1]-1);
    }
    cout << ans << endl;
}

