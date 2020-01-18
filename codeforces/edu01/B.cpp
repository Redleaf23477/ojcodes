//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

string str;
int q;

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
    cin >> str >> q;
}

void shift(string &str, int l, int r, int k)
{
    string seg = str.substr(l, r-l+1);
    string rot = seg;
    for(size_t i = 0; i < rot.size(); i++)
        rot[i] = seg[(i-k+seg.size())%seg.size()];
    for(size_t i = 0; i < seg.size(); i++)
        str[l+i] = rot[i];
}

void process()
{
    int l, r, k;
    while(q--)
    {
        cin >> l >> r >> k;
        l--; r--; k %= (r-l+1);
        shift(str, l, r, k);
    }
    cout << str << endl;
}

