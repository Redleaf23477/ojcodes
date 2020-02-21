// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

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
    int firstOne = -1, lastOne = -1, ones = 0;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == '1')
        {
            if(firstOne == -1) firstOne = i;
            lastOne = i;
            ones++;
        }
    }
    if(firstOne == -1) cout << 0 << endl;
    else cout << lastOne-firstOne+1-ones << endl;
}

