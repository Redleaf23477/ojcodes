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

int n;
vector<int> arr;

void init() {
    cin >> n;
    arr.assign(n, 0); for (auto &x : arr) cin >> x;
}

void process() {
    vector<int> goLeft(n, 0), goRight(n, 0); {
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) goLeft[i] = goLeft[i-1]+1;
        }
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) goRight[i] = goRight[i+1]+1;
        }
        /*
        cerr << "goLeft = "; for (auto x : goLeft) cerr << x << " "; cerr << endl;
        cerr << "goRight = "; for (auto x : goRight) cerr << x << " "; cerr << endl;
        */
    }
    int len = max(*max_element(range(goLeft)), *max_element(range(goRight)));
    int cnt = 0, ok = 0; {
        for (int i = 0; i < n; i++) {
            if (goLeft[i] == len || goRight[i] == len) cnt++;
            if (goLeft[i] == len && goRight[i] == len) ok++;
        }
    }
    // cerr << var(len) << var(cnt) << endl;
    if (cnt == 0 || cnt > 1 || len%2 == 1 || ok == 0) cout << 0 << endl;
    else cout << 1 << endl;
}

