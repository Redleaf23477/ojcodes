// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

int vn, D;

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
    cin >> vn >> D;
}

void solve()
{
    vector<int> pa(vn);
    vector<vector<int>> tree;
    vector<int> cursor;
    int dsum = 0;
    // build complete binary tree
    for(int use = 0, dep = 0; use < vn; dep++)
    {
        int thisLv = min(vn-use, 1<<dep);
        vector<int> lv(thisLv);
        for(int i = 0; i < thisLv; i++)
        {
            lv[i] = use;
            pa[use] = (use-1)/2;
            use++;
        }
        tree.push_back(lv);
        dsum += thisLv * dep;
        if(thisLv > 1) cursor.push_back(dep);
    }
    /*
    cerr << "TREE: " << endl;
    for(auto t : tree)
    {
        for(auto n : t)
            cerr << n << " ";
        cerr << endl;
    }
    cerr << "PA: ";
    for(auto p : pa) cerr << p << " ";
    cerr << endl;
    cerr << "cursor: ";
    for(auto c : cursor) cerr << c << " ";
    cerr << endl;
    */
    // if D too small, return
    if(D < dsum)
    {
        cout << "NO" << endl; return;
    }
    // make deep
    while(dsum < D)
    {
        int lv = cursor.back();
        int v = tree[lv].back();
        tree[lv].pop_back();
        if(tree[lv].size() == 1) cursor.pop_back();
        if(lv == (int)tree.size()-1)
        {
            tree.push_back(vector<int>());
        }
        tree[lv+1].push_back(v);
        if(tree[lv+1].size() > 1) cursor.push_back(lv+1);
        pa[v] = tree[lv][(tree[lv+1].size()-1)/2];
        dsum++;
    }
    cout << "YES" << endl;
    for(int i = 1; i < vn; i++)
        cout << pa[i]+1 << " ";
    cout << endl;
}

void process()
{
    if(D > vn*(vn-1)/2) 
    {
        cout << "NO" << endl; return;
    }
    else solve();
}

