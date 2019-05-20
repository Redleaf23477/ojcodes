//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;


const int N = 100005;

/////

vector<int> adj[N];
ll initMass[N];
ll mxMass[N];
ll indeg[N];
ll indeg_scc[N];
bool ub_pts[N];
bool ub_scc[N];
bool expand[N];

int D[N], L[N], scc[N];
vector<int> scc_adj[N];
int SCCID, timestamp;

stack<int> st;
void DFS(int v, int fa) { //call DFS(v,v) at first
    D[v] = L[v] = timestamp++; //timestamp > 0
    st.push(v);

    for (int w:adj[v]) {
        if( w==fa ) continue;
        if ( !D[w] ) { // D[w] = 0 if not visited
            DFS(w,v);
            L[v] = min(L[v], L[w]);
        }
        L[v] = min(L[v], D[w]);
    }
    if( D[v] == L[v] ) {
        int x;
        vector<int> tmp;
        do{
            x = st.top();
            st.pop();
            scc[x] = SCCID;
            tmp.push_back(x);
        }while( x != v );
//        cout << ".."; for(auto x:tmp) cout << x << " "; cout << endl;
        
        if(tmp.size() > 1)
        {
            bool any_is_ub = false;
            for(auto x:tmp) 
            {
                if(mxMass > 0 && (ub_pts[x] == true || scc[x] != 0))
                {
                    any_is_ub = true;
                    break;
                }
            }
            if(any_is_ub) 
            {
                ub_scc[SCCID] = true;
                for(auto x:tmp)
                {
                    if(!expand[x])
                    {
                        expand[x] = true;
                        for(auto y:adj[x]) ub_pts[y] = true;
                    }
                }
            }
        }
        else if(tmp.size() == 1 && mxMass[tmp[0]] > 0)  // must be true
        {
            int y = tmp[0];
            if(adj[y][0] == y || adj[y][1] == y)
            {
                for(auto z:adj[y]) ub_pts[z] = true;
            }
            if(adj[y][0] == y && adj[y][1] == y)
            {
                ub_scc[SCCID] = true;
            }
        }

        SCCID++;
    }
}

/////

int n;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
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
    cin >> n;

    SCCID = 1;
    timestamp = 1;
    memset(indeg, 0, sizeof(indeg));
    memset(D, 0, sizeof(D));
    memset(L, 0, sizeof(L));
    memset(scc, 0, sizeof(scc));
    memset(expand, 0, sizeof(expand));
    memset(ub_pts, 0, sizeof(ub_pts));
    memset(ub_scc, 0, sizeof(ub_scc));
    memset(indeg_scc, 0, sizeof(indeg_scc));
    while(!st.empty()) st.pop();
    for(int i = 0; i < n; i++) adj[i].clear();
    
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        adj[i].push_back(a);
        adj[i].push_back(b);
        indeg[a]++;
        indeg[b]++;
    }
    for(int i = 0; i < n; i++) 
    {
        cin >> initMass[i];
        mxMass = initMass[i];
    }
}

/*
void buildMxMass()
{
    queue<int> q;
    for(int i = 0; i < n; i++) if(indeg[i] == 0) q.push(q);
    if(q.empty())
    {
    }
    else
    {
        while(!q.empty())
        {
        }
    }
}
*/

void process()
{
    // check mxmass
    // buildMxMass();

    // build scc
    for(int i = 0; i < n; i++)
    {
        if(D[i] == 0) DFS(i, i);
    }
    if(ub_scc[scc[0]] == true) cout << "UNBOUNDED" << endl;
    else
    {
    }
    // build scc g
    for(int i = 0; i < n; i++)
    {
        int a = scc[i];
        for(auto x:adj[i])
        {
            int b = scc[x];
            scc_adj[a].push_back(b);
            indeg_scc[b]++;
        }
    }
    else cout << 

    /*
    for(int i = 0; i < n; i++)
    {
        cout << i << " : ";
        cout << "(SCCID: " << scc[i] << "), ";
        cout << "(ub_scc: " << ub_scc[scc[i]] << "), ";
        cout << "(ub_pts: " << ub_pts[i] << ")";
        cout << endl;
    }
    */
}

