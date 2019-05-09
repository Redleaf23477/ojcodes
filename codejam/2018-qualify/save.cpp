//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll d;
string str;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
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
    cin >> d >> str;
}

bool move()
{
    for(int i = str.size()-1; i > 0; i--)
    {
        if(str[i] == 'S' && str[i-1] == 'C')
        {
            swap(str[i], str[i-1]);
            return true;
        }
    }
    return false;
}

bool ok()
{
    ll atk = 1, tot = 0;
    for(auto x:str)
    {
        if(x == 'S') tot += atk;
        else atk *= 2;
    }
    return tot <= d;
}

void process()
{
    int mv = 0;
    bool possible = true;
    while(possible && !ok())
    {
        possible = move();
        mv++;
    }
    if(possible) cout << mv << endl;
    else cout << "IMPOSSIBLE" << endl;
}

