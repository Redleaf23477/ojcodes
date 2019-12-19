//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int cnt[10];

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
    string str; cin >> str;
    fill(cnt, cnt+10, 0);
    for(auto c : str) cnt[c-'0'] ++;
}

bool good()
{
    if(cnt[0] == 0) return false;
    cnt[0]--;
    int even = 0;
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        if(i%2 == 0 && cnt[i] > 0) even++;
        sum += cnt[i] * (i%3) % 3;
    }
    return even > 0 && sum%3 == 0;
}

void process()
{
    if(good()) cout << "red" << endl;
    else cout << "cyan" << endl;
}

