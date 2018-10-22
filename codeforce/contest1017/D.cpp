//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = (1<<12);

int len, q, listSz;
int value[20];
int inList[N]; 
int ans[N][110]; 
int sum[N][110];

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
    cin >> len >> listSz >> q;
    for(int i = 0; i < len; i++) cin >> value[i];
    for(int i = 0; i < listSz; i++)
    {
        string s; cin >> s;
        int bin = 0;
        for(int j = 0; j < len; j++)
        {
            if(s[j] == '1') bin += (1<<j);
        }
        inList[bin]++;
    }
    for(int x = 0; x < N; x++)
    {
        for(int lst = 0; lst < N; lst++)
        {
            if(inList[lst] == 0) continue;
            int a = x, b = lst, tot = 0;
            for(int i = 0; i < len; i++)
            {
                if( ((a>>i)&1) == ((b>>i)&1) ) tot += value[i];
            }
            if(tot <= 100) ans[x][tot] += inList[lst];
        }
    }
    for(int x = 0; x < N; x++)
    {
        sum[x][0] = ans[x][0];
        for(int k = 1; k <= 100; k++)
        {
            sum[x][k] = sum[x][k-1]+ans[x][k];
        }
    }
}

void process()
{
    string s; int k;
    while(q--)
    {
        int x = 0;
        cin >> s >> k;
        for(int i = 0; i < len; i++) if(s[i] == '1') x += (1<<i);
        cout << sum[x][k] << endl;
    }
}

