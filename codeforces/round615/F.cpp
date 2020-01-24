//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> Dep;

const int N = 200005;

int vn;
vector<int> tree[N];
vector<Dep> dep[N];
vector<Dep> preMx[N], sufMx[N];

Dep max(Dep lhs, Dep rhs)
{
    if(lhs.first > rhs.first) return lhs;
    else return rhs;
}

bool cmp(const Dep &lhs, const Dep &rhs)
{
    return lhs.first < rhs.first;
}

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
    cin >> vn;
    for(int i = 1; i < vn; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i = 0; i < vn; i++) 
    {
        dep[i].resize(tree[i].size());
        preMx[i].resize(tree[i].size());
        sufMx[i].resize(tree[i].size());
    }
}

Dep dfs1(int idx, int pa)
{
    Dep mxDep(0, idx);
    for(size_t i = 0; i < tree[idx].size(); i++)
    {
        int c = tree[idx][i];
        if(c == pa) continue;
        dep[idx][i] = dfs1(c, idx);
        mxDep = max(mxDep, dep[idx][i]);
    }
    mxDep.first += 1;
    return mxDep;
}

void dfs2(int idx, int pa, Dep mx)
{
    for(size_t i = 0; i < tree[idx].size(); i++)
        if(tree[idx][i] == pa) dep[idx][i] = mx;

    preMx[idx][0] = dep[idx][0];
    for(int i = 1; i < (int)tree[idx].size(); i++) 
        preMx[idx][i] = max(preMx[idx][i-1], dep[idx][i]);

    sufMx[idx].end()[-1] = dep[idx].back();
    for(int i = tree[idx].size()-2; i >= 0; i--)
        sufMx[idx][i] = max(sufMx[idx][i+1], dep[idx][i]);

    for(size_t i = 0; i < tree[idx].size(); i++)
    {
        int c = tree[idx][i];
        if(c == pa) continue;
        Dep mxForChild(0, idx);
        if(i > 0) mxForChild = max(mxForChild, preMx[idx][i-1]);
        if(i != tree[idx].size()-1) mxForChild = max(mxForChild, sufMx[idx][i+1]);
        mxForChild.first += 1;
        dfs2(c, idx, mxForChild);
    }
}

void process()
{
    dfs1(0, 0);
    dfs2(0, 0, Dep(0,0));
    int ans = 0;
    vector<int> arr;
    for(int v = 0; v < vn; v++) 
    {
        sort(dep[v].begin(), dep[v].end(), cmp);
        int sum = 0;
        vector<int> tmp;
        for(int i = dep[v].size()-1, j = 0; i >= 0 && j < 3; i--, j++)
        {
            sum += dep[v][i].first;
            tmp.push_back(dep[v][i].second);
        }
        if(sum > ans) ans = sum, arr = tmp;
    }
    cout << ans << endl;
    for(auto x : arr) cout << x+1 << " ";
    for(int i = 0, j = 0; i < 3-arr.size(); j++)
    {
        bool inarr = false;
        for(auto x : arr)
            if(x == j) inarr = true;
        if(inarr == false)
        {
            cout << j+1 << " ";
            i++;
        }
    }
    cout << endl;
}

