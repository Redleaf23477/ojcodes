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
vector<pair<LL,int>> arr;

void init() {
    cin >> n;
    arr.assign(n, make_pair(0,0));
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first; arr[i].second = i;
    }
    sort(range(arr));
}

void process() {
    int low = 0, high = n-1, mid, ans = -1;
    function<bool(int)> good = [&](int idx) {
        LL acc = arr[idx].first;
        for (int i = 0; i < n; i++) {
            if (idx == i) continue;
            if (arr[i].first > acc) return false;
            acc += arr[i].first;
        }
        return true;
    };
    while (low <= high) {
        mid = (low+high)/2;
        if (good(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    vector<int> out; {
        for (auto [val, idx] : arr) {
            if (val >= arr[ans].first) out.emplace_back(idx);
        }
        sort(range(out));
    }
    cout << out.size() << endl;
    for (auto x : out) cout << x+1 << " ";
    cout << endl;
}

