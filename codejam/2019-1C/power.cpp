//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;

ll cnt[10];

void init();
void process();

int32_t main()
{
    int T, F; cin >> T >> F;
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
}

void process()
{
    string ans(5, 'X');
    bool have[10] = {0};
    vector<int> group[10];
    // 1st
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < 5; i++) group[i].clear();
    for(int i = 0; i < 119; i++)
    {
        char ch;
        cout << 5*i+1 << endl;
        cin >> ch;
        cnt[ch-'A']++;
        group[ch-'A'].push_back(i);
    }
    int mn = 71222, mnidx;
    for(int i = 0; i < 5; i++)
    {
        if(cnt[i] < mn) mn = cnt[i], mnidx = i;
    }
    have[mnidx] = true;
    ans[0] = 'A'+mnidx;

    //  2nd
    vector<int> is = group[mnidx];
    for(int i = 0; i < 5; i++) group[i].clear();
    memset(cnt, 0, sizeof(cnt));
    for(auto i : is)
    {
        char ch;
        cout << 5*i+2 << endl;
        cin >> ch;
        cnt[ch-'A']++;
        group[ch-'A'].push_back(i);
    }
    mn = 71222, mnidx = -1;
    for(int i = 0; i < 5; i++)
    {
        if(have[i] == false && cnt[i] < mn) mn = cnt[i], mnidx = i;
    }
    have[mnidx] = true;
    ans[1] = 'A'+mnidx;

    // 3rd
    is = group[mnidx];
    for(int i = 0; i < 5; i++) group[i].clear();
    memset(cnt, 0, sizeof(cnt));
    for(auto i : is)
    {
        char ch;
        cout << 5*i+3 << endl;
        cin >> ch;
        cnt[ch-'A']++;
        group[ch-'A'].push_back(i);
    }
    mn = 71222, mnidx = -1;
    for(int i = 0; i < 5; i++)
    {
        if(have[i] == false && cnt[i] < mn) mn = cnt[i], mnidx = i;
    }
    have[mnidx] = true;
    ans[2] = 'A'+mnidx;

    // 4rd
    is = group[mnidx];
    for(int i = 0; i < 5; i++) group[i].clear();
    memset(cnt, 0, sizeof(cnt));
    for(auto i : is)
    {
        char ch;
        cout << 5*i+4 << endl;
        cin >> ch;
        cnt[ch-'A']++;
        group[ch-'A'].push_back(i);
    }
    mn = 71222, mnidx = -1;
    for(int i = 0; i < 5; i++)
    {
        if(have[i] == false && cnt[i] < mn) mn = cnt[i], mnidx = i;
    }
    have[mnidx] = true;
    ans[3] = 'A'+mnidx;

    // 5th
    for(int i = 0; i < 5; i++) 
    {
        if(have[i] == false) ans[4] = 'A'+i;
    }

    cout << ans << endl;

    char ch; cin >> ch;
}

