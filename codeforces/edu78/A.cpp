//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int scnt[30];
string s, p;

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
    cin >> s >> p;
    memset(scnt, 0, sizeof(scnt));
    for(auto c : s) scnt[c-'a']++;
}

bool good(string tmp)
{
    int cnt[30] = {0};
    for(auto c : tmp) cnt[c-'a']++;
    for(int i = 0; i < 30; i++) if(scnt[i] != cnt[i]) return false;
    return true;
}

void process()
{
    for(size_t i = 0; i < p.size(); i++)
        for(size_t j = i; j < p.size(); j++)
        {
            if(good(p.substr(i, j-i+1))) { cout << "YES" << endl; return; }
        }
    cout << "NO" << endl;
}

