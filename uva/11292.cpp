//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 20004;
int headNum, knightNum;
int head[N], knight[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> headNum >> knightNum && headNum && knightNum)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    for(int i = 0; i < headNum; i++) cin >> head[i];
    for(int i = 0; i < knightNum; i++) cin >> knight[i];
    sort(head, head+headNum);
    sort(knight, knight+knightNum);
}

void process()
{
    ll sum = 0;
    for(int i = 0, j = 0; i < headNum; i++, j++)
    {
        if(j == knightNum)
        {
            cout << "Loowater is doomed!" << endl;
            return;
        }
        while(knight[j] < head[i])
        {
            if(++j == knightNum)
            {
                cout << "Loowater is doomed!" << endl;
                return;
            }
        }
        sum += knight[j];
    }
    cout << sum << endl;
}

