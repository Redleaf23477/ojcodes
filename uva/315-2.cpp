// find AP
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 200;

int vn;
vector<int> G[N];
vector<int> T[N];
int tim;
int dep[N], low[N];
vector<int> AP;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> vn && vn)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> ws;
    tim = 1;
    AP.clear();
    for(int i = 0; i <= vn; i++) G[i].clear(), T[i].clear(), dep[i] = 0;
    string str;
    while(getline(cin, str))
    {
        int from, to;
        stringstream ss(str);
        ss >> from;
        if(from == 0) break;
        while(ss >> to) G[from].push_back(to), G[to].push_back(from);
    }
    /*
    for(int i = 1; i <= vn; i++)
    {
        cout << i << " : ";
        for(auto x:G[i]) cout << x << " ";
        cout << endl;
    }
    */
}

void dfs(int v, int f)
{
    bool isAP = false;
    dep[v] = low[v] = tim++;
    int childNum = 0;
    
    for(auto x:G[v])
    {
        if(x == f) continue;
        if(dep[x] == 0)
        {
            childNum++;
            dfs(x, v);
            // theorem 2: AP iff father->son and dep[father] <= low[son]
            if(low[x] >= dep[v]) isAP = true;
            low[v] = min(low[v], low[x]);
        }
        // update low
        low[v] = min(low[v], dep[x]);
    }

    // theorem 1: AP iff root and more than one child
    if(v == f) isAP = (childNum > 1);

    if(isAP) AP.push_back(v);
}

void process()
{
    dfs(1, 1);
    cout << AP.size() << endl;
//    cout << "AP: "; for(auto x:AP) cout << x << " "; cout << endl;
}

