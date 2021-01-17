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
vector<tuple<LL,LL>> cmd;
vector<LL> stat; // ignored(-1), otherwise end time

void init() {
    cin >> n;
    cmd.resize(n+1), stat.resize(n+1);
    for (int i = 0; i < n; i++) {
        LL t, x; cin >> t >> x;
        cmd[i] = make_tuple(t, x);
    }
    cmd[n] = make_tuple(3*1000000000ll, 0);
    LL pos = 0, endT = 0;
    for (int i = 0; i < n; i++) {
        auto [t, x] = cmd[i];
        if (t < endT) {
            stat[i] = -1;
        } else {
            stat[i] = endT = t+abs(pos-x);
            pos = x;
        }
    }
    /*
    cerr << "stat: ";
    for (auto x : stat) cerr << x << " ";
    cerr << endl;
    */
}

void process() {
    LL ans = 0;
    LL pos = 0, targ = 0, startT = 0, endT = 0;
    auto getPos = [&](LL t) {
        if (t >= endT) return targ;
        else {
            LL d = t - startT;
            LL dir = (targ > pos)? 1 : -1;
            LL p = pos + d * dir;
            return p;
        }
    };
    for (int i = 0; i < n; i++) {
        auto [t, x] = cmd[i];
        auto [nt, _] = cmd[i+1];
        if (stat[i] == -1) {
            LL pt = getPos(t), pnt = getPos(nt);
            if (min(pt, pnt) <= x && x <= max(pt, pnt)) ans++;
        } else {
            pos = targ, targ = x, startT = t, endT = stat[i];
            if (endT <= nt) ans++;
        }
    }
    cout << ans << endl;
}

