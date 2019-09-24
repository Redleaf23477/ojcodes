//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

string str;
vector<int> zero;

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
    cin >> str;
    zero.resize(str.size());
    zero[0] = 0;
    for(size_t i = 1; i < str.size(); i++)
    {
        if(str[i-1] == '1') zero[i] = 0;
        else zero[i] = zero[i-1]+1;
    }
}

void process()
{
    ll ans = 0;
    for(int i = str.length()-1; i >= 0; i--)
    {
        ll tmp = 0, l;
        // since if l >= 19, if there comes an '1', tmp must be greater than 2e5, if there always comes '0', there will be no answer
        for(l = 1; i-l+1 >= 0 && l <= 19; l++)
        {
            tmp += (str[i-l+1]-'0')*(1<<(l-1));
            if(tmp == l) ans++;
        }
        if(l == 20 && tmp > 19 && tmp <= 19+zero[i-19+1]) ans++;
    }
    cout << ans << endl;
}

