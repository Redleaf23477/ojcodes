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

const int INF = 1e9+10;

struct ST {
    int n;
    vector<int> st;
    void build(int l, int r, int idx, vector<int> &arr) {
        if (l == r) {
            st[idx] = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        st[idx] = min(st[lson], st[rson]);
    }
    void build(int _n, vector<int> &arr) {
        n = _n; 
        st.assign(4*n, 0);
        build(0, n-1, 1, arr);
    }
    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) return st[idx];
        else if (r < L || R < l) return INF;
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        return min(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }
};

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
vector<int> arr;
ST st;

void init() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    st.build(n, arr);
}

void process() {
    vector<int> sufMx(n, 0); {
        sufMx[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) sufMx[i] = max(sufMx[i+1], arr[i]);
    }
    int L = -1, R = -1;
    for (int i = 0, preMx = arr[0]; i < n-2; preMx = max(preMx, arr[++i])) {
        // search 
        int l = i+2, r = n-1, mid, ans = -1; 
        while (l <= r) {
            mid = (l+r)/2;
            if (sufMx[mid] > preMx) l = mid+1;
            else if (sufMx[mid] < preMx) r = mid-1;
            else {
                int mn = st.query(i+1, mid-1);
                if (mn == preMx) { ans = mid; break; }
                else if (mn < preMx) { r = mid-1; }
                else { l = mid + 1; }
            }
        }
        if (ans != -1) { L = i, R = mid; break; }
    }
    if (L == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << L+1 << " " << R-1-L << " " << n-R << endl;
    }
}
