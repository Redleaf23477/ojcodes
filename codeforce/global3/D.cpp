//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

struct P
{
    int id, first, second;
    P(int id, int first, int second):id(id), first(first), second(second){}
};

struct CmpA
{
    bool operator() (const P &lhs, const P &rhs)
    {
        return lhs.second > rhs.second;
    }
};
struct CmpB
{
    bool operator() (const P &lhs, const P &rhs)
    {
        return lhs.second < rhs.second;
    }
};

int n;
priority_queue<P, vector<P>, CmpA> minHeap;
priority_queue<P, vector<P>, CmpB> maxHeap;

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
        int a, b; cin >> a >> b;
        if(a > b) 
        {
            minHeap.emplace(i+1, a, b);
        }
        else
        {
            maxHeap.emplace(i+1, a, b);
        }
    }
}

void process()
{
    vector<P> mn, mx;
    while(!minHeap.empty())
    {
        mn.push_back(minHeap.top()); minHeap.pop();
        while(!minHeap.empty() && mn.back().second > minHeap.top().first) minHeap.pop();
    }
    while(!maxHeap.empty())
    {
        mx.push_back(maxHeap.top()); maxHeap.pop();
        while(!maxHeap.empty() && mx.back().second < maxHeap.top().first) maxHeap.pop();
    }
    if(mn.size() > mx.size())
    {
        cout << mn.size() << endl;
        for(auto x:mn) cout << x.id << " ";
        cout << endl;
    }
    else 
    {
        cout << mx.size() << endl;
        for(auto x:mx) cout << x.id << " ";
        cout << endl;
    }
}

