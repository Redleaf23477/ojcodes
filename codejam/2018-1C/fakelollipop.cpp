//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;

int n;
vector<int> cnt;
vector<bool> sold;

void init();
void process();

int32_t main()
{
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    cin >> n;
    cnt.resize(n);
    sold.resize(n);
    for(int i = 0; i < n; i++)
    {
        cnt[i] = 0;
        sold[i] = false;
    }
}

void process()
{
    for(int i = 0; i < n; i++)
    {
            int y; cin >> y;
            int finalchoice = -1;
            vector<int> choice(y);
            for(int j = 0; j < y; j++) cin >> choice[j];
            for(auto c:choice)
            {
                cnt[c]++;
            }
            int mn = 7122, mnidx = -1;
            for(auto c:choice)
            {
                if(sold[c]) continue;
                if(cnt[c] == 20) 
                {
                    finalchoice = c;
                    break;
                }
                if(cnt[c] < mn) mn = cnt[c], mnidx = c;
            }
            if(finalchoice == -1) finalchoice = mnidx;
            
            cout << finalchoice << endl;
            if(finalchoice != -1) sold[finalchoice] = true;
    }
}

