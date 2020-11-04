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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

const int N = 505;
const int INF = 1<<30;

struct Node {
    int t, r, c;
    Node(int _t, int _r, int _c):t(_t), r(_r), c(_c){}
};

int B, n;
vector<Node> arr;

void init() {
    cin >> B >> n;
    for(int i = 0; i < n; i++) {
        int t, r, c; cin >> t >> r >> c; r--, c--;
        arr.emplace_back(t, r, c);
    }
}

void process() {
    vector<int> dp(n, -INF);
    int mx = -1, mxidx = -1;
    for(int i = 0; i < n; i++) {
        while(mxidx+1 < i && arr[i].t - arr[mxidx+1].t >= 2*B) {
            mxidx++;
            mx = max(mx, dp[mxidx]);
        }
        if(mx > 0) dp[i] = mx + 1;
        if(arr[i].t >= arr[i].r+arr[i].c) dp[i] = max(dp[i], 1);
        for(int d = 1; d <= 2*B; d++) {
            int j = i-d;
            if(j < 0) break;
            if(arr[i].t - arr[j].t >= abs(arr[i].r-arr[j].r)+abs(arr[i].c-arr[j].c))
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    /*
    cerr << "dp = ";
    for(auto x : dp) cerr << x << " ";
    cerr << endl;
    */
    cout << max(0, *max_element(dp.begin(), dp.end())) << endl;
}

