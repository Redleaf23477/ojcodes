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

const int N = 1010;

int n, k; 
char graph[N][N];

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> graph[i][j];
}

void process() {
    auto gen_exchange = [](int i, int j, int k) -> void {
        i++, j++;
        cout << "YES" << endl;
        cout << (k%2? i : j) << " ";
        while (k--) {
            if (k%2) cout << i << " ";
            else cout << j << " ";
        }
        cout << endl;
    };
    auto gen_aabb = [](int u, int v, int w, int k) -> void {
        u++, v++, w++;
        cout << "YES" << endl;
        if (k == 2) {
            cout << u << " " << v << " " << w << " ";
        } else if (k%4 == 0) {
            cout << v << " ";
            while (k) {
                cout << w << " " << v << " " << u << " " << v << " ";
                k -= 4;
            }
        } else {
            cout << u << " " << v << " ";
            k -= 1;
            while (k > 1) {
                cout << w << " " << v << " " << u << " " << v << " ";
                k -= 4;
            }
            cout << w << " ";
        }
        cout << endl;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (graph[i][j] == graph[j][i]) {
                gen_exchange(i, j, k); return;
            }
        }
    }
    if (k%2 == 1) {
        // 0, 1 is ab or ba
        gen_exchange(0, 1, k); return;
    }
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            int a1 = -1, b1 = -1; // j->i
            int a2 = -1, b2 = -1; // i->j
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (graph[j][i] == 'a') a1 = j;
                if (graph[j][i] == 'b') b1 = j;
                if (graph[i][j] == 'a') a2 = j;
                if (graph[i][j] == 'b') b2 = j;
            }
            if (a1 != -1 && a2 != -1) {
                gen_aabb(a1, i, a2, k); return;
            }
            if (b1 != -1 && b2 != -1) {
                gen_aabb(b1, i, b2, k); return;
            }
        }
    }
    cout << "NO" << endl;
}

