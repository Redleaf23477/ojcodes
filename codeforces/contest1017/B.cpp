//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int len;
int a1;
int a00;
string sa, sb;

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
    cin >> len >> sa >> sb;
    a1 = a00 = 0;
    for(int i = 0; i < len; i++) 
    {
        a1 += sa[i]-'0';
        if(sb[i] == '0' && sa[i] == '0') a00++;
    }
}

void process()
{
    ll cnt = 0;
    for(int i = 0; i < len; i++)
    {
        if(sb[i] == '0')
        {
            if(sa[i] == '1') cnt += len-a1-a00;
            else cnt += a1;
        }
    }
    cout << cnt << endl;
}

