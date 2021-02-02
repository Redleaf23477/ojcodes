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

const int N = 200005;
const int INF = 2*N;

struct Node {
    int sum, mx, mn;
};

struct Seg1D {
    int n;
    Node st[4*N];
    void up(Node &rt, Node &lson, Node &rson) {
        rt.sum = lson.sum + rson.sum;
        rt.mx = max(lson.mx, lson.sum+rson.mx);
        rt.mn = min(lson.mn, lson.sum+rson.mn);
    }
    void init(int l, int r, int idx, string &arr) {
        if (l == r) {
            st[idx].sum = (arr[l] == '-'? -1 : 1);
            st[idx].mx = max(0, st[idx].sum);
            st[idx].mn = min(0, st[idx].sum);
            return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        init(l, mid, lson, arr);
        init(mid+1, r, rson, arr);
        up(st[idx], st[lson], st[rson]);
    }
    Node query(int l, int r, int idx, int L, int R) {
        if (r < L || R < l) return (Node){0, 0, 0};
        if (L <= l && r <= R) return st[idx];
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        Node res; {
            Node lq = query(l, mid, lson, L, R);
            Node rq = query(mid+1, r, rson, L, R);
            up(res, lq, rq);
        }
        return res;
    }
    void init(string &arr) { n = arr.size(); init(0, n-1, 1, arr); }
    Node query(int L, int R) { return query(0, n-1, 1, L, R); }
};

int n, q;
string arr;
Seg1D st;

void init() {
    cin >> n >> q >> arr;
}

void process() {
    st.init(arr);
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        if (l == 0 && r == n-1) {
            cout << 1 << endl;
        } else if (l == 0) {
            Node res = st.query(r+1, n-1);
            cout << res.mx - res.mn + 1 << endl;
        } else if (r == n-1) {
            Node res = st.query(0, l-1);
            cout << res.mx - res.mn + 1 << endl;
        } else {
            Node lq = st.query(0, l-1);
            Node rq = st.query(r+1, n-1);
            Node res; st.up(res, lq, rq);
            cout << res.mx - res.mn + 1 << endl;
        }
    }
}

