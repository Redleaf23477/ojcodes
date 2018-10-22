//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;
int vn, en;
vector<int> G[N];
stack<int> st;
int D[N], L[N], timestamp;
int indeg[N], instk[N];
int scc[N], SCCID;

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
    cin >> vn >> en;
    timestamp = 1, SCCID = 0;
    while(!st.empty()) st.pop();
    for(int i = 0; i <= vn; i++)
    {
        G[i].clear();
        D[i] = L[i] = indeg[i] = instk[i] = 0;
    }
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }
}

void DFS(int v) { //call DFS(v,v) at first
    D[v] = L[v] = timestamp++; //timestamp > 0
    st.push(v);
    instk[v] = 1;

    for (int w:G[v]) {
        if ( !D[w] ) { // D[w] = 0 if not visited
            DFS(w);
            L[v] = min(L[v], L[w]);
        }
        if(instk[w]) L[v] = min(L[v], D[w]);
    }
    if( D[v] == L[v] ) {
        int x;
        do{
            x = st.top();
            st.pop();
            instk[x] = 0;
            scc[x] = SCCID;
        }while( x != v );
        SCCID++;
    }
}

void process()
{
    for(int i = 1; i <= vn; i++)
        if(D[i] == 0)
        {
            DFS(i);
        }
    for(int i = 1; i <= vn; i++)
    {
        for(auto c:G[i])
        {
            if(scc[i] == scc[c]) continue;
            indeg[scc[c]]++;
        }
    }
    for(int i = 1; i <= vn; i++) cout << i << " : " << D[i] << " " << L[i] << " " << scc[i] << endl;
    //for(int i = 0; i < SCCID; i++) cout << i << " : " << indeg[i] << endl;
    int cnt = 0;
    for(int i = 0; i < SCCID; i++) cnt += (indeg[i] == 0);
    cout << cnt << endl;
}

