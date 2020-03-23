// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

ll n, m;
vector<ll> arr;

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
    cin >> n >> m;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    for(int i = 1; arr[0] < m && i < n; i++)
    {
        arr[0] = min(m, arr[0]+arr[i]);
    }
    cout << arr[0] << endl;
}

