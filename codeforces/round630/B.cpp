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
using ll = long long int;

const int M = 1000;

int sp[1010];

int n;
vector<int> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 0; i <= M; i++)
        sp[i] = i;
    for(int p = 2; p <= M; p++)
        if(sp[p] == p)
            for(int j = p*p; j <= M; j += p)
                sp[j] = p;
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    int idx = 1;
    map<int,int> col;
    for(auto x : arr)
    {
        if(col.count(sp[x]) == 0) col[sp[x]] = idx++;
    }
    cout << col.size() << endl;
    for(auto x : arr) cout << col[sp[x]] << " ";
    cout << endl;
}

