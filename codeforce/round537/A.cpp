//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void process()
{
    string s, t;
    cin >> s >> t;
    for(auto &c:s)
    {
        if(isVowel(c)) c = 'x';
        else c = 'y';
    }
    for(auto &c:t)
    {
        if(isVowel(c)) c = 'x';
        else c = 'y';
    }
    if(s == t) cout << "Yes" << endl;
    else cout << "No" << endl;
}

