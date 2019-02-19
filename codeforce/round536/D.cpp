//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;
int vn, en;
vector<int> graph[N];

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
    cin >> vn >> en;
    for(int i = 0; i < en; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void process()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<bool> pushed(vn+1, false);
    pq.push(1); pushed[1] = true;
    while(!pq.empty())
    {
        int tp = pq.top(); pq.pop();
        cout << tp << " ";
        for(auto x:graph[tp])
        {
            if(pushed[x]) continue;
            pq.push(x);
            pushed[x] = true;
        }
    }
    cout << endl;
}

