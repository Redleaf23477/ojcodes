//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, k;
string str;

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
    cin >> n >> k;
    cin >> str;
    sort(str.begin(), str.end());
}

void process()
{
    int tot = str[0]-'a'+1, add = 1;
    char prv = str[0];
    for(int i = 1; i < n && add < k; i++)
    {
        if(str[i]-prv <= 1) continue;
        tot += str[i]-'a'+1;
        prv = str[i];
        add++;
    }
    if(add < k) cout << -1 << endl;
    else cout << tot << endl;
}

