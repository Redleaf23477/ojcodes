// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n;
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
    cin >> n;
    cin >> str;
}

void process()
{
    vector<int> zero(26, 0), one(26, 0), ans(n, 0);
    zero[str[0]-'a'] = 1;
    bool good = true;
    for(int i = 1; i < n; i++)
    {
        int c = str[i]-'a';
        bool beZero = true, beOne = true;
        for(int j = c + 1; j < 26; j++)
        {
            if(zero[j] > 0) beZero = false;
            if(one[j] > 0) beOne= false;
        }
        if(beZero == false && beOne == false)
        {
            good = false;
        }
        else if(beZero == true)
        {
            zero[c]++;
        }
        else
        {
            one[c]++;
            ans[i] = 1;
        }
    }
    if(good)
    {
        cout << "YES" << endl;
        for(auto x : ans) cout << x;
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

