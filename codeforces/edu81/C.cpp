// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

vector<int> s[26];
string t;

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
    for(int i = 0; i < 26; i++) s[i].clear();
    string str; cin >> str >> t;
    for(int i = 0; i < (int)str.size(); i++)
    {
        s[str[i]-'a'].push_back(i);
    }
}

void process()
{
    int turn = 1, ptr = -1;
    for(int i = 0; i < (int)t.size(); i++)
    {
        char c = t[i];
        int idx = c-'a';
        if(s[idx].size() == 0)
        {
            cout << -1 << endl; return;
        }
        auto it = upper_bound(s[idx].begin(), s[idx].end(), ptr);
        if(it == s[idx].end())
        {
            turn++;
            ptr = s[idx].front();
        }
        else ptr = *it;
    }
    cout << turn << endl;
}

