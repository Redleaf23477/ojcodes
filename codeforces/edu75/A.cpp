//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

string str;

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
    cin >> str;
}

void process()
{
    vector<bool> good(26, false);
    char c = '\0'; int cnt = 0;
    for(auto ch : str)
    {
        if(ch != c)
        {
            if(cnt%2 == 1) good[c-'a'] = true;
            c = ch;
            cnt = 1;
        }
        else cnt++;
    }
    if(cnt%2 == 1) good[c-'a'] = true;
    for(int i = 0; i < 26; i++) if(good[i]) cout << (char)('a'+i);
    cout << endl;
}

