// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

int n;
vector<int> arr, col;

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
    arr.resize(n), col.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i]; arr[i]--;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> col[i];
    }
}

void process()
{
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++)
        ans[i] = arr[arr[i]];
    for(auto x : ans) cout << x+1 << " ";
    cout << endl;
}

