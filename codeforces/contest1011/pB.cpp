//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define w first
#define n second

bool operator < (const P &a, const P &b)
{
    return a.w/(a.n+1) < b.w/(b.n+1);
}

struct Cmp
{
    bool operator() (const P &a, const P &b)
    {
        return a < b;
    }
};

int n, m;
map<int, int> mp;

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
    for(int i = 0; i < m; i++)
    {
        int x; cin >> x;
        if(mp.count(x) == 0) mp[x] = 0;
        mp[x]++;
    }
}

void process()
{
    priority_queue<P, vector<P>, Cmp> pq;
    for(auto x:mp)
    {
        pq.push(P(x.second, 0));
    }
    bool ok = true;
    for(int i = 1; i < n; i++)
    {
        P top = pq.top(); pq.pop();
//        cout << top.w << " " << top.n << endl;
        top.n++;
        if(top.w/top.n <= 0)
        {
            ok = false; break;
        }
        pq.push(top);
    }
    P top = pq.top(); pq.pop();
    top.n++;
    cout << (ok && top.w/top.n > 0? top.w/top.n:0) << endl;
}

