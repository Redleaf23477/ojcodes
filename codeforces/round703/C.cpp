// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
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
    init();
    process();
    return 0;
}

void init() {
}

void process() {
    int n; cin >> n;

    function<int(int,int)> guess = [](int l, int r) {
        cout << "? " << l+1 << " " << r+1 << endl;
        int x; cin >> x;
        return x-1;
    };
    function<void(int)> report = [](int ans) {
        cout << "! " << ans+1 << endl;
    };

    int idx = guess(0, n-1);
    // left
    if (idx != 0 && guess(0, idx) == idx) {
        int l = 0, r = idx-1, mid, ans = -1;
        while (l <= r) {
            mid = (l+r)/2;
            int g = guess(mid, idx);
            if (g == idx) ans = mid, l = mid+1;
            else r = mid-1;
        }
        if (ans != -1) {
            report(ans); return;
        }
    }
    // right
    if (idx != n-1) {
        int l = idx+1, r = n-1, mid, ans = -1;
        while (l <= r) {
            mid = (l+r)/2;
            int g = guess(idx, mid);
            if (g == idx) ans = mid, r = mid-1;
            else l = mid+1;
        }
        if (ans != -1) {
            report(ans); return;
        }
    }
    assert(false && "unreachable");
}

