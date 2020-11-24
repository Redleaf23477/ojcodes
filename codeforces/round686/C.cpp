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
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
}

bool same() { return *max_element(arr.begin(), arr.end()) == *min_element(arr.begin(), arr.end()); }

void process() {
    vector<bool> valid(n+1, false);
    vector<int> cnt(n+1, 0);
    if (same()) cout << 0 << endl;
    else {
        int l = 0, r = n-1;
        while (arr[l] == arr[l+1]) l++;
        while (arr[r] == arr[r-1]) r--;
        for (int i = l; i <= r; i++) valid[arr[i]] = true;
        for (int i = l+1; i < r; i++) {
            if (arr[i-1] != arr[i]) cnt[arr[i]]++;
        }
        int ans = n;
        for (int i = 1; i <= n; i++) if (valid[i]) ans = min(ans, cnt[i]+1);
        cout << ans << endl;
    }
}

