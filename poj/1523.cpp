#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *  class to search AP, Bridge, BiCC in an undirected graph
 */
class UndirectedTarjan
{
private:
    int vn;
    int ts; // dfs timestamp
    vector< vector<int> > graph;  // index of v = 0 ~ vn-1
    vector<int> low;
    vector<int> dep;  // depth of node, implemented with timestamp
    stack<int> biccStk;  // stack, used to find BiCC
    stack<int> bccStk;  // stack, used to find BCC
    vector<int> AP;
    //vector<int> BiCC;
    vector< vector<int> > BiCC;
    vector< pair<int,int> > Bridge;
    vector< vector<int> > BCC;
    void reportAP(int ap) { AP.push_back(ap); }
    void reportBiCC(int v)
    {
        vector<int> block(1, v);
        while(biccStk.top() != v) 
        {
            block.push_back(biccStk.top()); biccStk.pop();
        }
        BiCC.push_back(block);
    }
    void reportBridge(int u, int v) { Bridge.push_back((pair<int,int>){u, v}); }
    void reportBCC(int v)
    {
        vector<int> bcc;
        int x;
        do
        {
            x = bccStk.top(); bccStk.pop();
        } while(x != v);
        BCC.push_back(bcc);
    }
    void dfs(int v, int p)
    {
        int childNum = 0;
        bool maybeAP = false;
        low[v] = dep[v] = ++ts;
        biccStk.push(v), bccStk.push(v);
        for(size_t i = 0; i < graph[v].size(); i++)
        {
            int c = graph[v][i];
            if(c == p) continue;
            if(dep[c] == 0) // not visited
            {
                childNum++;
                dfs(c, v);
                low[v] = min(low[v], low[c]);
                // AP
                if(dep[v] <= low[c]) maybeAP = true;
                // BiCC
                if(dep[v] <= low[c]) reportBiCC(v);
                // Bridge
                if(dep[v] < low[c]) reportBridge(v, c);
            }
            low[v] = min(low[v], dep[c]);
        }
        // BCC
        if(dep[v] == low[v]) reportBCC(v);
        // AP
        if(v == p && childNum >= 2) reportAP(v);
        if(v != p && maybeAP) reportAP(v);
    }
public:
    void init(int v)
    {
        vn = v, ts = 0;
        graph.resize(v);
        low.resize(v, 0);
        dep.resize(v, 0);
    }
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void run()
    {
        for(int i = 0; i < vn; i++)
            if(dep[i] == 0) dfs(i, i);
    }
    vector<int> getAP() { return AP; }
    vector< vector<int> > getBiCC() { return BiCC; }
    vector< pair<int,int> > getBridge() { return Bridge; }
    vector< vector<int> > getBCC() { return BCC; }
};

int arg;

void init();
void process();

int main()
{
    int caseN = 0;
    while(scanf("%d", &arg) && arg)
    {
        printf("Network #%d\n", ++caseN);
        init();
        process();
    }
}

UndirectedTarjan graph;

void init()
{
    graph = UndirectedTarjan();
    graph.init(1000);
    int u, v;
    scanf("%d", &v); graph.addEdge(arg-1, v-1);
    while(scanf("%d", &u) && u)
    {
        scanf("%d", &v);
        graph.addEdge(u-1, v-1);
    }
}

void process()
{
    graph.run();
    vector<int> cnt(1000, 0);
    vector< vector<int> > BiCC = graph.getBiCC();
    vector<int> AP = graph.getAP();
    if(AP.size() == 0)
    {
        printf("  No SPF nodes\n\n");
        return;
    }
    for(size_t i = 0; i < BiCC.size(); i++)
    {
        vector<int> &bicc = BiCC[i];
        for(size_t j = 0; j < bicc.size(); j++) cnt[bicc[j]]++;
    }
    sort(AP.begin(), AP.end());
    for(size_t i = 0; i < AP.size(); i++)
    {
        int v = AP[i];
        printf("  SPF node %d leaves %d subnets\n", v+1, cnt[v]);
    }
    printf("\n");
}

