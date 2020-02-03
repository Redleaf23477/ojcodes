// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

string str;
vector<int> cnt[26];
int q;

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
    cin >> str;
    for(int i = 0; i < 26; i++)
        cnt[i].resize(str.size(), 0);
    cnt[str[0]-'a'][0] = 1;
    for(size_t i = 1; i < str.size(); i++)
    {
        cnt[str[i]-'a'][i]++;
        for(int j = 0; j < 26; j++)
            cnt[j][i] += cnt[j][i-1];
    }
    /*
    for(int i = 0; i < (int)str.size(); i++)
    {
        cout << i << " : " << endl;
        for(int j = 0; j < 26; j++)
        {
            if(cnt[j][i] > 0) cout << (char)(j+'a') << " : " << cnt[j][i] << endl;
        }
    }
    */
    cin >> q;
}

void process()
{
    int l, r; 
    while(q--)
    {
        cin >> l >> r; l--, r--;
        vector<ll> tmp(26);
        ll hasValue = 0;
        for(int i = 0; i < 26; i++)
        {
            ll del = (l == 0)? 0 : cnt[i][l-1];
            tmp[i] = cnt[i][r]-del;
            if(tmp[i] > 0) hasValue++;
        }
        if(str[l] != str[r] || hasValue > 2 || l == r) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

