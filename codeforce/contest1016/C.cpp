//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;

int n;
ll arr[2][N];
ll u[N], upU[N], downU[N];

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
    cin >> n;
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    u[n-1] = arr[0][n-1]+arr[1][n-1];
    for(int i = n-2; i >= 0; i--)
        u[i] = u[i+1]+arr[0][i]+arr[1][i];
    upU[n-1] = arr[0][n-1];
    for(int i = n-2; i >= 0; i--)
        upU[i] = upU[i+1]+u[i+1]+arr[0][i]*((n-i)*2-1);
    downU[n-1] = arr[1][n-1];
    for(int i = n-2; i >= 0; i--)
        downU[i] = downU[i+1]+u[i+1]+arr[1][i]*((n-i)*2-1);
    upU[n] = downU[n] = u[n] = 0;
    
    /*
    cout << "U:" << endl;
    for(int i = 0; i < n; i++) cout << u[i] << " ";
    cout << endl;
    cout << "downU:" << endl;
    for(int i = 0; i < n; i++) cout << downU[i] << " ";
    cout << endl;
    cout << "upU:" << endl;
    for(int i = 0; i < n; i++) cout << upU[i] << " ";
    cout << endl;
    */
}


void process()
{
    ll mx = downU[0];
    int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, 1};
    ll tot = 0, r = 0, c = 0;
    for(ll t = 0; t < 2*n; t++)
    {
        tot += t*arr[r][c];
        ll tmp = tot;
        if(t%4 == 1) tmp += u[t/2+1]*(t+1) + upU[t/2+1];
        if(t%4 == 3) tmp += u[t/2+1]*(t+1) + downU[t/2+1];
//        if(t%4 == 1 || t%4 == 3) cout << tmp << " ";
        mx = max(mx, tmp);
        r += dr[t%4];
        c += dc[t%4];
    }
    cout << mx << endl;
}

