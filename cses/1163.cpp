#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg {
    LL l, r;
    Seg(LL a, LL b) : l(a), r(b) {}
    int get_len() const {
        return r - l;
    }
    bool operator < (const Seg &that) const {
        if (get_len() != that.get_len()) return get_len() < that.get_len();
        if (l != that.l) return l < that.l;
        return r < that.r;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL x; cin >> x;
    int n; cin >> n;
    vector<LL> pos(n);
    for (auto &p : pos) cin >> p;

    set<Seg> seg_set; seg_set.insert(Seg(0, x));
    set<LL> pos_set; pos_set.insert(0), pos_set.insert(x);
    for (auto p : pos) {
        auto it = pos_set.upper_bound(p);  // *it > p
        auto jt = it; jt--; // *jt < p, seg = (*jt, *it)
        auto seg_it = seg_set.find(Seg(*jt, *it));
        assert(seg_it != seg_set.end());

        /*
        cerr << "p = " << p << ", *it = " << *it << ", *jt = " << *jt << endl;
        */

        // remove(*jt+1, *it-1)
        seg_set.erase(seg_it);

        // push (*jt+1, p-1), (p+1, *it-1)
        for (auto seg : {Seg(*jt, p), Seg(p, *it)}) {
            if (seg.get_len() > 0) seg_set.insert(seg);
        }
        pos_set.insert(p);

        /*
        cerr << "seg_set = {";
        for (auto s : seg_set) {
            cerr << "(" << s.l << "," << s.r << ")";
        }
        cerr << "}" << endl;
        */

        auto max_seg_it = seg_set.end(); max_seg_it--;
        cout << max_seg_it->get_len() << " ";
    }
    cout << "\n";
}

