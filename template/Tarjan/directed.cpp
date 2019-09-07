/*
 * Tarjan's algo :
 *
 * - SCC
 *
 * on directed graph only!!!
 *
 * Tested : Uva 11504 - Dominos
 *
*/

#include <bits/stdc++.h>

using namespace std;

/*
 *  class to search AP, Bridge, BiCC in an undirected graph
 */
class DirectedTarjan
{
private:
    int vn;
    int ts; // dfs timestamp
    int sccIdx;
    vector<vector<int>> graph;  // index of v = 0 ~ vn-1
    vector<int> low;
    vector<int> dep;  // depth of node, implemented with timestamp
    stack<int> stk;
    vector<bool> inStk;
    vector<int> scc;  // scc[v] = id of scc
    void reportSCC(int v)
    {
        int x;
        do
        {
            x = stk.top(); stk.pop();
            inStk[x] = false;
            scc[x] = sccIdx;
        } while(x != v);
        sccIdx++;
    }
    void dfs(int v) 
    {
        low[v] = dep[v] = ++ts;
        stk.push(v); inStk[v] = true;
        for(auto c : graph[v])
        {
            if(dep[c] == 0) // not visited
            {
                dfs(c);
                low[v] = min(low[v], low[c]);
            }
            if(inStk[c]) low[v] = min(low[v], dep[c]);
        }
        if(low[v] == dep[v]) reportSCC(v);
    }
public:
    void init(int v)
    {
        vn = v, ts = 0, sccIdx = 0;
        graph.resize(v);
        low.resize(v, 0);
        dep.resize(v, 0);
        scc.resize(v, 0);
        inStk.resize(v, false);
    }
    void addEdge(int u, int v)
    {
        graph[u].emplace_back(v);
    }
    void run()
    {
        for(int v = 0; v < vn; v++)
            if(dep[v] == 0) dfs(v);
    }
    int getSCCId(int v) { return scc[v]; }
};

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
}

int vn;
DirectedTarjan graph;

void init()
{
    int en; cin >> vn >> en;
    graph.init(vn);
    while(en--)
    {
        int u, v; cin >> u >> v;
        graph.addEdge(u, v);
    }
}

void process()
{
    graph.run();
    for(int i = 0; i < vn; i++) 
        cout << "SCCID of " << i << " = " << graph.getSCCId(i) << endl;
}

