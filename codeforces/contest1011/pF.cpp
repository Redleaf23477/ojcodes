//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

struct Node
{
    char type; // A(and), O(or), X(xor), N(not), I(input)
    vector<int> child;
    bool val;

    void init(string s, int a, int b)
    {
        type = s[0];
        if(a > 0) child.push_back(a);
        if(b > 0) child.push_back(b);
    }
};

const int N = 1000006;
int n, root;
Node graph[N];
bool willChangeResult[N];

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
    cin >> n;
    vector<bool> checkRoot(n+1, false);
    fill(willChangeResult, willChangeResult+n+1, false);
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        string str; cin >> str;
        switch(str[0])
        {
            case 'A': case 'O': case 'X':
                cin >> a >> b;
                graph[i].init(str, a, b);
                checkRoot[a] = checkRoot[b] = true;
                break;
            case 'N':
                cin >> a;
                graph[i].init(str, a, -1);
                checkRoot[a] = true;
                break;
            case 'I':
                cin >> a;
                graph[i].type = 'I';
                graph[i].val = a;
                break;
            default: cout << __LINE__ << " : 7122" << endl; exit(0);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(checkRoot[i] == false)
        {
            root = i; break;
        }
    }
}

bool run(int idx)
{
    vector<int> &son = graph[idx].child;
    switch(graph[idx].type)
    {
        case 'A': return graph[son[0]].val & graph[son[1]].val;
        case 'O': return graph[son[0]].val | graph[son[1]].val;
        case 'X': return graph[son[0]].val ^ graph[son[1]].val;
        case 'N': return !graph[son[0]].val;
        default: cout << __LINE__ << " : 7122" << endl; exit(0);
    }
}

bool dfsOriResult(int idx)
{
    switch(graph[idx].type)
    {
        case 'A': return graph[idx].val = dfsOriResult(graph[idx].child[0]) & dfsOriResult(graph[idx].child[1]);
        case 'O': return graph[idx].val = dfsOriResult(graph[idx].child[0]) | dfsOriResult(graph[idx].child[1]);
        case 'X': return graph[idx].val = dfsOriResult(graph[idx].child[0]) ^ dfsOriResult(graph[idx].child[1]);
        case 'N': return graph[idx].val = !dfsOriResult(graph[idx].child[0]);
        case 'I': return graph[idx].val;
        default: cout << __LINE__ << " : 7122" << endl; exit(0);
    }
}

void dfsCheckChange(int idx, int fa)
{
    if(idx != fa)
    {
        bool oriRes = run(fa), newRes;
        graph[idx].val = !graph[idx].val;
        newRes = run(fa);
        graph[idx].val = !graph[idx].val;
        if(oriRes == newRes) return;
    }
    willChangeResult[idx] = true;
    for(auto c:graph[idx].child)
    {
        dfsCheckChange(c, idx);
    }
}

void process()
{
    bool res = dfsOriResult(root);
    dfsCheckChange(root, root);
    // print
    for(int i = 1; i <= n; i++)
    {
        if(graph[i].type == 'I') cout << (willChangeResult[i]? !res:res);
    }
    cout << endl;
}

