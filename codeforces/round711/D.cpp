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
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, m;
vector<int> vis;

void init() {
    cin >> n >> m;
    vis.assign(m+1, -1);
    vis[0] = 0;
}

LL ceil(LL x) {
    return x/100000 + (x%100000 > 0);
}

void process() {
    for (int ts = 1; ts <= n; ts++) {
        LL op, x, y; cin >> op >> x >> y;
        for (int j = 0; j <= m; j++) {
            if (vis[j] == -1 || vis[j] >= ts) continue;
            LL nxt = j;
            for (int k = 1; k <= y; k++) {
                nxt = (op == 1? nxt+ceil(x) : ceil(nxt*x));
                if (nxt > m) break;
                if (vis[nxt] != -1) break;
                vis[nxt] = ts;
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << vis[i] << " ";
    cout << endl;
}

