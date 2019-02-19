//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;
int n, m;
ll dishRemain[N];
ll dishCost[N];
int cheapPtr;
int cheapest[N];
bool cmp(int lhs, int rhs)
{
    return dishCost[lhs] < dishCost[rhs] || (dishCost[lhs] == dishCost[rhs] && lhs < rhs);
}

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
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> dishRemain[i];
    for(int i = 0; i < n; i++) cin >> dishCost[i];
    for(int i = 0; i < n; i++) cheapest[i] = i;
    sort(cheapest, cheapest+n, cmp);
    cheapPtr = 0;
}

void process()
{
    int wantIdx, wantNum;
    while(m--)
    {
        ll sum = 0;
        cin >> wantIdx >> wantNum; wantIdx--;
        if(dishRemain[wantIdx] >= wantNum)
        {
            dishRemain[wantIdx] -= wantNum;
            sum += dishCost[wantIdx] * wantNum;
        }
        else
        {
            bool gg = false;
            sum += dishRemain[wantIdx] * dishCost[wantIdx];
            wantNum -= dishRemain[wantIdx];
            dishRemain[wantIdx] = 0;
            while(wantNum > 0)
            {
                int cheap = cheapest[cheapPtr];
                if(cheapPtr >= n) 
                {
                    gg = true; break;
                }
                if(dishRemain[cheap] >= wantNum)
                {
                    dishRemain[cheap] -= wantNum;
                    sum += dishCost[cheap] * wantNum;
                    wantNum = 0;
                }
                else
                {
                    sum += dishCost[cheap] * dishRemain[cheap];
                    wantNum -= dishRemain[cheap];
                    dishRemain[cheap] = 0;
                    cheapPtr++;
                }
            }
            if(gg) sum = 0;
        }
        cout << sum << endl;
    }
}

