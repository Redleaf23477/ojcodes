#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
static constexpr LL INF = 1e18;

struct Matrix {
    // addition: natural number maximum
    // mulitplication: natural number addition
    //   --> multiplicative_identity = 0
    // natural number along with this two binary operation
    // forms a semiring
    
    static LL dot(LL v1, LL v2, LL w1, LL w2) {
        return min(v1 + w1, v2 + w2);
    }

    LL M[2][2];
    Matrix() {
        M[0][0] = M[1][1] = 0;
        M[0][1] = M[1][0] = INF;
    }
    Matrix mul(Matrix const &that) const { 
        Matrix ans;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ans.M[i][j] = dot(this->M[i][0], this->M[i][1], that.M[0][j], that.M[1][j]);
            }
        }
        return ans;
    }
};

struct Seg1D {
    int n; 
    vector<Matrix> const &arr;
    vector<Matrix> st;
    Seg1D(int _n, vector<Matrix> const &_data) : n(_n), arr(_data), st(4*n) {
        build(0, n-1, 1);
    }
    void build(int l, int r, int idx) {
        if (l == r) {
            st[idx] = arr[l]; return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson);
        build(mid + 1, r, rson);
        st[idx] = st[rson].mul(st[lson]);
    }
    void modify(int x, LL val) { modify(0, n-1, 1, x, val); }
    void modify(int l, int r, int idx, int x, LL val) {
        if (l == x && x == r) {
            st[idx].M[0][0] = st[idx].M[0][1] = val;
            return;
        } else if (x < l || r < x) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = st[rson].mul(st[lson]);
    }
    Matrix query(int L, int R) { return query(0, n-1, 1, L, R); }
    Matrix query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return st[idx];
        } else if (r < L || R < l) {
            return Matrix();
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        Matrix lq = query(l, mid, lson, L, R);
        Matrix rq = query(mid+1, r, rson, L, R);
        return rq.mul(lq);
    }
};

void solve_mini(int n) {
    LL the_only_edge; cin >> the_only_edge;

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        LL val; cin >> val;
        the_only_edge = val;

        cout << 2 * the_only_edge << "\n";
    }
}

void solve(int n) {
    vector<int> arr(n, 0);
    for (int i = 1; i < n; i++) cin >> arr[i];
    vector<Matrix> mat(n);  // f(i) = mat[i] f(i-1)
    for (int i = 3; i < n; i++) {
        mat[i].M[0][0] = mat[i].M[0][1] = arr[i];
        mat[i].M[1][0] = 0;
        mat[i].M[1][1] = INF;
    }

    /*
    vector<Matrix> pref(mat), suff(mat);
    for (int i = 4; i < n; i++) {
        pref[i] = pref[i].mul(pref[i-1]);
    }
    for (int i = n-2; i >= 3; i--) {
        suff[i] = suff[i+1].mul(suff[i]);
    }
    cerr << "check ans: " << 2 * Matrix::dot(pref.back().M[0][0], pref.back().M[0][1], arr[2] + arr[1], arr[1]) << endl;
    */

    Seg1D st(n, mat);
    /*
    Matrix A = st.query(0, n-1);
    cerr << "check ans: " << 2 * Matrix::dot(A.M[0][0], A.M[0][1], arr[2] + arr[1], arr[1]) << endl;
    */

    int q; cin >> q;
    while (q--) {
        int pos; cin >> pos;
        LL val; cin >> val;
        
        if (pos <= 2) {
            arr[pos] = val;
        } else {
            st.modify(pos, val);
        }
        Matrix A = st.query(0, n-1);
        cout << 2 * Matrix::dot(A.M[0][0], A.M[0][1], arr[2] + arr[1], arr[1]) << "\n";

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        int n; cin >> n;
        if (n <= 2) solve_mini(n);
        else solve(n);
    }
}



