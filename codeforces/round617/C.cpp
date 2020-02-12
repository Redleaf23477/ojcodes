// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
string str;

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
    cin >> n >> str;
}

void process()
{
    map<tuple<int,int>, vector<int>> mem;
    int u = 0, l = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'U') u++;
        else if(str[i] == 'D') u--;
        else if(str[i] == 'L') l++;
        else l--;
        auto tup = tie(u, l);
        if(mem.count(tup) == 0) mem[tup] = vector<int>();
        mem[tup].push_back(i);
    }
    u = l = 0;
    ll ans_l, ans_r, ans_len = 1ll<<30;
    {
        auto tup = make_tuple(0, 0);
        if(mem.count(tup) != 0)
        {
            ans_r = mem[tup].front();
            ans_l = 0;
            ans_len = ans_r - ans_l + 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'U') u++;
        else if(str[i] == 'D') u--;
        else if(str[i] == 'L') l++;
        else l--;
        auto tup = tie(u, l);
        auto &arr = mem[tup];
        auto it = upper_bound(arr.begin(), arr.end(), i);
        if(it != arr.end()) 
        {
            ll len = *it - i;
            if(len < ans_len) ans_len = len, ans_l = i+1, ans_r = *it;
        }
    }
    if(ans_len == 1ll<<30) cout << -1 << endl;
    else cout << ans_l+1 << " " << ans_r+1 << endl;
    /*
    for(auto p : mem)
    {
        tie(u, l) = p.first;
        cout << var(u) << var(l) << " : ";
        for(auto x : p.second) cout << x << " ";
        cout << endl;
    }
    */
}

