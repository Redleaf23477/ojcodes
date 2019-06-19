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

int lenA, lenB, q;
string sa, sb;

int match(int x)
{
    for(int i = 0; i < lenB; i++)
    {
        if(sa[x+i] != sb[i]) return false;
    }
    return true;
}

void process()
{
    cin >> lenA >> lenB >> q >> sa >> sb;
    vector<int> occur(lenA, 0), sum(lenA+1, 0);
    for(int i = 0; i <= lenA-lenB; i++)
    {
        occur[i] = match(i);
    }
    for(int i = 1; i <= lenA; i++) sum[i] = sum[i-1]+occur[i-1];
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << sum[max(l-1, r-lenB+1)]-sum[l-1] << endl;
    }
}

