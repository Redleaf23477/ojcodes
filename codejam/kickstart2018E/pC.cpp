//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 16;

int n, cardN;
ll fact[N];
ll bahu[N], bala[N];
ll bahuStrat[3], balaStrat[3];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    // calc fact
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    cardN = 3*n;
    for(int i = 0; i < cardN; i++) cin >> bahu[i];
    for(int i = 0; i < cardN; i++) cin >> bala[i];
    // bahuStrat: big big mini
    bahuStrat[0] = bahuStrat[1] = bahuStrat[2] = 0;
    sort(bahu, bahu+cardN);
    for(int i = cardN-1; i >= n; i--) 
    {
        if(bahuStrat[0] > bahuStrat[1]) bahuStrat[1] += bahu[i];
        else bahuStrat[0] += bahu[i];
    }
    for(int i = 0; i < n; i++) bahuStrat[2] += bahu[i];
}

int dfs(int idx, int sz0, int sz1, int sz2)
{
    int tot = 0;
    if(idx == cardN) // check and return
    {
        int order[3] = {0, 1, 2};
        do
        {
            int win = 0;
            for(int i = 0; i < 3; i++)
            {
                if(bahuStrat[i] > balaStrat[order[i]]) win++;
            }
            if(win >= 2) tot++;
        } while(next_permutation(order, order+3));
        return tot;
    }
    if(sz0 < n)
    {
        balaStrat[0] += bala[idx];
        tot += dfs(idx+1, sz0+1, sz1, sz2);
        balaStrat[0] -= bala[idx];
    }
    if(sz1 < n)
    {
        balaStrat[1] += bala[idx];
        tot += dfs(idx+1, sz0, sz1+1, sz2);
        balaStrat[1] -= bala[idx];
    }
    if(sz2 < n)
    {
        balaStrat[2] += bala[idx];
        tot += dfs(idx+1, sz0, sz1, sz2+1);
        balaStrat[2] -= bala[idx];
    }
    return tot;
}

void process()
{
    double bahuWin = dfs(0, 0, 0, 0); // how many times can bahu win
    double totBattle = fact[cardN]/fact[n]/fact[n]/fact[n]*6;
//    cout << bahuWin << " " << totBattle << " ";
    cout << fixed << setprecision(9) << bahuWin/totBattle << endl;
}

