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

int n;
vector<int> arr, pos;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
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
    pos.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i]; arr[i]--;
        pos[arr[i]] = i;
    }
}

bool good()
{
    int nxt = -1;
    vector<int> used(n, false);
    for(int i = 0; i < n; i++)
    {
        if(nxt == -1)
        {
            used[pos[i]] = true;
            nxt = pos[i]+1;
        }
        else
        {
            if(pos[i] != nxt) return false;
            used[nxt] = true;
            nxt = nxt+1;
        }
        if(nxt == n || used[nxt] == true) nxt = -1;
    }
    return true;
}

void process()
{
    if(good()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

