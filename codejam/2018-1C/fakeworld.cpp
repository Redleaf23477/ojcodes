//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n, len;
set<string> strset;
vector<set<char>> chset;

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
    cin >> n >> len;
    strset.clear();
    chset.resize(len);
    for(int i = 0; i < len; i++) chset[i].clear();
    for(int i = 0; i < n; i++)
    {
        string str; cin >> str;
        strset.insert(str);
        for(int j = 0; j < len; j++) chset[j].insert(str[j]);
    }
}

void process()
{
    if(len == 1)
    {
        cout << "-" << endl; return;
    }
    for(auto i:chset[0])
    {
        for(auto j:chset[1])
        {
            string tmp; tmp.push_back(i); tmp.push_back(j);
            if(strset.count(tmp) == 0)
            {
                cout << tmp << endl; return;
            }
        }
    }
    cout << "-" << endl;
}

