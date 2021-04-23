#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using LL = long long int;

struct Seg {
    int n;
    vector<int> st;
    void build(int l, int r, int idx, vector<int> &arr) {
        if (l == r) {
            st[idx] = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        st[idx] = max(st[lson], st[rson]);
    }
    Seg(int _n, vector<int> &arr) {
        n = _n;
        st.assign(4*n, -1);
        build(0, n-1, 1, arr);
    }
    int query(int l, int r, int idx, int L, int R) {
        if (r < L || R < l) return -1;
        if (L <= l && r <= R) return st[idx];
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        return max(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }
};

void solve() {
    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    vector<int> me_lmost(n, -1), me_rmost(n, -1);
    // me_lmost
    me_lmost[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i-1] < arr[i]) me_lmost[i] = me_lmost[i-1]+1;
        else me_lmost[i] = 0;
    }
    me_rmost[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[i+1]) me_rmost[i] = me_rmost[i+1]+1;
        else me_rmost[i] = 0;
    }
    /*
    cerr << "me_lmost = ";
    for (auto x : me_lmost) cerr << x << " ";
    cerr << endl;
    cerr << "me_rmost = ";
    for (auto x : me_rmost) cerr << x << " ";
    cerr << endl;
    */
    Seg he_right(n, me_lmost), he_left(n, me_rmost);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool kill = true;
        int goLeft = me_lmost[i], goRight = me_rmost[i];
        int shelter = 0;
        if (i-goLeft-1 >= 0) {
            // shelter = max(shelter, he_pre[i-goLeft-1]);
            shelter = max({shelter, he_left.query(0, i-goLeft-1), he_right.query(0, i-goLeft-1)});
        }
        if (i+goRight+1 <= n-1) {
            shelter = max({shelter, he_left.query(i+goRight+1, n-1), he_right.query(i+goRight+1, n-1)});
        }

        // he choose shelter
        if (shelter >= max(goLeft, goRight)) kill = false;
        // he choose left
        if (goLeft % 2 == 1) {
            if (goRight <= goLeft) kill = false;
        } else if (goLeft > 0) {
            if (goRight <= goLeft-1) kill = false;
        }
        // he choose right
        if (goRight % 2 == 1) {
            if (goLeft <= goRight) kill = false;
        } else if (goRight > 0) {
            if (goLeft <= goRight-1) kill = false;
        }

        if (kill) {
            ans++;
            // cerr << "i = " << i << endl;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}


