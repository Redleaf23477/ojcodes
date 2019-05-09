//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
size_t mxlen;
vector<string> oppo;
map<char, char> win;

void init();
void process();

int32_t main()
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
    cin >> n;
    mxlen = 0;
    win.clear();
    oppo.resize(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> oppo[i];
        mxlen = max(mxlen, oppo[i].size());
    }
    win['P'] = 'S';
    win['S'] = 'R';
    win['R'] = 'P';
}

bool good(string attempt)
{
    for(auto o:oppo)
    {
        int my = 0, you = 0;
        bool flag = false;
        for(int c = 0; c < 100; c++)
        {
            if(attempt[my] == o[you])
            {
                my++, you++;
                if(my == attempt.size()) my = 0;
                if(you == o.size()) you = 0;
            }
            else if(win[attempt[my]] == o[you]) return false;
            else if(win[o[you]] == attempt[my])
            {
                flag = true;
                break;
            }
        }
        if(flag == false) return false;
    }
    return true;
}

void process()
{
    string ans = "IMPOSSIBLE";
    queue<string> q;
    q.push("R"); q.push("P"); q.push("S");
    while(!q.empty())
    {
        string f = q.front(); q.pop();
//        cout << ".." << ans << " " << f << endl;
        if(good(f))
        {
            ans = f; break;
        }
        if(f.size() < mxlen) 
        {
            q.push(f+"R"); q.push(f+"P"); q.push(f+"S");
        }
    }
    cout << ans << endl;
}
