//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;

int n;
vector<ll> arr;
ll d;

void init();
void process();

int32_t main()
{
    init();
    process();
    return 0;
}

ll get_ai(int i)
{
    cout << "? " << i << endl;
    cout.flush();
    ll a; cin >> a; return a;
}

bool check_x(ll x)
{
    if(x > 1e9) return false;
    cout << "> " << x << endl;
    cout.flush();
    bool arr; cin >> arr; return arr;
}

void init()
{
    int bogo = 40;
    cin >> n;
    default_random_engine gen;
    uniform_int_distribution<int> dis(1, n);
    auto myrand = bind(dis, gen);
    if(n <= 60)
    {
        for(int i = 0; i < n; i++) arr.push_back(get_ai(i+1));
        sort(arr.begin(), arr.end());
        cout << "! " << arr[0] << " " << arr[1]-arr[0] << endl;
        exit(0);
    }
    vector<bool> qed(n+1, false);
    for(int i = 0; i < bogo; i++) 
    {
        int idx = myrand();
        while(qed[idx]) idx = rand()%n;
        qed[idx] = true;
        arr.push_back(get_ai(idx));
    }
    d = abs(arr[1]-arr[0]);
    for(int i = 2; i < bogo; i++)
    {
        d = __gcd(abs(arr[i]-arr[i-1]), d);
    }
}

void process()
{
    ll low = 0, high = n-1, mid, big = arr.back();
    while(low <= high)
    {
        mid = (low+high)/2;
        if(check_x(arr.back()+d*mid) == 1)
        {
            big = arr.back()+d*mid+d;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    // big = a1 * d(n-1)
    ll a1 = big-d*(n-1);
    cout << "! " << a1 << " " << d << endl;
}

