// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

int n, m;
vector<int> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    if(n <= m)
    {
        ll ans = 1;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                ans = ans*abs(arr[i]-arr[j])%m;
        cout << ans << endl;
    }
    else cout << 0 << endl;
}

