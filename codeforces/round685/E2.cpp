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

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

int n;
vector<int> x, ans;

int qry(string op, int i, int j) {
    cout << op << " " << i << " " << j << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void report() {
    cout << "!";
    for (auto x : ans) cout << " " << x;
    cout << endl;
}

bool case1() {  // found same elements
    vector<int> arr(n, -1);
    int u = -1, v = -1;
    for (int i = 1; i < n; i++) {
        if (arr[x[i]] == -1) arr[x[i]] = i;
        else { u = arr[x[i]], v = i; break; }
    }
    if (u == -1) return false;
    int y1 = x[u] + 2*qry("AND", 1, u+1);
    int y2 = 0 + 2*qry("AND", u+1, v+1);
    ans[0] = y1 - y2/2;
    for (int i = 1; i < n; i++) ans[i] = ans[0] ^ x[i];
    return true;
}

bool case2() { // every different
    vector<int> arr(n, -1);
    int u = -1, v = -1;
    for (int i = 1; i < n; i++) {
        arr[x[i]] = i;
        int y = n-1; 
        if (arr[y ^ x[i]] != -1) { u = i, v = arr[y^x[i]]; break; }
    }
    int y1 = x[u] + 2*qry("AND", 1, u+1);
    int y2 = x[v] + 2*qry("AND", 1, v+1);
    int y3 = (x[u]^x[v]);
    ans[0] = (y1 + y2 - y3)/2;
    for (int i = 1; i < n; i++) ans[i] = ans[0] ^ x[i];
    return true;
}

void init() {
    cin >> n;
    x.resize(n), ans.resize(n);
}

void process() {
    for (int i = 1; i < n; i++) {
        x[i] = qry("XOR", 1, i+1);
    }
    if (case1()) report();
    else { case2(), report(); }
}

