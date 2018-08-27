//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 30;

int n;
string s, t;

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
    cin >> n >> s >> t;
}

void process()
{
    bool bad = false;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int pos = -1;
        for(int j = i; j < n && pos < 0; j++)
        {
            if(t[i] == s[j]) pos = j;
        }
        if(pos == -1) { bad = true; break; }
        for(int j = pos-1; j >= i; j--)
        {
            ans.push_back(j);
            swap(s[j], s[j+1]);
        }
    }
    if(bad) cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i]+1 << " \n"[i==ans.size()-1];
    }
}

