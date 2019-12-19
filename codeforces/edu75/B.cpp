//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
int ones, zeros;
vector<int> len;

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
    cin >> n;
    string str;
    ones = zeros = 0;
    len.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        for(auto c : str) ones += (c=='1'), zeros += (c=='0');
        len[i] = str.size();
    }
    sort(len.begin(), len.end());
}

void process()
{
    int pairNum = (ones/2) + (zeros/2);
    int restNum = (ones%2) + (zeros%2);
    int ans = 0;
    for(auto l : len)
    {
        if(l%2 == 1)
        {
            if(restNum == 0) restNum = 2, pairNum -= 1;
            if(l/2 <= pairNum)
            {
                restNum -= 1;
                pairNum -= l/2;
                ans += 1;
            }
        }
        else
        {
            if(l/2 <= pairNum)
            {
                pairNum -= l/2;
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}

