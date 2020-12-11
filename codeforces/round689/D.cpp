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

int n, q;
vector<LL> arr;
vector<LL> qry;
map<LL, bool> qry2ans;

void init() {
    cin >> n >> q;
    arr.assign(n, 0), qry.assign(q, 0); qry2ans.clear();
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < q; i++) { 
        cin >> qry[i];
        qry2ans[qry[i]] = false;
    }
    sort(arr.begin(), arr.end());
}

void f(int l, int r) {
    if (r < l) return;
    if (l == r) {
        LL sum = arr[l];
        if (qry2ans.count(sum) == true) {
            qry2ans[sum] = true;
        }
        return;
    }
    LL mx = 0, mn = 1e9, sum = 0;
    for (int i = l; i <= r; i++) {
        sum += arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    if (qry2ans.count(sum) == true) {
        qry2ans[sum] = true;
    }
    // cerr << var(l) << var(r) << var(sum) << var(mx) << var(mn) << endl;
    LL mid = (mx + mn)/2, idx = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] <= mid) idx = i;
        else break;
    }
    if(idx != r) f(l, idx); 
    if(idx+1 <= r) f(idx+1, r);
}

void process() {
    f(0, n-1);
    for (auto q : qry) {
        if (qry2ans[q] == true) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

