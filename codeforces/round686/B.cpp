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
vector<int> arr;

void init() {
    cin >> n;
    arr.assign(n+1, -1);
}

void process() {
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (arr[x] == -1) arr[x] = i;
        else if (arr[x] != -2) arr[x] = -2;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= 0) { ans = arr[i]+1; break; }
    }
    cout << ans << endl;
}

