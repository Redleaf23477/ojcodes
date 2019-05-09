//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 1010;

int n;
list<string> strlist;

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
    string str[N];
    for(int i = 0; i < n; i++) 
    {
        cin >> str[i];
        reverse(str[i].begin(), str[i].end());
    }
    sort(str, str+n);
    strlist = list<string>(str, str+n);
}

string getPre(string &a, string &b)
{
    size_t len = 0;
    while(len < a.size() && len < b.size() && a[len] == b[len]) len++;
    return a.substr(0, len);
}

void process()
{
    ll ans = 0;
    set<string> used;


    string mx = ""; auto mx_l = strlist.end(), mx_r = strlist.end();
    do
    {
        mx = "";
        auto it_l = strlist.begin();
        auto it_r = strlist.begin(); it_r++;
        while(it_r != strlist.end())
        {
            string pre = getPre(*it_l, *it_r);
            string pp;
            for(int i = pre.size(); i > mx.size(); i--)
            {
                pp = pre.substr(0, i);
                if(used.count(pp) == 0) 
                {
                    mx = pp, mx_l = it_l, mx_r = it_r;
                    break;
                }
            }
            it_l++; it_r++;
        }
        if(mx.size() > 0)
        {
//            cout << ".." << mx << endl;
            used.insert(mx);
            ans += 2;
            strlist.erase(mx_r);
            strlist.erase(mx_l);
        }
//        for(auto x:strlist) cout << ".." << x << endl;
//        cout << endl;
    } while(mx.size() > 0);
    
    cout << ans << endl;
}

