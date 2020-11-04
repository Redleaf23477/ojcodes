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

void init() {
}

void process() {
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    if(arr.front().first == arr.back().first) {
        cout << "NO" << endl; return;
    }
    using PII = pair<int,int>;
    int m = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i].first != arr[m-1].first) {
            swap(arr[i], arr[m]);
            m++;
        }
    }
    /*
    for(int i = 0; i < n; i++) {
        cerr << var(arr[i].first) << var(arr[i].second) << endl;
    }
    */
    cout << "YES" << endl;
    for(int i = 0; i < m-1; i++) {
        cout << arr[i].second << " " << arr[i+1].second << endl;
    }
    for(int i = m; i < n; i++) {
        if(arr[i].first == arr[0].first) {
            cout << arr[1].second << " " << arr[i].second << endl;
        } else {
            cout << arr[0].second << " " << arr[i].second << endl;
        }
    }
}

