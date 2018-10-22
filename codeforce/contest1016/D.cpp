//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 110;

int r, c;
int rxor[N], cxor[N];

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
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> rxor[i];
    for(int i = 0; i < c; i++) cin >> cxor[i];
}

bool ok()
{
    int rx = 0, cx = 0;
    for(int i = 0; i < r; i++) rx ^= rxor[i];
    for(int i = 0; i < c; i++) cx ^= cxor[i];
    return rx == cx;
}

void process()
{
    if(ok()) cout << "YES" << endl;
    else { cout << "NO" << endl; return; }
    for(int i = 0; i < r; i++)
    {
        if(i == r-1)
        {
            int x = 0;
            for(int j = 0; j < c-1; j++) 
            {
                cout << cxor[j] << " ";
                x ^= cxor[j];
            }
            int last = x^rxor[r-1];
            cout << last << endl;
        }
        else for(int j = 0; j < c; j++)
        {
            if(j == c-1) cout << rxor[i] << endl;
            else cout << 0 << " ";
        }
    }
}

