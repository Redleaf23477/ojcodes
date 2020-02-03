// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n;
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
    cin >> n;
    cin >> str;
}

void process()
{
    while(!str.empty() && (str.back()-'0')%2 == 0)
        str.pop_back();
    if(str.empty())
    {
        cout << -1 << endl; return;
    }
    ll sum = 0;
    for(auto c : str) sum += (c-'0');
    if(sum % 2 != 0)
    {
        bool found = false;
        for(int i = (int)str.size()-2; i >= 0; i--)
        {
            if((str[i]-'0')%2 == 1)
            {
                str[i] = 'x'; 
                found = true;
                break;
            }
        }
        if(found == false)
        {
            cout << -1 << endl; return;
        }
    }
    for(auto c : str)
    {
        if(c == 'x') continue;
        cout << c;
    }
    cout << endl;
}
