//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, string> P;
#define complaint first
#define str second

const int N = 1010;

int n, m, p;
string buy[N];
int cnt[N][2];
unordered_set<string> forbid;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> m >> p;
    // init
    for(int i = 0; i < p; i++) cnt[i][0] = cnt[i][1] = 0;
    forbid.clear();
    // input
    for(int i = 0; i < n; i++) 
    {
        cin >> buy[i];
        for(int j = 0; j < p; j++) cnt[j][buy[i][j] == '1']++;
    }
    for(int i = 0; i < m; i++)
    {
        string str; cin >> str; forbid.insert(str);
    }
}

void process()
{
    ll bestComplaint = 0;
    string bestChoice(p, '0');
    // get best choice
    for(int i = 0; i < p; i++)
    {
        bestChoice[i] = (cnt[i][0] > cnt[i][1]? '0':'1');
        bestComplaint += min(cnt[i][0], cnt[i][1]);
    }
    // search
    priority_queue<P, vector<P>, greater<P> > pq;
    unordered_set<string> vis;
    pq.emplace(bestComplaint, bestChoice); vis.insert(bestChoice);
    while(!pq.empty())
    {
        P tp = pq.top(); pq.pop();
//        cout << tp.complaint << " " << tp.str << endl;
        if(forbid.count(tp.str) == 0) 
        {
            cout << tp.complaint << endl; return;
        }
        for(int i = 0; i < p; i++)
        {
            ll newComplaint = tp.complaint+cnt[i][tp.str[i]=='1']-cnt[i][tp.str[i]=='0'];
            tp.str[i] = '0'+(tp.str[i] == '0');
            if(vis.count(tp.str) == 0)
            {
                vis.insert(tp.str);
                pq.emplace(newComplaint, tp.str);
            }
            tp.str[i] = '0'+(tp.str[i] == '0');
        }
    }
    cout << 7122 << endl;
}

