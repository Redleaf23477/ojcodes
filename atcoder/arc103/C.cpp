//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

map<int, int> odd, even;

int n;
void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(i&1)
        {
            if(odd.count(x) == 0) odd[x] = 0;
            odd[x]++;
        }
        else 
        {
            if(even.count(x) == 0) even[x] = 0;
            even[x]++;
        }
    }
    odd[712223] = 0;
    even[712222] = 0;
}

void process()
{
    int oddmx = 712223, oddmx2 = 712223;
    int evenmx = 712222, evenmx2 = 712222;
    for(auto p:odd)
    {
        if(p.second > odd[oddmx]) oddmx2 = oddmx, oddmx = p.first;
        else if(p.second > odd[oddmx2]) oddmx2 = p.first;
    }
    for(auto p:even)
    {
        if(p.second > even[evenmx]) evenmx2 = evenmx, evenmx = p.first;
        else if(p.second > even[evenmx2]) evenmx2 = p.first;
    }

    int ans = 0;
    if(oddmx != evenmx)
    {
        ans = n - odd[oddmx] - even[evenmx];
    }
    else
    {
        ans = min(n - odd[oddmx] - even[evenmx2], n - even[evenmx] - odd[oddmx2]);
    }
    cout << ans << endl;
}

