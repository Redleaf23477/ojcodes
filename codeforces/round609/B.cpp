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
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
vector<LL> arr;

void init() {
    cin >> n;
    arr.assign(n, 0); for (auto &x : arr) cin >> x;
}

void process() {
    set<LL> diff;
    for (int i = 1; i < n; i++) {
        diff.insert(arr[i]-arr[i-1]);
    }
    if (n == 1) cout << 0 << endl;
    else if (diff.size() == 1) cout << 0 << endl;
    else if (diff.size() > 2) cout << -1 << endl;
    else {
        vector<LL> cad(range(diff));
        if ((cad[0] < 0) == (cad[1] < 0)) cout << -1 << endl;
        else {
            cad[0] = abs(cad[0]);
            if (*max_element(range(arr)) < cad[0]+cad[1])
                cout << cad[0]+cad[1] << " " << cad[1] << endl;
            else 
                cout << -1 << endl;
        }
    }
}

