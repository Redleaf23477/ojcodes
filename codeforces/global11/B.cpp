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

void init() {
}

void process() {
    int n, k; cin >> n >> k;
    string str; cin >> str;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'W') {
            ans++;
            if(i > 0 && str[i-1] == 'W') ans++;
        }
    }

    int start = 0, end = 0;
    int s = -1, e = -1;
    vector<int> mid;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'L') start++;
        else { s = i; break; }
    }
    for(int i = n-1; i >= 0; i--) {
        if(str[i] == 'L') end++;
        else { e = i;  break; }
    }
    if(s != -1 && e != -1) {
        for(int i = s, l = -1; i <= e; i++) {
            if(str[i] == 'L') {
                if(l == -1) l = i;
            } else {
                if(l != -1) mid.emplace_back(i-l);
                l = -1;
            }
        }
    }

    /*
    cerr << var(start) << var(end) << endl;
    cerr << "mid: ";
    for(auto x : mid) cerr << x << " ";
    cerr << endl;
    cerr << var(ans) << endl;
    */

    // k == 0
    if(k == 0) {
        cout << ans << endl;
    } else if(ans == 0) {
        // case1 : all lose
        ans = k + (k-1);
        cout << ans << endl;
    } else {
        // case2 : rest
        sort(mid.begin(), mid.end(), greater<int>());
        while(!mid.empty() && k > 0) {
            int x = mid.back(); mid.pop_back();
            if(k >= x) {
                k -= x;
                ans += 2*x+1;
            } else {
                ans += 2*k, k = 0;
            }
        }
        if(k > 0) {
            ans += 2*min(k, start+end);
        }
        cout << ans << endl;
    }

}

